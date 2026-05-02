class Solution {
public:
    // Brute force approach:
    // TC : O(n^2)
    // SC : O(1)
    // int maxProfit(vector<int>& prices) {
    //     int maxProfit = 0;
    //     for(int i = 0; i < prices.size(); i++){
    //         for(int j = i + 1; j < prices.size(); j++){
    //             int subs = prices[j] - prices[i];
    //             if(subs > maxProfit){
    //                 maxProfit = subs;
    //             }            
    //         }
    //     }
    //     return maxProfit;
    // }

    // Better approach
    // TC : O(n)
    // SC : O(1)
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;

        for(int i = 1; i < prices.size(); i++){
            if(prices[i] < minPrice){
                minPrice = prices[i];
            } else {
                int profit = prices[i] - minPrice;
                if(profit > maxProfit){
                    maxProfit = profit;
                }
            }
        }

        return maxProfit;
    }
};
