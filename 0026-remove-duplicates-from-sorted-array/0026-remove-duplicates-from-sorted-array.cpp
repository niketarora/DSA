class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1;
        int i = 0;
        for(int j=0; j<nums.size(); j++){
            if(nums[i] != nums[j]){ 
                k++; i++;
                nums[i] = nums[j];
            }
        }
        return k;
    }
};