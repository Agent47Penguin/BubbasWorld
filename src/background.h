#pragma once
#include "raylib.h"

class Background {
    public:
    Background(int screenWidth, int screenHeight, int tileSize);
    ~Background();

    void Draw();

    private:
    Texture2D *texture_;
    Rectangle sourceRect_;
    Rectangle destRect_;
    int tileSize_;
    int tilesX_;
    int tilesY_;
    bool textureLoaded_;
};
