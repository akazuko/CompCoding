/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 * 
 * typedef struct ListNode listnode;
 * 
 * listnode* listnode_new(int val) {
 *     listnode* node = (listnode *) malloc(sizeof(listnode));
 *     node->val = val;
 *     node->next = NULL;
 *     return node;
 * }
 */
/**
 * @input A : Head pointer of linked list 
 * @input B : Integer
 * 
 * @Output head pointer of list.
 */
listnode* partition(listnode* A, int B) {
    listnode* temp;
    listnode* curr;
    listnode* first=NULL;
    listnode* firstp=NULL;
    listnode* second=NULL;
    listnode* secondp=NULL;
    temp=A;
    while(temp!=NULL){
        /*if(temp->val<=B){
            //printf("%d\n",temp->val);
            if(first==NULL){
                first=temp;
                firstp=temp;
                temp=temp->next;
                if(firstp!=NULL)
                    firstp->next=NULL;
            }
            else{
                firstp->next=temp;
                temp=temp->next;
                if(firstp->next!=NULL)
                    firstp->next->next=NULL;
                firstp=firstp->next;
            }
        }
        else{
            if(first==NULL){
                second=temp;
                secondp=temp;
                temp=temp->next;
                if(secondp!=NULL)
                    secondp->next=NULL;
            }
            else{
                secondp->next=temp;
                temp=temp->next;
                if(secondp->next!=NULL)
                    secondp->next->next=NULL;
                secondp=secondp->next;
            }
        }*/
        if(temp->val<B){
            if(first==NULL){
                first = listnode_new(temp->val);
                firstp=first;
            }
            else{
                curr = listnode_new(temp->val);
                firstp->next = curr;
                firstp = curr;
            }
        }
        else{
            if(second==NULL){
                second = listnode_new(temp->val);
                secondp=second;
            }
            else{
                curr = listnode_new(temp->val);
                secondp->next = curr;
                secondp = curr;
            }
        }
        temp=temp->next;
        
    }
    if(firstp!=NULL){
        firstp->next=second;
    }
    if(first==NULL)
        return second;
    return first;
}
