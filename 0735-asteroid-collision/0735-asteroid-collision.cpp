class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        stack<int> st;

        for (int i = 0; i < asteroids.size(); i++) {
            int current = asteroids[i];

            if (current > 0) {
                st.push(current);
            }

            else {
                if (st.empty() || st.top() < 0) {
                    st.push(current);
                }

                else {
                    while (!st.empty() && st.top() > 0 && abs(st.top()) < abs(current)) {
                        st.pop();
                    }

                    if (st.empty() || st.top() < 0) {
                        st.push(current);
                    }

                    else if (abs(st.top()) == abs(current)) {
                        st.pop();
                    }                     
                }           
            }
        }

        vector<int> result;

        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        reverse(result.begin(), result.end());

        return result;
        
    }
};