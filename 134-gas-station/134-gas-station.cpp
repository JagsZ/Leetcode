class Solution {
  
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tgas = 0, cgas = 0, tcost = 0, n = gas.size(), start_index = 0;
        
        for(int i = 0; i < n; i++){
            tgas += gas[i] - cost[i];
            cgas += gas[i] - cost[i];
            if(cgas < 0){
                start_index = i+1;
                cgas = 0;
            }
        }
        return tgas >= 0 ? start_index : -1;
    }
};