class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        string ans = "";
        for(int i = 0; i < s.length(); i++){
            while(!st.empty() && i < s.length() && st.top() == s[i]){
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