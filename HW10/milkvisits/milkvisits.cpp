#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

void setIO(const string& name = "") {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    if (!name.empty()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int n, m, color;
int arr[100001] = {0};
char breed[100001];
vector<int> v[100001];

void connected(int x) {
    if (arr[x]) return;
    arr[x] = color;
    for (auto &i : v[x]) {
        if (breed[x] == breed[i]) {
            connected(i);
        }
    }
}

int main() {
    setIO("milkvisits");
    cin >> n >> m;
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        breed[i] = s[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        v[a - 1].push_back(b - 1);
        v[b - 1].push_back(a - 1);
    }
    for (int i = 0; i < n; ++i) {
        if (!arr[i]) {
            color++;
            connected(i);
        }
    }
    for (int i = 0; i < m; ++i) {
        int a;
        int b;
        char c;
        cin >> a >> b >> c;
        a = a - 1;
        b = b - 1;
        if (breed[a] != c && breed[b] != c && arr[a] == arr[b]) cout << 0;
        else cout << 1;
    }
    return 0;
}
