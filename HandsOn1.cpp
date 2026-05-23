#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>

using namespace std;

// Clase Matriz
class Matriz {
public:
    int f, c;
    vector<vector<double>> d;

    Matriz(int filas, int cols, double inicial = 0.0) {
        f = filas;
        c = cols;
        d.resize(f, vector<double>(c, inicial));
    }

    Matriz transpuesta() {
        Matriz res(c, f);
        for (int i = 0; i < f; i++)
            for (int j = 0; j < c; j++)
                res.d[j][i] = d[i][j];
        return res;
    }

    Matriz operator*(Matriz &otra) {
        if (c != otra.f) throw invalid_argument("Dimensiones erroneas");
        Matriz res(f, otra.c, 0.0);
        for (int i = 0; i < f; i++)
            for (int j = 0; j < otra.c; j++)
                for (int k = 0; k < c; k++)
                    res.d[i][j] += d[i][k] * otra.d[k][j];
        return res;
    }

    Matriz inversa3x3() {
        if (f != 3 || c != 3) throw invalid_argument("Solo 3x3");
        double det = d[0][0]*(d[1][1]*d[2][2] - d[1][2]*d[2][1]) -
                     d[0][1]*(d[1][0]*d[2][2] - d[1][2]*d[2][0]) +
                     d[0][2]*(d[1][0]*d[2][1] - d[1][1]*d[2][0]);
        if (det == 0) throw runtime_error("Determinante cero");
        double invd = 1.0 / det;
        Matriz inv(3,3);
        inv.d[0][0] = (d[1][1]*d[2][2] - d[1][2]*d[2][1]) * invd;
        inv.d[0][1] = (d[0][2]*d[2][1] - d[0][1]*d[2][2]) * invd;
        inv.d[0][2] = (d[0][1]*d[1][2] - d[0][2]*d[1][1]) * invd;
        inv.d[1][0] = (d[1][2]*d[2][0] - d[1][0]*d[2][2]) * invd;
        inv.d[1][1] = (d[0][0]*d[2][2] - d[0][2]*d[2][0]) * invd;
        inv.d[1][2] = (d[0][2]*d[1][0] - d[0][0]*d[1][2]) * invd;
        inv.d[2][0] = (d[1][0]*d[2][1] - d[1][1]*d[2][0]) * invd;
        inv.d[2][1] = (d[0][1]*d[2][0] - d[0][0]*d[2][1]) * invd;
        inv.d[2][2] = (d[0][0]*d[1][1] - d[0][1]*d[1][0]) * invd;
        return inv;
    }
};

// Clase del modelo de regresion
class Regresor {
private:
    double B0, B1, B2;
    bool listo;
    
    vector<double> x1, x2, y;

public:
    Regresor() {
        x1 = {41.9,43.4,43.9,44.5,47.3,47.5,47.9,50.2,52.8,53.2,56.7,57.0,63.5,65.3,71.1,77.0,77.8};
        x2 = {29.1,29.3,29.5,29.7,29.9,30.3,30.5,30.7,30.8,30.9,31.5,31.7,31.9,32.0,32.1,32.5,32.9};
        y  = {251.3,251.3,248.3,267.5,273.0,276.5,270.3,274.9,285.0,290.0,297.0,302.5,304.5,309.3,321.7,330.7,349.0};
        listo = false;
    }

    void entrenar() {
        int n = x1.size();
        Matriz X(n,3);
        Matriz Y(n,1);
        for (int i = 0; i < n; i++) {
            X.d[i][0] = 1.0;
            X.d[i][1] = x1[i];
            X.d[i][2] = x2[i];
            Y.d[i][0] = y[i];
        }
        Matriz Xt = X.transpuesta();
        Matriz XtX = Xt * X;
        Matriz inv = XtX.inversa3x3();
        Matriz XtY = Xt * Y;
        Matriz betas = inv * XtY;
        B0 = betas.d[0][0];
        B1 = betas.d[1][0];
        B2 = betas.d[2][0];
        listo = true;
    }

    void mostrarEcuacion() {
        if (!listo) return;
        cout << "\nEcuacion de regresion\n";
        cout << "Yield = " << B0 << " + " << B1 << "*x1 + " << B2 << "*x2\n";
    }

    double predecir(double a, double b) {
        if (!listo) return 0;
        return B0 + B1*a + B2*b;
    }
};

// Programa principal
int main() {
    try {
        Regresor modelo;
        modelo.entrenar();
        modelo.mostrarEcuacion();

        cout << "\nSimulacion de los 5 experimentos nuevos\n";
        cout << "Exp   x1      x2      Yield predicho\n";
        
        double nuevos_x1[] = {50.0, 60.0, 70.0, 45.0, 55.0};
        double nuevos_x2[] = {31.0, 31.5, 32.0, 29.8, 30.5};
        
        for (int i = 0; i < 5; i++) {
            double yp = modelo.predecir(nuevos_x1[i], nuevos_x2[i]);
            cout << i+1 << "     " << nuevos_x1[i] << "    " << nuevos_x2[i] << "      " << yp << endl;
        }
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;
}