class TimeMap {
public:
//Binary search for the first timestamp > target; then j is the last timestamp <= target.
    unordered_map<string, vector<pair<string, int>>> ump;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        ump[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {

        if (ump.find(key) == ump.end())
            return "";

        int i = 0;
        int j = ump[key].size() - 1;

        while (i <= j) {

            int mid = i + (j - i) / 2;

            if (ump[key][mid].second <= timestamp) {
                i = mid + 1;
            }
            else {
                j = mid - 1;
            }
        }

        // j is the largest index whose timestamp <= target
        if (j < 0)
            return "";

        return ump[key][j].first;
    }
};
