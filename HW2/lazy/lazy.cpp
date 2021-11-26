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
    setIO("lazy");
    int n, k;
    cin >> n >> k;
    int ps[n][n + 1];
    for (int i = 0; i < n; ++i) {
        ps[i][0] = 0;
        for (int j = 0; j < n; ++j) {
            int a;
            cin >> a;
            ps[i][j + 1] = ps[i][j] + a;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int a = 0;
            for (int l = max(0, i - k); l < min(n, i + k + 1); ++l) {
                int b = min(n, j + k - abs(i - l) + 1);
                int c = max(0, j - (k - abs(i - l)));
                a += ps[l][b] - ps[l][c];
            }
            ans = max(ans, a);
        }
    }
    cout << ans << "\n";
    return 0;
}
