#include<bits/stdc++.h>
using namespace std;
int partition_pivot(int arr[],int x,int y)
{
   int pivot_element = arr[y];
   int i=x-1;

   for(int j=x;j<y;j++)
   {
       if(arr[j]<=pivot_element)
       {
           i++;
           swap(arr[i],arr[j]);
       }

   }
swap(arr[i+1],arr[y]);
return i+1;
}

int partition_rand(int arr[],int l,int h)
{
   int random1= l + rand()% (h-l);
//cout<<random1<<" ";
   swap(arr[random1],arr[h]);

   int p = partition_pivot(arr,l,h);
   
   return p;
}

void quick_Sort(int arr[],int low,int high){
if(low<high)
{
    int x= partition_rand(arr,low,high);
    quick_Sort(arr,low,x-1);
    quick_Sort(arr,x+1,high);

}
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    cout<<"enter the array"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    quick_Sort(arr, 0, n - 1); 
    cout<<"Array after sorting :"<<endl;
    for(int i=0;i<n;i++)
   {
    cout<<arr[i]<<" \n";
   }
    
}

