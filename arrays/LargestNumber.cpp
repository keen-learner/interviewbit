/*
Largest Number
Given a list of non negative integers, arrange them such that they form the largest number.

For example:

Given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.

*/

bool compare(string s1,string s2){
	string s3=s1+s2;
	string s4=s2+s1;
	if(s3>s4)
		return false;
	return true;
}
string Solution::largestNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int i;	//loop variable
	vector<string> B;
	const auto n = A.size();
	for(i=0;i<A.size();i++)
		B.push_back(to_string(A[i]));
	sort(B.begin(),B.end(),compare);	//sort in ascending order
	string s=B[n-1];
	for(i=n-2;i>=0;i--)
		s+=B[i];
    
    if(!s.empty() && s[0] == '0') return "0";
    return s;
}

/*
// official solution

class Solution {
    public:
        static bool compareNum(string a, string b) {
            return a + b > b + a;
        }

        string largestNumber(const vector<int> &num) {
            string result;
            vector<string> str;
            for (int i = 0; i < num.size(); i++) {
                str.push_back(to_string(num[i]));
            }
            sort(str.begin(), str.end(), compareNum);
            for (int i = 0; i < str.size(); i++) {
                result += str[i];
            }

            int pos = 0;
            while (result[pos] == '0' && pos + 1 < result.size()) pos++; 
            return result.substr(pos);
        }
};
*/
