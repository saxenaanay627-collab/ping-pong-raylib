#include<raylib.h>
#include<stdio.h>
int main(){
    InitWindow(800+200,800+200,"Tic Tac Toe");
    SetTargetFPS(60);
    while(!WindowShouldClose()){
        
        //draw grid
        BeginDrawing();
        ClearBackground(BLACK);
        DrawLine(333,100,333,900,WHITE);
        DrawLine(666,100,666,900,WHITE);
        DrawLine(100,333,900,333,WHITE);
        DrawLine(100,666,900,666,WHITE);
        DrawText("Tic Tac Toe", 450, 10, 20, WHITE);
        DrawText("Player 1: X", 100, 10, 20, WHITE);
        DrawText("Player 2: O", 800, 10, 20, WHITE);
        EndDrawing();
    }
}