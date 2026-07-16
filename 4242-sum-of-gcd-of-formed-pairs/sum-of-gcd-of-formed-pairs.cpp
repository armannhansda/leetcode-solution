class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        
        vector<int> prefixGcd;
        int maxele = nums[0];
        for(int i =0; i <nums.size(); i++){
            maxele = max(maxele, nums[i]);
            prefixGcd.push_back(gcd(nums[i], maxele));
        }

        int i = 0, j = prefixGcd.size() -1;
        long long sum = 0;
        sort(prefixGcd.begin(), prefixGcd.end());
        while(i<j){
            sum += gcd(prefixGcd[i], prefixGcd[j]);
            i++;
            j--;
        }

        return sum;
    }
};