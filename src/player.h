#pragma once

#include "raylib.h"

class Player {
    public:
    Player();
    ~Player();

    void Update();
    void Draw();

    private:
    void Move();
    void SetFrame(int frame);
    void Animate();

    Texture2D texture_;
    Rectangle sourceRect_;
    Rectangle destRect_;
    Vector2 pos_;
    float velocity_;
    int frameWidth_;
    int frameHeight_;
    int frame_;
    int frameCount_;
    float animTimer_;
    bool isTextureLoaded_;
};
