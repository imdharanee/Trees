void solve(TreeNode* root,int lev,map<int,int>& hash)
   {
       if(!root) return;

       if(hash[lev])  
          hash[lev]=max(root->val,hash[lev]); 

       else   
           hash[lev]=root->val;

       solve(root->left,lev+1,hash);
       solve(root->right,lev+1,hash);
   }
    vector<int> largestValues(TreeNode* root) {
        map<int,int>hash; vector<int> arr;
        solve(root,1,hash);
        for(auto &it:hash)
            arr.push_back(it.second);
        return arr;
    }