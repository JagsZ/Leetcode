class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count = 0, i = 0, start_bits = 0, goal_bits = 0;
        if(start != 0)
            start_bits = log2(start)+1;
        
        if(goal != 0)
            goal_bits = log2(goal)+1;
        
        while(i < start_bits || i < goal_bits){
            if((start & (1 << i)) ^ (goal & (1 << i)))
                count++;
            i++;
        }
        return count;
    }
};