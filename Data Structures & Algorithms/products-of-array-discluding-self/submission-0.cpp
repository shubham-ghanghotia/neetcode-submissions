class Solution {
public:
    // vector<int> productExceptSelf(vector<int>& nums) {
    //     // Brute force approach
    //     // time complexity O(n^2)
    //     // space complexity O(1)
    //     vector<int> result;

    //     for(int i = 0; i < nums.size(); i++){
    //         int multi = 1;
    //         for(int j = 0; j < nums.size(); j++){
    //             if(i != j){
    //                 multi *= nums[j];
    //             }
    //         }
    //         result.push_back(multi);
    //     }

    //    return result;

    // }
     vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;

        int n = nums.size();

        vector<int> left(n, 1);

        for(int i = 1; i < n; i++){
            left[i] = left[i - 1] * nums[i - 1];
        }

        vector<int> right(n, 1);

        for(int j = n - 2; j >=0; j--){
            right[j] = right[j + 1] * nums[j + 1];
        }

        for(int i = 0; i < n; i++){
            result.push_back(left[i] * right[i]);
        }
        
       return result;

    }
};
