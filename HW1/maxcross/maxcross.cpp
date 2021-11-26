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
    setIO("maxcross");
    int n, k, b;
    cin >> n >> k >> b;
    int arr[n];
    fill(arr, arr + n, 0);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        arr[a - 1] = 1;
    }
    int p[n + 1];
    p[0] = 0;
    for (int i = 1; i < n + 1; ++i) {
        p[i] = p[i - 1] + arr[i - 1];
    }
    int m = p[k];
    for (int i = 1; i < n - k + 2; ++i) {
        m = min(m, p[k + i - 1] - p[i - 1]);
    }
    cout << m << "\n";
    return 0;
}
