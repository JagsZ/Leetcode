class Solution {
public:
void expandSubstring(string s,int left,int right, int &count)
{
    while(s[left] == s[right]){
        left--;
        right++;
        count++;
        if(left < 0 || right > s.length())
            break;
    }
}
    
public:
    int countSubstrings(string s) {
        
    int count = 0;
    for(int i=0; i<s.length();i++){
        expandSubstring(s,i,i,count);
        expandSubstring(s,i, (i+1),count);
    }
    return count;
    }
};