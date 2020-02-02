#include <bits/stdc++.h>

using namespace std;
int find(string s,struct node * root,int wordpre);
void insert(string s, struct node * root);
struct node{
    
    struct node * arr[26];
    int flag;
};
struct node * createnode(){
    struct node* root=(struct node*)malloc(sizeof(struct node*));
    for(int i=0;i<26;i++)
        {
            root->arr[i]=NULL;
            
        }
        //root->flag=0;
    return root;
}
void insert(string s, struct node * root){
    int f=0;
    if(root->arr[s[0]-'a']!=NULL)
     f=find(s,root,1);
    
    if(f)
    return;
    else{
        int i=0;
        int n=s.length();
        while(i<n && root->arr[s[i]-'a']!=NULL)
         {
             if(root->arr[s[i]-'a']->flag==1)
                root->arr[s[i]-'a']->flag=2;
             root=root->arr[s[i++]-'a'];
             
             
         }
         
        for(int j=i;j<s.size();j++)
        {
            if(j!=(s.size()-1))
                {  struct node * nroot=createnode();
                    root->arr[s[j]-'a']=nroot;
                    root->arr[s[j]-'a']->flag=0;
                }
            else{
                 struct node * nroot=createnode();
                    root->arr[s[j]-'a']=nroot;
                root->arr[s[j]-'a']->flag=1;
            }
                
            
        }
    }
}
int find(string s,struct node * root,int wordpre){
   int n=s.length();
   
   int fl=0;
   
   if(root->arr[s[0]-'a']==NULL)
   return 0;
   for(int i=0;i<n;i++){
       
       if(i!=n-1){
           //cout<<"fewf "<<s[i]<<endl;
           if(root->arr[s[i]-'a']==NULL)
            return 0;
       }
       
       else{
           
           if(root->arr[s[i]-'a']==NULL)
           return 0;
           if(root->arr[s[i]-'a']!=NULL){
               if(root->arr[s[i]-'a']->flag==2)
               return 1;
               
                   if(root->arr[s[i]-'a']->flag==wordpre)
                   return 1;
                   else 
                   return 0;
              
               
               
           }
           
       }
       root=root->arr[s[i]-'a'];
   }
   return 0;
    
}

void delet(string s, struct node * root){
    int f=find(s,root,1);
    
    if(f){
        int n=s.size();
        struct node * cp=root;
        int i=0;
        while((root->arr[s[i]-'a']->flag==2 || root->arr[s[i]-'a']->flag==0) && i!=n-1){
           if(i!=0)
           cp=cp->arr[s[i-1]-'a'];
           root=root->arr[s[i]-'a'];
           i++;
        }
        if(i==n-1){
            if(root->arr[s[i]-'a']->flag==2)
            root->arr[s[i]-'a']->flag=0;
            
        }
        if(root->arr[s[i]-'a']->flag==1)
         cp->arr[s[i-1]]=NULL;
        
        
    }
    return;
}
int main() {
    // cout<<"Hello World";
    

    
    
    
    struct node* root =createnode();
    for(int i=0;i<3;i++){
        string s;
        cin>>s;
    insert(s,root);
   // cout<<find(s,root,1)<<endl;;
    }
    
    
    
    
    return 0;
}