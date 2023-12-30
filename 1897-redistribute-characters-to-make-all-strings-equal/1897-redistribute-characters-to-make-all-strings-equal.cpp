class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map <char, int> mp;
        for(auto word : words){
            for(char ch : word){
                mp[ch]++;
            }
        }
        int size = words.size();
        for (const auto& pair : mp) {
            if (pair.second % size != 0) {
                return false;
            }
        }

        return true;
    }
};