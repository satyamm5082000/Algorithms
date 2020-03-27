#include <bits/stdc++.h>
using namespace std;

// int Minimumcost(int **in,int l,int h,int l1,int h1,int **outp)
// {
//     if(l==l1&&h==h1)
//     return in[l][h];

//      if(l>l1||h>h1)
//      return INT_MAX;
//      if(outp>0)
//      return outp[l][h];

//      int a=Minimumcost(in,l,h+1,l1,h1,outp);
//      int b=Minimumcost(in,l+1,h,l1,h1,outp);
//      int c=Minimumcost(in,l+1,h+1,l1,h1,outp);

//       int r=in[l][h];

//      if(a<b&&a<c)
//      r+=a;
//      else if(b<a&&b<c)
//      r+=b;
//      else r+=c;
//      outp[l][h]=r;
//       return r;
// }
// int min1(int a,int b,int c)
// {
//   if(a<b&&a<c)
//       return a;
//       else if(b<a&&b<c)
//       return b;
//       else return c;
// }
// int minimumcost(int **in,int l,int h,int l1,int h1)
// {
//   int **out=new int* [l];
//   for(int i=0;i<l;i++)
//   {
//     out[i]=new int[h];
//   }
//     out[l-1][h-1]=in[l-1][h-1];

//   for(int i=h-2;i>=0;i--)
//   {
//     out[l-1][i]=out[l-1][i+1]+in[l-1][i];
//   }

//   for(int i=l-2;i>=0;i--)
//   {
//     out[i][h-1]=out[i+1][h-1]+in[i][h-1];
//   }
//   for(int i=l-2;i>=0;i--)
//   {
//     for(int j=h-2;j>=0;j--)
//     {
//       out[i][j]=in[i][j]+min1(out[i+1][j+1],out[i+1][j],out[i][j+1]);
//     }
//   }

//   return out[l1][h1];

// }

int magicgrid(int **in, int l1, int h1)
{
  int **out = new int *[l1];
  for (int i = 0; i < l1; i++)
  {
    out[i] = new int[h1];
  }
  out[l1 - 1][h1 - 1] = 1;
  for (int i = l1 - 2; i >= 0; i--) //up
  {
    if (out[i + 1][h1 - 1] <= in[i][h1 - 1])
      out[i][h1 - 1] = 1;
    else
      out[i][h1 - 1] = out[i + 1][h1 - 1] - in[i][h1 - 1];
  }
  for (int i = h1 - 2; i >= 0; i--) //left
  {
    if (out[l1 - 1][i + 1] <= in[l1 - 1][i])
      out[l1 - 1][i] = 1;
    else
      out[l1 - 1][i] = out[l1 - 1][i + 1] - in[l1 - 1][i];
  }
  for (int i = l1 - 2; i >= 0; i--)
  {
    for (int j = h1 - 2; j >= 0; j--)
    {
      int x = min(out[i + 1][j], out[i][j + 1]);
      if (x <= in[i][j])
        out[i][j] = 1;
      else
        out[i][j] = x - in[i][j];
    }
  }

  for (int i = 0; i < l1; i++)
  {
    for (int j = 0; j < h1; j++)
    {
      cout << out[i][j] << " ";
    }
    cout << endl;
  }
  return out[0][0];
}
// int minrec (int** ar,int si,int ei,int m,int n)
// {
//     if (si==m-1&&ei==n-1)
//     return 1;
    
//     if ((si==m-1 && ei==n-2) || (si==m-2 && ei==n-1))
//     return 1;

//     if(si>m||ei>n)
//     return INT_MAX;
    
//     int op1 = minrec (ar,si+1,ei,m,n)-ar[si+1][ei];
//     int op2 = minrec (ar,si,ei+1,m,n)-ar[si][ei+1];
    
//     int t = min (op1,op2);
    
//     if (t<0)
//     t=1;
//     //cout<<t;
//     return t;
// }
int main()
{
  int n, m;
  cin >> n >> m;
  int **in = new int *[n], **outp = new int *[n];
  for (int i = 0; i < n; i++)
  {
    in[i] = new int[m];
    outp[i] = new int[m];
    for (int j = 0; j < m; j++)
    {
      cin >> in[i][j];
      outp[i][j] = 0;
    }
  }
  int l,h,l1, h1;
  cin >> l>>h>>l1 >> h1;

  int min = magicgrid(in, l1, h1);
  cout << min;
  
}
