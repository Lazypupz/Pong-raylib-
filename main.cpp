#include "common.hpp"
#include "player.hpp"
#include "ball.hpp"


const int screenWidth = 1200;
const int screenHeight = 800;

Rect::Rect(){
    posy = 100;
    posx = 50;
    AIx = 1200 - 50;
    AIy = 100;
}

void Rect::Move(){
    if(IsKeyDown(KEY_W)){
        posy-=15;
    }
    if(IsKeyDown(KEY_S)){
        posy+=15;
    }
    if(IsKeyDown(KEY_K)){
        AIy += 15;
    }
    if(IsKeyDown(KEY_I)){
        AIy -= 15;
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

    if(bally + radius >= screenHeight || bally - radius <= 0){
        speedy *= -1;
        
    }
    if(ballx + radius >= screenWidth || ballx - radius <=0){
        speedx *= -1;
    }
}
void Ball::Draw(){
    DrawCircle(ballx,bally,radius,PINK);
}


int main(){

    InitWindow(screenWidth,screenHeight, "Raylib Test");
    SetTargetFPS(60);
    Rect rect;
    Ball ball;

    while(!WindowShouldClose()){


        //Updating

        if(CheckCollisionCircleRec(Vector2{static_cast<float>(ball.ballx), static_cast<float>(ball.bally)}, 20, Rectangle{static_cast<float>(rect.posx),static_cast<float>(rect.posy),60,120})){
            ball.speedx *= -1;
        }
        if(CheckCollisionCircleRec(Vector2{static_cast<float>(ball.ballx), static_cast<float>(ball.bally)}, 20, Rectangle{static_cast<float>(rect.AIx),static_cast<float>(rect.AIy),60,120})){
            ball.speedx *= -1;
        }

        //Drawing        
        BeginDrawing();
            ball.initBall();
            rect.Move();

            ClearBackground(BLACK);
            ball.Draw();
            DrawRectangle(static_cast<float>(rect.AIx),static_cast<float>(rect.AIy), 60, 120, RED);
            
            DrawRectangle(rect.posx, rect.posy, 60, 120, RED);
            DrawLine(screenWidth / 2, screenHeight, screenWidth / 2 + 1, screenHeight - screenHeight + 1, WHITE);
        EndDrawing();

    }
    CloseWindow();
}