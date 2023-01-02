class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> map;
        
        //sort(bills.begin(), bills.end());
        
        for(int i = 0; i < bills.size(); i++){
            
            if(bills[i] == 5){
                map[bills[i]]++;
                continue;
            }
            map[bills[i]]++;
            if((map.find(5) == map.end()) || map[5] <= 0)
                    return false;
            
            if(bills[i] == 10){
                map[5]--;
            }else if(bills[i] == 20){
                if((map.find(10) != map.end()) && map[10] > 0){
                    map[5]--;
                    map[10]--;
                }else{
                    if(map[5] < 3)
                        return false;
                    map[5] -= 3;
                }
            }
        }
        return true;
    }
};