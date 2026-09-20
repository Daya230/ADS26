#include <iostream>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(): val(0), next(nullptr) {}
    Node(int x): val(x),next(nullptr) {}
    Node(Node* next): val(0), next(next) {}
};

Node *insert(Node* head, Node* node, int p){
    if(p==0){
        node->next = head;
        return node;
    }

    Node* cur = head;

    for(int i =0; i<p-1; i++){
        cur = cur->next;
    }

    node->next = cur->next;
    cur->next = node;

    return head;
}

Node* remove(Node* head, int p){
    if(p==0){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* cur = head;

    for(int i =0;i< p-1; i++){
        cur = cur->next;
    }

    Node* temp = cur->next;
    cur->next = temp->next;

    delete temp;

    return head;
}

void print(Node* head){
    if (head == nullptr){
        cout<< -1<< endl;
        return;
    }

    Node* cur = head;

    while(cur != nullptr){
        cout<< cur->val<< " ";
        cur = cur->next;
    }

    cout<< endl;
}

Node* replace(Node* head, int p1, int p2){
    Node* node;

    if(p1==0){
        node = head;
        head = head->next;
    }
    else{
        Node* cur = head;
        for(int i =0; i<p1-1; i++){
            cur = cur->next;
        }

        node = cur->next;
        cur->next = node->next;
    }

    if(p2 == 0){
        node->next = head;
        return node;
    }
     
    Node* cur = head;

    for(int i =0; i< p2 -1 ; i++){
        cur = cur->next;
    }
    
    node->next = cur->next;
    cur->next = node;

    return head;
}

Node* reverse(Node* head){
    Node* prev = nullptr;
    Node* cur = head;

    while (cur != nullptr){
        Node* next = cur->next;

        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

Node* cyclic_left(Node* head, int x){
    if (head == nullptr || head->next == nullptr){
        return head;
    }

    Node* tail = head;
    int n =1;

    while(tail->next != nullptr){
        tail = tail->next;
        n++;
    }

    x%=n;

    if (x==0){
        return head;
    }

    Node* cur = head;

    for(int i =1;i<x;i++){
        cur = cur->next;
    }

    Node* newHead = cur->next;
    cur->next = nullptr;
    tail->next = head;

    return newHead;
}

Node* cyclic_right(Node* head, int x){
    if(head ==  nullptr || head->next == nullptr){
        return head;
    }

    Node* tail = head;
    int n =1;
    while(tail->next != nullptr){
        tail = tail->next;
        n++;
    }
    x%=n;

    if(x==0){
        return head;
    }

    int left = n-x;

    Node* cur = head;

    for(int i = 1; i< left; i++){
        cur = cur-> next;
    }

    Node* newHead = cur->next;

    cur->next = nullptr;
    tail->next = head;
    

    return newHead;
}

int main(){
    Node* head = nullptr;

    while(true){
        int com;
        cin >> com;

        if(com == 0){
            break;
        }
        else if(com ==1){
            int x,p;
            cin>> x>>p;
        
            head = insert(head,new Node(x), p);
        }
        else if(com == 2){
            int p;
            cin>> p;

            head = remove(head, p);
        }
        else if(com==3){
            print(head);
        }
        else if (com == 4){
            int p1,p2;
            cin>> p1>> p2;

            head = replace(head, p1, p2);
        }
        else if(com == 5){
            head = reverse(head);
        }
        else if(com == 6){
            int x;
            cin>> x;

            head = cyclic_left(head,x);
        }
        else if(com == 7){
            int x;
            cin>> x;

            head = cyclic_right(head,x);
        }

    }
    return 0;
}
