class Solution {
public:

vector<int> parent, rank;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = (int)edges.size();

        parent.resize(n + 1);
        rank.assign(n + 1, 1);

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            if (!Union(u, v)) return e;
        }

        return {};
    }

    int find(int x) {
        if (x == parent[x]) return x;
        parent[x] = find(parent[x]);
        return parent[x];
    }

    bool Union(int a, int b) {
        int ra = find(a);
        int rb = find(b);

        if (ra == rb) return false;

        if (rank[ra] < rank[rb]) swap(ra, rb);
        parent[rb] = ra;
        rank[ra] += rank[rb];

        return true;
    }
};