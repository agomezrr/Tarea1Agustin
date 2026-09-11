// Agustin Adolfo Gomez Rios
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

vector<vector<int>> naive(const vector<vector<int>>& m1, const vector<vector<int>>& m2);
vector<vector<int>> strassen(const vector<vector<int>>& m1, const vector<vector<int>>& m2);


vector<vector<int>> leerMatriz(const string& archivo, int n) {
    vector<vector<int>> matriz(n, vector<int>(n));
    ifstream file(archivo);
    
    if (!file.is_open()) {
        return {};
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            file >> matriz[i][j];
        }
    }
    return matriz;
}

void guardarMatriz(const vector<vector<int>>& mat, const string& nombreArchivo) {
    ofstream file(nombreArchivo);
    for (const auto& fila : mat) {
        for (size_t i = 0; i < fila.size(); i++) {
            file << fila[i] << (i == fila.size() - 1 ? "" : " ");
        }
        file << "\n";
    }
    file.close();
}

int main(){
    vector<int> N = {16, 64, 256, 1024};
    vector<string> T = {"dispersa", "diagonal", "densa"};
    vector<string> D = {"D0", "D10"};
    vector<string> M = {"a", "b", "c"};

    string direccionSalida = "data/measurements/salida_matrix.csv";
    ofstream archivoSalida(direccionSalida);

    if(!archivoSalida.is_open()) {
        cerr << "Error al crear el archivo " << direccionSalida << endl;
        return 1;
    }

    archivoSalida << "Algoritmo,N,Tipo,Dominio,Muestra,Tiempo_us\n";

    for (int n : N) {
        for (const auto& t : T) {
            for (const auto& d : D) {
                for (const auto& m : M) {
                    string nombreBase = to_string(n) + "_" + t + "_" + d + "_" + m;
                    string archivo1 = "data/matrix_input/" + nombreBase + "_1.txt";
                    string archivo2 = "data/matrix_input/" + nombreBase + "_2.txt";

                    vector<vector<int>> m1 = leerMatriz(archivo1, n);
                    vector<vector<int>> m2 = leerMatriz(archivo2, n);

                    if (m1.empty() || m2.empty()) continue; 
                    
                    cout << "Analizando " << nombreBase << endl;

                    // Naive 
                    auto inicio = high_resolution_clock::now();
                    vector<vector<int>> resNaive = naive(m1, m2);
                    auto fin = high_resolution_clock::now();
                    auto duracion = duration_cast<microseconds>(fin - inicio);
                    archivoSalida << "naive," << n << "," << t << "," << d << "," << m << "," << duracion.count() << "\n";
                    
                    guardarMatriz(resNaive, "data/matrix_output/" + nombreBase + "_naive_out.txt");

                    // Strassen
                    inicio = high_resolution_clock::now();
                    vector<vector<int>> resStrassen = strassen(m1, m2);
                    fin = high_resolution_clock::now();
                    duracion = duration_cast<microseconds>(fin - inicio);
                    archivoSalida << "strassen," << n << "," << t << "," << d << "," << m << "," << duracion.count() << "\n";
                    
                    guardarMatriz(resStrassen, "data/matrix_output/" + nombreBase + "_strassen_out.txt");
                }
            }
        }
    }

    archivoSalida.close();
    cout << "\nProceso realizado correctamente" << endl;
    cout << "Se guardaron los resultados en " << direccionSalida << endl;

    return 0;
}