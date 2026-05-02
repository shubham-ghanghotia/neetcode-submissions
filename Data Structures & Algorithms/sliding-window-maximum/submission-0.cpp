class Solution {
public:
    // // Brute force Approach
    // // TC : O(n * k)
    // // SC : O(1)
    // vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    //     int m = nums.size();
    //     int left = 0;
    //     vector<int> result;

    //     for(int i = k - 1; i < m; i++){
    //         int maxN = INT_MIN;
    //         int start = left;

    //         while(start <= i){
    //             maxN = max(maxN, nums[start]);
    //             start++;
    //         }
    //         result.push_back(maxN);
    //         left++;
    //     }

    //     return result;
    // }
   
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        int m = nums.size();
        int left = 0;
        vector<int> result;


        for(int i = 0; i < m; i++){

            while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);

            if(dq.front() < left){
                dq.pop_front();
            }

            if(i >= k - 1){
                result.push_back(nums[dq.front()]);
                left++;
            }
        }

        return result;
    }
};
