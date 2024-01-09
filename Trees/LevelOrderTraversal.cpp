void solve(TreeNode* root,vector<int> & sub,int level)
   {
       if(root==nullptr)
           return;
        if(level==1)
           sub.push_back(root->val);
        solve(root->left,sub,level-1);
        solve(root->right,sub,level-1);
   }
    int height(TreeNode* root)
    {
        if(root==nullptr)
           return 0;
        int lefth=height(root->left);
        int righth=height(root->right);
        if(lefth>righth)
          return lefth+1;
        else
          return righth+1;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>fin;
        int h=height(root);
        for(int i=1;i<=h;i++)
        {
            vector<int>sub;
            solve(root,sub,i);
            fin.push_back(sub);
        }
        return fin;
    }