class Solution {
public:
    bool isValid(string c) {
        stack<char> st;

        for (char c : c) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if (st.empty())
                    return 0;
                char top = st.top();
                st.pop();

                if ((c == ')' && top != '(') || (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) {
                    return 0;
                }
            }
        }
        return st.empty();
    }
};