#include<bits/stdc++.h>
using namespace std;
#define v 5
int min1(int pr[],bool m[])
{
   int mkey = INT_MAX;
   int minimum;
   for(int k=0;k<v;k++)
   {
      if(m[k]==false&&pr[k]<mkey)
      {
          mkey=pr[k];
          minimum=k;
      }
   }
   return minimum;
}
void displaymst(int mst[],int grp[v][v])
{
   cout<<"Edges\t weights\n";
    for (int i=1; i<v; i++)  
        cout<<mst[i]<<" - "<<i<<" \t"<<grp[i][mst[i]]<<" \n";  
}
void primmst(int prim[v][v])
{
  int mst[v];
  int key[v];
  bool check1[v];

  for(int i=0;i<v;i++)
  {
      key[i]=INT_MAX;
      check1[i]=false;
  }
   key[0]=0;
   mst[0]=-1;
   for(int j=0;j<v-1;j++)
   {
      int x=min1(key,check1);
      
      check1[x]=true;

      for(int i=0;i<v;i++)
      {
          if(prim[x][i]&&check1[i]==false&&prim[x][i]<key[i])
          {
              mst[i]=x;
              key[i]=prim[x][i];
          }
      }  
   }
   displaymst(mst,prim);

}

int main()
{
    
    int grp[v][v]= {{0,2,0,6,0},
                    {2,0,3,8,5},
                    {0,3,0,0,7},
                    {6,8,0,0,9},
                    {0,5,7,9,0}};
   
primmst(grp);


}
