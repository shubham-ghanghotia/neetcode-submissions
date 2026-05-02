class Solution {
public:
    // vector<int> topKFrequent(vector<int>& nums, int k) {

    //     unordered_map<int, int> mp;

    //     for(int &num: nums){
    //         mp[num]++;
    //     };

    //     vector<pair<int, int>> vec;
        
    //     for(auto &[key, value] : mp){
    //         vec.emplace_back(key, value);
    //     }

    //   sort(vec.begin(), vec.end(), [](auto &a, auto &b){
    //         return a.second > b.second;
    //     });


    //     vector<int> result;

    //     for(int i = 0; i < k; i++){
    //         result.push_back(vec[i].first);
    //     }


    //     return result;
        
    // }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for(int num: nums){
            mp[num]++;
        };

        vector<vector<int>> bucket(nums.size() + 1);

        for(auto &[num, freq] : mp){
            bucket[freq].push_back(num);
        }

        vector<int> result;

        for(int i = nums.size(); i >= 0 && result.size() < k; i--){
            for(int num : bucket[i]){
                result.push_back(num);
                if(result.size() == k) break;
            }
        }

        return result;
        
    }
};
