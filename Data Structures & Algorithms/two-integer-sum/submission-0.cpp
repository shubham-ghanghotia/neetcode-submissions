class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ss;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            if (ss.count(complement)) {
                return {ss[complement], i};
            }

            ss[nums[i]] = i; 
        }

        return {};
    }
};