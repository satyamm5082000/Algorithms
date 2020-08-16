#include<bits/stdc++.h>
using namespace std;

class trienode
{
public:
    trienode *childs[26];
    int wieght;
    bool isleaf;
    trienode()
    {
        for(int i=0;i<26;i++)
        {
            childs[i]=NULL;
        }
        wieght=0;
        isleaf=false;
    }

  
    
};

void insert(string x, trienode *head,int wieght)
{
    if(x.empty())
    {
        head->isleaf=true;
        return;
        
    }
    trienode *start,*curr=head;
    int in=x[0]-'a';
    if(curr->childs[in]){
        start=curr->childs[in];
    }
    else{
        start=new trienode();
        curr->childs[in]=start;
    }

    if(curr->wieght<wieght){
        curr->wieght=wieght;
        //cout<<in<<" "<< curr->wieght<<endl;
    }
    insert(x.substr(1),start,wieght);
}

int SEarchweight(trienode *head, string s)
{
    int Bweight=-1;
    trienode *curr=head;
   for(int i=0;i<s.length();i++){
       int in=s[i]-'a';
       trienode *start=curr->childs[in];
       if(start)
       {
          curr=start;
          Bweight=start->wieght;
       }
       else{
           return -1;
       }
   }
   return Bweight;
}
void displayWords(trienode* curr,string str,string str1)
{
    if(curr->isleaf)
    {
         str1 += '\0';
        cout<<str1<<endl;
        
    }
    for(int i=0;i<26;i++)
    {
        if(curr->childs[i])
        {
        str1 +=i+'a';
        displayWords(curr->childs[i],str,str1);
        str1=str;
        }
    }
}

void HelpPradyumn(trienode *head,string str)
{
  trienode *curr=head;
      for(int i=0;i<str.length();i++){
       int in=str[i]-'a';
       trienode *start=curr->childs[in];
       if(start)
       {
          curr=start;
       }
   }
   displayWords(curr,str,str);
   
}

int main()
{
    string arr[10] = {"ball","band","cap","cook","priya","sit","pen","pick","land","let"};
    int weights[10]={10,26,35,12,11,5,13,20,15,6};
    trienode *head=new trienode();
    int n=10;
    for (int i = 0; i < n;i++)
    {
       // cout<<arr[i]<<weights[i];
        insert(arr[i], head,weights[i]);
    }
    string str="ba";
    int ans=SEarchweight(head,str);
    cout<<ans;

    HelpPradyumn(head,str);
}  