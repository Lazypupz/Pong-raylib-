#include <iostream>
#include "raylib.h"
#include "raymath.h"
#include "player.hpp"
#include "ball.hpp"
using namespace std;

Rect::Rect(){
    posy = 100;
    posx = 50;
}

void Rect::Move(){
    if(IsKeyDown(KEY_W)){
        posy-=15;
    }
    if(IsKeyDown(KEY_S)){
        posy+=15;
    }
}


Ball::Ball(){
    ballHeight = 20;
    ballWidth = 20;
}

//void Ball::initBall(){
    
//}

int main(){
    Rect rect;
    
    InitWindow(GetMonitorWidth(GetCurrentMonitor()) - 10, GetMonitorHeight(GetCurrentMonitor()) - 10, "Raylib Test");
    
    SetTargetFPS(60);

    while(!WindowShouldClose()){

        rect.Move(); 
        DrawText("Pong", 10,10,20,WHITE);
        cout << "The Rectangle position is: " << rect.posx << rect.posy << endl;

        BeginDrawing();
            ClearBackground(BLACK);
            DrawRectangle(rect.posx, rect.posy, 60, 120, RED);
            
        EndDrawing();

    }
    CloseWindow();
}