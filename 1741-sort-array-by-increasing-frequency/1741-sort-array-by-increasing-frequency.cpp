#include <vector>
#include <unordered_map>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> frequencyMap;
        for (int num : nums) {
            frequencyMap[num]++;
        }
        auto cmp = [](pair<int, int>& a, pair<int, int>& b) {
            if (a.first == b.first) return a.second < b.second;
            return a.first > b.first; 
        };
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        
        for (auto& entry : frequencyMap) {
            pq.push({entry.second, entry.first});
        }
        
        vector<int> result;
        while (!pq.empty()) {
            auto [freq, num] = pq.top();
            pq.pop();
            for (int i = 0; i < freq; ++i) {
                result.push_back(num);
            }
        }
        
        return result;
    }
};
