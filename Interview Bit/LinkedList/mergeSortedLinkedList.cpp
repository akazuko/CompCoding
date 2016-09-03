/* Link list Node  
struct Node {
    int data;
    struct Node* next;
}; */

struct Node* SortedMerge(struct Node* head1,  struct Node* head2)
{
    struct Node* h = NULL;
    struct Node* prev = NULL;
    struct Node* A = head1;
    struct Node* B = head2;
    struct Node* t;
    while(A!=NULL && B!=NULL){
        
        if(A->data < B->data){
            t = A->next;
            A->next = NULL;
            if(prev==NULL){
                h = A;
                prev = h;
            }
            else{
                prev->next = A;
                prev = A;
            }
            A = t;
        }
        else{
            t = B->next;
            B->next = NULL;
            if(prev==NULL){
                h = B;
                prev = h;
            }
            else{
                prev->next = B;
                prev = B;
            }
            B = t;
        }
    }
    while(A!=NULL){
        
            t = A->next;
            A->next = NULL;
            if(prev==NULL){
                h = A;
                prev = h;
            }
            else{
                prev->next = A;
                prev = A;
            }
            A = t;
        
    }
    while(B!=NULL){
            t = B->next;
            B->next = NULL;
            if(prev==NULL){
                h = B;
                prev = h;
            }
            else{
                prev->next = B;
                prev = B;
            }
            B = t;
    }
    return h;
}
