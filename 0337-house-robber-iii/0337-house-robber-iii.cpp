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
    int rob(TreeNode* root) {
        pair<int, int> result = dfs(root);
        return max(result.first, result.second);
    }

private:
    pair<int, int> dfs(TreeNode* node) {
        if (!node) return {0, 0};

        pair<int, int> leftPair = dfs(node -> left);
        pair<int, int> rightPair = dfs(node -> right);

        int withRoot = node -> val + leftPair.second + rightPair.second;
        int withoutRoot = max(leftPair.first, leftPair.second) + max(rightPair.first, rightPair.second);

        return {withRoot, withoutRoot};

    }


};
