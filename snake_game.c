// create a blank canvas & game loop 
// creating the food 
// creating the snake 
// moving the snake
// making the snake eat the food
// making the snake grow 
// checking for collisions with the walls and itself
// adding title and frame
// keeping score
// adding sound effects
#include<raylib.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#define maxSnakeLength 625
typedef struct{
    int x;
    int y;
}cell;
int border=75;
int main(){
    InitWindow(800+border, 800+border, "Snake Game");
    SetTargetFPS(10);
    int gridSize = 32;
    int gridcount=25;
    cell food;
    food.x = GetRandomValue(0, gridcount - 1);
    food.y = GetRandomValue(0, gridcount - 1);
    cell snake[maxSnakeLength];
    int snakeLength = 2;
    snake[0]=(cell){12,12}; //snake head
    snake[1]=(cell){11,12}; //snake body
    //directions
    cell dirx = (cell){1,0}; //right
    cell diry = (cell){0,1}; //down
    cell dirleft = (cell){-1,0}; //left
    cell dirup = (cell){0,-1}; //up
    while(!WindowShouldClose()){
        if(IsKeyPressed(KEY_RIGHT)){
            dirx=(cell){1,0};
        }
        else if(IsKeyPressed(KEY_LEFT)){
            dirx=(cell){-1,0};
        }
        else if(IsKeyPressed(KEY_UP)){
            dirx=(cell){0,-1};
        }
        else if(IsKeyPressed(KEY_DOWN)){
            dirx=(cell){0,1};
        }
        //move snake
        for(int i=snakeLength-1;i>0;i--){
            snake[i]=snake[i-1];
        }
        snake[0].x += dirx.x;
        snake[0].y += dirx.y;
        //check for food collision
        if(snake[0].x == food.x && snake[0].y == food.y){
            snakeLength++;
            food.x = GetRandomValue(0, gridcount - 1);
            food.y = GetRandomValue(0, gridcount - 1);
            snake[snakeLength-1] = snake[snakeLength-2]; //add new segment to the snake
        }
        //wall collision
        if(snake[0].x < border || snake[0].x > 800-border || snake[0].y < border || snake[0].y > 800-border){
            BeginDrawing();
            DrawText("Game Over!", 350, 400, 20, RED);
            EndDrawing();
        }
        //self collision
        for(int i=1;i<snakeLength;i++){
            if(snake[0].x == snake[i].x && snake[0].y == snake[i].y){
                BeginDrawing();
                DrawText("Game Over!", 350, 400, 20, RED);
                EndDrawing();
                break;
            }
        }
        BeginDrawing();
        ClearBackground(BLACK);
        DrawRectangle(food.x * gridSize, food.y * gridSize, gridSize, gridSize, RED);
        for(int i=0;i<snakeLength;i++){
            DrawRectangle(snake[i].x * gridSize, snake[i].y * gridSize, gridSize, gridSize, GREEN);
        }
        DrawLine(0, border, 800+border, border, WHITE);
        DrawLine(border, 0, border, 800+border, WHITE);
        DrawLine(800-border, 0, 800-border, 800+border, WHITE);
        DrawLine(0, 800-border, 800+border, 800-border, WHITE);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}