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

        if(!root) return res;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* backNode = NULL;
            int size = q.size();

            for(int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if(node) {
                    backNode = node;
                    q.push(node -> left);
                    q.push(node -> right);
                }
            }
            if(backNode) {
                res.push_back(backNode -> val);
            }
        }

        // vector<TreeNode*> q;
        // q.push_back(root);
        // while(!q.empty()) {
        //     int size = q.size();
        //     if(q.back()) {
        //         res.push_back(q.back() -> val);
            
        //         for(int i = size; i > 0; i--) {
        //             TreeNode* node = q.front();
        //             q.erase(q.begin());
        //             if(node) {
        //                 q.push_back(node -> left);         
        //                 q.push_back(node -> right);
        //             }
        //         }
        //     }
        //     else {
        //         q.pop_back();
        //     }
        // }
        return res;
    }
};
