class Solution {
public:
    string decodeString(string s) {
        vector<string> stack;

        for(char&c : s) {
            if(c != ']') stack.push_back(string(1, c));

            else {
                string substr = "";
                while(stack.back() != "[") {
                    substr = stack.back() + substr;
                    stack.pop_back();
                }
                stack.pop_back();

                string number = "";
                while(!stack.empty() && isdigit(stack.back()[0])) {
                    number = stack.back() + number;
                    stack.pop_back();
                }

                int count = stoi(number);

                string repeat = "";
                for(int i = 0; i < count; i++) {
                    repeat += substr;
                }
                stack.push_back(repeat);
            }
        }


        string res = "";

        for(auto& part : stack) {
            res += part;
        }
        return res;

    }
};