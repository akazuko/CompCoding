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
listnode* removeNthFromEnd(listnode* A, int B) {
    listnode* temp=A;
    listnode* prev=NULL;
    int len=0;
    temp=A;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    temp=A;
    if(B==1 && temp->next==NULL)
        return prev;
    B = len - B;
    if (B<=0)
        return A->next;
    while(B!=0){
        prev = temp;
        temp=temp->next;
        B--;
    }
    prev->next=temp->next;
    //free(temp);
    return A;
}
