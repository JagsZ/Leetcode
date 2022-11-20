class Solution {
public:
    int calculate(string s) {
        int len = s.length();
        int sign = 1;
        int ans = 0;
        long int currNo = 0;
        stack<int> st;
        for (int i = 0; i < len; i++) {
            if (isdigit(s[i])) {
                currNo = s[i] - '0';
                while (i + 1 < len && isdigit(s[i+1])) {
                    currNo = currNo * 10 + s[i + 1] - '0';
                    i++;
                }
                currNo = currNo * sign;
                ans += currNo;
                currNo = 0;
                sign = 1;
            } else if (s[i] == '+')
                sign = 1;
            else if (s[i] == '-')
                sign = -1; //  -1 respresents negative sign
            else if (s[i] == '(') {
                st.push(ans); // store the result calculated so far
                st.push(sign); // store the upcoming sign
                ans = 0;
                sign = 1;
            } else if (s[i] == ')') {
                int prevSign = st.top();
                st.pop();
                ans = prevSign* ans ;
                int prevAns = st.top();
                st.pop();
                ans = ans + prevAns;
            }

        }
        return ans;
    }
};