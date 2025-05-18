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

/*
 * Problem:
 * Count the number of nodes in a binary tree where the node's value is equal to
 * the integer average of values in its subtree (including itself).
 *
 * Approach:
 * - Use two DFS traversals:
 *   1. `nodesdown()` to calculate the number of nodes in the subtree rooted at each node.
 *   2. `hlo()` to calculate the sum of the subtree rooted at each node,
 *      and compare the integer average to the node's value.
 * - Store subtree node counts in an unordered_map for reuse.
 */

class Solution {
public:
    int count = 0; // Counter for nodes that satisfy the condition

    // Calculates the sum of values in the subtree rooted at `root`
    // Also checks if the average of the subtree equals the root value
    int hlo(TreeNode* root, unordered_map<TreeNode*, int>& mp) {
        if (!root)
            return 0;

        int leftSum = hlo(root->left, mp);      // Sum of left subtree
        int rightSum = hlo(root->right, mp);    // Sum of right subtree
        int totalSum = leftSum + rightSum + root->val; // Total sum of current subtree

        // If the average equals the root's value, increment count
        if ((totalSum / mp[root]) == root->val)
            count++;

        return totalSum;
    }

    // Computes and stores the number of nodes in the subtree rooted at `root`
    int nodesdown(TreeNode* root, unordered_map<TreeNode*, int>& mp) {
        if (!root)
            return 0;

        mp[root] = 1 + nodesdown(root->left, mp) + nodesdown(root->right, mp);
        return mp[root];
    }

    // Main function to initiate the process
    int averageOfSubtree(TreeNode* root) {
        unordered_map<TreeNode*, int> mp;
        nodesdown(root, mp);  // Precompute subtree sizes
        hlo(root, mp);        // Evaluate subtree sums and check condition
        return count;
    }
};
