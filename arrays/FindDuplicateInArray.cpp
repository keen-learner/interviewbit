/*
Find Duplicate in Array
Given a read only array of n + 1 integers between 1 and n, find one number that repeats in linear time using less than O(n) space and traversing the stream sequentially O(1) times.

Sample Input:

[3 4 1 4 1]
Sample Output:

1
If there are multiple possible answers ( like in the sample case above ), output any one.

If there is no duplicate, output -1

RELATED:
  LEETCODE # 217: https://leetcode.com/problems/contains-duplicate/#/description
  LEETCODE # 219: https://leetcode.com/problems/contains-duplicate-ii/#/description
  LEETCODE # 220: https://leetcode.com/problems/contains-duplicate-iii/#/description
  LEETCODE # 287: https://leetcode.com/problems/find-the-duplicate-number/#/description 
  LEETCODE # 442: https://leetcode.com/problems/find-all-duplicates-in-an-array/#/description

  LEETCODE # 26: https://leetcode.com/problems/remove-duplicates-from-sorted-array/#/description 
  LEETCODE # 80: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/#/description 
  LEETCODE # 82: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/#/description 
  LEETCODE # 83: https://leetcode.com/problems/remove-duplicates-from-sorted-list/#/description 
  LEETCODE # 316: https://leetcode.com/problems/remove-duplicate-letters/#/description 

*/

int Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if (A.size()>1) {
        int slow = A[0];
        int fast = A[A[0]];
        while(slow != fast) {
            slow = A[slow];
            fast = A[A[fast]];
        }
        fast = 0;
        while(slow!=fast) {
            fast = A[fast];
            slow = A[slow];
        }
        return slow;
    }
    return -1;
}

/*
// official solution

class Solution {
public:
    int repeatedNumber(const vector<int> &V) {
        if (V.size() <= 1) return -1;
        int valueRange = V.size() - 1; // 1 to N when the size is N+1.
        int range = sqrt(valueRange);
        if (range * range < valueRange) range++;
        int count[range + 1];
        memset(count, 0, sizeof(count));

        for (int i = 0; i < V.size(); i++) {
        count[(V[i] - 1) / range]++;
        }
    
        int repeatingRange = -1;
        int numRanges = ((valueRange - 1) / range) + 1;
        for (int i = 0; i < numRanges && repeatingRange == -1; i++) {
            if (i < numRanges - 1 || valueRange % range == 0) {
                if (count[i] > range) repeatingRange = i;
            } else {
                if (count[i] > valueRange % range) repeatingRange = i;
            }
        }
        if (repeatingRange == -1) return -1;
        memset(count, 0, sizeof(count));
        for (int i = 0; i < V.size(); i++) {
            if ((V[i] - 1) / range == repeatingRange) count[(V[i] - 1) % range]++;
        }
        for (int i = 0; i < range; i++) {
            if (count[i] > 1) {
                return repeatingRange * range + i + 1;
            }
        }
        return -1;
    }
};

*/
