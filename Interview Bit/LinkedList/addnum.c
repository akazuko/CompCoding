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
 * @input B : Head pointer of linked list 
 * 
 * @Output head pointer of list.
 */
listnode* addTwoNumbers(listnode* A, listnode* B) {
    listnode* temp;
    listnode* curr;
    listnode* prev=NULL;
    listnode* res=NULL;
    
    listnode* startA;
    listnode* startB;
    temp=A;
    
    startA = A;
    startB = B;
    int med;
    int carry=0;
    
    while(startA!=NULL && startB!=NULL){
        med = startA->val + startB->val + carry;
        if(med>=10){
            carry = 1;
            med = med - 10;
        }
        else{
            carry = 0;
        }
        if(res==NULL){
            curr = listnode_new(med);
            res =  curr;
            prev = curr;
        }
        else{
            curr = listnode_new(med);
            prev->next = curr;
            prev = curr;
        }
        startA = startA->next;
        startB = startB->next;
    }
    
    if(startA==NULL && startB!=NULL){
        while(startB!=NULL){
            med = startB->val + carry;
            if(med>=10){
                carry = 1;
                med = med - 10;
            }
            else{
                carry = 0;
            }
            if(res==NULL){
                curr = listnode_new(med);
                res =  curr;
                prev = curr;
            }
            else{
                curr = listnode_new(med);
                prev->next = curr;
                prev = curr;
            }
        
            startB = startB->next;
        }
    }
    else if (startA!=NULL && startB==NULL){
        while(startA!=NULL){
            med = startA->val + carry;
            if(med>=10){
                carry = 1;
                med = med - 10;
            }
            else{
                carry = 0;
            }
            if(res==NULL){
                curr = listnode_new(med);
                res =  curr;
                prev = curr;
            }
            else{
                curr = listnode_new(med);
                prev->next = curr;
                prev = curr;
            }
        
            startA = startA->next;
        }
    }
    if(carry == 1){
        curr = listnode_new(1);
        prev->next = curr;
    }
    return res;
}
