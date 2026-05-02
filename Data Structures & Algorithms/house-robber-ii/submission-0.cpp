class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        int case1 = robLinear(nums, 0, n-2);
        int case2 = robLinear(nums, 1, n-1);

        return max(case1, case2);
        
    }

    int robLinear(vector<int> &nums, int start, int end){
        int n = nums.size();
        if(n == 0) return nums[0];

        int prev2 = nums[start];
        int prev1 = max(prev2, nums[start + 1]);

        for(int i = start + 2; i <= end; i++){
            int curr = max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};
