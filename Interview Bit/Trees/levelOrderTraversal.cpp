//You are required to complete this method
void levelOrder(struct Node* node)
{
 //Your code here
 if(node==NULL) return;
 int cur_level = 0;
 string s = "";
 queue< pair<struct Node*, int> > q;
 q.push(make_pair(node, 0));
 while(!q.empty()){
     struct Node* t = q.front().first;
     int level = q.front().second;
     q.pop();
     if(level==cur_level) s+=to_string(t->data) + " ";
     else{ cur_level = level; cout<<s<<"$ "; s=to_string(t->data)+" ";}
     if(t->left)
        q.push(make_pair(t->left, level + 1));
     if(t->right)
        q.push(make_pair(t->right, level + 1));
 }
 cout<<s<<"$";
}



