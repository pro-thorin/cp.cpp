#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    long long p[n];
    fill(p, p + n, 0);
    for (int i = 0; i < q; ++i) {
        long long a, b, c;
        cin >> a >> b >> c;
        p[a - 1] += c;
        p[b] -= c;
    }
    long long m = -1;
    long long t = 0;
    for (const auto &i : p) {
        t += i;
        m = max(m, t);
    }
    cout << m;
}
