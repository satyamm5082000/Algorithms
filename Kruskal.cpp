#include<bits/stdc++.h>
using namespace std;

int checkcycle(int x,int id[1000])
{
    while(id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void markvertices(int x, int y,int id[1000])
{
    int p = checkcycle(x,id);
    int q = checkcycle(y,id);
    id[p] = id[q];
}

long long kruskal(pair<long long, pair<int, int> > p[],int nodes,int edges,int id[1000])
{
    int x, y;
    long long cost, minimumCost = 0;
    for(int i = 0;i < edges;++i)
    {
        
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        
        if(checkcycle(x,id) != checkcycle(y,id))
        {
            minimumCost += cost;
            cout<<x<<" "<<y<<" "<<cost<<"\n";
            markvertices(x, y,id);
        }    
    }
    return minimumCost;
}

int main()
{
    int x, y;
    long long weight, cost, minimumCost;
    int id[1000],nodes,edges;
    pair <long long, pair<int, int> > p[1000];


    for(int i = 0;i < 1000;++i)
        id[i] = i;

    cin >> nodes >> edges;

    for(int i = 0;i < edges;++i)
    {
        cin >> x >> y >> weight;
        p[i] = make_pair(weight, make_pair(x, y));
    }
    
    sort(p, p + edges);
    cout<<"Minimum spanning tree: \n";
    minimumCost = kruskal(p,nodes,edges,id);
    cout << "Minimum cost :"<<minimumCost << endl;
    return 0;
}