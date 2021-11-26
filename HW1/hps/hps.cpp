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
    setIO("hps");
    int n;
    cin >> n;
    int p[3][n + 1];
    p[0][0] = 0; p[1][0] = 0; p[2][0] = 0;
    for (int i = 0; i < n; ++i) {
        char a;
        cin >> a;
        if (a == 'H') {
            p[0][i + 1] = p[0][i] + 1;
            p[1][i + 1] = p[1][i];
            p[2][i + 1] = p[2][i];
        }
        else if (a == 'P') {
            p[1][i + 1] = p[1][i] + 1;
            p[0][i + 1] = p[0][i];
            p[2][i + 1] = p[2][i];
        }
        else {
            p[2][i + 1] = p[2][i] + 1;
            p[0][i + 1] = p[0][i];
            p[1][i + 1] = p[1][i];
        }
    }
    int m = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i==j) continue;
            for (int k = 1; k <= n; ++k) {
                int a = p[i][k];
                int b = p[j][n] - p[j][k];
                m = max(m, a + b);
            }
        }
    }
    // m = max(p[2][n], max(p[1][n], max(m, p[0][n])));
    cout << m << "\n";
    return 0;
}
