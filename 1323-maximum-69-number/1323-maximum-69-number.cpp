class Solution {
public:
    int maximum69Number (int num) {
        stack<int> st;
        int ans = 0;
        while(num > 0){
            int digit = num % 10;
            st.push(digit);
            num = num / 10;
        }
        int flag = false;
        while(!st.empty()){
            ans *= 10;
            if(st.top() == 6 && flag == false){
                ans += 9;
                flag = true;
            }
            else{
                ans += st.top();
            }
            st.pop();
        }
        return ans;
    }
};