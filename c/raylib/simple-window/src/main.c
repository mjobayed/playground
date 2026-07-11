#include "raylib.h"

#define WINDOW_HEIGHT 800
#define WINDOW_WIDTH 800

int main() {
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "raylib window");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground((Color){0, 0, 0, 255});
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
