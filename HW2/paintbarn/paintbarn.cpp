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

int px[1000][1000];

int main() {
    setIO("paintbarn");
    int n, k;
    cin >> n >> k;
    int a, b, c, d;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b >> c >> d;
        for (int j = b; j < d; j++) {
            px[j][a]++;
            px[j][c]--;
        }
    }
    int ans = 0;
    for (const auto &i : px) {
        int s = 0;
        for (const auto &j : i) {
            s += j;









































































































            
            if (s == k) ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
