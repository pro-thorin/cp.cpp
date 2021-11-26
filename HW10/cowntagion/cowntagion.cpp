#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int n, days;
int number[100001] = {0};
vector<int> adj[100001];

void dfs(int x) {
    int c = 0;
    number[x] = 1;
    for (int &v : adj[x]) {
        if (number[v] == 0) {
            c++;
        }
    }
    days += ceil(log2(c + 1));
    for (int &v : adj[x]) {
        if (number[v] == 0) {
            days++;
            dfs(v);
        }
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }
    number[0] = 1;
    days = 0;
    dfs(0);
    cout << days << "\n";
}