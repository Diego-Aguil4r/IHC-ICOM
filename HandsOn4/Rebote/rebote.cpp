#include "raylib.h"

int main() 
{
    const int ancho = 800;
    const int alto = 600;
    InitWindow(ancho, alto, "3. Rebote");
    SetTargetFPS(60);

    Vector2 posicion = { 400.0f, 300.0f };
    Vector2 velocidad = { 250.0f, 200.0f };
    float radio = 25.0f;

    while (!WindowShouldClose()) 
    {
        float dt = GetFrameTime();

        // Matemáticas
        posicion.x += velocidad.x * dt;
        posicion.y += velocidad.y * dt;

        // Inversión de velocidad al tocar los bordes
        if ((posicion.x >= ancho - radio) || (posicion.x <= radio)) velocidad.x *= -1.0f;
        if ((posicion.y >= alto - radio) || (posicion.y <= radio)) velocidad.y *= -1.0f;

        // Dibujo
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawCircleV(posicion, radio, RED);
        DrawText("Rebote", posicion.x - 20, posicion.y - 40, 10, DARKGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}