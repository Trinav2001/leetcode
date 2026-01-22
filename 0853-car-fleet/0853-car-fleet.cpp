class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        vector<pair<int, int>> pair;

        for (int i = 0; i < position.size(); i++) {
            pair.push_back({position[i], speed[i]});
        }

        sort(pair.rbegin(), pair.rend());

        stack<double> st;

        for (int i = 0; i < pair.size(); i++) {
            double cur = (target - pair[i].first) / pair[i].second;

            if (st.empty()) {
                st.push(cur);
                continue;
            }

            auto top = st.top();

            st.push(cur);

            if (st.size() >= 2 && top >= cur) {
                st.pop();
            }





        }

        return st.size();

        
        
    }
};