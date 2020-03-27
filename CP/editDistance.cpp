
#include<bits/stdc++.h>
using namespace std;

int Lcs(char *s1,char *s2,int m,int n,int** out)
{
   if(m==0||n==0)
   return 0;
   
   if(out[m][n]>-1)
   return out[m][n];

   int max1;

   if(s1[0]==s2[0])
   max1=1+Lcs(s1+1,s2+1,m-1,n-1,out);
   else{
       int a=Lcs(s1+1,s2,m-1,n,out);
       int b=Lcs(s1,s2+1,m,n-1,out);
       max1=max(a,b);
   }
   out[m][n]=max1;

   return max1;
  

}

int  main()
{
    int m,n;
    cin>>m>>n;
    char s1[m],s2[n];
    cin>>s1>>s2;
    
    
    int **out=new int *[m+1];
    for(int i=0;i<=m;i++)
    {
        out[i]=new int[n+1];
        for(int j=0;j<=n;j++)
        {
            out[i][j]=-1;
        }
    }
    int lcs;
    lcs=Lcs(s1,s2,m,n,out);
    cout<<max(m,n)-lcs;
}