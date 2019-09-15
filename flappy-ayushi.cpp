{\rtf1\ansi\ansicpg1252\cocoartf1671\cocoasubrtf200
{\fonttbl\f0\fmodern\fcharset0 Courier;}
{\colortbl;\red255\green255\blue255;\red62\green0\blue93;\red13\green96\blue1;\red0\green0\blue0;
\red0\green0\blue160;\red76\green0\blue36;}
{\*\expandedcolortbl;;\cssrgb\c31373\c0\c43922;\cssrgb\c0\c43922\c0;\cssrgb\c0\c0\c0;
\cssrgb\c0\c0\c69020;\cssrgb\c37647\c0\c18824;}
\paperw11900\paperh16840\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\deftab720
\pard\pardeftab720\sl280\partightenfactor0

\f0\fs24 \cf2 \expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 #include <iostream> \cf3 \strokec3 //created by Ayushi\cf4 \strokec4 \
\cf2 \strokec2 #include <cstdlib>\cf4 \strokec4 \
\cf2 \strokec2 #include <windows.h>\cf4 \strokec4 \
\cf2 \strokec2 #include <conio.h>\cf4 \strokec4 \
\cf2 \strokec2 #include <ctime>\cf4 \strokec4 \
\cf2 \strokec2 #include <fstream>\cf4 \strokec4 \
\cf2 \strokec2 #include <iomanip>\cf4 \strokec4 \
\
\pard\pardeftab720\sl280\partightenfactor0
\cf5 \strokec5 using\cf4 \strokec4  \cf5 \strokec5 namespace\cf4 \strokec4  std;\
\
ifstream inp;  \cf3 \strokec3 //data file reading and writing operators\cf4 \strokec4 \
ofstream outp;\
\
\cf5 \strokec5 char\cf4 \strokec4  c[30][21]; \cf3 \strokec3 //variable for storing screen particles (pixels)\cf4 \strokec4 \
\cf5 \strokec5 int\cf4 \strokec4  n[30][21];  \cf3 \strokec3 //variable for checking\cf4 \strokec4 \
\cf5 \strokec5 int\cf4 \strokec4  highscore;\
\cf5 \strokec5 int\cf4 \strokec4  contr,tuk=0,score=0,t=0,bt=0,birdx=0,birdy=0; \cf3 \strokec3 //variaous variables for certain operations\cf4 \strokec4 \
\cf5 \strokec5 bool\cf4 \strokec4  err; \cf3 \strokec3 //boolean for error detection\cf4 \strokec4 \
\
\cf5 \strokec5 void\cf4 \strokec4  game();  \cf3 \strokec3 //various functions\cf4 \strokec4 \
\cf5 \strokec5 void\cf4 \strokec4  screen();\
\cf5 \strokec5 void\cf4 \strokec4  pipes();\
\cf5 \strokec5 void\cf4 \strokec4  bird();\
\cf5 \strokec5 bool\cf4 \strokec4  gameover();\
\cf5 \strokec5 void\cf4 \strokec4  checkscore();\
\cf5 \strokec5 void\cf4 \strokec4  help();\
\cf5 \strokec5 void\cf4 \strokec4  menu();\
\cf5 \strokec5 void\cf4 \strokec4  endgame();\
\cf5 \strokec5 void\cf4 \strokec4  credits();\
\
\cf5 \strokec5 int\cf4 \strokec4  main()\
\{\
srand(time(0));  \cf3 \strokec3 //seeding random number gen, we will need it later;\cf4 \strokec4 \
inp.open(\cf6 \strokec6 "/Program Files/FlappyBird/options.txt"\cf4 \strokec4 );  \cf3 \strokec3 //opening file in which highscore is stored\cf4 \strokec4 \
\cf5 \strokec5 if\cf4 \strokec4 (inp.is_open()) \cf3 \strokec3 //if file opens successfully, it reads the highscore\cf4 \strokec4 \
\{\
    inp>>highscore;\
    inp.close();\
    err=\cf5 \strokec5 false\cf4 \strokec4 ;  \cf3 \strokec3 //error will be false, because file opened successfully\cf4 \strokec4 \
\}\
\cf5 \strokec5 else\cf4 \strokec4 \
\{\
    highscore=0; \cf3 \strokec3 //if file doesnt exist, highscore will be 0, and err will be true\cf4 \strokec4 \
    err=\cf5 \strokec5 true\cf4 \strokec4 ;\
\}\
\
\cf5 \strokec5 int\cf4 \strokec4  a=0,b;\
\cf5 \strokec5 char\cf4 \strokec4  sl; \cf3 \strokec3 //selection variable\cf4 \strokec4 \
\cf5 \strokec5 while\cf4 \strokec4 (1) \cf3 \strokec3 //loop for repeating actions after each start\cf4 \strokec4 \
\{\
    \cf5 \strokec5 if\cf4 \strokec4 (a==0) \cf5 \strokec5 goto\cf4 \strokec4  play; \
    \cf5 \strokec5 if\cf4 \strokec4 (a>0)               \cf3 \strokec3 //if you play not the first time, it will ask you if you want to play\cf4 \strokec4 \
    \{\
        score=0;\
        cout<<\cf6 \strokec6 "Do you want to play again? [y/n] "\cf4 \strokec4 ;\
        cin>>sl;\
        \cf5 \strokec5 if\cf4 \strokec4 (sl==\cf6 \strokec6 'n'\cf4 \strokec4 ) \cf5 \strokec5 goto\cf4 \strokec4  quit;\
        \cf5 \strokec5 else\cf4 \strokec4  \cf5 \strokec5 goto\cf4 \strokec4  play;\
    \}\
    play:\
    menu(); \cf3 \strokec3 //calling menu function\cf4 \strokec4 \
    cin>>sl;\
    \cf5 \strokec5 switch\cf4 \strokec4 (sl) \cf3 \strokec3 //menu selections\cf4 \strokec4 \
    \{\
        \cf5 \strokec5 case\cf4 \strokec4  \cf6 \strokec6 '1'\cf4 \strokec4 :\
        \{\
            game(); \cf3 \strokec3 //if you choose play, it calls function game\cf4 \strokec4 \
            \cf5 \strokec5 break\cf4 \strokec4 ;\
        \}\
        \cf5 \strokec5 case\cf4 \strokec4  \cf6 \strokec6 '2'\cf4 \strokec4 : \cf3 \strokec3 //other selections-other functions\cf4 \strokec4 \
        \{\
            help(); \
            \cf5 \strokec5 goto\cf4 \strokec4  play;\
            \cf5 \strokec5 break\cf4 \strokec4 ;\
        \}\
        \cf5 \strokec5 case\cf4 \strokec4  \cf6 \strokec6 '3'\cf4 \strokec4 :\
        \{\
            credits();\
            \cf5 \strokec5 goto\cf4 \strokec4  play;\
            \cf5 \strokec5 break\cf4 \strokec4 ;\
        \}\
        \cf5 \strokec5 case\cf4 \strokec4  \cf6 \strokec6 '4'\cf4 \strokec4 :\
        \{\
            \cf5 \strokec5 goto\cf4 \strokec4  quit; \cf3 \strokec3 //exits game\cf4 \strokec4 \
            \cf5 \strokec5 break\cf4 \strokec4 ;\
        \}\
        \cf5 \strokec5 default\cf4 \strokec4 :\
        \{\
            \cf5 \strokec5 goto\cf4 \strokec4  play;\
            \cf5 \strokec5 break\cf4 \strokec4 ;\
        \}\
    \}\
    a++; \cf3 \strokec3 //variable for checking how many times you've played\cf4 \strokec4 \
\}\
quit:\
\{\
   cout<<\cf6 \strokec6 "I quit."\cf4 \strokec4 ; \cf3 \strokec3 //stops game, app closes.\cf4 \strokec4 \
\}\
\
\cf5 \strokec5 return\cf4 \strokec4  0;\
\}\
\
\cf5 \strokec5 void\cf4 \strokec4  game()  \cf3 \strokec3 //function for playing game\cf4 \strokec4 \
\{\
    \cf5 \strokec5 int\cf4 \strokec4  x,y;\
    \cf5 \strokec5 char\cf4 \strokec4  s;\
    \cf5 \strokec5 for\cf4 \strokec4 (y=0;y<21;y++)  \cf3 \strokec3 //setting screen\cf4 \strokec4 \
    \{\
        \cf5 \strokec5 for\cf4 \strokec4 (x=0;x<30;x++)\
        \{\
            \cf5 \strokec5 if\cf4 \strokec4 (y<20)\
            \{\
            c[x][y]=\cf6 \strokec6 ' '\cf4 \strokec4 ;\
            n[x][y]=0;\
            \}\
            \cf5 \strokec5 if\cf4 \strokec4 (y==20)\
            \{\
                c[x][y]=\cf6 \strokec6 '-'\cf4 \strokec4 ;\
                n[x][y]=2;\
            \}\
        \}\
    \}\
    c[10][10]=\cf6 \strokec6 '*'\cf4 \strokec4 ;  \cf3 \strokec3 //in these coordinates will be our bird, marked *\cf4 \strokec4 \
    screen();      \cf3 \strokec3 //calls func for showin screen\cf4 \strokec4 \
    \cf5 \strokec5 while\cf4 \strokec4 (1)       \cf3 \strokec3 //loop starts, actual gameplay begins\cf4 \strokec4 \
    \{\
        s=\cf6 \strokec6 '~'\cf4 \strokec4 ;  \cf3 \strokec3 //default control variable\cf4 \strokec4 \
        Sleep(0.2*1000);  \cf3 \strokec3 //this sets how fast everyhing moves\cf4 \strokec4 \
        t++;              \cf3 \strokec3 //this is a variable for storing 'time',or how many times a loop passed\cf4 \strokec4 \
        \cf5 \strokec5 if\cf4 \strokec4 (kbhit()) \cf3 \strokec3 //if key is pressed, certain operations are done for bird to move up.\cf4 \strokec4 \
        \{\
            s=getch();        \cf3 \strokec3 //gets what key is pressed\cf4 \strokec4 \
            \cf5 \strokec5 if\cf4 \strokec4 (s!=\cf6 \strokec6 '~'\cf4 \strokec4 ) tuk=1; \cf3 \strokec3 //if it is not default, then 'tuk' will be equal to 1, meaning that bird will fly up\cf4 \strokec4 \
        \}\
        \cf5 \strokec5 for\cf4 \strokec4 (x=0;x<30;x++) \cf3 \strokec3 //just setting ground\cf4 \strokec4 \
        \{\
            c[x][20]=\cf6 \strokec6 '-'\cf4 \strokec4 ;\
            n[x][20]=2;\
        \}\
        bird();                       \cf3 \strokec3 //cals bird move function\cf4 \strokec4 \
        checkscore();                 \cf3 \strokec3 //checks score\cf4 \strokec4 \
        \cf5 \strokec5 if\cf4 \strokec4 (gameover()==\cf5 \strokec5 true\cf4 \strokec4 ) \cf5 \strokec5 goto\cf4 \strokec4  gameEnd;   \cf3 \strokec3 //checks if bird hits pipes, if yes, game ends\cf4 \strokec4 \
        pipes();                             \cf3 \strokec3 //spawns and moves pipes\cf4 \strokec4 \
        \cf5 \strokec5 if\cf4 \strokec4 (score>highscore) highscore=score;  \cf3 \strokec3 //i think this is clear\cf4 \strokec4 \
        screen();                            \cf3 \strokec3 //finally, calls screen function to show enerything.\cf4 \strokec4 \
\
        \cf5 \strokec5 if\cf4 \strokec4 (tuk>0) tuk++;           \cf3 \strokec3 //if key is pressed, bird will fly up 2 times.\cf4 \strokec4 \
        \cf5 \strokec5 if\cf4 \strokec4 (tuk==3) tuk=0;          \cf3 \strokec3 //after that, bird falls\cf4 \strokec4 \
    \}\
    gameEnd:   \cf3 \strokec3 //ends game\cf4 \strokec4 \
    \{\
        \cf5 \strokec5 if\cf4 \strokec4 (score>highscore) highscore=score;\
        \cf5 \strokec5 if\cf4 \strokec4 (err==\cf5 \strokec5 false\cf4 \strokec4 )              \cf3 \strokec3 //if hi-score file exists, it writes your new highscore there.\cf4 \strokec4 \
        \{\
            outp.open(\cf6 \strokec6 "/Program Files/FlappyBird/options.txt"\cf4 \strokec4 );\
            outp<<highscore;\
            outp.close();\
        \}\
        screen();    \cf3 \strokec3 //shows ending screen, and returns to int main\cf4 \strokec4 \
        endgame();\
        \cf5 \strokec5 return\cf4 \strokec4 ;\
    \}\
\}\
\
\cf5 \strokec5 void\cf4 \strokec4  screen()    \cf3 \strokec3 //func for showing screen\cf4 \strokec4 \
\{\
    \cf5 \strokec5 int\cf4 \strokec4  x,y;\
    system(\cf6 \strokec6 "cls"\cf4 \strokec4 );    \cf3 \strokec3 //clears console\cf4 \strokec4 \
    \cf5 \strokec5 for\cf4 \strokec4 (y=0;y<21;y++) \cf3 \strokec3 //shows pixels on their coordinates, and your score\cf4 \strokec4 \
    \{\
        \cf5 \strokec5 for\cf4 \strokec4 (x=0;x<30;x++)\
        \{\
            \cf5 \strokec5 if\cf4 \strokec4 (x<29) cout<<c[x][y];\
            \cf5 \strokec5 if\cf4 \strokec4 (x==29) cout<<c[x][y]<<endl;\
        \}\
    \}\
    cout<<\cf6 \strokec6 ""\cf4 \strokec4 <<endl;\
    cout<<\cf6 \strokec6 "Your Score: "\cf4 \strokec4 <<score;\
\}\
\
\cf5 \strokec5 void\cf4 \strokec4  pipes()  \cf3 \strokec3 //pipe movement and spawn func\cf4 \strokec4 \
\{\
    \cf5 \strokec5 int\cf4 \strokec4  x,y,r;\
    \cf5 \strokec5 if\cf4 \strokec4 (t==10)   \cf3 \strokec3 //if time is 10, or loop has passed 10 times, it spawns a new pipe\cf4 \strokec4 \
    \{\
        r=(rand()%11)+5;  \cf3 \strokec3 //generates random number, which will be the pipe's hole center\cf4 \strokec4 \
        \cf5 \strokec5 for\cf4 \strokec4 (y=0;y<20;y++)  \cf3 \strokec3 // only y coordinate is needed\cf4 \strokec4 \
        \{\
            c[29][y]=\cf6 \strokec6 '|'\cf4 \strokec4 ;  \cf3 \strokec3 //sets pipe\cf4 \strokec4 \
            n[29][y]=2;    \cf3 \strokec3 //n will be 2, for checking if bird has hit it,\cf4 \strokec4 \
        \}\
        c[29][r-1]=\cf6 \strokec6 ' '\cf4 \strokec4 ;  \cf3 \strokec3 //sets hole\cf4 \strokec4 \
        c[29][r]=\cf6 \strokec6 ' '\cf4 \strokec4 ;\
        c[29][r+1]=\cf6 \strokec6 ' '\cf4 \strokec4 ;\
        n[29][r-1]=0;\
        n[29][r]=0;\
        n[29][r+1]=0;\
        t=0;\
        \cf5 \strokec5 goto\cf4 \strokec4  mv; \cf3 \strokec3 //moves pipes\cf4 \strokec4 \
    \}\
    \cf5 \strokec5 else\cf4 \strokec4  \cf5 \strokec5 goto\cf4 \strokec4  mv;\
    mv:                 \cf3 \strokec3 //pipe movement\cf4 \strokec4 \
    \{\
        \cf5 \strokec5 for\cf4 \strokec4 (y=0;y<20;y++)  \cf3 \strokec3 //loops for generating coordinates\cf4 \strokec4 \
        \{\
            \cf5 \strokec5 for\cf4 \strokec4 (x=0;x<30;x++)\
            \{\
                \cf5 \strokec5 if\cf4 \strokec4 (c[x][y]==\cf6 \strokec6 '|'\cf4 \strokec4 )  \cf3 \strokec3 //all the pipes will be moved left by 1;\cf4 \strokec4 \
                \{\
                    \cf5 \strokec5 if\cf4 \strokec4 (x>0)\
                    \{\
                        c[x-1][y]=\cf6 \strokec6 '|'\cf4 \strokec4 ;\
                        n[x-1][y]=2;\
                        c[x][y]=\cf6 \strokec6 ' '\cf4 \strokec4 ;\
                        n[x][y]=0;\
                    \} \
                    \cf5 \strokec5 if\cf4 \strokec4 (x==0)  \cf3 \strokec3 //if screen ends (x=0) pipe will dissapear, to prevent errors\cf4 \strokec4 \
                    \{\
                        c[x][y]=\cf6 \strokec6 ' '\cf4 \strokec4 ;\
                        n[x][y]=0;\
                    \}\
                \}\
            \}\
        \}\
    \}\
\}\
\
\cf5 \strokec5 void\cf4 \strokec4  bird()   \cf3 \strokec3 //bird movement function!\cf4 \strokec4 \
\{\
    \cf5 \strokec5 int\cf4 \strokec4  x,y;\
    \cf5 \strokec5 if\cf4 \strokec4 (tuk>0) \cf3 \strokec3 //if key is pressed, bird moves up\cf4 \strokec4 \
    \{\
        bt=0;\
        \cf5 \strokec5 for\cf4 \strokec4 (y=0;y<20;y++)   \cf3 \strokec3 //loops for finding bird coordinates\cf4 \strokec4 \
        \{\
            \cf5 \strokec5 for\cf4 \strokec4 (x=0;x<30;x++)\
            \{\
                \cf5 \strokec5 if\cf4 \strokec4 (c[x][y]==\cf6 \strokec6 '*'\cf4 \strokec4 )\
                \{\
                    \cf5 \strokec5 if\cf4 \strokec4 (y>0)\
                    \{\
                    c[x][y-1]=\cf6 \strokec6 '*'\cf4 \strokec4 ;  \cf3 \strokec3 //bird moves up by 1;\cf4 \strokec4 \
                    c[x][y]=\cf6 \strokec6 ' '\cf4 \strokec4 ;\
                    birdx=x;        \cf3 \strokec3 //sets bird x coordinate\cf4 \strokec4 \
                    birdy=y-1;      \cf3 \strokec3 //sets bird y coord\cf4 \strokec4 \
                    \cf5 \strokec5 return\cf4 \strokec4 ;         \cf3 \strokec3 //retuns to game func\cf4 \strokec4 \
                    \}\
                \}\
            \}\
        \}\
    \}\
    \cf5 \strokec5 else\cf4 \strokec4    \cf3 \strokec3 //if no key is pressed, bird falls\cf4 \strokec4 \
    \{\
        bt++;\
        \cf5 \strokec5 for\cf4 \strokec4 (y=0;y<20;y++)\
        \{\
            \cf5 \strokec5 for\cf4 \strokec4 (x=0;x<30;x++)\
            \{\
                \cf5 \strokec5 if\cf4 \strokec4 (c[x][y]==\cf6 \strokec6 '*'\cf4 \strokec4 )\
                \{\
                    \cf5 \strokec5 if\cf4 \strokec4 (y<20)  \cf3 \strokec3 //if bird is not on the ground\cf4 \strokec4 \
                    \{\
                        \cf5 \strokec5 if\cf4 \strokec4 (bt<3)   \cf3 \strokec3 //if bird time is lower that 3, it falls 1 pixel\cf4 \strokec4 \
                        \{\
                            c[x][y+1]=\cf6 \strokec6 '*'\cf4 \strokec4 ;\
                            c[x][y]=\cf6 \strokec6 ' '\cf4 \strokec4 ;\
                            birdx=x;\
                            birdy=y+1;\
                            \cf5 \strokec5 return\cf4 \strokec4 ;\
                        \}\
                        \cf5 \strokec5 else\cf4 \strokec4  \cf5 \strokec5 if\cf4 \strokec4 (bt>2 && bt<5)  \cf3 \strokec3 //more time has passed, faster bird falls (acceleration)\cf4 \strokec4 \
                        \{\
                            c[x][y+2]=\cf6 \strokec6 '*'\cf4 \strokec4 ;\
                            c[x][y]=\cf6 \strokec6 ' '\cf4 \strokec4 ;\
                            birdx=x;\
                            birdy=y+2;\
                            \cf5 \strokec5 return\cf4 \strokec4 ;\
                        \}\
                        \cf5 \strokec5 else\cf4 \strokec4  \cf5 \strokec5 if\cf4 \strokec4 (bt>4)\
                        \{\
                            c[x][y+3]=\cf6 \strokec6 '*'\cf4 \strokec4 ;\
                            c[x][y]=\cf6 \strokec6 ' '\cf4 \strokec4 ;\
                            birdx=x;\
                            birdy=y+3;\
                            \cf5 \strokec5 return\cf4 \strokec4 ;\
                        \}\
                    \}\
                    \cf5 \strokec5 else\cf4 \strokec4 \
                    \{\
                        \cf5 \strokec5 return\cf4 \strokec4 ;  \cf3 \strokec3 //if bird is already on the ground, function returns to check for game over.\cf4 \strokec4 \
                    \}\
                \}\
            \}\
        \}\
    \}\
\}\
\
\
\pard\pardeftab720\sl280\partightenfactor0
\cf5 \strokec5 void\cf4 \strokec4  checkscore()  \cf3 \strokec3 //checks if bird gained score\cf4 \strokec4 \
\{\
    \cf5 \strokec5 int\cf4 \strokec4  y;\
    \cf5 \strokec5 for\cf4 \strokec4 (y=0;y<20;y++)\
    \{\
        \cf5 \strokec5 if\cf4 \strokec4 (c[birdx][y]==\cf6 \strokec6 '|'\cf4 \strokec4 )  \cf3 \strokec3 //if bird x coord is equal to pipe's coord, you get 1 point\cf4 \strokec4 \
        \{\
            score++;\
            \cf5 \strokec5 return\cf4 \strokec4 ;\
        \}\
    \}\
\}\
\
\cf5 \strokec5 bool\cf4 \strokec4  gameover()  \cf3 \strokec3 //checks if bird has hit something\cf4 \strokec4 \
\{\
    \cf5 \strokec5 int\cf4 \strokec4  x,y,f=0;\
    \cf5 \strokec5 if\cf4 \strokec4 (birdy>19) \cf3 \strokec3 //checks if bird hits ground\cf4 \strokec4 \
    \{\
        c[birdx][19]=\cf6 \strokec6 '*'\cf4 \strokec4 ;  \cf3 \strokec3 //sets bird and ground again, prevents errors\cf4 \strokec4 \
        c[birdx][20]=\cf6 \strokec6 '-'\cf4 \strokec4 ;\
        f=1;           \cf3 \strokec3 //f=1, means function will return true\cf4 \strokec4 \
        \cf5 \strokec5 goto\cf4 \strokec4  quit;\
    \}\
    \cf5 \strokec5 else\cf4 \strokec4 \
    \{     \cf3 \strokec3 //checks if bird has hit pipes, here the 'n' variable is needed (pipe's coordinate's n is equal 2 (more than 0))\cf4 \strokec4 \
        \cf5 \strokec5 if\cf4 \strokec4 (n[birdx][birdy]>0 && (c[birdx][birdy]==\cf6 \strokec6 '|'\cf4 \strokec4  || c[birdx][birdy]==\cf6 \strokec6 '*'\cf4 \strokec4 ))\
        \{\
            c[birdx][birdy]=\cf6 \strokec6 '|'\cf4 \strokec4 ;\
            c[birdx-1][19]=\cf6 \strokec6 '*'\cf4 \strokec4 ;\
            f=1;\
            \cf5 \strokec5 goto\cf4 \strokec4  quit;\
        \}\
    \}\
    quit:\
    \cf5 \strokec5 if\cf4 \strokec4 (f==1) \cf5 \strokec5 return\cf4 \strokec4  \cf5 \strokec5 true\cf4 \strokec4 ;\
    \cf5 \strokec5 else\cf4 \strokec4  \cf5 \strokec5 return\cf4 \strokec4  \cf5 \strokec5 false\cf4 \strokec4 ;\
\}\
\
\cf5 \strokec5 void\cf4 \strokec4  endgame() \cf3 \strokec3 //just some screens for certain actions\cf4 \strokec4 \
\{\
    screen();   \cf3 \strokec3 //this one pops up if game ends\cf4 \strokec4 \
    cout<<\cf6 \strokec6 ""\cf4 \strokec4 <<endl<<endl;\
    cout<<\cf6 \strokec6 " ------------------------------------------------------------------------- "\cf4 \strokec4 <<endl;\
    cout<<\cf6 \strokec6 "|    *****      *     *       * ******       ****  *       ****** ****    |"\cf4 \strokec4 <<endl;\
    cout<<\cf6 \strokec6 "|   *          * *    * *   * * *           *    *  *     * *     *   *   |"\cf4 \strokec4 <<endl;\
    cout<<\cf6 \strokec6 "|   *  ****   *   *   *  * *  * *****       *    *   *   *  ****  ****    |"\cf4 \strokec4 <<endl;\
    cout<<\cf6 \strokec6 "|   *  *  *  *******  *   *   * *           *    *    * *   *     * *     |"\cf4 \strokec4 <<endl;\
    cout<<\cf6 \strokec6 "|    *****  *       * *       * ******       ****      *    ***** *   *   |"\cf4 \strokec4 <<endl;\
    cout<<\cf6 \strokec6 " ------------------------------------------------------------------------- "\cf4 \strokec4 <<endl;\
    cout<<\cf6 \strokec6 ""\cf4 \strokec4 <<endl<<endl;\
    cout<<\cf6 \strokec6 "                        Y O U R   S C O R E : "\cf4 \strokec4 <<score<<endl<<endl;\
    cout<<\cf6 \strokec6 "                        H I G H   S C O R E : "\cf4 \strokec4 <<highscore<<endl;\
    cout<<\cf6 \strokec6 ""\cf4 \strokec4 <<endl<<endl;\
\}\
\
\cf5 \strokec5 void\cf4 \strokec4  menu()  \cf3 \strokec3 //shows menu\cf4 \strokec4 \
\{\
    system(\cf6 \strokec6 "cls"\cf4 \strokec4 );\
    cout<<\cf6 \strokec6 ""\cf4 \strokec4 <<endl;\
    cout<<\cf6 \strokec6 " --------------------------------------------------------  "\cf4 \strokec4 <<endl;\
    cout<<\cf6 \strokec6 "|                                                        | "\cf4 \strokec4 <<endl;\
    cout<<\cf6 \strokec6 "|   **** *    **** **** **** *   *    ***  * ***  ***    | "\cf4 \strokec4 <<endl;\
    cout<<\cf6 \strokec6 "|   *    *    *  * *  * *  * *   *    *  * * *  * *  *   | "\cf4 \strokec4 <<endl;\
    cout<<\cf6 \strokec6 "|   ***  *    **** **** **** *****    ***  * ***  *  *   | "\cf4 \strokec4 <<endl;\
    cout<<\cf6 \strokec6 "|   *    *    *  * *    *      *      *  * * *  * *  *   | "\cf4 \strokec4 <<endl;\
    cout<<\cf6 \strokec6 "|   *    **** *  * *    *      *      ***  * *  * ***    | "\cf4 \strokec4 <<endl;\
    cout<<\cf6 \strokec6 "|                                                  v 1.0 | "\cf4 \strokec4 <<endl;\
    cout<<\cf6 \strokec6 " --------------------------------------------------------  "\cf4 \strokec4 <<endl;\
    cout<<\cf6 \strokec6 ""\cf4 \strokec4 <<endl<<endl;\
    cout<<\cf6 \strokec6 "                  High Score:  "\cf4 \strokec4 <<highscore<<endl<<endl;\
    cout<<\cf6 \strokec6 ""\cf4 \strokec4 <<endl<<endl;\
    cout<<\cf6 \strokec6 "                     M E N U:    "\cf4 \strokec4 <<endl<<endl;\
    cout<<\cf6 \strokec6 "                  1: Start Game  "\cf4 \strokec4 <<endl<<endl;\
    cout<<\cf6 \strokec6 "                  2: Help        "\cf4 \strokec4 <<endl<<endl;\
    cout<<\cf6 \strokec6 "                  3: Credits     "\cf4 \strokec4 <<endl<<endl;\
    cout<<\cf6 \strokec6 "                  4: Exit        "\cf4 \strokec4 <<endl<<endl;\
\}\
\
\cf5 \strokec5 void\cf4 \strokec4  credits()\
\{\
    \cf5 \strokec5 char\cf4 \strokec4  sel;\
    system(\cf6 \strokec6 "cls"\cf4 \strokec4 );\
    \cf5 \strokec5 while\cf4 \strokec4 (\cf5 \strokec5 true\cf4 \strokec4 )\
    \{\
    cout<<\cf6 \strokec6 ""\cf4 \strokec4 <<endl<<endl;\
    cout<<\cf6 \strokec6 "               Lead programmer: hakeris1010 "\cf4 \strokec4 <<endl<<endl;\
    cout<<\cf6 \strokec6 "               Designer: hakeris1010 "\cf4 \strokec4 <<endl<<endl;\
    cout<<\cf6 \strokec6 "               Testers: hakeris1010 "\cf4 \strokec4 <<endl<<endl;\
    cout<<\cf6 \strokec6 "               Special thanks to: hakeris1010 ,Dong Nguyen (original)"\cf4 \strokec4 <<endl<<endl;\
    cout<<\cf6 \strokec6 "               Version: 1.0 "\cf4 \strokec4 <<endl<<endl<<endl;\
    cout<<\cf6 \strokec6 "Go back? [y/n]  "\cf4 \strokec4 ;\
    cin>>sel;\
    \cf5 \strokec5 if\cf4 \strokec4 (sel==\cf6 \strokec6 'y'\cf4 \strokec4 ) \cf5 \strokec5 return\cf4 \strokec4 ;\
    \cf5 \strokec5 else\cf4 \strokec4  system(\cf6 \strokec6 "cls"\cf4 \strokec4 );\
    \}\
\}\
\
\cf5 \strokec5 void\cf4 \strokec4  help()\
\{\
    \cf5 \strokec5 char\cf4 \strokec4  sel;\
    system(\cf6 \strokec6 "cls"\cf4 \strokec4 );\
    \cf5 \strokec5 while\cf4 \strokec4 (\cf5 \strokec5 true\cf4 \strokec4 )\
    \{\
    cout<<\cf6 \strokec6 ""\cf4 \strokec4 <<endl<<endl;\
    cout<<\cf6 \strokec6 "                   Controls: Press any key to fly up.         "\cf4 \strokec4 <<endl<<endl;\
    cout<<\cf6 \strokec6 "             Goal: Fly through the holes between the pipes.   "\cf4 \strokec4 <<endl;\
    cout<<\cf6 \strokec6 "             When you pass through the hole,you get 1 point.  "\cf4 \strokec4 <<endl;\
    cout<<\cf6 \strokec6 "                    Try to pass as much as you can.           "\cf4 \strokec4 <<endl;\
    cout<<\cf6 \strokec6 "            But be careful, don't hit the pipes or the ground!"\cf4 \strokec4 <<endl<<endl;\
    cout<<\cf6 \strokec6 "                          Are you ready? Go!                  "\cf4 \strokec4 <<endl<<endl<<endl;\
    cout<<\cf6 \strokec6 "Go back? [y/n]  "\cf4 \strokec4 ;\
    cin>>sel;\
    \cf5 \strokec5 if\cf4 \strokec4 (sel==\cf6 \strokec6 'y'\cf4 \strokec4 ) \cf5 \strokec5 return\cf4 \strokec4 ;\
    \cf5 \strokec5 else\cf4 \strokec4  system(\cf6 \strokec6 "cls"\cf4 \strokec4 );\
    \}\
\}\
\
\pard\pardeftab720\sl280\partightenfactor0
\cf4 \
}