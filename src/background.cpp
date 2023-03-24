#include "background.h"

Background::Background(int screenWidth, int screenHeight, int tileSize)
    : texture_(nullptr), tileSize_(tileSize), textureLoaded_(false) {
    // Calculate the number of tiles needed to fill the screen
    tilesX_ = screenWidth / tileSize_ + 1;
    tilesY_ = screenHeight / tileSize_ + 1;

    // Set up source and destination rectangles
    sourceRect_ = {0.0f, 0.0f, (float)tileSize_, (float)tileSize_};
    destRect_ = {0.0f, 0.0f, (float)tileSize_, (float)tileSize_};
}

Background::~Background() {
    if (texture_ != nullptr) {
        UnloadTexture(texture_[0]);
    }
}

void Background::Draw() {
    // Load the texture if it hasn't been loaded yet
    if (!textureLoaded_ && texture_ == nullptr) {
        texture_ = new Texture2D(LoadTexture("assets/background/stars.png"));
        textureLoaded_ = true;
    }

    Color color = ColorAlpha(WHITE, 0.5f);

    // Draw the background tiles to fill the screen
    for (int x = 0; x < tilesX_; x++) {
        for (int y = 0; y < tilesY_; y++) {
            destRect_.x = x * tileSize_;
            destRect_.y = y * tileSize_;
            DrawTexturePro(texture_[0], sourceRect_, destRect_, {0.0f, 0.0f}, 0.0f, color);
        }
    }
}
