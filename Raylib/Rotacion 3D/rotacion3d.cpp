#include "raylib.h"
#include "rlgl.h"

int main() 
{
    InitWindow(800, 600, "1. Rotacion 3D");
    SetTargetFPS(60);

    // Configuración de la cámara 3D
    Camera3D camara = { 0 };
    camara.position = { 0.0f, 5.0f, 10.0f }; // Posición de la cámara
    camara.target = { 0.0f, 0.0f, 0.0f };    // Hacia dónde mira
    camara.up = { 0.0f, 1.0f, 0.0f };
    camara.fovy = 45.0f;
    camara.projection = CAMERA_PERSPECTIVE;

    // Variables de transformación
    Vector3 rotacion = { 0.0f, 0.0f, 0.0f }; 
    Vector3 velocidadRotacion = { 45.0f, 90.0f, 30.0f }; // Grados por segundo

    while (!WindowShouldClose()) 
    {
        float dt = GetFrameTime();

        // Matemáticas: Suma de ángulos en cada eje
        rotacion.x += velocidadRotacion.x * dt;
        rotacion.y += velocidadRotacion.y * dt;
        rotacion.z += velocidadRotacion.z * dt;

        // Dibujo
        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode3D(camara);
            DrawGrid(10, 1.0f); // Dibuja un piso de referencia

            // Aplicar rotaciones 3D usando rlgl
            rlPushMatrix();
                rlRotatef(rotacion.x, 1.0f, 0.0f, 0.0f); // Rotar en X (Pitch)
                rlRotatef(rotacion.y, 0.0f, 1.0f, 0.0f); // Rotar en Y (Yaw)
                rlRotatef(rotacion.z, 0.0f, 0.0f, 1.0f); // Rotar en Z (Roll)
                
                DrawCube({0.0f, 1.0f, 0.0f}, 2.0f, 2.0f, 2.0f, RED);
                DrawCubeWires({0.0f, 1.0f, 0.0f}, 2.0f, 2.0f, 2.0f, DARKGRAY);
            rlPopMatrix();

        EndMode3D();

        DrawText("Rotacion en X, Y, Z", 10, 10, 20, DARKGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}