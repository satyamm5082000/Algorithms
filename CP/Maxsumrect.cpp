// #include<bits/stdc++.h>
// using namespace std;

// int  main()
// {
//    int m,n;
//    cin>>m>>n;
//    int ** in=new int*[m],**outp=new int*[m]; 
//  for(int i=0;i<m;i++)
//  {
//         in[i]=new int[n];
//         outp[i]=new int[n];
//      for(int j=0;j<n;j++)
//      {
//        cin>>in[i][j];
//        outp[i][j]=0;
//      }
//  }
//  outp[0][0]=in[0][0];
//  for(int i=1;i<m;i++)
//  {
//      outp[i][0]=in[i][0]+outp[i-1][0];

//  }
//  for(int j=1;j<n;j++)
//  {
//      outp[0][j]=in[0][j]+outp[0][j-1];

//  }
//   for(int i=1;i<m;i++)
//   {
//       for(int j=1;j<n;j++)
//       {
//         outp[i][j]=in[i][j]+outp[i-1][j]+outp[i][j-1];
//       }
//   }

//   int max=INT_MIN;
//   for(int i=0;i<m;i++)
//   {
//       for(int j=0;j<n;j++)
//       {
//         cout<<outp[i][j]<<" \t";
//         if(outp[i][j]>max)
//         max=outp[i][j];
//       }
//       cout<<endl;
//   }
  
//  cout<<max;





// }

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int m,n;
    cin>>m>>n;

    int ar[m][n];

    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            cin>>ar[i][j];
        }
    }

    int sumarr[m][n];
    int sum=0;

    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            sum=0;
            for (int k=i;k<m;k++)
            {
                for (int l=j;l<n;l++)
                {
                    sum+=ar[k][l];
                }
            }

            sumarr[i][j]=sum;
        }
    }

    sum=0;
    int h=0,g=0,ma=INT_MIN;

    for (int i=0;i<m-1;i++)
    {
        for (int j=0;j<n-1;j++)
        {   
            for (int k=i;k<m;k++)
            {
                for (int l=j;l<n;l++)
                {
                    //cout<<k<<" "<<l<<endl;
                    if (i==k&&j==l)
                    continue;
                    sum=0;
                    h=0;
                    g=0;
                    sum=sum+sumarr[i][j];
                    //cout<<sum<<" ";
                    if (l<n-1)
                    {
                        h=1;
                        sum=sum-sumarr[i][l+1];
                    }
                    //cout<<sum<<" ";
                    if (k<m-1)
                    {
                        g=1;
                        sum=sum-sumarr[k+1][j];
                    }
                    //cout<<sum<<" ";
                    if (h==1&&g==1)
                    {
                        sum=sum+sumarr[k+1][l+1];
                    }
                    //cout<<sum<<endl;

                    ma=max (ma,sum);
                }
            }

            
        }
    }

    cout<<ma<<endl;

    
}