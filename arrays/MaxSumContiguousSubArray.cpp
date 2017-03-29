/*
Max Sum Contiguous Subarray
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example:

Given the array [-2,1,-3,4,-1,2,1,-5,4],

the contiguous subarray [4,-1,2,1] has the largest sum = 6.

For this problem, return the maximum sum.

LEETCODE #53 : https://leetcode.com/problems/maximum-subarray/#/description
*/

int Solution::maxSubArray(const vector<int> &nums) {
	// Do not write main() function.
	// Do not read input, instead use the arguments to the function.
	// Do not print the output, instead return values as specified
	// Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	const int n = nums.size();
	if(n == 0) return 0;
	//else if(n == 1) return nums[0];
	int res = nums[0];
	int run_max = nums[0];
	for(int i = 1; i < n; ++i) {
	    run_max = max(nums[i], run_max+nums[i]);
	    res = max(res, run_max);
	}
	return res;
}


/*
// official solution

class Solution {
    public:
        int maxSubArray(const vector<int> &A) {
            int n = A.size();
            int curSum = 0, maxSum = -1000000000;
            for (int i = 0; i < n; i++) {
                curSum += A[i];
                maxSum = max(maxSum, curSum);
                if (curSum < 0) curSum = 0;
            }
            return maxSum;
        }
};

*/
