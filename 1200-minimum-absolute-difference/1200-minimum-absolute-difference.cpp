class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int min = INT_MAX;
        int n = nums.size();
        for(int i=0 ;i<n-1; i++){
            int sum = nums[i+1] - nums[i];
            if(min>sum)
                min = sum;
        }
        int i = 0;
        while(i<n-1){
            vector<int> res;
            int dif = nums[i+1] - nums[i];
            if(dif == min){
                res.push_back(nums[i]);
                res.push_back(nums[i+1]);
                ans.push_back(res);
            }
            i++;
        }
        return ans;
    }
};