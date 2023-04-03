class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int start = 0, end = people.size()-1, ans = 0;
        sort(people.begin(), people.end());
        
        while(start <= end){
            if(people[end] + people[start] > limit){
                end--;
            }else{
                start++;
                end --;
            }
            ans++;
        }
        return ans;
    }
};