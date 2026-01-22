class Solution {
public:
    bool sorted(vector<int>& nums){
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]>nums[i+1]){
                return false;
            }
        }
        return true;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int operation = 0;
        while(!sorted(nums) && nums.size()>1){
            int idx = -1;
            int min = INT_MAX;
            for(int i=0; i<nums.size()-1; i++){
                int sum = nums[i] + nums[i+1];
                if(sum<min){
                    idx = i;
                    min = sum;
                }
            }
            nums[idx] = nums[idx] + nums[idx+1];
            nums.erase(nums.begin() + idx + 1);
            operation++;
        }
        return operation;
    }
};