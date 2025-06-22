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
    int maxDepth(TreeNode* root) {
        // Iterative DFS
        // stack<pair<TreeNode*, int>> stack;
        // stack.push({root, 1});
        // int res = 0;

        // while(!stack.empty()) {
        //     pair<TreeNode*, int> current = stack.top();
        //     stack.pop();
        //     int depth = current.second;
        //     TreeNode* node = current.first;

        //     if(node) {
        //         res = max(res, depth);
        //         stack.push({node -> left, depth + 1});
        //         stack.push({node -> right, depth + 1});
        //     }
        // }
        // return res;


        // BFS
        queue<TreeNode*> q;
        if(root != NULL) q.push(root);

        int level = 0;

        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if(node -> left) q.push(node -> left);
                if(node -> right) q.push(node -> right);
            }
            level++;
        }
        return level;
        
        // Recursive DFS
        // if(!root) return 0;

        // return 1 + max(maxDepth(root -> left), maxDepth(root -> right));
    }
};