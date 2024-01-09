TreeNode* invertTree(TreeNode* root)
        {
            invert(root);
            return root;
        }
        void  invert(TreeNode* root) {
        if(root==nullptr)
           return;
        
          std::swap(root->left,root->right);
        
        invert(root->left);
        invert(root->right);}