
// Github - e92Edvin
// LinkedIn - https://www.linkedin.com/in/edvin-rusecki-848a3215b/

#include <bits/stdc++.h>
#include <conio.h>
#include <chrono>
#include <thread>

using namespace std;

const int width = 20;
const int height = 20;
bool gameOver, inners, eat = false, reps = true;
int x, y, fruitX, fruitY, score, ExtraX, ExtraY, level, iter, ks, nTail, adder;
int Snake_tailX[1000], Snake_tailY[1000], max_arr[1000]={0};
char ch, inp;
enum MoveDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
MoveDirection direct;

void Setup_Check()
{
	cout << "Choose level: 1, 2, 3, 4, 5 " << endl;
	cin >> level;
	while (true) {
		if (level > 0 && level < 6) break;
		else {
			system("cls");
			cout << "Wrong choose! " << endl;
			cout << "Choose level: 1, 2, 3, 4, 5" << endl;
			cin >> level;
		}
	}

	cout << "Do you want walkable walls? (y/n)" << endl;
	cin >> ch;
	while (true) {
		if (ch == 'y') {
			inners = true;
			break;
		}
		else if (ch == 'n') {
			inners = false;
			break;
		}
		else {
			system("cls");
			cout << "Wrong input!" << endl;
			cout << "Type 'y' or 'n' " << endl;
			cin >> ch;
		}
	}
}

void Setup()
{
	Setup_Check();
	gameOver = false;
	direct = STOP;
	x = width / 2 - 1;
	y = height / 2 - 1;
	ks = 3;
	fruitX = rand() % width;
	fruitY = rand() % height;
	ExtraX = rand() % width;
	ExtraY = rand() % height;
	nTail = 0;
	score = 0;
}

void Representation()
{
	system("cls");
	for (int i = 0; i<width + 1; i++)
		cout << "@";
	cout << endl;

	for (int i = 0; i<height; i++) {
		for (int j = 0; j<width; j++) {
			if (j == 0 || j == width - 1)
				cout << "@";
			if (i == y && j == x)
				cout << "0";
			else if (i == fruitY && j == fruitX)
				cout << "*";
			else if (i == ExtraY && j == ExtraX)
				cout << (!eat ? " " : "X");
			else {
				bool print = false;
				for (int k = 0; k<nTail; k++) {
					if (Snake_tailX[k] == j && Snake_tailY[k] == i) {
						print = true;
						cout << "o";
					}
				}
				if (!print) cout << " ";
			}
		}
		cout << endl;
	}

	for (int i = 0; i<width + 1; i++)
		cout << "@";
	cout << endl;
	cout << "Score: " << score << endl;
	switch (level)
	{
	case 1:
		this_thread::sleep_for(chrono::milliseconds(700));
		break;
	case 2:
		this_thread::sleep_for(chrono::milliseconds(350));
		break;
	case 3:
		this_thread::sleep_for(chrono::milliseconds(150));
		break;
	case 4:
		this_thread::sleep_for(chrono::milliseconds(85));
		break;
	case 5:
		this_thread::sleep_for(chrono::milliseconds(1));
		break;
	}
}

void Control()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			direct = LEFT;
			break;
		case 'd':
			direct = RIGHT;
			break;
		case 'w':
			direct = UP;
			break;
		case 's':
			direct = DOWN;
			break;
		case 'x':
			gameOver = true;
			break;
		}
	}
}

void GameLogic()
{
	int prevX = Snake_tailX[0];
	int prevY = Snake_tailY[0];
	int prev2X, prev2Y;
	Snake_tailX[0] = x;
	Snake_tailY[0] = y;
	for (int i = 1; i<nTail; i++) {
		prev2X = Snake_tailX[i];
		prev2Y = Snake_tailY[i];
		Snake_tailX[i] = prevX;
		Snake_tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	switch (direct)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	}

	if (ch == 'n') {
		if (x > width || x < 0 || y > height || y < 0)
			gameOver = true;
	}
	else {
		if (x >= width - 1)
			x = 0;
		else if (x < 0)
			x = width - 2;

		if (y >= height)
			y = 0;
		else if (y < 0)
			y = height - 2;
	}


	for (int i = 0; i<nTail; i++) {
		if (Snake_tailX[i] == x && Snake_tailY[i] == y)
			gameOver = true;
	}

	if (x == fruitX && y == fruitY) {
		score += 10;
		fruitX = rand() % width - 1;
		fruitY = rand() % height - 1;
		nTail++;
		iter++;
	}
	if (iter >= ks) {
		eat = true;
		if (x == ExtraX && y == ExtraY) {
			score += 30;
			ExtraX = rand() % width - 1;
			ExtraY = rand() % height - 1;
			nTail++;
			eat = false;
			iter = 0;
			ks = rand() % 10 + 1;
		}
	}
}

void Checker()
{
    gameOver = false;
    system("cls");
		cout << "GAME OVER!" << endl;
		cout << "Your total score : " << score << endl;
		cout << "Do you want to repeat? (y/n) : "  << endl;
		cin >> inp;
	if (inp == 'y'){
            reps =  true;
            max_arr[adder++] = score;
            cout << "Your record score : " << *max_element(max_arr, max_arr+adder) << endl;
	}
	else{
        reps =  false;
        max_arr[adder++] = score;
        system("cls");
        cout << "Nice work! " << "Your record score : " << *max_element(max_arr, max_arr+adder) << endl;
    }
}

int main()
{
	while (reps) {
		Setup();
		while (!gameOver) {
			Representation();
			Control();
			GameLogic();
		}
        Checker();
	}
	return 0;
}
