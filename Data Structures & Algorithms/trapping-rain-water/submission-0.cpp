class Solution {
public:
    // Brute force Approach:
    // TC : O(n^2)
    // SC : O(1)
    // int trap(vector<int>& height) {
    //     int size = height.size();
    //     int totalWater = 0;

    //     for(int i = 0; i < size; i++){

    //         int leftMax = 0;
    //         int rightMax = 0;

    //         for(int j = 0; j <= i; j++){
    //             leftMax = max(leftMax, height[j]);
    //         };

    //         for(int j = i; j<size; j++){
    //             rightMax = max(rightMax, height[j]);
    //         }

    //         int total = min(leftMax, rightMax) - height[i];

    //         if(total > 0){
    //             totalWater+=total;
    //         }
    //     }

    //     return totalWater;
        
    // }

    // Better Approach:
    // TC : O(n)
    // SC : O(1)
    // int trap(vector<int>& height) {
    //     int n = height.size();
    //     int totalWater = 0;

    //     vector<int> leftMax(n, 0);
    //     vector<int> rightMax(n, 0);

    //     leftMax[0] = height[0];
    //     rightMax[n -1] = height[n - 1];

    //     // Fill left max value
    //     for(int i = 1; i < n; i++){
    //         leftMax[i] = max(height[i], leftMax[i - 1]);
    //     };

    //     // Fill right max value
    //     for(int i = n - 2; i >=0; i--){
    //         rightMax[i] = max(height[i], rightMax[i + 1]);
    //     }

    //     for(int i = 0; i < n; i++){
    //         int water = min(leftMax[i], rightMax[i]) - height[i];
    //         if(water > 0){
    //             totalWater += water;
    //         }
    //     }
    //     return totalWater;
    // }



    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n - 1;

        int leftMax = 0;
        int rightMax = 0;
        int totalWater = 0;

        while(left < right){
            if(height[left] < height[right]){
                leftMax = max(leftMax, height[left]);
                totalWater += leftMax - height[left];
                left++;
            } else {
                rightMax = max(rightMax, height[right]);
                totalWater += rightMax - height[right];
                right--;
            }
        }

        return totalWater;
    }

};
