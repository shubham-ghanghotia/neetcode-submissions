class Solution {
public:

    // // Brute force approach: 
    // // TC : O(n^2)
    // // SC : O(1)
    // vector<int> twoSum(vector<int>& numbers, int target) {
    //     int size = numbers.size();

    //     for(int i =0; i < size; i++){
    //         for(int j = i + 1; j < size; j++){
    //             int sum = numbers[i] + numbers[j];
    //             if(sum == target){
    //                 return {i+1, j+1};
    //             }
    //         }
    //     }
    //     return {};
    // }

    // Optimal soluction
    // TC : O(n)
    // SC : O(1)
    vector<int> twoSum(vector<int>& numbers, int target) {  
        int size = numbers.size();
        int left = 0;
        int right = size - 1;

        while(left < right){
            int sum = numbers[left] + numbers[right];

            if(sum == target){
                return {left + 1, right + 1};
            } else if(sum < target){
                left++;
            } else {
                right--;
            }
        }

        return {};
    }
};















