/* struct Node
 {
   int data;
   struct Node* next;
 }; */

/* Should return data of n'th node from the end of linked list */
int getNthFromLast(struct Node *head, int n)
{
       int l = 0;
       struct Node *t = head;
       while(t){
           l++;
           t = t->next;
       }
       if(n>l) return -1;
       int k = l-n;
       t = head;
       while(k--){
           t= t->next;
       }
       return t->data;
}
