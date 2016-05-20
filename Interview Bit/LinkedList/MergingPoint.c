// #include <stdio.h>
// #include <stdlib.h>


// struct ListNode {
//     int val;
//     struct ListNode *next;
// };
  
// typedef struct ListNode listnode;
  
// listnode* listnode_new(int val) {
//     listnode* node = (listnode *) malloc(sizeof(listnode));
//     node->val = val;    
//     node->next = NULL;
//     return node;
// }
 

listnode* getIntersectionNode(listnode* A, listnode* B) {
    int len1=0;
    int len2=0;
    listnode *temp;
    listnode *startA;
    listnode *startB;
    temp=A;
    while(temp!=NULL){
        len1++;
        temp=temp->next;
    }
    temp=B;
    while(temp!=NULL){
        len2++;
        temp=temp->next;
    }

    if(len1>len2){
        temp=A;
        int k=len1-len2;
        while(k!=0){
            temp=temp->next;
            k--;
        }
    
        startA=temp;
        startB=B;
    }
    else if (len2>len1){
        temp=B;
        int k=len2-len1;
        while(k!=0){
            temp=temp->next;
            k--;
        }
        startA=A;
        startB=temp;
    }
    else{
        startA=A;
        startB=B;
    }
    
    listnode *res=NULL;
    while(startA!=NULL && startB!=NULL){
        if(startA==startB){
            res=startA;
            break;
        }
        else{
            startA=startA->next;
            startB=startB->next;
        }
    }
    return res;
    
}