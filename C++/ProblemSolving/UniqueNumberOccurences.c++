class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;

        // count frequencies
        for(int x : arr) {
            freq[x]++;
        }

        unordered_set<int> s;

        // insert frequencies into set
        for(auto it : freq) {
            s.insert(it.second);
        }

        // if unique -> sizes must match
        return s.size() == freq.size();
    }
};
