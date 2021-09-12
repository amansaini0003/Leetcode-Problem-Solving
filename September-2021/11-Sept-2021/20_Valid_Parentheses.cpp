class Solution {
public:
    bool isValid(string s) {
        if(s[0] == ')' || s[0] == ']' || s[0] == '}')
            return false;
        
        stack<char> stk;
        
        for(int i=0; i<s.size(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                stk.push(s[i]);
                continue;
            }
             if(stk.empty())
                return false;
            char top = stk.top();
            
            if(s[i]==')' && top=='(')
                    stk.pop();
            else if(s[i]==']' && top=='[')
                    stk.pop();
            else if(s[i]=='}' && top=='{')
                    stk.pop();
            else
                return false;
        }
        if(!stk.empty())
            return false;
        
        return true;    
    }
};