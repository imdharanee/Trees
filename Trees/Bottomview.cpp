void solve(map<int,int>& map,Node* root)
    {
        std::queue<pair<Node*,int>>q;
        q.push({root,0});
        
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            int level=it.second;
            map[level]=it.first->data;
            if(it.first->left)
              q.push({it.first->left,level-1});
            if(it.first->right)
              q.push({it.first->right,level+1});
        }
        
    }
    vector <int> bottomView(Node *root) {
        // Your Code Here
      vector<int>ans;
      map<int,int>map;
      solve(map,root);
      for(auto it:map)
      {
          ans.push_back(it.second);
      }
      return ans;
      
    }