class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int m = bank.size(), n = bank[0].length(), count = 0, r1=0,r2=0,beam=0;
        vector<int> rest;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(bank[i][j] == '1')
                    count++;
            }
            rest.push_back(count);
            count = 0;
        } 
        r2=r1+1; 
        while(r2 <= rest.size()-1){
            if(rest[r2] > 0){
                beam += rest[r1] * rest[r2];
                r1=r2;
                r2++;
            }
            else{
                r2++;
            }
        }
        return beam;  
    }
};