#include <bits/stdc++.h>
using namespace std;

void printGrid(vector<vector<bool>> grid) {
    for (vector<bool> row : grid) {
        string rowPrint;
        for (bool cell : row) {
            rowPrint += (cell == true) ? "⬜" : "⬛";
        }
        cout << rowPrint << "\n";
    }
    cout << "\n";
}

void cycle(int *index, int vectorSize) {
    *index = (*index == vectorSize - 1) ? 0 : *index + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int outlineW, outlineH, cutoutW, cutoutH, steps;
    cin >> outlineW >> outlineH >> cutoutW >> cutoutH >> steps;
    vector<vector<bool>> grid(outlineH + 1, vector<bool>(outlineW + 1, true));

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (
                (i <= cutoutH && j <= cutoutW) ||
                (i <= cutoutH && j > outlineW - cutoutW) ||
                (i > outlineH - cutoutH && j <= cutoutW) ||
                (i > outlineH - cutoutH && j > outlineW - cutoutW) ||
                i == 0 ||
                j == 0
            ) {
                grid[i][j] = false;
            }
        }
    }

    int col = cutoutW + 1;
    int row = 1;
    int index = 0;
    int cornerTurn = 0;
    vector<vector<int>> directions = {
        {1, 0},
        {0, 1},
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, 1},
        {-1, 0},
        {0, -1},
        {-1, 0},
        {0, -1},
        {1, 0},
        {0, -1},
    };

    while (true) {
        // printGrid(grid);

        if (steps <= 0) {
            break;
        }

        int nextCol = col + directions[index][0];
        int nextRow = row + directions[index][1];

        if (
            nextCol <= 0 ||
            nextCol >= outlineW + 1 ||
            nextRow <= 0 ||
            nextRow >= outlineH + 1 ||
            grid[nextRow][nextCol] == false ||
            ((index == 1 || index == 7) && (cornerTurn == cutoutH)) ||
            ((index == 4 || index == 10) && (cornerTurn == cutoutW))
        ) {
            cornerTurn = 0;
            cycle(&index, directions.size());

            nextCol = col + directions[index][0];
            nextRow = row + directions[index][1];

            if (
                nextCol <= 0 ||
                nextCol >= outlineW + 1 ||
                nextRow <= 0 ||
                nextRow >= outlineH + 1 ||
                grid[nextRow][nextCol] == false
            ) {
                break;
            }

        }

        
        grid[row][col] = false;

        col = nextCol;
        row = nextRow;

        steps--;

        if (index == 1 || index == 4 || index == 7 || index == 10) {
            cornerTurn++;
        }
    }

    cout << "\n" << col << "\n" << row;
}