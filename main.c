#include <stdio.h>
#include <stdbool.h>
#define FOR(i,a,b) for(int i=a;i<b;i++)
int Sudoku[9][9] = { 0 };
bool solve(int num);
bool check(int line, int row, int val);
int main()
{
    FOR(i, 0, 9) FOR(j, 0, 9) scanf("%d", &Sudoku[i][j]);
    solve(0);
    FOR(i, 0, 9) FOR(j, 0, 9)
            j == 8 ? printf("%d\n", Sudoku[i][j]) : printf("%d ", Sudoku[i][j]);
    return 0;
}

bool solve(int num)
{
    int line = num / 9;
    int row = num % 9;
    if (num == 81)
        return true;
    else if (Sudoku[line][row] != 0)
        return solve(num + 1);
    else
    {
        FOR(val, 1, 10)
        {
            if (check(line,row,val))
            {
                Sudoku[line][row] = val;
                if (solve(num + 1))
                    return true;
                Sudoku[line][row] = 0;
            }
        }
    }
    return false;
}
bool check(int line, int row, int val)
{
    FOR(i, 0, 9)
        if (Sudoku[i][row] == val)
            return false;
    FOR(j, 0, 9)
        if (Sudoku[line][j] == val)
            return false;
    FOR(i, line / 3 * 3, (line/3+1)*3)
        FOR(j, row / 3 * 3, (row/3+1)*3)
            if (Sudoku[i][j] == val)
                return false;
    return true;
}
