class Solution {
public:
    bool isValid(const string& s, const string& w){
        int i =0, j = 0;
        int n = s.length(), m = w.length();

        while(i<n && j<m){
            if(s[i]!= w[j]) return false;

            int len1 = 0;
            char c = s[i];
            while(i<n && s[i] == c){
                len1++;
                i++;
            }
            int len2 = 0;
            while(j<m && w[j] == c){
                len2++;
                j++;
            }

            //extensin rule
            if(len1<len2) return false;
            if(len1> len2 && len1 < 3) return false;
        }

        return i ==n && j == m;
    }
    int expressiveWords(string s, vector<string>& words) {
        int stretchyCount = 0;

        for(const string& word: words){
            if(isValid(s, word)){
                stretchyCount++;
            }
        }

        return stretchyCount;
    }
};