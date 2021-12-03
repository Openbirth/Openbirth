#include <iostream>
#include <raylib.h>
#include "ConfigFiles.h"
#include "defs.h"
#include "Chardev.h"


#pragma region


Openbirth::Characters::Character Mary{ "Mary", 6, 3, 75 }; // Mary, original character from Openbirth
Openbirth::Characters::Character Terry{ "Terry", 6, 3, 75 }; // Terry, original character from Openbirth

Openbirth::Characters::CharacterBuffer buffer{ {Mary, Terry} };



#pragma endregion Defining Characters







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
            break;
        }

        


        EndDrawing();
    }

    CloseWindow();

    return 0;
    
}