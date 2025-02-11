#include <bits/stdc++.h>
using namespace std;



/*
5
10 5 1 10 2 10
*/



vector<int> p;
vector<vector<int>> m, s;


void printOptimalParens(int i, int j, char &name)
{
    if (i == j)
    {
        cout << name++;  //start from 'A'
    }
    else
    {
        cout << "(";
        printOptimalParens(i, s[i][j], name);    // Left part
        printOptimalParens(s[i][j] + 1, j, name); // Right part
        cout << ")";
    }
}


void mcm()
{


    int n = p.size() - 1;



    for (int l = 2; l <= n; l++)
    {
        for (int i = 1; i <= n - l + 1; i++)
        {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
            {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    char name = 'A';
    printOptimalParens(1, n, name);

    cout << " : " << m[1][n] << endl;
}

int main()
{
    int n;
    cout << "Enter the number of matrices: ";
    cin >> n;

    p.resize(n + 1);
    m.resize(n + 1, vector<int>(n + 1, 0));
    s.resize(n + 1, vector<int>(n + 1, 0));

    cout << "Enter the dimensions of the matrices (size p0 -> p" << n << "): ";
    for (int i = 0; i <= n; i++)
    {
        cin >> p[i];
    }

    mcm();

    return 0;
}

