/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return dfs(grid, grid.size(), 0, 0);
    }

    Node* dfs(vector<vector<int>>& grid, int n, int r, int c) {
        bool isSameValue = true;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[r][c] != grid[r + i][c +j]) {
                    isSameValue = false;
                    break;
                }
            }
        }

        if (isSameValue) {
            int val = grid[r][c];
            return new Node(val, true, NULL, NULL, NULL, NULL);
        }

        int mid = n / 2;
        Node* topLeft = dfs(grid, mid, r, c);
        Node* topRight = dfs(grid, mid, r, c + mid);
        Node* bottomLeft = dfs(grid, mid, r + mid, c);
        Node* bottomRight = dfs(grid, mid, r + mid, c + mid);

        return new Node(true, false, topLeft, topRight, bottomLeft, bottomRight);



    }
};