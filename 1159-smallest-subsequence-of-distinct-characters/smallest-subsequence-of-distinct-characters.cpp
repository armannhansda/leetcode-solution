class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> lastIdx(26, 0);
        for (int i = 0; i < s.length(); i++) {
            lastIdx[s[i] - 'a'] = i; // Record the last index of each character
        }
        
        vector<bool> visited(26, false);
        string result = ""; // Using a string directly as a stack
        
        for (int i = 0; i < s.length(); i++) {
            char curr = s[i];
            
            // Skip if the character is already included in the sequence
            if (visited[curr - 'a']) continue;
            
            // Pop greater characters if they appear again later
            while (!result.empty() && result.back() > curr && lastIdx[result.back() - 'a'] > i) {
                visited[result.back() - 'a'] = false;
                result.pop_back();
            }
            
            // Add current character to stack and mark visited
            result.push_back(curr);
            visited[curr - 'a'] = true;
        }
        
        return result;
    }
};