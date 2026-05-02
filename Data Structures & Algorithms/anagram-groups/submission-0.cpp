class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for(string str: strs){

            vector<int> freq(26, 0);

            for(char ch: str){
                freq[ch - 'a']++;
            }

            string key = "";
            for(int count : freq){
                key += to_string(count) + "#";
            }

            mp[key].push_back(str);
        }

        vector<vector<string>> result;

        for(auto &[key, value] : mp){
            result.push_back(value);
        };
        return result;
    }

};
