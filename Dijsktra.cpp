#include<bits/stdc++.h>
using namespace std;

int minimundist(int *dis,bool *ch,int v)
{ 
    int min=INT_MAX,m_index;
    for(int i=0;i<v;i++)
    {
        if(ch[i]==false && dis[i]<=min)
        {
            min=dis[i];
            m_index=i;  
        }
    }
    return m_index;
}
void display(int *distance,int v)
{
    cout<<"vertex \t shortest distance from source(0)\n";
    for(int i=0;i<v;i++)
    {
        cout<<i<<"\t"<<distance[i]<<"\n";
    }
}
void dijsktra(int g[][],int src,int v)
{
   int d[v];
   bool check[v];

   for(int i=0;i<v;i++)
   {
       d[i]=INT_MAX;
       check[i]=false;
   }

   d[src]=0;

   for(int j=0;j<v-1;j++)
   {
       int u;
       u=minimundist(d,check,v);
  //cout<<u<<" ";
       check[u]=true;
       for(int i=0;i<v;i++)
       {
       if(!check[i]&&d[u]!=INT_MAX  && g[u][i]&&d[u]+g[u][i]<d[i])
       d[i]=d[u]+g[u][i];   
       }
   }
   display(d,v);
}
int main()
{
    int v;
    cout<<"No. of vertices:";
    v=6;
         int grph[6][6];
    // int grph[v][v]={ { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
	// 					{ 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
	// 					{ 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
	// 					{ 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
	// 					{ 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
	// 					{ 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
	// 					{ 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
	// 					{ 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
	// 					{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

     int edges,x,y,w;
     cin>>edges;
     for(int  i=0;i<edges;i++)
     {
         cin>>x>>y>>w;
         grph[x][y]=w;
         grph[y][x]=w;
     }

    dijsktra(grph,0,v);

    return 0;
}