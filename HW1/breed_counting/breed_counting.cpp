#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

void setIO(const string& name = "") {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    if (!name.empty()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO("bcount");
    int n, q;
    cin >> n >> q;
    int h[n + 1];
    int g[n + 1];
    int j[n + 1];
    h[0] = 0; g[0] = 0; j[0] = 0;
    for (int i = 1; i < n + 1; ++i) {
        int a;
        cin >> a;
        h[i] = h[i -1];
        g[i] = g[i - 1];
        j[i] = j[i - 1];
        if (a == 1) h[i]++;
        else if (a == 2) g[i]++;
        else j[i]++;
    }
    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        cout << h[b] - h[a - 1] << " " << g[b] - g[a - 1] << " " << j[b] - j[a - 1] << "\n";
    }
    return 0;
}
