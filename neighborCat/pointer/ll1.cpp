#include <iostream>
using namespace std;

struct Node{
    int id;
    Node *next;
    Node(int num){
        id = num;
        next = NULL;
    }
};

void show(Node *ptr){
    while (ptr != NULL){
        // dont print 0
        if (ptr->id == 0){
            ptr = ptr->next;
            continue;
        }
        cout << ptr->id << " ";
        ptr = ptr->next;
    }

    cout << '\n';
}


void insert(Node *head, int newId, int Bid){
    Node *ptr = head; // just in case: we can restart from beginning

    // if the current id isn't the one we're looking for
    while (ptr->next != NULL && ptr->id != Bid)
    {   
        if(ptr->id == newId) return; // cant add replicas 
        ptr = ptr->next;
    }
    if(ptr->id == newId) return; // check last node

    // insert front
    if (ptr->next == NULL && ptr->id != Bid){
        
        Node *temp = head->next;
        head->next = new Node(newId);
        head->next->next = temp;
        
        show(head);
        return;
    };

    // if at correct node

    Node *temp = ptr->next;
    ptr->next = new Node(newId);
    ptr->next->next = temp;
    show(head);
} 

void del(Node *head, int Delid){

    if(head->next == NULL || head->next->next == NULL) return;    

    Node *ptr1 = head;
    Node *ptr2 = head->next;

    // don't delete if only 1 node left
    


    while (ptr2->id != Delid && ptr2->next != NULL){
        ptr1 = ptr2;
        ptr2 = ptr2->next;
    }

    // can't find any
    if (ptr2->id != Delid){
        return;
    }   

    // can find node to delete 

    // Node *temp = ptr2;
    // ptr2 = ptr2->next;

    // ptr1->next = ptr2;
    // delete(temp);

    ptr1->next = ptr2->next;
    delete (ptr2);

    // success, so print

    show(head);
}



int main(){

    Node *head;

    head = new Node(0);

    // insert(head, 1, 0);
    // show(head);

    while (true){
        int mode;
        cin >> mode;
        if (mode == 3) break;
        else if (mode == 1){
            int newID, Bid;
            cin >> newID >> Bid;
            insert(head, newID, Bid);
        }
        else if(mode == 0){
            int delId;
            cin >> delId;
            del(head, delId);
        }
    }
    return 0;
}
