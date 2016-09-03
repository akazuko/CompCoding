/* A binary tree node
struct Node
{
    int data;
    struct Node* left, * right;
}; */

// A wrapper over leftViewUtil()
void leftView(struct Node *root)
{   
    if(root==NULL) return;
   map< int, int> m;
   queue< pair<struct Node*, int> > q;
   q.push(make_pair(root, 0));
   while(!q.empty()){
       auto k = q.front();
       q.pop();
       struct Node *t = k.first;
       int level  = k.second;
       if(m.find(level)==m.end()) {
           cout<<t->data<<" ";
            m[level] = t->data;
       }
       if(t->left) q.push(make_pair(t->left, level + 1));
       if(t->right) q.push(make_pair(t->right, level + 1));
   }
}
