#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n, q, h;
    cin >> n >> q >> h;
    int a,b;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        if (h >= a) {
            arr[i] = b;
        }
        else arr[i] = 0;
    }
    int p[n + 1];
    p[0] = 0;
    for (int i = 1; i < n + 1; ++i) {
        p[i] = p[i - 1] + arr[i - 1];
    }
    int l, r, m = 0;
    for (int i = 0; i < q; ++i) {
        cin >> l >> r;
        m = max(p[r] - p[l - 1], m);
    }
    cout << m;
}