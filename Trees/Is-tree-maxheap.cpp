bool func(Node* root,int maxi)
    {
        if(!root)
         return true;
        if(root->data>maxi)
          return false;
        return func(root->left,root->data) and func(root->right,root->data);
    }
    bool comp(Node* root)
    {
        queue<Node*>q;
        q.push(root);
        bool flag=false;
        while(!q.empty())
        {
            auto it=q.front();q.pop();
            if(it->left)
            {
                 if(flag)
                   return false;
                 q.push(it->left);
            }
            else
              flag=true;
            if(it->right)
            {
                  if(flag)
                    return false;
                  q.push(it->right);
            }
            else
            {
                flag=true;
            }
        }
        return true;
    }
    bool isHeap(struct Node* root) {
        
        bool check=func(root,INT_MAX);
        bool iscomp=comp(root);
        return (check and iscomp);
        
    }