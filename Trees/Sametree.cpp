if(!p and !q)
{
           return true;
       if(!p or !q)
           return false;
       if(p->val!=q->val)
          return false;
       return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
      
       
 }