#include <iostream>
using namespace std;

class Node {
public : 
    int data;
    Node * next;
};

void printList(Node * head){
    Node * cursor = new Node();
    if (head == NULL){
        cout<<"The head is NULL"<<endl;
    }else{
        cursor = head -> next;
        while(cursor!=NULL){
            cout<<cursor->data<<" ";
            cursor = cursor ->next;
        }
    }
}

Node * insert(Node * head, int new_data){
    if (head == NULL){
        cout<<"The head is NULL"<<endl;
        return head;
    }

    Node * new_node = new Node();
    new_node->data = new_data;
    new_node->next = head->next;
    head->next = new_node;
    return head;
}

Node *deleteNode(Node * head, int key){
    if (head == NULL){
        cout<<"The head is NULL"<<endl;
        return head; 
    }
    Node * cursor = new Node();
    cursor = head;
    while(cursor->next->data != key){
        cursor = cursor->next;
    }
    Node * tmp = new Node();
    tmp = cursor->next;
    cursor -> next = cursor->next->next;
    delete tmp;
    return head;
}

int main(){
    Node * head = new Node();
    head = insert(head,1);
    head = insert(head,2);
    head = insert(head,3);
    printList(head);
    head = deleteNode(head,1);
    printList(head);
    cout<<endl;
    return 0;
}