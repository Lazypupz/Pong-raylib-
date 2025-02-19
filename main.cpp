#include "common.hpp"
#include "player.hpp"
#include "ball.hpp"

using namespace std;

const int screenWidth = 1200;
const int screenHeight = 800;

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
    ballx = screenWidth / 2;
    bally = screenHeight / 2;
    radius = 20;
    speedx = 7;
    speedy = 7;
}


void Ball::initBall(){
    ballx += speedx;
    bally += speedy;

    if(bally + radius >= GetScreenHeight() || bally - radius <= 0){
        speedy *= -1;
    }
    if(ballx + radius >= GetScreenWidth() || ballx - radius <=0){
        speedx *= -1;
    }
}
void Ball::Draw(){
    DrawCircle(ballx,bally,radius,PINK);
}

int main(){
    Rect rect;
    Ball ball;
    
    

    InitWindow(screenWidth,screenHeight, "Raylib Test");

    SetTargetFPS(60);

    while(!WindowShouldClose()){

        rect.Move(); 
        DrawText(dynamic_cast<string>(rect.posx), 10,10,20,WHITE);
        cout << "The Rectangle position is: " << rect.posx << rect.posy << endl;

        BeginDrawing();
            ball.initBall();
            if(ball.ballx - ball.radius <= rect.posx){
                ball.speedx *=-1;
            }
            ClearBackground(BLACK);
            ball.Draw();
            DrawLine(screenWidth / 2, screenHeight, screenWidth / 2 + 1, screenHeight - screenHeight + 1, WHITE);
            DrawRectangle(rect.posx, rect.posy, 60, 120, RED);
           
        EndDrawing();

    }
    CloseWindow();
}