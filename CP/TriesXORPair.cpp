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

int MaxXORPair(trienode *head, int *arr, int n)
{
    int maxxor = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int x = arr[i];
        trienode *start = head;
        int curxor = 0;

        for (int j = 31; j >= 0; j--)
        {
            int b = x & (1 << j);
            if (b == 0)
            {
            
                if (start->right)
                {
                    curxor += pow(2, j);
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
                    curxor += pow(2, j);
                    start=start->left;
                }
                else
                {
                    start = start->right;
                }
            }
        }
         if(maxxor<curxor)
            {
                maxxor=curxor;
            }
    }
    return maxxor;
}
int main()
{
    int arr[10] = {1, 2, 5, 7, 6, 10, 15, 16, 11, 12};
    trienode *head=new trienode();
    int n=10;
    for (int i = 0; i < n;i++)
    {
        insert(arr[i], head);
    }
    int ans = MaxXORPair(head, arr, n);
    cout << ans << endl;
}  