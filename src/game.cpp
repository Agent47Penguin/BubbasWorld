#include "game.h"

Game::Game(int winWidth, int winHeight, const char *winTitle)
    : screenWidth(winWidth), screenHeight(winHeight), title(winTitle) {}

Game::~Game() {}

void Game::Init() {
    InitWindow(screenWidth, screenHeight, title);
    SetTargetFPS(60);
}

void Game::Update() {
}

void Game::Draw() {
    BeginDrawing();
    ClearBackground(BLUE);
    EndDrawing();
}

void Game::Shutdown() {
    CloseWindow();
}

void Game::Run() {
    Init();

    while (!WindowShouldClose()) {
        Update();
        Draw();
    }

    Shutdown();
}