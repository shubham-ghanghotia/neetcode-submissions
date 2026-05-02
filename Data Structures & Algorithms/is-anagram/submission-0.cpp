class Solution {
public:
    bool isAnagram(string s, string t) {
         if(s.size() != t.size()){
            return false;
        };

        unordered_map<char, int> ss;

        for (int i = 0; i < s.size(); i++) {
            ss[s[i]]++;  
            ss[t[i]]--;   
        }

        for (auto &[key, value] : ss) {
            if (value != 0) {
                return false;
            }
        }

        return true;

    }
};
