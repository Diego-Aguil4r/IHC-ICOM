#include "raylib.h"

int main() 
{
    InitWindow(800, 600, "5. Trayectoria");
    SetTargetFPS(60);

    Vector2 posicion = { 50.0f, 550.0f };
    Vector2 velocidad = { 200.0f, -600.0f }; // Impulso inicial hacia arriba y derecha
    const float gravedad = 800.0f; // Fuerza que jala hacia abajo

    while (!WindowShouldClose()) 
    {
        float dt = GetFrameTime();

        // Matemáticas (Aceleración gravitacional)
        velocidad.y += gravedad * dt; 
        posicion.x += velocidad.x * dt;
        posicion.y += velocidad.y * dt;

        // Reiniciar cuando cae al fondo
        if (posicion.y > 650.0f) { 
            posicion = { 50.0f, 550.0f };
            velocidad = { 200.0f, -600.0f };
        }

        // Dibujo
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawCircleV(posicion, 15.0f, ORANGE);
        DrawText("Trayectoria", posicion.x - 30, posicion.y + 20, 10, DARKGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}