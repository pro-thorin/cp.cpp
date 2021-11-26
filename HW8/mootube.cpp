#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 5000;
vector<pair<int, int>> adj_list[MAX_N];


/**
4 3
1 2 3
2 3 2
2 4 4
1 2
4 1
3 1
 * 
 * @return int 
 */
int main() {
    int n, q; cin >> n >> q;
    for (int i = 0; i < n-1; ++i) {
        int u, v, w; cin >> u >> v >> w;
        adj_list[u-1].push_back({v-1, w});
        adj_list[v-1].push_back({u-1, w});
    }
}