#include <bits/stdc++.h>
using namespace std;

#define N 4

// A utility function to print solution
void printSolution(int board[N][N]) {
    for(int i=0; i<N; ++i) {
        for(int j=0; j<N; ++j)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
}

/* A utility function to check if a queen can
   be placed on bard[row][col]. Note that this
   function is called when "col" queens are
   already placed in columns from 0 to col -1.
   So we need to check only left side for
   attacking queens */
bool isSafe(int board[N][N], int row, int col) {
    int i,j;

    // Check this row on left side
    for(i=0; i<col; ++i)
        if (board[row][i])
            return false;

    // Check upper diagonal on left side
    for(i=row, j=col; i>=0 && j>=0; --i, --j)
        if (board[i][j])
            return false;

    // Check lower diagonal on left side
    for(i=row, j=col; j>=0 && i<N; ++i, --j)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQUtil(int board[N][N], int col) {
    if (col >= N)
        return true;

    for (int i = 0; i<N; ++i) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;

            if (solveNQUtil(board, col + 1))
                return true;

            board[i][col] = 0;
        }
    }
    return false;
}

bool solveNQ() {
    int board[N][N] = { {0,0,0,0},
                        {0,0,0,0},
                        {0,0,0,0},
                        {0,0,0,0} };
    if (solveNQUtil(board, 0) == false) {
        printf("Solution does not exist");
        return false;
    }

    printSolution(board);
    return true;
}

int main() {
    solveNQ();
    return 0;
}

