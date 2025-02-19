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
    private:
    void postOrder(TreeNode* node, vector<int>& result) {
        if(node == nullptr) {
            return;
        }
        postOrder(node->left, result);
        postOrder(node->right, result);
        result.push_back(node->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
//         left right root
        vector<int> result;
        postOrder(root, result);
        return result;
    }
};