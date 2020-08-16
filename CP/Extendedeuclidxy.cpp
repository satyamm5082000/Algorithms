#include<bits/stdc++.h>
using namespace std;
typedef pair<pair<int,int>,int>ppiii;

ppiii extendedeuclid(int a,int b){

    if(b==0)
    {
        ppiii ans1;
        ans1.first.first=1;
        ans1.first.second=0;
        ans1.second=a;
        return ans1;
    }

    ppiii s1=extendedeuclid(b,a%b);
    ppiii a1;
    a1.first.first=s1.first.second;
    a1.first.second=s1.first.first-s1.first.second*(a/b);
    a1.second=s1.second;
    return a1;
}

int sachinandvarun(int a,int b,int d)
{
       int n;
       int gcd=extendedeuclid(a,b).second;
       int a1=a/gcd,b1=b/gcd,d1=d/gcd;

       int mod=extendedeuclid(b1,a1).first.first;
       mod=(mod%a1+a1)%a1;

       if(d%gcd!=0){
           return 0;
       }

       if(d==0)
       {
           return 1;
       }

       int y1=(d1%a1*mod)%a1;

        if(d1/b1>y1)
        {
            n=(d1/b1-y1)/a1+1;
        }
        else {
            n=0;
        }
       return n;


}

int main()
{
    // int a,b;
    // cin>>a>>b;
    // ppiii ans=extendedeuclid(max(a,b),min(a,b));
    // cout<<"x="<<ans.first.first<<endl;
    // cout<<"y="<<ans.first.second<<endl;
    // cout<<"gcd="<<ans.second<<endl;

    int a,b,d;
    cin>>a>>b>>d;

    int noofpairs=sachinandvarun(a,b,d);
   cout<<noofpairs;

   

}