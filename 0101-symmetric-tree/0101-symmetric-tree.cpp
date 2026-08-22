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
    /**
     * Determines if a binary tree is symmetric around its center
     * @param root: Root node of the binary tree
     * @return: true if the tree is symmetric, false otherwise
     */
    bool isSymmetric(TreeNode* root) {
        // Handle edge case of null root
        if (!root) {
            return true;
        }
      
        // Check if left and right subtrees are mirrors of each other
        return isMirror(root->left, root->right);
    }
  
private:
    /**
     * Helper function to check if two trees are mirrors of each other
     * @param leftNode: Root of the left subtree
     * @param rightNode: Root of the right subtree
     * @return: true if the trees are mirrors, false otherwise
     */
    bool isMirror(TreeNode* leftNode, TreeNode* rightNode) {
        // Both nodes are null - symmetric at this level
        if (!leftNode && !rightNode) {
            return true;
        }
      
        // Only one node is null - not symmetric
        if (!leftNode || !rightNode) {
            return false;
        }
      
        // Check if current nodes have same value
        // Then recursively check:
        // - left child of leftNode with right child of rightNode
        // - right child of leftNode with left child of rightNode
        return (leftNode->val == rightNode->val) &&
               isMirror(leftNode->left, rightNode->right) &&
               isMirror(leftNode->right, rightNode->left);
    }
};
