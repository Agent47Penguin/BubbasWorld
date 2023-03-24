#pragma once
#include "raylib.h"

class Game {
    public:
    Game(int winWidth, int winHeight, const char *winTitle);
    ~Game();

    void Run();

    private:
    void Init();
    void Update();
    void Draw();
    void Shutdown();

    int screenWidth;
    int screenHeight;
    const char *title;
};