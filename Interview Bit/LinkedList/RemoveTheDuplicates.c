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
 * @Output head pointer of list.
 */
listnode* deleteDuplicates(listnode* A) {
    int nval=A->val;
    listnode* temp=A;
    listnode* prev=A;
    while(temp!=NULL){
        if(temp->val!=nval){
            nval=temp->val;
            prev->next=temp;
            prev=temp;
        }
        temp=temp->next;
    }
    prev->next=NULL;
    return A;
}
