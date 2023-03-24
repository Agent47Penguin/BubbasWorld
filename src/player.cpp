#include "player.h"

Player::Player()
    : pos_{0.0f, 100.0f}, frameWidth_(21), frameHeight_(41), frame_(0), frameCount_(8), animTimer_(0.0f), isTextureLoaded_(false) {
    sourceRect_ = {0.0f, 0.0f, (float)frameWidth_, (float)frameHeight_};
    destRect_ = {pos_.x, pos_.y, (float)frameWidth_ * 2, (float)frameHeight_ * 2};
}

Player::~Player() {
    if (isTextureLoaded_) {
        UnloadTexture(texture_);
    }
}

void Player::Update() {
    Move();
    Animate();
}

void Player::Move() {
    // Get Input
    if (IsKeyDown(KEY_D) && IsKeyDown(KEY_A)) {
        velocity_ = 0.0f;
    } else if (IsKeyDown(KEY_D)) {
        if (velocity_ == 0) {
            SetFrame(1);
        }
        velocity_ = +300.0f;
    } else if (IsKeyDown(KEY_A)) {
        if (velocity_ == 0) {
            SetFrame(3);
        }
        velocity_ = -300.0f;
    } else {
        velocity_ = 0.0f;
    }

    // Apply Movement
    pos_.x += velocity_ * GetFrameTime();
}

void Player::SetFrame(int frame) {
    frame_ = frame;
    sourceRect_.x = (float)frame_ * (float)frameWidth_;
}

void Player::Animate() {
    if (velocity_ != 0) {
        animTimer_ += GetFrameTime();
        if (animTimer_ >= 0.2f) {
            animTimer_ = 0.0f;
            frame_++;
            if (frame_ >= frameCount_) {
                frame_ = 0;
            }
            sourceRect_.x = (float)frame_ * (float)frameWidth_;
        }
    } else {
        SetFrame(0);
    }
}

void Player::Draw() {
    if (!isTextureLoaded_) {
        texture_ = LoadTexture("assets/face-sheet.png");
        isTextureLoaded_ = true;
    }
    destRect_.x = pos_.x;
    destRect_.y = pos_.y;
    DrawTexturePro(texture_, sourceRect_, destRect_, {0.0f, 0.0f}, 0.0f, WHITE);
}
