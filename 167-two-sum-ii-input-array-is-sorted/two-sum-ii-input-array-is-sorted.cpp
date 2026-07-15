class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;

        while(l<r){
            int currsum = numbers[l]+ numbers[r];

            if(currsum> target){
                r--;
            }else if(currsum<target){
                l++;
            }else{
                return {l+1, r+1};
            }
        }

        return {};
    }
};
