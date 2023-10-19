class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s1="",t1="";
        
        for(int i=0; i<s.length(); i++){
            if(s1.length() > 0 && s[i]=='#'){
                s1.erase(s1.length()-1);
            }else if(s[i] !='#')
                s1 += s[i];
        }
        for(int i=0; i<t.length(); i++){
            if(t1.length() > 0 && t[i]=='#'){
                t1.erase(t1.length()-1);
            }else if(t[i] !='#')
                t1 += t[i];
        }
        return (s1==t1)? true:  false;
    }
};