#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int MAX = 1e4 + 5;
int id[MAX], n, e;
pair <ll, pair<int, int> > p[MAX];


int cycle(int x)
{
    while(id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void join(int x, int y)
{
    int p = cycle(x);
    int q = cycle(y);
    id[p] = id[q];
}

ll kruskal(pair<ll, pair<int, int> > p[])
{
    int x, y;
    ll cost, min_Cost = 0;
    for(int i = 0;i < e ;++i)
    {
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        
        if(cycle(x) != cycle(y))
        {
            min_Cost += cost;
            join(x, y);
        }    
    }
    return min_Cost;
}

int main()
{
    int x, y;
    ll weight, cost, min_Cost;

    for(int i = 0;i < MAX;++i)
        id[i] = i;

    cin >> n >> e;

    for(int i = 0;i < e;++i)
    {
        cin >> x >> y >> weight;
        p[i] = make_pair(weight, make_pair(x, y));
    }
   
    sort(p, p + e);

    min_Cost = kruskal(p);

    cout << min_Cost << endl;
    
    return 0;
}