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
listnode* swapPairs(listnode* A) {
    listnode* one;
    listnode* temp;
    listnode* head=NULL;
    listnode* two;
    listnode* pre=NULL;
    one=A;
    if(one->next==NULL)
        return one;
    two=A->next;
    while(two!=NULL && one!=NULL){
        //printf("one:%d two :%d\n",one->val,two->val);
        temp=two;
        two=one;
        one=temp;
        two->next = one->next;
        one->next = two;
        if(pre!=NULL){
            pre->next=one;
        }
        pre = two;
        if(head==NULL)
            head = one;
        
        one = one->next->next;
        two = two->next;
        if(two==NULL)
            break;
        two=two->next;
    }

    return head;
}
