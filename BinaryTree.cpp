#include <bits/stdc++.h>
using namespace std;
  class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int data){
        this->val = data;
        this->left = NULL;
        this->right = NULL;
    }
  };


// helper function or CORE LOGIC FOR BST CREATION

 Node* Insert_In_BST(Node* root , int data){
  
  // root create kr rhe h 
  if(root == NULL){
   root = new Node(data);
  }
  else{
    if(data < root->val){
        root->left = Insert_In_BST(root->left , data);
    }
    else{
        root->right = Insert_In_BST(root->right , data);
    }
  }

  return root;

 }


  // BST CREATION FROM A GIVEN ARRAY USING RECURSION

 void Create_BST(Node* &root){
    cout<<" Enter a val  ";
    int data;
    cin>>data;
 
   while(data != -1){
    root = Insert_In_BST(root , data); 
     cout<<endl<<" Enter a val  ";  
      cin>>data;
   }
 }


 // LEVEL ORDER TRAVERSAL
 void Level_order_traversal(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* front = q.front();
        q.pop();
        if(front == NULL){
            cout<<endl;

            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<front->val<<" ";
            if(front->left != NULL) q.push(front->left);
            if(front->right != NULL) q.push(front->right);
        }
    }
 }

int main(){
   Node* root = NULL;
   Create_BST(root);
   Level_order_traversal(root);
}