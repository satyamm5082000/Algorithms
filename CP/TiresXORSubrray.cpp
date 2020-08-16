#include<bits/stdc++.h>
using namespace std;

class trienode
{
public:
    trienode *left;
    trienode *right;
  
    
};

void insert(int x, trienode *head)
{
    trienode *start = head;

    for (int i = 31; i >= 0; i--)
    {
        int b = x & (1 << i);
     
        if (b == 0)
        {
            if (!start->left)
            {
                trienode *l=new trienode();
                start->left = l;
            }
            start = start->left;
        }
        else
        {
            if (!start->right)
            {
                trienode *r=new trienode();
                start->right = r;
            }
            start = start->right;
        }
     }
     

}

int MaxXORSubarray(trienode *head, int *arr, int n)
{
    int maxxor = INT_MIN,curxor=0;
    insert(curxor,head);
    for (int i = 0; i < n; i++)
    {
        curxor=curxor^arr[i];
        insert(curxor,head);
        int x=0;
        trienode *start = head;
        for (int j = 31; j >= 0; j--)
        {
            int b = curxor & (1 << j);
            if (b == 0)
            {
            
                if (start->right)
                {
                    x+= pow(2, j);
                    start = start->right;
                }
                else
                {
                    start = start->left;
                }
            }
            else
            {
                if (start->left)
                {
                    x += pow(2, j);
                    start=start->left;
                }
                else
                {
                    start = start->right;
                }
            }
        }
         if(x>maxxor)
            {
                maxxor=x;
            }
    }
    return maxxor;
}
int main()
{
    int arr[10] = {1,2,8,4};
    trienode *head=new trienode();
    int n=4;
    int k=15;
    
    int ans = MaxXORSubarray(head, arr, n);
    cout << ans << endl;
 
    
}  