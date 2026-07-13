class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        vector<int> ans;

        for(int len = 2; len <=s.length(); len++){
            for(int i = 0; i <= s.length() -len; i++){
                string sub = s.substr(i, len);
                int num = stoi(sub);

                if(num>=low && num<= high){
                    ans.push_back(num);
                }
            }
        }

        return ans;

    }
};