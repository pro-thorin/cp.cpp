#include <iostream>
#include <algorithm>
#include <cstdio>
#include <set>
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
    setIO("div7");
    int n;
    cin >> n;
    long long p[n + 1];
    p[0] = 0;
    for (int i = 1; i < n + 1; ++i) {
        long long a;
        cin >> a;
        p[i] = p[i - 1] + a;
    }
    int a[7];
    fill(a, a + 7, -1);
    int b[7];
    fill(b, b + 7, 1);
    for (int i = 0; i < n + 1; ++i) {
        long long mod = p[i] % 7;
        if (a[mod] == -1) a[mod] = i;
        else b[mod] = i;
    }
    int m = 0;
    for (int i = 0; i < 7; ++i) {
        m = max(b[i] - a[i], m);
    }
    cout << m;
    return 0;
}
