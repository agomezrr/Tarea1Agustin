// Agustin Adolfo Gomez Rios
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;
vector<int> sortArray(vector<int>& arr);
vector<int> mergeSort(vector<int>& arr);
vector<int> quickSort(vector<int>& arr);
void patienceSort(vector<int>& arr);

/*
Funcion para leer archivos txt y pasar a vector
*/
vector<int> leerArray(const string& archivo){
    vector<int> arr;
    ifstream file(archivo);
    int num;
    while(file >> num){
        arr.push_back(num);
    }
    return arr;
}

void guardarArray(const vector<int>& arr, const string& nombreArchivo) {
    ofstream file(nombreArchivo);
    for (size_t i = 0; i < arr.size(); i++) {
        file << arr[i] << (i == arr.size() - 1 ? "" : " ");
    }
    file.close();
}

int main(){
    vector<string> N = {"10", "1000", "100000", "10000000"};
    vector<string> T = {"ascendente", "descendente", "aleatorio"};
    vector<string> D = {"D1", "D7"};
    vector<string> M = {"a", "b", "c"};

    string direccionSalida = "data/measurements/salida_sort.csv";
    ofstream archivoSalida(direccionSalida);

    archivoSalida << "Algoritmo,N,Tipo,Dominio,Muestra,Tiempo-ms\n";
    for(const auto& n : N){
        for(const auto& t : T){
            for(const auto& d : D){
                for(const auto& m : M){
                    string nombreArchivo = n + "_" + t + "_" + d + "_" + m + ".txt";
                    string direccionArchivo = "data/array_input/" + nombreArchivo;

                    vector<int> arregloOriginal = leerArray(direccionArchivo);
                    if(arregloOriginal.empty()) continue;
                    cout << "Analizando " << nombreArchivo << endl;


                    // std sort
                    vector<int> arreglo1 = arregloOriginal;
                    auto inicio = high_resolution_clock::now();
                    sortArray(arreglo1);
                    auto fin = high_resolution_clock::now();
                    auto duracion = duration_cast<milliseconds>(fin - inicio);
                    archivoSalida << "std_sort,"<<n<<","<<t<<","<<d<<","<<m<<","<< duracion.count()<< "\n";

                    // Merge sort
                    vector<int> arreglo2 = arregloOriginal;
                    inicio = high_resolution_clock::now();
                    mergeSort(arreglo2);
                    fin = high_resolution_clock::now();
                    duracion = duration_cast<milliseconds>(fin - inicio);
                    archivoSalida << "merge_sort,"<<n<<","<<t<<","<<d<<","<<m<<","<< duracion.count()<< "\n";

                    // Quick sort
                    vector<int> arreglo3 = arregloOriginal;
                    inicio = high_resolution_clock::now();
                    quickSort(arreglo3);
                    fin = high_resolution_clock::now();
                    duracion = duration_cast<milliseconds>(fin - inicio);
                    archivoSalida << "quick_sort,"<<n<<","<<t<<","<<d<<","<<m<<","<< duracion.count()<< "\n";

                    // Patience sort
                    vector<int> arreglo4 = arregloOriginal;
                    inicio = high_resolution_clock::now();
                    patienceSort(arreglo4);
                    fin = high_resolution_clock::now();
                    duracion = duration_cast<milliseconds>(fin - inicio);
                    archivoSalida << "patience_sort,"<<n<<","<<t<<","<<d<<","<<m<<","<< duracion.count()<< "\n";

                    string baseOut = "data/array_output/" + nombreArchivo.substr(0, nombreArchivo.find(".txt"));
                    guardarArray(arreglo1, baseOut + "_std_sort_out.txt");
                    guardarArray(arreglo2, baseOut + "_merge_sort_out.txt");
                    guardarArray(arreglo3, baseOut + "_quick_sort_out.txt");
                    guardarArray(arreglo4, baseOut + "_patience_sort_out.txt");
                }
            }
        }
    }

    archivoSalida.close();
    cout << "Archivo creado, se ha guardado en: " << direccionSalida << endl;
    return 0;
}


