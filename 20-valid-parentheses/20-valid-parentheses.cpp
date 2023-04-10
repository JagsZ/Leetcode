class Solution {
public:
    bool isValid(string s) {
        int index = 0;
        stack<char> st;
        
        while(index < s.length()){
            if(s[index] == '(' || s[index] == '{' || s[index] == '['){
                st.push(s[index]);
            }else if(st.empty() == false){
                if((s[index] == ')' && st.top() != '(') || (s[index] == '}' && st.top() != '{') ||
                 (s[index] == ']' && st.top() != '['))
                    return false;
                st.pop();
            }else 
                return false;
            index++;
        }
        if(st.empty() == true)
            return true;
        return false;
    }
};