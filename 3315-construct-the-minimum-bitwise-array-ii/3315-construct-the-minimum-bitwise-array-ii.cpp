class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(nums[i] == 2){
                ans.push_back(-1);
                continue;
            }
            bool flag = false;
            for(int j=0; j<32; j++){
                if((nums[i] & (1<<j))  >  0){
                    continue;
                }
                int x = nums[i] ^ (1<<(j-1));
                ans.push_back(x);
                flag = true;
                break;
            }
            if(flag == false){
                ans.push_back(-1);
            }
        }
        return ans;
    }
};