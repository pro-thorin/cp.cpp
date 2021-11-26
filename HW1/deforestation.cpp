#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n;
    int p[n + 1];
    p[0] = 0;
    for (int i = 1; i < n + 1; ++i) {
        int a;
        cin >> a;
        p[i] = p[i - 1] + a;
    }
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        cout << p[b + 1] - p[a] << "\n";
    }
}