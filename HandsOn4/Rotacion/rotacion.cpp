#include "raylib.h"

int main() 
{
    InitWindow(800, 600, "2. Rotacion");
    SetTargetFPS(60);

    float angulo = 0.0f;
    Rectangle rectangulo = { 400.0f, 300.0f, 100.0f, 100.0f };
    Vector2 origen = { rectangulo.width / 2, rectangulo.height / 2 };

    while (!WindowShouldClose()) 
    {
        float dt = GetFrameTime();

        // Matemáticas (100 grados por segundo)
        angulo += 100.0f * dt; 

        // Dibujo
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawRectanglePro(rectangulo, origen, angulo, GREEN);
        DrawText("Rotacion", rectangulo.x - 30, rectangulo.y - 70, 10, DARKGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}