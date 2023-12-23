class Solution {
public:
    bool isPathCrossing(string path) {
        int x = 0;
        int y = 0;
        unordered_set<string> visited; 

        visited.insert("0,0");

        for (char ch : path) {
            if (ch == 'N') {
                y++;
            } else if (ch == 'S') {
                y--;
            } else if (ch == 'E') {
                x++;
            } else if (ch == 'W') {
                x--;
            }
            string currentPos = to_string(x) + "," + to_string(y);
            if (visited.find(currentPos) != visited.end()) {
                return true; 
            }
            visited.insert(currentPos);
        }

        return false; 
    }
};
