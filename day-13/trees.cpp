#include <bits/stdc++.h>
using namespace std;

class Node{
  int data;
  Node* left, *right;
  Node* createNode(int val){
    Node* newNode = new Node;
    newNode->data = val;
    newNode->left = newNode->right = nullptr;
    return newNode;
  }
  Node* minChildNode(Node* root){
    if(root->left != nullptr){
      root = minChildNode(root->left);
    }
    return root;
  }
public:
  Node* insertNode(Node* root, int val){
    if(root == nullptr){
      root = createNode(val);
      return root;
    } else if(root->data > val){
      root->left = insertNode(root->left, val);
    } else if(root->data < val){
      root->right = insertNode(root->right, val);
    }
  }
  
  Node* deleteNode(Node* root, int val){
    if(root == nullptr){
      return root;
    } else if(root->data > val){
      root->left = deleteNode(root->left, val);
    } else if(root->data < val) {
      root->right = deleteNode(root->right, val);
    } else{
      Node* foundNode = root;
      if(foundNode->left == nullptr){
        Node* temp = foundNode->right;
        delete foundNode;
        return temp;
      } else if(foundNode->right == nullptr){
        Node* temp = foundNode->left;
        delete foundNode;
        return temp;
      }
      Node* minChild = minChildNode(foundNode->right);
      foundNode->data = minChild->data;
      foundNode->right = deleteNode(foundNode->right, minChild->data);
    }
    return root;
  }
  Node* invert(Node* root){
    if(root != nullptr){
      Node* temp = root->left;
      root->left = root->right;
      root->right = temp;
      invert(root->left);
      invert(root->right);
    }
  }
  int height(Node* root){
    if(root == nullptr){
      return 0;
    }
    return max(height(root->left), height(root->right)) + 1;
  }
  void inorder(Node* root){
    if(root != nullptr){
      inorder(root->left);
      cout << root->data << " ";
      inorder(root->right);
    }
  }
};

int main(){
  Node* root = nullptr;
  root = root->insertNode(root, 10);root = root->insertNode(root, 1);
  root = root->insertNode(root, 20);root = root->insertNode(root, 15);
  root = root->insertNode(root, 50);
  root->inorder(root);
  root = root->deleteNode(root, 10);
  cout << "\nheight: " << root->height(root);
  cout << '\n';
  root->inorder(root);
  root = root->invert(root);
  cout << '\n';
  root->inorder(root);

  return 0;
}