class Solution {
    unordered_map<string, int> map;
    vector<vector<string>> ans;
    string start = "";
    void dfs(string word, vector<string> &seq){
        if(word == start){
            vector<string> tmp = seq;
            reverse(tmp.begin(), tmp.end());
            ans.push_back(tmp);
            return;
        }
        
        int steps = map[word];
        for(int i = 0; i < word.size(); i++){
            char orig = word[i];
            for(char ch = 'a'; ch <= 'z'; ch++){
                word[i] = ch;
                if(map.find(word) != map.end() && map[word]+1 == steps){
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back();
                }
            }
            word[i] = orig;
        }
        
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> st;
        queue<pair<string, int>> q;
        vector<string> seq;
        
        start = beginWord;
        map[beginWord] = 1;    
        for(auto it: wordList)
            st.insert(it);
        q.push({beginWord, 1});
        st.erase(beginWord);
        seq.push_back(endWord);
        
        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            if(word == endWord){
                cout<<steps<<endl;
                break;
            }
            
            for(int i = 0; i < word.size(); i++){
                char orig = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    if(st.find(word) != st.end()){
                        q.push({word, steps+1});
                        st.erase(word);
                        map[word] = steps+1;
                    }
                }
                word[i] = orig;
            }
        }
        dfs(endWord, seq);
        return ans;
    }
};