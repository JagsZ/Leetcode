
class Solution {
    int mod = 1000000007;
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        
        stack<pair<int, int>> st1, st2;
        
        for(int i = 0; i < n; i++){
            int count = 1;
            while(!st1.empty() && st1.top().first > arr[i]){
                count += st1.top().second;
                st1.pop();
            }
            left[i] = count;
            st1.push({arr[i], count});
        }
        
        for(int i = n-1; i >= 0; i--){
            int count = 1;
            while(!st2.empty() && st2.top().first >= arr[i]){
                count += st2.top().second;
                st2.pop();
            }
            right[i] = count;
            st2.push({arr[i], count});
        }
        
        long ans = 0;
        for(int i = 0; i < n; i++){
            long  mn = (left[i] * right[i]) % mod;
            ans = (ans + ( mn * arr[i])) % mod;
        }
        return ans;
    }
};