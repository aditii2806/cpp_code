#include<iostream>
using namespace std;
#include<queue>
class node
{
    public:
    int data;
    node* left;
    node* right;

    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
void insertBST(node* &root,int val){
    if(root==NULL){
        root=new node(val);
        return;
    }
    if(val<root->data){
        insertBST(root->left,val);
    }
    else
    {
        insertBST(root->right,val);
    }
}
void input(node* &root){
    int val;
    cout<<" Enter values :  ";
    cin>>val;
    while(val!=-1){
        insertBST(root,val);
        cin>>val;
    }
}
bool search(node* root,int val){
    if(root==NULL){
        return false;
    }
    if (root->data==val)
    {
        return true;
    }
    if(val<root->data){
        return search(root->left,val);
    }
    else
    {
        return search(root->right,val);
    }
}
node* searchk(node* root,int k1){
    node* temp;
    if(root->data==k1){
        temp=root;
    }
    else if(root->data>k1){
        temp=searchk(root->left,k1);
    }
    else{
        temp=searchk(root->right,k1);
    }
    return temp;

}
bool is_ancestor(node* &root,int k1,int k2){
   node* temp=searchk(root,k1);
   return search(temp,k2);
}
int main(){
    node* root=NULL;
    input(root);
    int k1,k2;
    cout<<endl<<" k1 : ";
    cin>>k1;
    cout<<" k2 : ";
    cin>>k2;
    cout<<" is k1 ancestor of k2 : "<<is_ancestor(root,k1,k2);
    return 0;
}