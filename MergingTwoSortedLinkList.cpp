/*
  Merge two sorted lists A and B as one linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* MergeLists(Node *headA, Node* headB)
{
  // This is a "method-only" submission. 
  // You only need to complete this method 
    Node* temp;
    if(headA==NULL)
        return headB;
    else if(headB==NULL)
        return headA;
    else if(headA!=NULL && headB!=NULL){
        if(headA->data<headB->data){
            temp = headA->next;
            headA->next = MergeLists(temp,headB);
            return headA;
        }
        else{
            temp = headB->next;
            headB->next = MergeLists(headA,temp);
            return headB;
        }
    }
    else
        return NULL;
}
