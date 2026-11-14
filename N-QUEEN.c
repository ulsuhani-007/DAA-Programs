
#include <stdio.h>
#include <stdlib.h>
int board[20][20];
int n;
int isSafe(int row, int col)
{
    int i, j;
    for (i = 0; i < row; i++)
        if (board[i][col])
            return 0;
    for (i = row - 1, j = col - 1;i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return 0;
    for (i = row - 1, j = col + 1;
         i >= 0 && j < n; i--, j++)
        if (board[i][j])
            return 0;
    return 1;
}

int solveNQueen(int row)
{
    if (row == n)
        return 1;
    for (int col = 0; col < n; col++)
    {
        if (isSafe(row, col))
        {
            board[row][col] = 1;
            if (solveNQueen(row + 1))
                return 1;
            board[row][col] = 0;
        }
    }
    return 0;
}

int main()
{
    printf("Enter the number of queens: ");
    scanf("%d", &n);
    if (n < 1 || n > 20)
    {
        printf("Invalid input\n");
        return 0;
    }
    if (solveNQueen(0))
    {
        printf("\nSolution:\n");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                printf("%d ", board[i][j]);
                printf("\n");
        }
    }
    else
    {
        printf("No solution exists\n");
    }

    return 0;
}
