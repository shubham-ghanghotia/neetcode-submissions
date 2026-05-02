class Solution {
public:
    // int characterReplacement(string s, int k) {

    //     int maxLen = 0;

    //     for(int i = 0; i < s.size(); i++){
    //         for(int j = i; j < s.size(); j++){
    //             int start = i;
    //             int window_size = j - i + 1;

    //             // find maximum repeating character
    //             unordered_map<char, int> freq;

    //             int maxF = 0;

    //             while(start <= j){
    //                 freq[s[start]]++;
    //                 maxF = max(maxF,freq[s[start]]);
    //                 start++;
    //             }

    //             // calculate replacement needed
    //             int replacement_needed = window_size - maxF;

    //             // updated with max length
    //             if(replacement_needed <= k){
    //                 maxLen = max(maxLen, window_size);
    //             }

    //         }
    //     }

    //     return maxLen;
    // }
    // int characterReplacement(string s, int k) {
    //     int maxLen = 0;

    //     for(int i = 0; i < s.size(); i++){
    //         unordered_map<char, int> freq;

    //         int maxF = 0;

    //         for(int j = i; j < s.size(); j++){
    //             freq[s[j]]++;
    //             maxF = max(maxF, freq[s[j]]);
    //             int window_size = j - i + 1;

    //            int replacement_needed = window_size - maxF;

                // if(replacement_needed <= k){
                //     maxLen = max(maxLen, window_size);
                // }
    //         }

            
    //     }


    //     return maxLen;
    // }

    // int characterReplacement(string s, int k) {
    //     int maxLen = 0;
    //     unordered_map<char, int> freq;

    //     int left = 0;
    //     int maxF = 0;

    //     for(int i = 0; i < s.size(); i++){
    //         freq[s[i]]++;
    //         maxF = max(maxF, freq[s[i]]);
    //         int window_size = i - left + 1;
    //         int replacement_needed = window_size - maxF;

    //         if(replacement_needed <= k){
    //             maxLen = max(maxLen, window_size);
    //         } else {
    //             freq[s[left]]--;
    //             left++;
    //         }

    //     }

    //     return maxLen;
    // }
    int characterReplacement(string s, int k) {
        int maxLen = 0;
        vector<int> freq(26, 0);

        int left = 0;
        int maxF = 0;

        for(int i = 0; i < s.size(); i++){
            freq[s[i] - 'A']++;
            maxF = max(maxF, freq[s[i] - 'A']);
            int window_size = i - left + 1;
            int replacement_needed = window_size - maxF;

            if(replacement_needed <= k){
                maxLen = max(maxLen, window_size);
            } else {
                freq[s[left] - 'A']--;
                left++;
            }

        }

        return maxLen;
    }
};
