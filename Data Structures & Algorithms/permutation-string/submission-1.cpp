class Solution {
public:
    // Brute force approach
    // TC : O(n) + O(nklogk)
    // SC : O(1)
    // bool checkInclusion(string s1, string s2) {

    //     sort(s1.begin(), s1.end());

    //     for(int i = 0; i <= s2.size() - s1.size(); i++){
    //         string str = s2.substr(i,  s1.size());
    //         if(s1 == str){
    //             return true;
    //         }
    //     }
    //     return false;
    // }
    
    bool checkInclusion(string s1, string s2) {
        int left = 0;

        vector<int> freq(26, 0);
        for(char sub1: s1){
            freq[sub1 - 'a']++;
        }

        vector<int> freq1(26, 0);

        for(int i = 0; i < s2.size(); i++){
            freq1[s2[i] - 'a']++;

            int window_size = i - left + 1;

            if(window_size > s1.size()){
                freq1[s2[left] - 'a']--;
                left++;
            }

            if(freq == freq1){
                return true;
            }

        }
        return false;
    }
};
