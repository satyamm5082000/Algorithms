#include <bits/stdc++.h>
using namespace std;

bool Check(int edges[26][26], int n1, char *s, int *vis)
{
  
    vis[s[0] - 'A'] = 1;
    for (int i = 0; i < 26; i++)
    {
        if (i == s[0] - 'A')
            continue;
        if (edges[s[0] - 'A'][s[1] - 'A'] == 1)
        {
            if (vis[i])
                continue;
            if (i == (s[n1 - 1] - 'A'))
                return true;
            return Check(edges, n1, s + 1, vis);
        }
    }
    return false;
}

int main()
{
    
        char s[11];
        for (int k = 0; k < 11; k++)
        {
            cin >> s[k];
        }
    int n, m, x = -1, y = -1;
    cin >> n >> m;
    char **arr = new char *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new char[m];
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    int edges[26][26] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i + 1 < n)
            {
                edges[arr[i][j] - 'A'][arr[i + 1][j] - 'A'] = 1;
                edges[arr[i + 1][j] - 'A'][arr[i][j] - 'A'] = 1;
            }
            if (i - 1 >= 0)
            {
                edges[arr[i][j] - 'A'][arr[i - 1][j] - 'A'] = 1;
                edges[arr[i - 1][j] - 'A'][arr[i][j] - 'A'] = 1;
            }
            if (j + 1 < m)
            {
                edges[arr[i][j] - 'A'][arr[i][j + 1] - 'A'] = 1;
                edges[arr[i][j + 1] - 'A'][arr[i][j] - 'A'] = 1;
            }
            if (i + 1 < n && j + 1 < m)
            {
                edges[arr[i][j] - 'A'][arr[i + 1][j + 1] - 'A'] = 1;
                edges[arr[i + 1][j + 1] - 'A'][arr[i][j] - 'A'] = 1;
            }
            if (j - 1 >= 0 && i - 1 >= 0)
            {
                edges[arr[i][j] - 'A'][arr[i - 1][j - 1] - 'A'] = 1;
                edges[arr[i - 1][j - 1] - 'A'][arr[i + 1][j] - 'A'] = 1;
            }
            if (j - 1 >= 0)
            {
                edges[arr[i][j] - 'A'][arr[i][j - 1] - 'A'] = 1;
                edges[arr[i][j - 1] - 'A'][arr[i + 1][j] - 'A'] = 1;
            }
         
        }
    }
    
        int n1 = 10, visi[26] = {0};
        bool r = Check(edges, 11, s, visi);
        if (r == true){
            cout << "1";
        }
        else
        {
            cout << 0;
        }
}
