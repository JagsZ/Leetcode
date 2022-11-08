class Solution {
public:
    string makeGood(string s) {
        string ans = "";
        stack<char> st;
        
        for(int i = 0; i < s.length(); i++){
            while(!st.empty() && (i < s.length()) && ((s[i] == st.top() + ' ') || (s[i] + ' '== st.top()))){
                st.pop();
                i++;
                continue;
            }
            if(i < s.length())
                st.push(s[i]);
        }
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};