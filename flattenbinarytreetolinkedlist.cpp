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
    TreeNode* flatten(TreeNode* root) {
        if (!root) return nullptr;

        // Flatten the left and right subtrees
        TreeNode* leftLast = flatten(root->left);
        TreeNode* rightLast = flatten(root->right);

        // If there's a left subtree, attach it to the right
        if (root->left) {
            TreeNode* temp = root->right; // Save the original right subtree
            root->right = root->left;    // Move the left subtree to the right
            root->left = nullptr;        // Set left to null
            if (leftLast) {
                leftLast->right = temp;  // Attach the original right subtree
            }
        }

        // Return the last node of the flattened tree
        return rightLast ? rightLast : (leftLast ? leftLast : root);
    }
};
