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
 * @input m : Integer
 * @input n : Integer
 * 
 * @Output head pointer of list.
 */

listnode* reverseList(listnode* A, int len) {
    listnode *curr;
    listnode *prev;
    listnode *temp;

    prev=A;
    curr=prev->next;
    prev->next=NULL;
    
    while(len!=1){
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
        len--;
    }
    return prev;
}

listnode* reverseBetween(listnode* A, int m, int n) {
    listnode* temp1=NULL;
    listnode* temp2=NULL;
    listnode* prev1=NULL;
    listnode* prev2=NULL;
    int len= n-m+1;
    int k = m;
    temp1=A;
    prev1=temp1;
    temp2=A;
    while(m!=1){
        prev1 = temp1;
        temp1=temp1->next;
        m--;
    }
    prev2=temp2;
    while(n!=0){
        prev2 = temp2;
        temp2=temp2->next;
        n--;
    }
    
    if(prev1!=NULL && k!=1){
        prev1->next = reverseList(temp1,len);
        if(prev1!=NULL)
           temp1 = prev1->next;
        while(len--){
            prev1 = temp1;
            temp1=temp1->next;
        }
    }
    else if(prev1!=NULL && k==1){
        prev1 = reverseList(temp1,len);
        temp1 = prev1;
        A = prev1;
        while(len!=0){
            prev1 = temp1;
            temp1=temp1->next;
            len--;
        }
        
    }
    
        
        
    
    if(prev1!=NULL)
        prev1->next=temp2;
    return A;
}
