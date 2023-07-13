


Snake Game description.
--------------------------Game settings--------------------------
Question 1
---You can choose from 1 level to 5 level---
---1 level - very easy---
---5 level - hard---

Question 2
---You can press "y" if you want to go through walls---
---input "y" - you can pass the walls---
---input "n" - you can not go through the walls---
-----------------------------------------------------------------
#################################################################
--------------------------Game controls--------------------------
Keaboard keys:
a - turn left
d - turn right
w - go up
s - go down
x - to exit game
-----------------------------------------------------------------
#################################################################
--------------------------Console output-------------------------
Console outputs:
4 walls using character '@'
Snake head - 'O'
Snake tail - 'o'
Snake food - '*' gives 10 points
Snake "extra tasty food" defined as "X" and it gives 30 point
Also, console output "Score";
-----------------------------------------------------------------
#################################################################
--------------------------Implementation features----------------
To create levels simulation : 
this_thread::sleep_for(chrono::milliseconds());
Speed of rewrite image

For managing the game while the program is running used "_kbhit()" 
To get controls char used "_getch()"
-----------------------------------------------------------------
#################################################################
