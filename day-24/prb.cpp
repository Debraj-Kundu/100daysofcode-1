#include <bits/stdc++.h>
using namespace std;

class Node{
public:
  int data;
  Node* left, *right;
  Node(int data){
    this->data = data;
    left = right = nullptr;
  }
};

int maxNode(Node* root){
  int left, right, rootVal, max_ele = INT_MIN;
  if(root){
    rootVal = root->data;
    left = maxNode(root->left);
    right = maxNode(root->right);
    if(left > right)
      max_ele = left;
    else 
      max_ele = right;
    if(rootVal > max_ele)
      max_ele = rootVal;
  }
  return max_ele;
}

int main(){
  Node* root = nullptr;
  root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->right = new Node(6);
  root->left->left = new Node(7);
  root->right->right = new Node(4);
  root->right->left = new Node(5);
  cout << maxNode(root);

  return 0;
}