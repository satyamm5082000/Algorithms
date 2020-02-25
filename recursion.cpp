#include<bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int sum_digit(int x)
{
    int s,rem;
     if(x==0)
    return 0;

    rem=x%10;
    s=sum_digit(x/10)+rem;
    return s;
   
}
int main()
{
   FASTIO;
    int n,sum;
    cin>>n;
    sum=sum_digit(n);
    cout<<"sum :"<<sum;
}