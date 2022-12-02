class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<char, int> freq1;
        unordered_map<char, int> freq2;
        vector<int> w1,w2;
    
        if(word1.length() != word2.length())
            return false;
        
        for(int i = 0; i < word1.length(); i++){
            freq1[word1[i]]++;
            freq2[word2[i]]++;
        }
        for(int i = 0; i < word1.length(); i++){
            if(freq2.find(word1[i]) == freq2.end())
                return false;
            w1.push_back(freq1[word1[i]]);
            w2.push_back(freq2[word2[i]]);
        }
        if(w1 == w2)
            return true;
        sort(w1.begin(), w1.end());
        sort(w2.begin(), w2.end());
        return w1 == w2;
    }
};