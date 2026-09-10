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
    int averageOfSubtree(TreeNode* root) {
        int count = 0;  // Counter for nodes whose value equals the average of their subtree
      
        // Lambda function for DFS traversal
        // Returns a pair: {sum of subtree values, number of nodes in subtree}
        auto dfs = [&](this auto&& dfs, TreeNode* node) -> pair<int, int> {
            // Base case: empty node returns sum=0, count=0
            if (!node) {
                return {0, 0};
            }
          
            // Recursively process left subtree
            auto [leftSum, leftCount] = dfs(node->left);
          
            // Recursively process right subtree
            auto [rightSum, rightCount] = dfs(node->right);
          
            // Calculate total sum and count for current subtree
            int subtreeSum = leftSum + rightSum + node->val;
            int subtreeCount = leftCount + rightCount + 1;
          
            // Check if current node's value equals the average of its subtree
            // Using integer division as per problem requirements
            if (subtreeSum / subtreeCount == node->val) {
                ++count;
            }
          
            // Return sum and count for parent node's calculation
            return {subtreeSum, subtreeCount};
        };
      
        // Start DFS traversal from root
        dfs(root);
      
        return count;
    }
};
