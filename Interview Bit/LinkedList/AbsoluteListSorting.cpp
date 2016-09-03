/* The structure of the Linked list Node is as follows:
struct Node
{
    Node* next;
    int data;
}; */

void sortList(Node** head) {
    Node* h = NULL;
    Node* prev = NULL;
    Node* cur = *head;
    while(cur){
        if(cur->data<0){
            Node *tnext = cur->next;
            cur->next = NULL;
            if(h==NULL){
                h = cur;
                h->next = NULL;
            }
            else{
                cur->next = h;
                h = cur;
            }
            if(prev==NULL){
                *head = tnext;
                 cur = tnext;
            }
            else{
                prev->next = tnext;
                cur = tnext;
            }
        }
        else{
            prev = cur;
            cur = cur->next;
        }
    }
    while(h){
        cout<<h->data<<" ";
        h = h->next;
    }
}
