#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007

vector<int> sieve(int n)
{
    bool sieve1[n+1];
    for(int i=0;i<=n;i++)
    {
        sieve1[i]=true;
    }
    sieve1[0]=false;
    sieve1[1]=false;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(sieve1[i]){
        for(int j=i*i;j<=n;j+=i)
        {
            sieve1[j]=false;
        }
        }
    }
    vector<int>primes;
    primes.push_back(2);
    for(int  i=3;i<=n;i+=2)
    {
        if(sieve1[i])
        {
            primes.push_back(i);
        }
    }
  return primes;
}

ll divisors(int n,vector<int> primes)
{
    ll ans=1;
    for(int i=0;primes[i]<=n;i++)
    {
        int p=0,k=primes[i];
      while(n/k!=0)
      {
          p+=n/k;
          k=k*k;
      }
      //ans=(ans*((p+1)%MOD)%MOD)%MOD;
      ans*=(p+1);
    }
    return ans%MOD;
}


int main()
{
    int n;
    cin>>n;
    vector<int>primes=sieve(n);
    cout<<divisors(n,primes);
}

