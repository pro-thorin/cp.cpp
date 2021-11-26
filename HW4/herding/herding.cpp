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
    setIO("herding");
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);\
    int s1 = a[1] - a[0] - 1, s2 = a[n - 1] - a[n - 2] - 1;
    int t = a[n-1] - a[0] - n + 1;
    int ma = t - min(s1, s2);
    int x = 0, y = 1;
    int mi = n + 1;
    if (a[n - 1] - a[1] != n - 2 && a[n - 2] - a[0] != n - 2) {
        while (y < n) {
            if (a[y] - a[x] - 1 > n) {
                mi = min(mi, n - (y - x));
                x++;
            }
            else y++;
        }
    }
    else {
        if (a[n - 1] - a[0] > n) mi = 2;
        else if (a[n - 1] - a[0] == n) mi = 1;
        else mi = 0;
    }
    cout << mi << "\n" << ma << "\n";
    return 0;
}
