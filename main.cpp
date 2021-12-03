#include <iostream>
#include <raylib.h>
#include "defs.hpp"
#include "Chardev.hpp"
#include "Projectiles.hpp"


#pragma region


Openbirth::Characters::Character Mary{ "Mary", 6, 3, 75 }; // Mary, original character from Openbirth
Openbirth::Characters::Character Terry{ "Terry", 6, 3, 75 }; // Terry, original character from Openbirth

Openbirth::Characters::CharacterBuffer buffer{ {Mary, Terry} };



#pragma endregion Defining Characters


Openbirth::Yeetables::ProjectileBuffer projectileBuffer;

int projectilesNumber=0;
int stepsgonethru = 0;




Openbirth::Scenes::GameManager manager = Openbirth::Scenes::GameManager::MENU;


int selectedCharacter;


int main(int argc, char* argv[]) {
    const int screenWidth = 800;
    const int screenHeight = 450;
    bool stillPlaying = true;
    InitWindow(screenWidth, screenHeight, "Openbirth");
    int menuSelection = 0;
    SetTargetFPS(60);

    Vector2 playerPosition{ GetScreenWidth() / 2, GetScreenHeight() / 2 };

    while (!WindowShouldClose() && stillPlaying)
    {
        BeginDrawing();

        ClearBackground(BLACK);

        switch (manager) {
        case Openbirth::Scenes::GameManager::MENU:
            DrawText("Openbirth", 10, 10, 60, WHITE);
            if (IsKeyPressed(KEY_UP)) menuSelection--;
            if (IsKeyPressed(KEY_DOWN)) menuSelection++;
            DrawText("Play", 10, 70, 20, WHITE);
            DrawText("Exit", 10, 90, 20, WHITE);
            switch (menuSelection) {
            case 0:
                break;
            case 1:
                DrawText("Play", 10, 70, 20, RED);
                break;
            case 2:
                DrawText("Exit", 10, 90, 20, RED);
                break;
            }

            if (IsKeyPressed(KEY_ENTER)) {
                switch (menuSelection) {
                case 0:
                    break;
                case 1:
                    manager = Openbirth::Scenes::GameManager::CHARSEL;
                    menuSelection = 0;
                    break;
                case 2:
                    stillPlaying = false;
                    break;
                }
            }

            break;
        case Openbirth::Scenes::GameManager::CHARSEL:
            DrawText("Select your character:", 10, 10, 60, WHITE);
            if (IsKeyPressed(KEY_UP)) menuSelection--;
            if (IsKeyPressed(KEY_DOWN)) menuSelection++;
            DrawText("Mary", 10, 70, 20, WHITE);
            DrawText("Terry", 10, 90, 20, WHITE);

            switch (menuSelection) {
            case 0:
                break;
            case 1:
                DrawText("Mary", 10, 70, 20, RED);
                break;
            case 2:
                DrawText("Terry", 10, 90, 20, RED);
                break;
            }

            if (IsKeyPressed(KEY_ENTER)) {
                switch (menuSelection) {
                case 0:
                    break;
                case 1:
                    manager = Openbirth::Scenes::GameManager::GAME;
                    selectedCharacter = 1;
                    break;
                case 2:
                    manager = Openbirth::Scenes::GameManager::GAME;
                    selectedCharacter = 2;
                    break;
                }
            }
            break;

        case Openbirth::Scenes::GameManager::GAME:
            ClearBackground({ 158, 82, 0, 255 });
            DrawCircleV(playerPosition, 20, PINK);
            if (IsKeyDown(KEY_S)) playerPosition.y++;
            if (IsKeyDown(KEY_W)) playerPosition.y--;
            if (IsKeyDown(KEY_D)) playerPosition.x++;
            if (IsKeyDown(KEY_A)) playerPosition.x--;
            
            while (stepsgonethru < projectilesNumber) {
                if (projectileBuffer.projectiles[stepsgonethru].dir == Openbirth::Coordination::LEFT) projectileBuffer.projectiles[stepsgonethru].projectilePosition.x -= projectileBuffer.projectiles[stepsgonethru].speed;
                if (projectileBuffer.projectiles[stepsgonethru].dir == Openbirth::Coordination::RIGHT) projectileBuffer.projectiles[stepsgonethru].projectilePosition.x += projectileBuffer.projectiles[stepsgonethru].speed;
                if (projectileBuffer.projectiles[stepsgonethru].dir == Openbirth::Coordination::UP) projectileBuffer.projectiles[stepsgonethru].projectilePosition.y -= projectileBuffer.projectiles[stepsgonethru].speed;
                if (projectileBuffer.projectiles[stepsgonethru].dir == Openbirth::Coordination::DOWN) projectileBuffer.projectiles[stepsgonethru].projectilePosition.y += projectileBuffer.projectiles[stepsgonethru].speed;
                //projectileBuffer.projectiles[stepsgonethru].projectilePosition = Openbirth::Yeetables::CalculateTrajectory(projectileBuffer.projectiles[stepsgonethru]);
                DrawCircleV(projectileBuffer.projectiles[stepsgonethru].projectilePosition, 5, SKYBLUE);
                printf("supposed to render a tear\n");

                printf("supposed to have finished step\n");
                printf("%f, %f\n", projectileBuffer.projectiles[stepsgonethru].projectilePosition.x, projectileBuffer.projectiles[stepsgonethru].projectilePosition.y);
                stepsgonethru++;
            }

            stepsgonethru = 0;

            if (IsKeyPressed(KEY_LEFT)) {
                projectileBuffer.projectiles[projectilesNumber].projectilePosition = playerPosition;
                projectileBuffer.projectiles[projectilesNumber].type = Openbirth::Yeetables::TEAR;
                projectileBuffer.projectiles[projectilesNumber].speed = 0;
                projectileBuffer.projectiles[projectilesNumber].dir = Openbirth::Coordination::LEFT;
                projectilesNumber++;
                printf("Cried a tear\n");
            }
            if (IsKeyPressed(KEY_RIGHT)) {
                projectileBuffer.projectiles[projectilesNumber].projectilePosition = playerPosition;
                projectileBuffer.projectiles[projectilesNumber].type = Openbirth::Yeetables::TEAR;
                projectileBuffer.projectiles[projectilesNumber].speed = 0;
                projectileBuffer.projectiles[projectilesNumber].dir = Openbirth::Coordination::RIGHT;
                projectilesNumber++;
                printf("Cried a tear\n");
            }
            if (IsKeyPressed(KEY_UP)) {
                projectileBuffer.projectiles[projectilesNumber].projectilePosition = playerPosition;
                projectileBuffer.projectiles[projectilesNumber].type = Openbirth::Yeetables::TEAR;
                projectileBuffer.projectiles[projectilesNumber].speed = 0;
                projectileBuffer.projectiles[projectilesNumber].dir = Openbirth::Coordination::UP;
                projectilesNumber++;
                printf("Cried a tear\n");
            }
            if (IsKeyPressed(KEY_DOWN)) {
                projectileBuffer.projectiles[projectilesNumber].projectilePosition = playerPosition;
                projectileBuffer.projectiles[projectilesNumber].type = Openbirth::Yeetables::TEAR;
                projectileBuffer.projectiles[projectilesNumber].speed = 0;
                projectileBuffer.projectiles[projectilesNumber].dir = Openbirth::Coordination::DOWN;
                projectilesNumber++;
                printf("Cried a tear\n");
            }
           
            
            break;
        }

        


        EndDrawing();
    }

    CloseWindow();

    return 0;
    
}