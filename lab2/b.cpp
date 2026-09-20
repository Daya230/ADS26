#include <iostream>
using namespace std;

struct Node{
    int val;
    Node *next;
};

int main(){
    int n;
    cin>> n;

    Node* head = nullptr;
    Node* tail = nullptr;

    for(int i = 0;i<n; i++){
        int x;
        cin>> x;

        Node* temp = new Node();
        temp->val = x;
        temp->next = nullptr;

        if (head == nullptr){
            head = temp;
            tail = temp;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
    }
    Node*cur = head;
    while(cur != nullptr && cur->next != nullptr){
        Node* del = cur->next;
        cur->next = del->next;
        delete del;

        cur = cur -> next;
    }
    cur = head;
    while (cur != nullptr){
        cout<< cur->val<<' ';
        cur = cur->next;
    }
    return 0;
}
