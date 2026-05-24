#include "raylib.h"

int main() 
{
    InitWindow(800, 600, "2. Trayectoria Espacial 3D");
    SetTargetFPS(60);

    Camera3D camara = { 0 };
    camara.position = { 15.0f, 10.0f, 15.0f }; 
    camara.target = { 0.0f, 0.0f, 0.0f };    
    camara.up = { 0.0f, 1.0f, 0.0f };
    camara.fovy = 45.0f;
    camara.projection = CAMERA_PERSPECTIVE;

    // Variables de transformación
    Vector3 posicion = { -10.0f, 0.5f, 10.0f }; 
    Vector3 velocidad = { 8.0f, 15.0f, -8.0f }; 
    const float gravedad = -25.0f; // Hacia abajo en el eje Y

    while (!WindowShouldClose()) 
    {
        float dt = GetFrameTime();

        // Matemáticas: Gravedad y velocidad espacial
        velocidad.y += gravedad * dt; 
        posicion.x += velocidad.x * dt;
        posicion.y += velocidad.y * dt;
        posicion.z += velocidad.z * dt;

        // Reiniciar si cae por debajo del piso
        if (posicion.y < 0.5f) {
            posicion = { -10.0f, 0.5f, 10.0f };
            velocidad = { 8.0f, 15.0f, -8.0f };
        }

        // Dibujo
        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode3D(camara);
            DrawGrid(20, 1.0f);
            DrawSphere(posicion, 0.5f, ORANGE);
        EndMode3D();

        DrawText("Tiro Parabolico 3D", 10, 10, 20, DARKGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}