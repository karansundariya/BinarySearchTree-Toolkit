📘 Binary Search Tree (BST) Implementation in C++
This C++ program demonstrates a comprehensive implementation of Binary Search Tree (BST) operations including:

Insertion (recursive and helper-based)

Search

Deletion

Level-order traversal

Conversion of a sorted linked list to a height-balanced BST

📂 Features
✅ Create BST from user input (until -1 is entered)
🔍 Search a value in BST
❌ Delete a node from BST (covers all 4 cases)
➕ Insert a node into the BST (helper based)
🌳 Convert a sorted Linked List to Balanced BST
🔄 Level Order Traversal for printing BST level-wise

🔧 Code Structure
🔹 class Node
Represents a node in a Binary Search Tree.

cpp
Copy
Edit
class Node {
public:
    int val;
    Node* left;
    Node* right;
};
🔹 class ListNode
Represents a singly linked list node.

cpp
Copy
Edit
class ListNode {
public:
    int val;
    ListNode* next;
};
🔹 Core Functions

Function Name	Description
Insert_In_BST	Inserts a value recursively into BST
Create_BST	Creates BST using user input
Level_order_traversal	Prints BST level by level
Search_IN_BST	Searches for a value in BST
Delete_In_BST	Deletes a node from BST
Add_IN_BST	Adds a node using a helper function
LinkList_to_BST	Converts sorted linked list to balanced BST
🧪 Sample Execution Flow
User is prompted to enter values to create BST.

The tree is printed level-wise.

User searches for a value.

User deletes a node from the BST.

Updated tree is shown.

User inserts another node into the BST.

Updated tree is printed again.

A sorted linked list is created, and converted to a balanced BST.

The new BST is printed level-wise.

📌 Important Notes
Pass Node*& root by reference when modifying BST in-place.
Head pointer of LinkedList must be passed by reference during conversion to BST.
The Delete_In_BST() function handles all four cases:
Leaf node
Node with one child (left or right)
Node with two children (uses maximum from left subtree)

🛠️ How to Run
bash
Copy
Edit
g++ filename.cpp -o bst
./bst
📷 Sample Output
text
Copy
Edit
Enter a val: 10
Enter a val: 5
Enter a val: 15
Enter a val: -1

10 
5 15 

Enter Val to be searched in BST: 5
target is found in BST

Enter target to delete From BSt: 5
10 
15 

Enter Target to enter in BST: 8
10 
8 15 

BST from Sorted List:
3
1 4
2 5
🧑‍💻 Author
Karan Sundariya
3rd-year CSE IIIT-BH | Passionate about Data Structures and Algorithms
