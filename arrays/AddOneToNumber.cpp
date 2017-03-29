/*

Add One To Number
Given a non-negative number represented as an array of digits,

add 1 to the number ( increment the number represented by the digits ).

The digits are stored such that the most significant digit is at the head of the list.

Example:

If the vector has [1, 2, 3]

the returned vector should be [1, 2, 4]

as 123 + 1 = 124.

NOTE:

NOTE: Certain things are intentionally left unclear in this question which you should practice asking the interviewer.
For example, for this problem, following are some good questions to ask :
Q : Can the input have 0’s before the most significant digit. Or in other words, is 0 1 2 3 a valid input?
A : For the purpose of this question, YES
Q : Can the output have 0’s before the most significant digit? Or in other words, is 0 1 2 4 a valid output?
A : For the purpose of this question, NO. Even if the input has zeroes before the most significant digit.

*/

vector<int> Solution::plusOne(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int i;
    int n=A.size();
    int sum,carry=1;
    for(i=0;i<n/2;i++)  //reverse the vector
   		swap(A[i],A[n-1-i]);
   	i=n-1;
   	while(A[i]==0 && i>=0){ //trim zeros
    	A.pop_back();
    	i--;
    }
    n=A.size();
    for(i=0;i<n;i++){ //perform addition
    	sum=carry+A[i];
    	carry=sum/10;
    	sum=sum%10;
    	A[i]=sum;
    }
    if(carry>0) //add carry bit
    	A.push_back(carry);
    n=A.size();
    for(i=0;i<n/2;i++)  //reverse array
   		swap(A[i],A[n-1-i]);
    return A;
}

/*
// official solution

class Solution {
    public:
        vector<int> plusOne(vector<int> &digits) {
            reverse(digits.begin(), digits.end());
            vector<int> ans;
            int carry = 1;
            for (int i = 0; i < digits.size(); i++) {
                int sum = digits[i] + carry;
                ans.push_back(sum%10);
                carry = sum / 10;
            }
            while (carry) {
                ans.push_back(carry%10);
                carry /= 10;
            }
            while (ans[ans.size() - 1] == 0 && ans.size() > 1) {
                ans.pop_back();
            }
            reverse(ans.begin(), ans.end());
            reverse(digits.begin(), digits.end());
            return ans;
        }
};

*/
