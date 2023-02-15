class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int carry = 0, n = num.size(), i= 0;
        vector<int> ans;
        for(i = n-1; i >=0 && k > 0; i--){
            int digit = k % 10;
            int sum = num[i] + digit + carry;
            carry = (sum / 10);
            ans.push_back(sum % 10);
            k = k / 10;
        }
        while( i >= 0){
            int sum = num[i] + carry;
            carry = (sum / 10);
            ans.push_back(sum % 10);
            i--;
        }
        while( k > 0){
            int sum = (k % 10) + carry;
            carry = (sum / 10);
            ans.push_back(sum % 10);
            k = k / 10;
        }
        if(carry)
            ans.push_back(carry);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};