class Solution {
public:
    // // Brute force approach:
    // // TC : O(n^2)
    // // SC : O(1)
    // int maxArea(vector<int>& heights) {
    //     int size = heights.size();
    //     int max = 0;
    //     for(int i = 0; i < size; i++){
    //         for(int j = i + 1; j < size; j++){
    //             int diff = abs(i - j);
    //             int area = min((heights[j] * diff), (heights[i] * diff));
    //             if(area > max){
    //                     max = area;
    //             }
    //         }
    //     }
    //     return max;
    // }

     int maxArea(vector<int>& heights) {
        int size = heights.size();
        int left = 0;
        int right = size - 1;

        int max = 0;

        while(left < right){

            int diff = abs(left - right);

            int area = min(heights[left] , heights[right]) * diff;

            if(area > max){
                max = area;
            }

            if(heights[left] > heights[right]){
                right--;
            }else {
                left++;
            }
        }

        return max;
     }
};












