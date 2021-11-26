// Source: https://usaco.guide/general/io

#include <iostream>
using namespace std;

const int MAX_N = 1000;

int grid[MAX_N][MAX_N];
int side;
bool visited[MAX_N][MAX_N];
int curr_size = 0;

void floodfill(int r, int c){
    if (
            (r < 0 || r >= row_num || c < 0 || c >= col_num)
            || grid[r][c] == 0
            || visited[r][c]
            ) return;
    visited[r][c] = true;
    curr_size++;
    floodfill(r, c + 1, color);
    floodfill(r, c - 1, color);
    floodfill(r - 1, c, color);
    floodfill(r + 1, c, color);
}

int main() {
    cin >> side;
    for (int i = 0; i < side; ++i) {
        for (int j = 0; j < side; ++j) {
            char c;
            cin >> c;
            if (c == '.') grid[i][j] = 0;
            else grid[i][j] = 1;
        }
    }
    int m = -1;
    for (int i = 0; i < side; ++i) {
        for (int j = 0; j < side; ++j) {
            if (!visited[i][j]){
                curr_size = 0;
                m = max(m, floodfill(i, j));
            }
        }
    }
    cout << m << "\n";
    return 0;
}