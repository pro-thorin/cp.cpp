#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    pair<int, int> a[2500];
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        a[i].first = x; a[i].second = y;
    }
}