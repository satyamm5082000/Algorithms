// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin>>n;
//     int Eulertotient[1000+1];
//     for(int i=0;i<=1000;i++)
//     {
//         Eulertotient[i]=i;
//     }
//     for(int i=2;i<=1000;i++)
//     {
//         if(Eulertotient[i]==i){
//             Eulertotient[i]=i-1;
//             for(int j=2*i;j<=1000;j=j+i)
//             {
//                 Eulertotient[j]=(Eulertotient[j]*(i-1))/i;
//             }
//         } 
//     }
//  cout<<Eulertotient[n]<<endl;
   
// }
