class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<int>res;
        //Count the frequency of each number's occurance by using map.
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;

        }
        //Use a vector for storing the frequencies.
        for(auto it:mp)
        {
            res.push_back(it.second);
        }
        //Sort the given vector in descending order
        sort(res.begin(),res.end(),greater<int>());
        //Store the maximum count in ans  
        int ans=res[0];
        //We check further for values equal to maximum frequency in res and then add    
        //it to ans 
        for(int i=1;i<res.size();i++)
        {
            if(res[i]==res[0])
            ans=ans+res[i];
        }
        //Finally return the obtained ans.
        return ans;
    }
};