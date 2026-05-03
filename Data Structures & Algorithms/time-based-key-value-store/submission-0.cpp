class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> kv;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        kv[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(kv.find(key) == kv.end()) return "";

        auto &pairs = kv[key];

        int start = 0, end = pairs.size() - 1;

        string result = "";

        while(start <= end){
            int mid = start + (end - start) / 2;

            if(pairs[mid].first == timestamp){
                return pairs[mid].second;
            } else if(pairs[mid].first < timestamp){
                result = pairs[mid].second;
                start = mid + 1;
            } else {
                end = mid - 1;
            }

        }
        return result;
    }
};
