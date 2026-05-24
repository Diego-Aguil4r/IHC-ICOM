#include "raylib.h"

int main() 
{
    InitWindow(800, 600, "1. Traslacion");
    SetTargetFPS(60);

    Vector2 posicion = { 50.0f, 300.0f };
    Vector2 velocidad = { 150.0f, 0.0f };

    while (!WindowShouldClose()) 
    {
        float dt = GetFrameTime();

        // Matemáticas
        posicion.x += velocidad.x * dt;
        if (posicion.x > 850.0f) posicion.x = -50.0f; // Reinicia al salir de pantalla

        // Dibujo
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawRectangleV(posicion, {40.0f, 40.0f}, BLUE);
        DrawText("Traslacion", posicion.x, posicion.y - 20, 10, DARKGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}