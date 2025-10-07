#include <iostream>
#include <vector>
using namespace std;


pair<int,int> spiralSearch(vector<vector<int>>& grid, pair<int,int> start, int target) {
    int rows = grid.size();
    int cols = grid[0].size();
    int x = start.first, y = start.second;
    int step = 1;

   
    vector<pair<int,int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};

    while (x >= 0 && x < rows && y >= 0 && y < cols) {
        for (int i = 0; i < 4; i++) { 
            int dx = directions[i].first;
            int dy = directions[i].second;
            for (int s = 0; s < step; s++) {
                if (x >= 0 && x < rows && y >= 0 && y < cols) {
                    if (grid[x][y] == target) {
                        return {x, y}; // found!
                    }
                }
                x += dx;
                y += dy;
            }
            if (i % 2 == 1) step++; // after down & up, step grows
        }
    }
    return {-1, -1}; // not found
}

int main() {
    vector<vector<int>> grid = {
        {0,0,0,0,0},
        {0,0,7,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}
    };

    pair<int,int> start = {2, 2}; // center
    int target = 7;

    auto result = spiralSearch(grid, start, target);
    if (result.first != -1)
        cout << "✅ Found at (" << result.first << ", " << result.second << ")" << endl;
    else
        cout << "❌ Target not found" << endl;

    return 0;
}
