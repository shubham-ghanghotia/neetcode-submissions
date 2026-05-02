class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

    // Brute force approach
    // TC : O(nlogn)
    // SC: O(1)
    //     sort(nums.begin(), nums.end());

    //     int longest = 1;
    //     int current = 1;

    //     for(int i = 1; i < nums.size(); i++){
    //         int subs = nums[i] - nums[i - 1];
    //         if(subs == 0){
    //             continue;
    //         } else if(subs == 1){
    //             current++;
    //         } else {
    //             longest = max(longest, current);
    //             current = 1;
    //         }
            
    //     }
    //     return max(longest, current);
    // }


    // TC : O(n)
    // SC : O(n)
    unordered_set<int> s(nums.begin(), nums.end());
        
        int longest = 0;
        
        for(int num: s){
            
            if(s.find(num - 1) == s.end()){
                int currentNum = num;
                int count = 1;
                
                while(s.find(currentNum + 1) != s.end()){
                    count++;
                    currentNum++;
                }
                
                longest = max(longest, count);
            }
        }
        
        return longest;

    }
};
