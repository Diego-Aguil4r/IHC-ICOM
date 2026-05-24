#include "raylib.h"
#include <math.h>

int main() 
{
    InitWindow(800, 600, "6. Orbita");
    SetTargetFPS(60);

    Vector2 centro = { 400.0f, 300.0f };
    float angulo = 0.0f;
    float radio = 150.0f;

    while (!WindowShouldClose()) 
    {
        float dt = GetFrameTime();

        // Matemáticas: x = r*cos(a), y = r*sin(a)
        angulo += 2.0f * dt; // Velocidad de la órbita (radianes por segundo)
        Vector2 posicionPlaneta = {
            centro.x + cosf(angulo) * radio,
            centro.y + sinf(angulo) * radio
        };

        // Dibujo
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawCircleV(centro, 20.0f, GOLD); // Centro (Sol)
        DrawCircleV(posicionPlaneta, 15.0f, MAROON); // Objeto orbitando
        DrawText("Centro", centro.x - 20, centro.y - 35, 10, DARKGRAY);
        DrawText("Orbita", posicionPlaneta.x - 20, posicionPlaneta.y - 25, 10, DARKGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}