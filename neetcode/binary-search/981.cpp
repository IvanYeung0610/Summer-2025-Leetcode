// Ivan Yeung
// 981. Time Based Key-Value Store

#include <string>
#include <vector>
#include <unordered_map>
#include <utility>

using namespace std;

class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        map[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (map.find(key) == map.end()) return "";
        int left = 0;
        int right = map[key].size() - 1;
        string res = "";
        while (left <= right) {
            int mid = (left + right) / 2;
            if (map[key][mid].first <= timestamp) {
                res = map[key][mid].second;
            }
            if (map[key][mid].first > timestamp) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return res;

    }
private:
    unordered_map<string, vector<pair<int, string>>> map;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
