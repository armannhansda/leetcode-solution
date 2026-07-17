#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int max_val = *max_element(nums.begin(), nums.end());
        
        // Step 1: Count frequency of each number
        vector<long long> freq(max_val + 1, 0);
        for (int num : nums) {
            freq[num]++;
        }
        
        // Step 2: Count how many elements are multiples of each number i
        vector<long long> exact_gcd(max_val + 1, 0);
        for (int i = max_val; i >= 1; i--) {
            long long count_multiples = 0;
            for (int j = i; j <= max_val; j += i) {
                count_multiples += freq[j];
            }
            
            // Total pairs where i is a common divisor
            long long total_pairs = (count_multiples * (count_multiples - 1)) / 2;
            
            // Step 3: Subtract pairs that have a strictly larger GCD (multiples of i)
            for (int j = 2 * i; j <= max_val; j += i) {
                total_pairs -= exact_gcd[j];
            }
            exact_gcd[i] = total_pairs;
        }
        
        // Step 4: Compute prefix sums of the pair counts
        vector<long long> prefix_sums(max_val + 1, 0);
        for (int i = 1; i <= max_val; i++) {
            prefix_sums[i] = prefix_sums[i - 1] + exact_gcd[i];
        }
        
        // Step 5: Answer queries using binary search
        vector<int> ans;
        ans.reserve(queries.size());
        for (long long q : queries) {
            // Find the first GCD index where the accumulated pairs exceed the query index q
            auto it = upper_bound(prefix_sums.begin(), prefix_sums.end(), q);
            ans.push_back(distance(prefix_sums.begin(), it));
        }
        
        return ans;
    }
};