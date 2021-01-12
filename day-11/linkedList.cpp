#include <bits/stdc++.h>
using namespace std;

class LinkedList{
  int data;
  LinkedList* next;
  LinkedList* createNode(int val){
    LinkedList* newNode = new LinkedList;
    newNode->data = val;
    newNode->next = nullptr;
    return newNode;
  }
public:
  LinkedList* insertNode(LinkedList* head, int val){
    LinkedList* newNode = createNode(val);
    if(head == nullptr){
      head = newNode;
    } else{
      newNode->next = head;
      head = newNode;
    }
    return head;
  }
  LinkedList* appendNode(LinkedList* head, int val){
    if(head == nullptr){
      LinkedList* newNode = createNode(val);
      head = newNode;
      return head;
    } else if(head->next == nullptr){
      LinkedList* newNode = createNode(val);
      head->next = newNode;
      return head;
    } else{
      head->next = appendNode(head->next, val);
    }
    return head;
  }
  LinkedList* reverseList(LinkedList* head){
    LinkedList* prev=nullptr, *curr=nullptr, *next=nullptr;
    curr = head;
    while(curr != nullptr){
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    head = prev;
    return head;
  }
  int midEle(LinkedList* head){
    LinkedList* slow=head, *fast=head;
    while(fast&&fast->next){
      slow = slow->next;
      fast = fast->next->next;
    }
    return (slow->data);
  }
  LinkedList* findEle(LinkedList* head, int val){
    LinkedList* ptr = head;
    while(ptr != nullptr){
      if(ptr->data == val){
        return ptr;
      }
      ptr = ptr->next;
    }
    return nullptr;
  }
  LinkedList* deleteNode(LinkedList* head, int val){
    if(head == nullptr){
      return nullptr;
    } else if(head->data == val){
      LinkedList* temp = head;
      head = head->next;
      delete temp;
    } else{
      LinkedList* pos = findEle(head, val);
      if(pos == nullptr)
        return head;
      LinkedList* temp = pos, *curr = head;
      while(curr->next != pos){
        curr = curr->next;
      }
      curr->next = pos->next;
      delete temp;
    }
    return head;
  }
  void printList(LinkedList* head){
    if(head != nullptr){
      cout << head->data << " ";
      printList(head->next);
    }
  }
};

int main(){
  LinkedList* head = nullptr;
  head = head->insertNode(head, 10);head = head->insertNode(head, 30);
  head = head->insertNode(head, 20);head = head->insertNode(head, 40);
  head = head->appendNode(head, 5);head = head->appendNode(head, 0);
  head->printList(head);
  head = head->reverseList(head);
  cout << "\nreverse:  ";
  head->printList(head);
  cout << "\nMid element: " << head->midEle(head);
  head = head->deleteNode(head, 0);
  cout << "\nDelete: ";
  head->printList(head);

  return 0;
}