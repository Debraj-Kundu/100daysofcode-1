#include <bits/stdc++.h>
using namespace std;

class Node{
  int diameterHelper(Node* root){
    if(root == nullptr){
      return 0;
    }
    return max(diameterHelper(root->left), diameterHelper(root->right))+1;
  }
public:
  int data;
  Node* left, *right;
  Node* createNode(int val){
    Node* newNode = new Node;
    newNode->data = val;
    newNode->left = newNode->right = nullptr;
    return newNode;
  }

  void levelOreder(Node* root){
    queue<Node*> qu;
    qu.push(root);
    while(!qu.empty()){
      Node* temp = qu.front();
      cout << temp->data << " ";
      qu.pop();
      if(temp->left != nullptr){
        qu.push(temp->left);
      }
      if(temp->right != nullptr){
        qu.push(temp->right);
      }
    }
  }

  void reverseLevelOreder(Node* root){
    queue<Node*> qu;
    stack<Node*> st;
    qu.push(root);
    
    while(!qu.empty()){
      Node* temp = qu.front();
      st.push(temp);
      qu.pop();
      if(temp->right != nullptr){
        qu.push(temp->right);
      }
      if(temp->left != nullptr){
        qu.push(temp->left);
      }
    }
    while(!st.empty()){
      cout << st.top()->data << " ";
      st.pop();
    }
  }

  int diameter(Node* root){
    if(root == nullptr){
      return 0;
    }
    int left = diameterHelper(root->left);
    int right = diameterHelper(root->right);
    return left+right+1;
  }

  void postorder(Node* root){
    stack<Node*> st;
    Node* curr = root;
    while(curr || !st.empty()){
      if(curr){
        st.push(curr);
        curr = curr->left;
      } else{
        Node* top = st.top()->right;
        if(top == nullptr){
          top = st.top();
          st.pop();
          cout<<top->data << " ";
          while(!st.empty() && top == st.top()->right){
            top = st.top();
            st.pop();
            cout << top->data << " ";
          }
        } else{
          curr = top;
        }
      }
    }
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
  root = root->createNode(10);
  root->right = root->createNode(20);
  root->left = root->createNode(5);
  root->right->left = root->createNode(15);
  root->right->right = root->createNode(30);
  root->right->right->right = root->createNode(40);
  cout << root->diameter(root);

  return 0;
}