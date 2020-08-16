#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

long long facta(int x)
{
    if (x == 0 || x == 1)
        return 1;
    
    return x*facta(x - 1);
}

void printGraphDFS(int **edges, int n, int *vis, int st,vector<int>&v)
{    
    vis[st] = 1;
    v.push_back(st);
    for (int i = 0; i < n; i++)
    {
        if (i == st)
            continue;
        if (edges[st][i] == 1)
        {
            if (vis[i])
                continue;
               
            printGraphDFS(edges, n, vis, i,v);
        }
    }
   
}
vector<vector<int>> Connectedhorses(int **edges,int *vis,int n)
{
      vector<vector<int>>components;
      for(int i=0;i<n;i++)
      {
          if(!vis[i]){
                    vector<int >v1;
          printGraphDFS(edges,n,vis,i,v1);
          components.push_back(v1);
          }
      }
      return components;
}
int main()
{
    int n, m, q, a, b;
    cin >> n >> m >> q;
    vector<pair<int, int>> v;
    for (int i = 1; i <= q; i++)
    {
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    int **edges = new int *[n];
    int ff, fs, sf, ss, pf, ps;
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            edges[i][j] = 0;
        }
    }
    for (int i = 1; i <= q; i++)
    {
        ff = v[i - 1].first;
        fs = v[i - 1].second;
        for (int j = i; j <= q; j++)
        {
            sf = v[j - 1].first;
            ss = v[j - 1].second;
            pf = abs(ff - sf);
            ps = abs(fs - ss);
            if ((pf == 2 && ps == 1) || (pf == 1 && ps == 2))
            {

                edges[i - 1][j - 1] = 1;
                edges[j - 1][i - 1] = 1;
            }
        }
    }
    vector<int> compo;
    vector<vector<int>>c1;

    int in = 0,st=0;
    int vis[q];
    for (int i = 0; i < q; i++)
    {
        vis[i] = 0;
    } 
     c1=Connectedhorses(edges,vis,q);
    long long fact1 = 1;
    for (int i = 0; i < c1.size(); i++)
    {
        int a = c1[i].size();
        fact1 *= facta(a);

        fact1 %= MOD;
    }
    cout << fact1 % MOD;
   
}


