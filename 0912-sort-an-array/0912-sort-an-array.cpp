class Solution {
    void merge(int l, int mid, int r, vector<int> &nums){
        vector<int> tmp1;
        vector<int> tmp2;
        int index =  l, index1 = 0, index2 = 0;
        
        for(int i = l; i <= mid; i++)
            tmp1.push_back(nums[i]);
        
        for(int i = mid+1; i <= r; i++)
            tmp2.push_back(nums[i]);
        
        while(index1 < tmp1.size() && index2 < tmp2.size()){
            if(tmp1[index1] <= tmp2[index2]){
                nums[index] = tmp1[index1];
                index1++;
            }else{
                nums[index] = tmp2[index2];
                index2++;
            }
            index++;
        }
        while(index1 < tmp1.size()){
            nums[index] = tmp1[index1];
            index1++;
            index++;
        }
        while(index2 < tmp2.size()){
            nums[index] = tmp2[index2];
            index2++;
            index++;
        }
    }
    void merge_sort(int l, int r, vector<int> &nums){
        if(l >= r)
            return;
        int mid = (l + r) / 2;  
        merge_sort(l, mid, nums);
        merge_sort(mid+1, r, nums);
        merge(l, mid, r, nums);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        merge_sort(l, r, nums);
        return nums;
    }
};