 unordered_map<TreeNode*,TreeNode*> find_parent(TreeNode* root)
    {
        unordered_map<TreeNode*,TreeNode*>parent;
        queue<TreeNode*>q;
        q.push({root});;
        parent[root]=nullptr;
        while(!q.empty())
        {
            auto it=q.front();q.pop();
            if(it->left){
              parent[it->left]=it;
              q.push(it->left);}
            if(it->right){
              parent[it->right]=it;
              q.push(it->right);}
        }
        return parent;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k==0)
          return {target->val};
       ;vector<int>res;
        unordered_map<TreeNode*,TreeNode*>parent=find_parent(root);
        queue<pair<TreeNode*,int>>q;int t;
        set<TreeNode*>myset;
        myset.insert(target);
        q.push({target,0});
        while(!q.empty())
        {
            int size=q.size();
            if(t+1==k)
              break;
            for(int i=0;i<size;i++)
            {
                auto it=q.front();q.pop();
                t=it.second;
                
                
                if(it.first->left)
                {
                    if(myset.find(it.first->left)==myset.end())
                    {
                        q.push({it.first->left,t+1});
                        myset.insert(it.first->left);
                    }
                }
                if(it.first->right)
                {
                    if(myset.find(it.first->right)==myset.end())
                    {
                        q.push({it.first->right,t+1});
                        myset.insert(it.first->right);
                    }
                }
                if(parent[it.first])
                {
                    if(myset.find(parent[it.first])==myset.end())
                    {
                        q.push({parent[it.first],t+1});
                        myset.insert(parent[it.first]);
                    }
                }
                
                
                
            }
        }
        while(!q.empty())
        {
            res.push_back(q.front().first->val);q.pop();
        }
        return res;
    }