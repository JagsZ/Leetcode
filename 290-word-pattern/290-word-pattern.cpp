class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        unordered_map<string , char> map;
        vector<char> di(26, 0);
        string word = "", ans = "";
        int index = 0;
        
        while(ss >> word){
            if(index >= pattern.length()) 
                break;
            if(di[pattern[index] - 'a'] == 0)
                map[word] = pattern[index];
            di[pattern[index] -  'a'] = 1;
            index++;
        }
        stringstream sss(s);
        while(sss >> word){
            if(word != " " && (map.find(word) != map.end())){
                ans += map[word];
            }
        }
        return ans == pattern;
    }
};