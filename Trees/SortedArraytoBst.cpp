TreeNode* solve(vector<int>& nums,int low,int high)
   {
       
       if(low>high)
        return nullptr;
       int mid=(low+high)/2;
       TreeNode* root=new TreeNode(nums[mid]);
        root->left=solve(nums,low,mid-1);
        root->right=solve(nums,mid+1,high);
        return root;
   }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
       TreeNode* root;
        root= solve(nums,0,nums.size()-1);
        return root;
    } 