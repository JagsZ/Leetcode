class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int cnt=0,c=0;
        if(s.size()!=goal.size()) return false;
        vector<int>a(256),b(256);
        for(int i=0;i<s.size();i++){
            a[s[i]-'a']++;
            b[goal[i]-'a']++;
            if(s[i]!=goal[i]){
                cnt++; //counting different positions
            }
        }
        if(cnt>2) return false;
        for(int i=0;i<256;i++){
            if(a[i]!=b[i]) return false;
            if(a[i]>=2) c++; //if we have freq==2 of any char then we can swap them if the strings are equal
        }
        if(s==goal && c<1) return false;
        return true; 
    }
};