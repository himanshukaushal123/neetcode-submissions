class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> ump;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        ump[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {

        if (ump.find(key) == ump.end())
            return "";

        string ans = "";

        for (auto it : ump[key]) {

            if (it.second <= timestamp) {
                ans = it.first;
            }
            else {
                break;
            }
        }

        return ans;
    }
};
