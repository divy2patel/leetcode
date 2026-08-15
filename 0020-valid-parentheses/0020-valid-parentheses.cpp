class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 != 0) return false;

        stack<char> str;
        for (char c : s) {
            if (c == '{' || c == '(' || c == '[') {
                str.push(c);
            } else {
                if (str.empty()) return false;  // nothing to match against

                if (c == '}' && str.top() != '{') return false;
                else if (c == ']' && str.top() != '[') return false;
                else if (c == ')' && str.top() != '(') return false;
                else str.pop();
            }
        }
        return str.empty();  // catches unclosed opens like "((("
    }
};