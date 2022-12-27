class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n=capacity.size();
        int m=rocks.size();
        vector<int> v(n);
        long long remaining=0;
        for(int i=0;i<n;i++){
            remaining+=(capacity[i]-rocks[i]);
            v[i]=(capacity[i]-rocks[i]);
        }
        if(additionalRocks>=remaining)
            return n;
        sort(v.begin(),v.end());
        int i=0;
        long long sum=0;
        while(additionalRocks>=v[i]){
            additionalRocks-=v[i];
            i++;
        }
        return i;
    }
};