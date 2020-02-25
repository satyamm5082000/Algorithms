#include<bits/stdc++.h>
using namespace std;

void buildsegmenttreee(int ar[],int STree[],int s,int e,int l)
{
   

    if(s==e){
    STree[l]=ar[s];
    return;
    }
    int mid=(s+e)/2;

    buildsegmenttreee(ar,STree,s,mid,2*l);
    buildsegmenttreee(ar,STree,mid+1,e,2*l+1);
    
        STree[l]=STree[2*l]+STree[2*l+1];
            // cout<<2*l<<" "<<2*l+1<<" "<<STree[2*l]<<" "<<STree[2*l+1]<<" "<<STree[l]<<"\n";


}


int main()
{
    int ar[12]={1,2,3,4,5,6,7,8,9,10,11,12};

    int STree[24];

    buildsegmenttreee(ar,STree,0,11,1);

    for(int i=1;i<24;i++)
    {
        cout<<STree[i]<<" ";
    }
    //cout<<STree[12]<<" "<<STree[13]<<" "<<STree[14]<<" "<<STree[15]<<STree[18]<<" "<<STree[19];
}