class Solution {
public:
   int findIntersection(unordered_set<string> &s1,unordered_set<string> &s2){
        int total = 0;
        for(auto i:s1){
            if(s2.find(i)!=s2.end()) total++;
        }
        return total;
    }

    long long distinctNames(vector<string>& ideas) {
        int n = ideas.size();
        long long ans = 0;

        vector<unordered_set<string>> mp(26); // unordered because here ordering doesn't matter O(1)
        for(auto i:ideas){
            mp[i[0]-'a'].insert(i.substr(1));
        }

        for(int i=0;i<25;i++){
            if(mp[i].size()!=0){
                for(int j=i+1;j<26;j++){
                    if(mp[j].size()!=0){
                        int comm = findIntersection(mp[i],mp[j]); // common elements
                        ans+=2*(mp[i].size()-comm)*(mp[j].size()-comm);
                    }
                }   
            }
        }
        return ans;
    }
};