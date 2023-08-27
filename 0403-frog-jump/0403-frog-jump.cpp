class Solution {
    int binarySearch(vector<int> &stones, int l, int r, int target){
        while( l <= r){
            int mid = (l+r)/2;
            if(stones[mid] == target){
                return mid;
            }
            else if(target < stones[mid]){
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return -1;
    }
    int canCrosshelper(vector<int> &stones, int ind, int jump_size, vector<vector<int>> &memo){
    
            
        if(memo[ind][jump_size] >= 0)
            return memo[ind][jump_size];
        
        int indx1 = binarySearch(stones, ind+1, stones.size()-1, stones[ind]+jump_size);
        if(indx1 >= 0 && canCrosshelper(stones, indx1, jump_size, memo) == 1){
            memo[ind][jump_size] = 1;
            return 1;
        }

        
        int indx2 = binarySearch(stones, ind+1, stones.size()-1, stones[ind]+jump_size-1);
        if(indx2 >= 0 && canCrosshelper(stones, indx2, jump_size-1, memo) == 1){
            memo[ind][jump_size-1] = 1;
            return 1;
        }
        
        int indx3 = binarySearch(stones, ind+1, stones.size()-1, stones[ind]+jump_size+1);
        if(indx3 >= 0 && canCrosshelper(stones, indx3, jump_size+1, memo) == 1){
            memo[ind][jump_size+1] = 1;
            return 1;
        }
        memo[ind][jump_size] = (ind == stones.size()-1)? 1 : 0;
        return memo[ind][jump_size];
    }
    
    public:
    bool canCross(vector<int> &stones) {
        vector<vector<int>> memo(stones.size(), vector<int>(stones.size(), -1));
        return canCrosshelper(stones, 0, 0, memo) == 1;
        
    }
};