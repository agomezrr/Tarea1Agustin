// Agustin Adolfo Gomez Rios
// Algoritmo base y correccion de 3 vias basadas de Geeks for Geeks
// https://www.geeksforgeeks.org/dsa/3-way-quicksort-dutch-national-flag/
// https://www.geeksforgeeks.org/dsa/quick-sort-algorithm/
#include <vector>
#include <utility>

using namespace std;

void quickSortHelper(vector<int>& arr, int low, int high) {
    if (low >= high) return;

    // Elegimos el pivote el elemento central para evitar el peor caso en arreglos ordenados
    int mid = low + (high - low) / 2;
    int pivot = arr[mid];

    // Partimos en 3 bloques para manejar los duplicados masivos
    int i = low;
    int j = low;
    int k = high;

    while (j <= k) {
        if (arr[j] < pivot) {
            swap(arr[i], arr[j]);
            i++;
            j++;
        } else if (arr[j] > pivot) {
            swap(arr[j], arr[k]);
            k--;
        } else {
            j++;
        }
    }

    // Llamamos recursivamente ignorando toda la franja central de elementos iguales al pivote
    quickSortHelper(arr, low, i - 1);
    quickSortHelper(arr, k + 1, high);
}

// Funcion principal
vector<int> quickSort(vector<int>& arr) {
    if (!arr.empty()) {
        quickSortHelper(arr, 0, arr.size() - 1);
    }
    return arr;
}