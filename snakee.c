#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h> //for the delay

#define WIDTH 30
#define HEIGHT 15
#define MAX_SNAKE 100

int snakeX[MAX_SNAKE];
int snakeY[MAX_SNAKE];

int snakeLength;
int foodX;
int foodY;
int score;
int gameOver;

enum Direction{
    UP,
    DOWN,
    LEFT,
    RIGHT
};
enum Direction direction;

void clearScreen(){
    // system("cls") ki jagah cursor ko 0,0 pe le jao
    COORD cursorPosition;
    cursorPosition.X = 0;
    cursorPosition.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

void hideCursor(){
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}
void spawnFood(){
    int valid;
    do{
        valid = 1;
        foodX = rand() % WIDTH;
        foodY = rand() % HEIGHT;

        for(int i = 0; i<snakeLength; i++){
            if(snakeX[i] == foodX && snakeY[i] == foodY ){
                valid = 0;
                break;
            }
        }
    }while(!valid);
}

void intializeGame(){
    snakeLength = 3;
    snakeX[0] = WIDTH /2;
    snakeY[0] = HEIGHT /2;

    snakeX[1] = snakeX[0]-1;
    snakeY[1] = snakeY[0];
    snakeX[2] = snakeX[0]-2;
    snakeY[2] = snakeY[0];

    direction = RIGHT;

    score = 0;
    gameOver = 0;
    spawnFood();
}
void draw(){
    clearScreen();
    printf("Score: %d\n\n",score);

    for(int y = -1; y <= HEIGHT; y++){
        for(int x = -1; x <= WIDTH; x++){
            if(x == -1 || x == WIDTH || y == -1 || y == HEIGHT){
                printf("##");
                continue;
            }
            if(x == foodX && y == foodY){
                printf("[]");
                continue;
            }
            int printed = 0;

            for(int i = 0; i < snakeLength; i++){
                if(snakeX[i] == x && snakeY[i] == y){
                    if(i == 0)
                        printf("OO");
                    else
                        printf("oo");
                    printed = 1;
                    break;
                }
            }
            if(!printed){
                printf("  ");
            }
        }
        printf("\n");
    }
    printf("\n WASD = Move | Q = Quit\n");
}

void handleInput(){
    if(!_kbhit()){
        return;
    }
    
    char input = _getch();
    if(input == 'q' || input == 'Q'){
        gameOver = 1;
    }
    if((input == 'w' || input == 'W') && direction != DOWN){
        direction = UP;
    }
    if((input == 'a' || input == 'A') && direction != RIGHT){
        direction = LEFT;
    }
    if((input == 's' || input == 'S') && direction != UP){
        direction = DOWN;
    }
    if((input == 'd' || input == 'D') && direction != LEFT){
        direction = RIGHT;
    }
}

void moveSnake(){
    for(int i = snakeLength - 1; i > 0; i --){
        snakeX[i] = snakeX[i-1];
        snakeY[i] = snakeY[i-1];
    }
    if(direction == UP){
        snakeY[0]--;
    }
    else if(direction == DOWN){
        snakeY[0]++;
    }
    else if(direction == LEFT){
        snakeX[0]--;
    }
    else if(direction == RIGHT){
        snakeX[0]++;
    }
    //wrap around Horizantlly
    if(snakeX[0] < 0){
        snakeX[0] = WIDTH-1;
    }
    else if(snakeX[0]>= WIDTH){
        snakeX[0] = 0;
    }
     //wrap around Vertically
    if(snakeY[0] < 0){
        snakeY[0] = HEIGHT-1;
    }
    else if(snakeY[0]>= HEIGHT){
        snakeY[0] = 0;
    }

}

void checkCollision(){
    for (int i = 1; i < snakeLength; i++){
        if (snakeX[0] == snakeX[i] && snakeY[0]  == snakeY[i]){
            gameOver = 1;
            return;
        }
    }
}

void checkFood(){
    if(snakeX[0] == foodX && snakeY[0] == foodY){
        if(snakeLength < MAX_SNAKE){
            snakeLength++;
        }
        score += 10;
        spawnFood();
    }
}


int main(){
    hideCursor();
    srand(time(NULL));
    intializeGame();

    while(!gameOver){

        draw();
        handleInput();
        moveSnake();
        checkCollision();
        if(!gameOver){
            checkFood();

        }
        Sleep(120);
    }
    clearScreen();
    system("cls");
    printf("=================================\n");
    printf("           Game Over\n");
    printf("=================================\n");
    printf("Final Score: %d\n",score);
    printf("Thanks for Playing!\n");

    return 0;
}
