class Solution {
public:
    string convert(string s, int numRows) {
        string ans;
        int index = 0, row = 0, n = s.length();
        int char_insert = 2*(numRows - 1);
        
        if(n == 1 || numRows == 1)
            return s;
        
        while(row < numRows){
            index = row;
            while(index < n){
                ans += s[index];
                
                if(row != 0 && row != numRows-1){
                    int second_index = char_insert - 2*row + index;
                    if(second_index < n)
                        ans += s[second_index];
                }
                index += 2*numRows - 2;
            }
            row++;
        }
        return ans;
    }
};