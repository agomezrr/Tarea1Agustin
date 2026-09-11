// Agustin Adolfo Gomez Rios
// Algoritmo base extraido de Geeks for Geeks
// https://www.geeksforgeeks.org/dsa/strassens-matrix-multiplication/
#include <vector>

using namespace std;

vector<vector<int>> sumarMatriz(const vector<vector<int>>& m1, const vector<vector<int>>&m2){
    int n = m1.size();
    vector<vector<int>> ret(n, vector<int>(n));
    for(int i = 0; i < n; i++)
        for(int j=0; j < n; j++)
            ret[i][j] = m1[i][j] + m2[i][j];
    return ret;
}

vector<vector<int>> restarMatriz(const vector<vector<int>>& m1, const vector<vector<int>>&m2){
    int n = m1.size();
    vector<vector<int>> ret(n, vector<int>(n));
    for(int i = 0; i < n; i++)
        for(int j=0; j < n; j++)
            ret[i][j] = m1[i][j] - m2[i][j];
    return ret;
}

vector<vector<int>> strassen(const vector<vector<int>>& m1, const vector<vector<int>>& m2){
    int n = m1.size();
    int mitad = n/2;
    if(n == 1){
        return {{m1[0][0]*m2[0][0]}};
    }
    
    vector<vector<int>> A11(mitad, vector<int>(mitad)), A12(mitad, vector<int>(mitad));
    vector<vector<int>> A21(mitad, vector<int>(mitad)), A22(mitad, vector<int>(mitad));
    vector<vector<int>> B11(mitad, vector<int>(mitad)), B12(mitad, vector<int>(mitad));
    vector<vector<int>> B21(mitad, vector<int>(mitad)), B22(mitad, vector<int>(mitad));

    // Se llenan las submatrices dividiendo m1 y m2 en 4
    for (int i = 0; i < mitad; i++) {
        for (int j = 0; j < mitad; j++) {
            A11[i][j] = m1[i][j];
            A12[i][j] = m1[i][j + mitad];
            A21[i][j] = m1[i + mitad][j];
            A22[i][j] = m1[i + mitad][j + mitad];

            B11[i][j] = m2[i][j];
            B12[i][j] = m2[i][j + mitad];
            B21[i][j] = m2[i + mitad][j];
            B22[i][j] = m2[i + mitad][j + mitad];
        }
    }

    // Se calculan los 7 productos con Strassen de forma recursiva
    vector<vector<int>> P1 = strassen(A11, restarMatriz(B12, B22));
    vector<vector<int>> P2 = strassen(sumarMatriz(A11, A12), B22);
    vector<vector<int>> P3 = strassen(sumarMatriz(A21, A22), B11);
    vector<vector<int>> P4 = strassen(A22, restarMatriz(B21, B11));
    vector<vector<int>> P5 = strassen(sumarMatriz(A11, A22), sumarMatriz(B11, B22));
    vector<vector<int>> P6 = strassen(restarMatriz(A12, A22), sumarMatriz(B21, B22));
    vector<vector<int>> P7 = strassen(restarMatriz(A11, A21), sumarMatriz(B11, B12));

    // Calculamos las submatrices de la matriz resultante C
    vector<vector<int>> C11 = sumarMatriz(restarMatriz(sumarMatriz(P5, P4), P2), P6);
    vector<vector<int>> C12 = sumarMatriz(P1, P2);
    vector<vector<int>> C21 = sumarMatriz(P3, P4);
    vector<vector<int>> C22 = restarMatriz(sumarMatriz(P5, P1), sumarMatriz(P3, P7));


    vector<vector<int>> ret(n, vector<int>(n));
    for (int i = 0; i < mitad; i++) {
        for (int j = 0; j < mitad; j++) {
            ret[i][j] = C11[i][j];
            ret[i][j + mitad] = C12[i][j];
            ret[i + mitad][j] = C21[i][j];
            ret[i + mitad][j + mitad] = C22[i][j];
        }
    }

    return ret;
}