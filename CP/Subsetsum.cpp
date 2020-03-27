#include<bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin>>n;
    int items[n];
    for(int i=0;i<n;i++)
    {
        cin>>items[i];
    }
    int sum;
    cin>>sum;
    bool dp[n+1][sum+1];

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(j==0)
            dp[i][j]=true;
            else if(i==0||j==0)
            dp[i][j]=false;
            else if(items[i-1]<=j)
            dp[i][j]=dp[i-1][j]||dp[i-1][j-items[i-1]];
            else
            {
                dp[i][j]=dp[i-1][j];
            }
            

        }
    }
    if(dp[n][sum]==true)
    cout<<"Yes";
    else
    {
        cout<<"No";
    }
    
}
// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {

//     int n;
//     cin>>n;
//     int items[n];
//     for(int i=0;i<n;i++)
//     {
//         cin>>items[i];
//     }
//     int sum;
//     cin>>sum;
//     bool dp[2][sum+1];
//    int flag=1;
//    for(int i=0;i<=sum;i++)
//    {
//        dp[flag^1][i]=false;
//    }
//     for(int i=0;i<=n;i++)
//     {
//         for(int j=0;j<=sum;j++)
//         {
          
//             if(items[i-1]<=j)
//             dp[flag][j]=dp[flag^1][j]||dp[flag^1][j-items[i-1]];
//             else
//             {
//                 dp[flag][j]=dp[flag^1][j];
//             }
            

//         }
//     }
//     if(dp[n][sum]==true)
//     cout<<"Yes";
//     else
//     {
//         cout<<"No";
//     }
    
// }