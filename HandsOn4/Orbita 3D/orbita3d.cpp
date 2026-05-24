#include "raylib.h"
#include <math.h>

int main() 
{
    InitWindow(800, 600, "3. Orbita 3D");
    SetTargetFPS(60);

    Camera3D camara = { 0 };
    camara.position = { 0.0f, 15.0f, 20.0f }; 
    camara.target = { 0.0f, 0.0f, 0.0f };    
    camara.up = { 0.0f, 1.0f, 0.0f };
    camara.fovy = 45.0f;
    camara.projection = CAMERA_PERSPECTIVE;

    // Variables de transformación
    Vector3 centro = { 0.0f, 2.0f, 0.0f }; 
    float radio = 8.0f;
    float angulo = 0.0f;
    float velocidadOrbita = 1.5f;

    while (!WindowShouldClose()) 
    {
        float dt = GetFrameTime();

        // Matemáticas: Ecuaciones paramétricas en plano X-Z
        angulo += velocidadOrbita * dt; 
        
        Vector3 posicionPlaneta = {
            centro.x + cosf(angulo) * radio,
            centro.y,                        
            centro.z + sinf(angulo) * radio  
        };

        // Dibujo
        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode3D(camara);
            DrawGrid(20, 1.0f);
            
            DrawSphere(centro, 1.5f, GOLD); // Sol
            DrawSphere(posicionPlaneta, 0.5f, BLUE); // Planeta orbitando
        EndMode3D();

        DrawText("Orbita tridimensional", 10, 10, 20, DARKGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}