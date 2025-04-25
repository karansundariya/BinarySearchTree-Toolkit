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


  // LinkList class
  class ListNode{
    public:
    int val;
    ListNode* next;
    ListNode(int data){
      this->val = data;
      this->next = NULL;
    }
  };


// helper function or CORE LOGIC FOR BST CREATION

 Node* Insert_In_BST(Node* root , int data){
  
  // root create kr rhe h 
  // First Node Creation
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

   // Yaha root ko ByReference hi pass krna h ye galti Hogi 
 void Create_BST(Node*& root){
    cout<<" Enter a val  ";
    int data;
    cin>>data;
 
   while(data != -1){

    root = Insert_In_BST(root , data); 
    // 

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

  // Functuion for searching in BST 
   bool Search_IN_BST(int target , Node* root){
    if(root == NULL ) return false;
    if(root->val == target) return true;

  return root->val > target ? Search_IN_BST(target , root->left) : Search_IN_BST(target , root->right);
   }

  // Function for FInding Max From a BSt 
  int max_from_BST(Node* root){
    Node* temp = root;
    while(temp->right != NULL) temp = temp-> right ;

    return temp->val;
  }

  // Function for Finding min From BST
  int min_from_BST(Node* root){
    Node* temp = root;

    while(temp->left != NULL) temp = temp->left ;

    return temp->val;
  }
   
   
   // Function for deleting a node in BSt
       // FInd kremge or jese hi mil gaya 4 cases banenge 
   Node* Delete_In_BST(Node* root , int target){
    if(root == NULL) return NULL;

    // Find Target then delete it

    if(root->val == target){
        // 4 cases
        // 1st CASE
      if(root->left == NULL && root->right == NULL){
        delete(root);
        return NULL;
      }

      // case 2
      else if(root->left == NULL && root->right != NULL){
        Node* rightSubTree = root->right ;
        delete (root);
        return rightSubTree;
      }

      // case 3 
      else if(root->left != NULL && root->right == NULL){
        Node* leftSubTree = root->left;
        delete(root);
        return leftSubTree;
      }  

      // Case 4

      else {
        // LeftSubtree se MAX ya RightSubTree ka MIN find kro 
            // Replace kro root ko us sey  
            // Delete kro jis se replace kiyo ho 
        int maxi = max_from_BST(root->left);

        root->val = maxi;

        root->left = Delete_In_BST(root->left , maxi);

        return root;
      }

    }

    else if(root->val > target) {
        root->left = Delete_In_BST(root->left , target);
    }
    else{
        root->right = Delete_In_BST(root->right , target);
    }

    return root;
   }



   // Recursive function for adding Node in BST helper Function

   void Insert_IN_BST_HELPER(Node* root , int target){

    if(root->val > target){
      if(root->left == NULL ){
        Node* newnode = new Node(target);
        root->left = newnode;
        return ;
      }
     Insert_IN_BST_HELPER(root->left , target);
    }

     else{
        if(root->right == NULL){
             Node* newnode = new Node(target);
             root->right =  newnode;
             return ;
        }
        Insert_IN_BST_HELPER(root->right , target);
      }

      return ;
    }
   

   // Function for Adding a NODE in BST 
  void Add_IN_BST(Node* &root , int target){
   if(root == NULL) {
    root = new Node(target);
    return ;
   }

   else Insert_IN_BST_HELPER(root , target);

   return ;
  }

  // Making link list to balanced BST
  // HEAD KO BYREF PASS KRNA H 
       // YEHI GALTI HOGI
      // Base case n ==0 return NULL
    // LNR 
       // leftcall(Head , n/2);
       // CurrProcess 
                   // Make root = new Node(head->val)

          // Head ko aage badana h qki rightSubtree nikala h 
        // RightCall(Head , n - n/2 -1);
    
  Node* LinkList_to_BST(ListNode* &head , int n){

    if(n <= 0 || head== NULL ) return NULL;

    Node* leftSubTree = LinkList_to_BST(head , n/2);

    Node* root = new Node(head->val);

     root->left = leftSubTree;
   
 // UPDATE HEAD qki ab RIGHT SUBTREE banaana h 
     head = head->next;
    Node* rightSubTree = LinkList_to_BST(head , n - n/2 -1);
    root->right = rightSubTree;

    return root;
  }




int main(){
    // Yaha galti hogi NULL krna h root ko pahle 
   Node* root = NULL;

   Create_BST(root);

   Level_order_traversal(root);

   // Sarching In BST
   cout<<endl;
   cout<<" Enter Val to be searched in BST ";
   int target;
   cin>>target;
  if (Search_IN_BST(target ,  root) ) cout<<" target is found in BST ";
  else cout<<" Target Not found in BST ";

  // Function for Deleting a NODE from BST
    cout<<endl<<" Enter target to delete From BSt ";
    cin>>target;
  Delete_In_BST(root , target);

  Level_order_traversal(root);

  // Function for adding a node in BST

  cout <<" Enter Target to enter in BST ";
  cin>>target;
  Add_IN_BST(root , target);

  Level_order_traversal(root);



cout<<endl<<" BST from Sorted List"<<endl;
  // Making a Sorted LINKLIST 
    // then Making BST from This Sorted LINKList
  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);

  // Size of Given List is 5 
  Node* newRoot = LinkList_to_BST(head , 5);
  Level_order_traversal(newRoot);



}