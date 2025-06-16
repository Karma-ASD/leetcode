/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* f=NULL;
    TreeNode* s=NULL;
    TreeNode* pre=NULL;
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        if(!f && root->val<pre->val){
            f=pre;
        }
        if(f && root->val<pre->val){
            s=root;
        }
        pre=root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        pre = new TreeNode(INT_MIN);  // Initialize pre with a minimum value node
        inorder(root);  // Perform in-order traversal to find the mistakes
        swap(f->val, s->val);
    }
};
