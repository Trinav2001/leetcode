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
    vector<int> rightSideView(TreeNode* root) {

        vector<int> res;
        
        if (!root) {
            return res;
        }

        queue<TreeNode*> queue;

        TreeNode* cur;
        queue.push(root);

        while(!queue.empty()) {
            int levelSize = queue.size();
            TreeNode* backNode = queue.back();

            for (int i = 0; i < levelSize; i++) {
                cur = queue.front();
                queue.pop();

                if (cur -> left) queue.push(cur -> left);
                if (cur -> right) queue.push(cur -> right);
       
            }

            if (backNode) {
                res.push_back(backNode -> val);
            }

        }
        
        return res;
    }
};