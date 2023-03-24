#include "raylib.h"

int main() {
    InitWindow(640, 360, "Bubba's World");

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLUE);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}