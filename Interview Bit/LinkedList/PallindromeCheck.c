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
 * 
 * @Output Integer
 * 
 * 
 */
 
listnode* reverseList(listnode* A) {
    listnode *curr;
    listnode *prev;
    listnode *temp;

    prev=A;
    curr=prev->next;
    prev->next=NULL;
    
    while(curr!=NULL){
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    return prev;
}


int lPalin(listnode* A) {
    listnode *list1=A;
    listnode *mid;
    listnode *temp;
    listnode *prev;
    listnode *list2;
    
    temp=A;
    int len=0;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    if(len==1)
    return 1;
    mid=A;
    int p=0;
    if(len%2==0)
        p=len/2;
    else
        p=len/2 + 1;
    while(p!=0){
        prev=mid;
        mid=mid->next;
        p--;
    }
    prev->next=NULL;
    list2 = reverseList(mid);
    p=len/2;
    while(p!=0){
        if(list1->val!=list2->val)
            return 0;
        list1=list1->next;
        list2=list2->next;
        p--;
    }
    return 1;
}
