// Agustin Adolfo Gomez Rios
// Algoritmo base extraido de Geeks for Geeks

#include <vector>
using namespace std;

vector<vector<int>> naive(const vector<vector<int>>& m1, const vector<vector<int>>& m2){
    int n = m1.size();
    vector<vector<int>> ret(n, vector<int>(n,0));

    for(int i = 0; i < n; ++i){
        for(int j=0; j < n; ++j){
            for(int k = 0; k <n; ++k){
                ret[i][j] += m1[i][k]*m2[k][j];
            }
        }
    }
    return ret;
}
