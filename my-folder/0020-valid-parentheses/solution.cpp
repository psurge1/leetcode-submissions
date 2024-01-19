class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> closingPs;
        closingPs['{'] = '}';
        closingPs['['] = ']';
        closingPs['('] = ')';
        // create a char stack
        // read input chars of string by index
        // on [ { ( push to stack
        // on ] } ) pop from stack
        // if pop isn't equal to input, return false
        // if pop while stack is empty, return false
        stack<char> parenthesisStack;
        for(int i = 0, k = s.length(); i < k; ++i)
        {
            switch(s[i])
            {
                case '{':
                case '[':
                case '(':
                    parenthesisStack.push(s[i]);
                    break;
                case '}':
                case ']':
                case ')':
                    if (parenthesisStack.empty())
                        return false;
                    char p = parenthesisStack.top();
                    parenthesisStack.pop();
                    if (closingPs[p] != s[i])
                        return false;
            }
        }
        return parenthesisStack.empty();

    }
};
