class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> map;

public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        map[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        auto& val = map[key];
        int left = 0;
        int right = val.size() - 1;
        string res = "";

        while(left <= right) {
            int mid = left + (right - left) / 2;

            if(val[mid].first <= timestamp) {
                res = val[mid].second;
                left = mid + 1;
                
            }
            else {
                right = mid - 1;
            }
        }
        return res;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */