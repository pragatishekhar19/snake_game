#include <iostream>
#include<cstdlib>//for rand
#include<conio.h>
#include<windows.h> //For the delay function

using namespace std;

bool  gameOver;
const int width=40;
const int length=20;
int x,y,fruitX,fruitY,score;
int tailX[100],tailY[100],ntail;
enum eDirection {STOP=0, LEFT , RIGHT , UP , DOWN};
eDirection d;

void generateFruit(){
    bool validFruit = false;
    while (!validFruit) {
        fruitX = rand() % (width-2) +1 ;
        fruitY = rand() % (length-2) +1 ;
        validFruit = true;

        // Check if the new fruit position overlaps with the snake's tail
        for (int i = 0; i < ntail; i++) {
            if (tailX[i] == fruitX && tailY[i] == fruitY) {
                validFruit = false;
                break;
            }
        }
    }
}
void setup(){
    gameOver=false;
    ntail=0;
    d=STOP;
    x=width/2;
    y=length/2;
    generateFruit();
    score=0;
}
void draw(){

    system("cls");

    // Top border
    for (int i = 0; i < width + 2; i++) {
        cout << "#";
    }
    cout << endl;

    // Side borders and inner spaces
    for (int i = 1; i <length; i++) {
        cout << "#";
        for (int j = 0; j < width; j++){

            if(i == y && j==x) cout<<"O";// Snake head
            else if(i == fruitY&&j==fruitX) cout<<"X"; //fruit
            else {
                bool printTail=false;
                for(int k=0;k<ntail;k++){
                    if(tailX[k]==j && tailY[k]==i){
                        cout<<"o";//tail
                        printTail=true;
                    }
                  
                }
                if(!printTail){
                    cout<<" ";//empty space
                }
            }
            
        }
        cout << "#" << endl;
    }

    // Bottom border
    for (int i = 0; i < width + 2; i++) {
        cout << "#";
    }
    cout << endl;
    cout<<"score="<<score;
}
void input(){
    if(_kbhit()){
        switch (_getch())
        {
        case 72:
            d=UP;
            break;
        case  80:
            d=DOWN;
            break;
        case 75:
            d=LEFT;
            break;
        case 77:
            d=RIGHT;
            break;
        //case 48:
        //    gameOver=true;
        //    break;

        }
    }

}
void logic() {
    tailX[0] = x;
    tailY[0] = y;
    int prevX = tailX[0], prevY = tailY[0];
    int prev2x, prev2y;

    for (int i = 0; i < ntail; i++) {
        prev2x = tailX[i];
        prev2y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2x;
        prevY = prev2y;
    }

    switch (d) {
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

    // Collision with walls and snake
    if (x == 0 || x >= width - 1 || y == 0 || y >= length - 1 ){
        gameOver = true;
    }

    // If snake eats fruit
    if (x == fruitX && y == fruitY) {
        score++;
        ntail++; // Increase the tail length
        generateFruit();
        

    }
}

int main(){
    setup();
    while(!gameOver){
        draw();
        input();
        logic();
        Sleep(10);        
    }

    return 0;
}
