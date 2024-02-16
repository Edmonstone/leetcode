class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        // Sort based on frequency in ascending order
        vector<pair<int, int>> freqArr(mp.begin(), mp.end());
        sort(freqArr.begin(), freqArr.end(), [](const auto& a, const auto& b) {
            return a.second < b.second;
        });

        int countUnique = freqArr.size();

        // Remove elements with the lowest frequency until k becomes zero
        for (const auto& pair : freqArr) {
            int freq = pair.second;
            if (k >= freq) {
                k -= freq;
                countUnique--;
            } else {
                break;
            }
        }

        return countUnique;
    }
};