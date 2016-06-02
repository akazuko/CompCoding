/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int k = A.size();
    ListNode* cur;
    ListNode* ans;
    ListNode* prev;
    bool done;
    bool first = true;
    int index;
    int minn;
    while(1){
        
        done = true;
        for(int i=0; i<k; ++i){
            if(A[i]!=NULL){
                done = false;
                break;
            }
        }
        
        if(done) break;
        
        
        minn = INT_MAX;
        for(int i =0; i<k; ++i){
            if(A[i]!=NULL && minn>A[i]->val){
                index = i;
                minn = A[i]->val;
            }
        }
        //break;
        
        cur = A[index];
        A[index] = A[index]->next;
        
        if(first){
            first = false;
            ans = cur;
        }
        else{
            if(prev!=NULL)
                prev->next = cur;
            
        }
        prev = cur;
        
    }
    return ans;
}
