#include "raylib.h"
#include <math.h>

int main() 
{
    InitWindow(800, 600, "4. Movimiento Senoidal");
    SetTargetFPS(60);

    float tiempo = 0.0f;
    Vector2 posicion = { 0.0f, 300.0f };
    float amplitud = 100.0f;
    float frecuencia = 5.0f;

    while (!WindowShouldClose()) 
    {
        float dt = GetFrameTime();

        // Matemáticas: y = Centro + sen(wt) * Amplitud
        tiempo += dt;
        posicion.x += 150.0f * dt; // Movimiento horizontal constante
        posicion.y = 300.0f + sinf(tiempo * frecuencia) * amplitud; 

        if (posicion.x > 850.0f) posicion.x = -50.0f;

        // Dibujo
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawCircleV(posicion, 20.0f, PURPLE);
        DrawText("Senoidal", posicion.x - 20, posicion.y - 30, 10, DARKGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}