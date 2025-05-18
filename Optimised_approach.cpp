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
 * Count the number of nodes in a binary tree where the node's value equals
 * the integer average of values in its entire subtree (including the node itself).
 *
 * Approach:
 * - Perform a single DFS traversal.
 * - At each node, compute:
 *     1. The total sum of values in the subtree.
 *     2. The total number of nodes in the subtree.
 * - Use this information to calculate the integer average.
 * - Compare the average to the node's value and increment a counter if they match.
 */

class Solution {
public:
    int count = 0; // To count nodes where value == average of subtree

    // Returns a pair: {sum of subtree, number of nodes in subtree}
    pair<int, int> hlo(TreeNode* root) {
        if (!root)
            return {0, 0};

        // Recursively compute sum and count for left and right subtrees
        auto left = hlo(root->left);
        auto right = hlo(root->right);

        int sum = left.first + right.first + root->val;
        int nodes = left.second + right.second + 1;

        // If the average equals the node value, increment the count
        if ((sum / nodes) == root->val)
            count++;

        return {sum, nodes};
    }

    // Initiates DFS and returns the count
    int averageOfSubtree(TreeNode* root) {
        hlo(root);
        return count;
    }
};
