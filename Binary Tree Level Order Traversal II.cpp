class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == NULL)    return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> s;

            for(int i=0;i<size;i++){
                TreeNode* front = q.front();
                q.pop();

                s.push_back(front -> val);

                if(front -> left != NULL) q.push(front -> left);
                if(front -> right != NULL) q.push(front -> right);
            }

            ans.push_back(s);
        }
        reverse(ans.begin(), ans.end());
        // int i=0,j=ans.size()-1;
        // while(i<j){
        //     swap(ans[i++], ans[j--]);
        // }
        return ans;
    }
};
