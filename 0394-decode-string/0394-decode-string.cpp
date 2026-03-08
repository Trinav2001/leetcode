class Solution {
public:
    string decodeString(string s) {

        vector<string> stack;

        for (auto& c : s) {
            if (c != ']') {
                stack.push_back(string(1, c));  // char to string of size = 1
            }

            else {
                
                string substr = "";
                while(stack.back() != "[") {
                    substr = stack.back() + substr;
                    stack.pop_back();
                }

                stack.pop_back();

                string n = "";

                string k = "";

                while (!stack.empty() && isdigit(stack.back()[0])) {
                    k = stack.back() + k;
                    stack.pop_back();
                }

                int count = stoi(k);

                string repeat = "";
                for (int i = 0; i < count; i++) {
                    repeat += substr;
                }

                stack.push_back(repeat);
            }
        }

        string res = "";

        for (auto& s : stack) {
            res += s;
        }

        return res;




        
    }
};