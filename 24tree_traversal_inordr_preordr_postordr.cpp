#include <iostream>
using namespace std;

// Binary Tree Node structure
struct Node
{
  int data;
  Node *left;
  Node *right;

  Node(int val)
  {
    data = val;
    left = right = nullptr;
  }
};

// Inorder Traversal (Left, Root, Right)
void inorder(Node *root)
{
  if (root == nullptr)
    return;
  inorder(root->left);       // Traverse left subtree
  cout << root->data << " "; // Visit root node
  inorder(root->right);      // Traverse right subtree
}

// Preorder Traversal (Root, Left, Right)
void preorder(Node *root)
{
  if (root == nullptr)
    return;
  cout << root->data << " "; // Visit root node
  preorder(root->left);      // Traverse left subtree
  preorder(root->right);     // Traverse right subtree
}

// Postorder Traversal (Left, Right, Root)
void postorder(Node *root)
{
  if (root == nullptr)
    return;
  postorder(root->left);     // Traverse left subtree
  postorder(root->right);    // Traverse right subtree
  cout << root->data << " "; // Visit root node
}

int main()
{
  // Create a simple binary tree
  //        1
  //       / \
    //      2   3
  //     / \   
    //    4   5

  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);

  // Inorder Traversal: Left, Root, Right
  cout << "Inorder Traversal: ";
  inorder(root);
  cout << endl;

  // Preorder Traversal: Root, Left, Right
  cout << "Preorder Traversal: ";
  preorder(root);
  cout << endl;

  // Postorder Traversal: Left, Right, Root
  cout << "Postorder Traversal: ";
  postorder(root);
  cout << endl;

  return 0;
}
