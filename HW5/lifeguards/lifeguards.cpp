#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

struct Timestamp {
    int id, time;
    bool starting;
    bool operator < (const Timestamp& t) {
        return time < t.time;
    }
};

bool cmp(const Timestamp& t1, const Timestamp& t2) {
    return t1.time < t2.time;
}

int main() {
    int N; cin >> N;
    Timestamp ts[2*N];
    for (int i = 0; i < N; ++i) {
        int t1, t2; cin >> t1 >> t2;
        ts[2*i] = {i, t1, true};
        ts[2*i+1] = {i, t2, false};
    }
    sort(ts, ts+2*N);
    set<int> active;
    int a[N] = {0};
    int total = 0;
    int prev = 0;
    for (const auto &i : ts) {
        if (!active.empty()) {
            total += i.time - prev;
        }
        if (active.size() == 1) {
            a[i.id]++;
        }
        if (i.starting) {
            active.insert(i.id);
        }
        else active.erase(i.id);
        prev = i.time;
    }
    for (a)
}
