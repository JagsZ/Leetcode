class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        int index = 0;
        unordered_map<int, int> map;
        
        if(n % groupSize != 0)
            return false;
        
        sort(hand.begin(), hand.end());
        for(auto x : hand)
            map[x]++;
        
        while(index < n && map.size() >= groupSize){
            if(map.find(hand[index]) == map.end()){
                index++;
                continue;
            }
            int start = hand[index];
            while((start - hand[index]) < groupSize){
                if(map.find(start) == map.end()){
                    return false;
                }
                map[start]--;
                if(map[start] == 0)
                       map.erase(start);
                start++;
            }
        }
        return map.size() == 0;
    }
};