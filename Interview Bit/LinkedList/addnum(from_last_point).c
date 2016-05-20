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
    int len1=0;
    while(temp!=NULL){
        len1++;
        temp=temp->next;
    }
    temp=B;
    int len2=0;
    while(temp!=NULL){
        len2++;
        temp=temp->next;
    }
    int diff = len1-len2;
    if(diff>0){
        temp=A;
        while(diff>0){
            if(res==NULL){
                curr = listnode_new(temp->val);
                res =  curr;
                prev = curr;
            }
            else{
                curr = listnode_new(temp->val);
                prev->next = curr;
                prev = curr;
            }
            temp=temp->next;
            diff--;
        }
        startA = temp;
        startB = B;
    }
    else if(diff<0){
        temp=B;
        diff = diff*-1;
        while(diff>0){
            if(res==NULL){
                curr = listnode_new(temp->val);
                res =  curr;
                prev = curr;
            }
            else{
                curr = listnode_new(temp->val);
                prev->next = curr;
                prev = curr;
            }
            temp=temp->next;
            diff--;
        }
        startA = A;
        startB = temp;
    }
    else{
        startA = A;
        startB = B;
    }
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
    if(carry == 1){
        curr = listnode_new(1);
        prev->next = curr;
    }
    return res;
}
