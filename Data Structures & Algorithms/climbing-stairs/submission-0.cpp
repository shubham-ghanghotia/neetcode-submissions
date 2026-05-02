class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;
        
        int total = 0;

        int prev1 = 1;
        int prev = 2;

        for(int i = 3; i <= n; i++){
            total = prev1 + prev;
            prev1 = prev;
            prev = total;
        }
        return total;
    }
};
