#include<iostream>
 
using namespace std;
 
int m[9][9];
bool r[9][9];
bool c[9][9];
bool s[9][9];

 
void Print()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << m[i][j] << " ";
        }
        cout << "\n";
    }
}
 
void DFS(int Cnt)
{
    int x = Cnt / 9;    // x 좌표
    int y = Cnt % 9;    // y 좌표
    
    if (Cnt == 81)
    {
        Print();
        exit(0);
    }
 
    if (m[x][y] == 0)
    {
        for (int i = 1; i <= 9; i++)
        {
            if (r[x][i] == false && c[y][i] == false && s[(x / 3) * 3 + (y / 3)][i] == false)
            {
                r[x][i] = true;
                c[y][i] = true;
                s[(x / 3) * 3 + (y / 3)][i] = true;
                m[x][y] = i;
                DFS(Cnt + 1);
                m[x][y] = 0;
                r[x][i] = false;
                c[y][i] = false;
                s[(x / 3) * 3 + (y / 3)][i] = false;
            }
        }
    }
    else DFS(Cnt + 1);
}
 
void Solve()
{
	for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> m[i][j];
            if (m[i][j] != 0)
            {
                r[i][m[i][j]] = true;
                c[j][m[i][j]] = true;
                s[(i / 3) * 3 + (j / 3)][m[i][j]] = true;
            }
        }
    }
    DFS(0);
}
 
int main(void)
{
    Solve();
    return 0;
}
