class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        
        // vector<int> prefixGcd;
        int maxele = nums[0];
        for(int i =0; i <nums.size(); i++){
            maxele = max(maxele, nums[i]);
            // prefixGcd.push_back(gcd(nums[i], maxele));

            //in-place
            nums[i] = gcd(nums[i], maxele);
        }

        // sort(prefixGcd.begin(), prefixGcd.end());
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() -1;
        
        long long sum = 0;

        while(i<j){
            sum += gcd(nums[i], nums[j]);
            i++;
            j--;
        }

        return sum;
    }
};