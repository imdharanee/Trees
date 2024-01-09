int height(Node* root,int a,int lev)
{
    if(!root)
     return 0;
    if(root->data==a)
      return lev;
    int l=height(root->left,a,lev+1);
    if(l!=0)
      return l;
    l=height(root->right,a,lev+1);
    return l;
}
Node* parentof(Node* root,int a)
{
    if(!root)
      return nullptr;
  
    if(root->left && root->left->data==a)
      return root;
     if(root->right && root->right->data==a)
      return root;
    Node* p=parentof(root->left,a);
    if(p!=nullptr)
      return p;
    p=parentof(root->right,a);
    return p;
}
bool isCousins(Node *root, int a, int b)
{
   //add code here.
   int l=height(root,a,0);int r=height(root,b,0);
   if(l!=r)
     return false;
    Node* p1=parentof(root,a);
    Node* p2=parentof(root,b);
    if(p1->data==p2->data)
      return false;
    return true;
}