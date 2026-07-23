class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 1;
        if(n == 2) return 2;

        int msb = 1; // most significant bit of power 2
        while((msb<<1) <=n){
            msb <<= 1;
        }

        return msb*2;
    }
};