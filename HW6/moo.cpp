#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int len(int k) {
    int x;
    if (k == -1) return 0;
    x = len(k - 1);
    return x + k + 3 + x;
}

char solve(int n, int k) {
    if (n > len(k)) return solve(n, k + 1);
    if (n <= len(k - 1)) return solve(n, k - 1);
    n = n - len(k - 1);
    if (n <= k + 3) return (n==1) ? 'm' : 'o';
    n = n - (k + 3);
    return solve(n, k - 1);
}

void setIO(const string& name = "") {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    if (!name.empty()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO("moo");
    int n;
    cin >> n;
    cout << solve(n, 0) << "\n";
    return 0;
}
