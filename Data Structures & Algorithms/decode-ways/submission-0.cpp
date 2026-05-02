class Solution {
public:
    // int numDecodings(string s) {
    //     int n = s.size();

    //     vector<int> dp(n+1);

    //     dp[0] = 1;
    //     dp[1] = (s[0] == '0') ? 0 : 1;
        
    //     for(int i = 2; i <= n; i++){
    //         int oneDigit = stoi(s.substr(i-1, 1));
    //         int twoDigit = stoi(s.substr(i-2, 2));

    //         if(oneDigit >= 1){
    //             dp[i] += dp[i - 1];
    //         };

    //         if(twoDigit >= 10 && twoDigit <= 26){
    //             dp[i] += dp[i - 2];
    //         }

    //     }
        
    //     return dp[n];
    // }

    int numDecodings(string s) {
        int n = s.size();

        if(n == 0 || s[0] == '0') return 0;

        int prev2 = 1;  // dp[i-2]
        int prev1 = 1;  // dp[i-1]

        for(int i = 2; i <= n; i++){
            int curr = 0;

            int oneDigit = s[i-1] - '0';
            int twoDigit = (s[i-2] - '0') * 10 + (s[i-1] - '0');

            if(oneDigit >= 1)
                curr += prev1;

            if(twoDigit >= 10 && twoDigit <= 26)
                curr += prev2;

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};
