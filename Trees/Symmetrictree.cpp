bool solve(TreeNode* root1,TreeNode* root2)
    {
        if(!root1 and !root2)
        {
            return true;
        }
        if(!root1 or !root2)
        {
            return false;
        }
       
        if(root1->val!=root2->val)
        {
            return false;
        }
        return solve(root1->left,root2->right) && solve(root1->right,root2->left);
    }