#include<bits/stdc++.h>
using namespace std;

void multiply(int a[2][2],int m[2][2])
{
    int x=a[0][0]*m[0][0] + a[0][1]*m[1][0];
    int y=a[0][0]*m[0][1] + a[0][1]*m[1][1];
    int z=a[1][0]*m[0][0] + a[1][1]*m[1][0];
    int w=a[1][0]*m[0][1] + a[1][1]*m[1][0];

    a[0][0]=x;
    a[0][1]=y;
    a[1][0]=z;
    a[1][1]=w;
}

void power(int a[2][2],int n)
{
    if(n==0||n==1)
    return ;
    power(a,n/2);

    multiply(a,a);

    if(n%2!=0)
    {
        int m[2][2]={{1,1},{1,0}};
        multiply(a,m);
    }
}

int fib(int n)
{
    if(n==0)
    return 0;

    int a[2][2]={{1,1},{1,0}};

    power(a,n-1);

    return a[0][0];

}

int main()
{
    int n;
    cin>>n;
    cout<<fib(n)<<endl;
    int n1,m;
    cin>>n1>>m;
    cout<<(fib(m+1)-fib(n1+2);
}