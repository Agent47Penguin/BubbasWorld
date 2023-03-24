#include "game.h"

Game::Game(int winWidth, int winHeight, const char *winTitle)
    : screenWidth_(winWidth), screenHeight_(winHeight), title_(winTitle),
      background_(screenWidth_, screenHeight_, 32),
      player_() {}

Game::~Game() {}

void Game::Init() {
    InitWindow(screenWidth_, screenHeight_, title_);
    SetTargetFPS(60);
}

void Game::Update() {
    player_.Update();
}

void Game::Draw() {
    BeginDrawing();
    ClearBackground(BLUE);

    background_.Draw();
    player_.Draw();

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