// Agustin Adolfo Gomez Rios
// Algoritmo base extraido de Geeks for Geeks
// https://www.geeksforgeeks.org/dsa/patience-sorting/

#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


// struct que se utiliza para manejar los elementos en la cola de prioridad
struct Nodo {
    int val;
    size_t pila_idx;
    
    bool operator>(const Nodo& otro) const {
        return val > otro.val;
    }
};

void patienceSort(vector<int>& arr) {
    if (arr.empty()) return;

    vector<vector<int>> piles;

    // creamos stack en O(n log(n)) usando la busqueda binaria
    for (int x : arr) {
        auto it = lower_bound(piles.begin(), piles.end(), x,
            [](const vector<int>& pila, int val) {
                return pila.back() < val;
            });
            
        if (it == piles.end()) {
            piles.push_back({x});
        } else {
            it->push_back(x);
        }
    }

    // Fase 2: K-way merge en O(n log k) usando un Min-Heap
    priority_queue<Nodo, vector<Nodo>, greater<Nodo>> pq;
    
    for (size_t i = 0; i < piles.size(); i++) {
        pq.push({piles[i].back(), i});
        piles[i].pop_back();
    }

    size_t idx = 0;
    while (!pq.empty()) {
        Nodo actual = pq.top();
        pq.pop();
        
        arr[idx++] = actual.val;
        
        if (!piles[actual.pila_idx].empty()) {
            pq.push({piles[actual.pila_idx].back(), actual.pila_idx});
            piles[actual.pila_idx].pop_back();
        }
    }
}