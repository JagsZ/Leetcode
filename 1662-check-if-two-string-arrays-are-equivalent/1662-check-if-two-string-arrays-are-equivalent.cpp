class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string str1 = "";
        string str2 = "";
        int index1 = 0, index2 = 0;
        
        while(index1 < word1.size()){ 
            str1 += word1[index1]; 
            index1++;
        }
        while(index2 < word2.size()){
            str2 += word2[index2];
            index2++;
        }
        return str1 == str2? true : false;
    } 
};