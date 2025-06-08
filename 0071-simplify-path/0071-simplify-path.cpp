class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        string current;

        for(char c : path + "/") {
            if(c == '/') {
                if(current == "..") {
                    if(!stack.empty()) stack.pop_back();
                }
                else if(!current.empty() && current != ".") {
                    stack.push_back(current);
                }
                current.clear();
            }
            else {
                current += c;
            }
        }

        string result = "/";

        for(int i = 0; i < stack.size(); i++) {
            result += stack[i];
            result += "/";
        }
        if (result.length() > 1) result.pop_back();
        return result;

    }
};