/*
Power of 2

Find if Given number is power of 2 or not. 
More specifically, find if given number can be expressed as 2^k where k >= 1.

Input:

number length can be more than 64, which mean number can be greater than 2 ^ 64 (out of long long range)
Output:

return 1 if the number if a power of 2 else return 0

Example:

Input : 128
Output : 1

*/

string multiplyby2(string A){
    string ans="";
    int i;
    int n=A.length();
    int sum=0,carry=0;
    for(i=n-1;i>=0;i--){
        sum=(A[i]-'0')*2+carry;
        carry=sum/10;
        sum%=10;
        ans+=(sum+'0');
    }
    if(carry>0)
        ans+=(carry+'0');
    n=ans.length();
    char c;
    for(i=0;i<n/2;i++){
        c=ans[i];
        ans[i]=ans[n-1-i];
        ans[n-1-i]=c;
    }
    return ans;
}

bool compare(string A,string B){
    if(A.length()==B.length())
        return A<B;
    else if(A.length()<B.length())
        return true;
    return false;
}

int Solution::power(string A) {
    int i=0;
    int n=A.length();
    string B="";
    while(i<n && A[i]=='0') i++;
    if(i==n)
        return 0;
    while(i<n){
        B+=A[i];
        i++;
    }
    string temp="2";
    while(compare(temp,B)){
        temp=multiplyby2(temp);
    }
    if(temp.length()==B.length() && temp==B)
        return 1;
    return 0;
    
}

/*
// official solution

class Solution {
    public:
    
    bool Not_one(string N) {
        int sz = N.size();
        if(sz > 1)
                return 1;
        if(N[0] != '1')
                return 1;
        return 0;
    }

    bool is_Eve(string N) {
        int data = (N[N.size() - 1] - '0') & 1;
        if(data)
             return 0;
        return 1;
    }

    string Divide(string N, int data) {
        reverse(N.begin(), N.end());
        long long base = 10;
        string temp = "";
        for(int i = (int)N.size() - 1, rem = 0; i >= 0; --i) {
            long long Cur = (N[i] - '0') + rem * base;
            int val = Cur / data;
            rem = Cur % data;
            temp += (val + '0');
        }
        
        while(temp.size() && !(temp[0] - '0'))
                temp.erase(temp.begin());
        
        return temp;
    }

    int power(string N) {
        
        int sz = N.size();
        if(sz == 1) {
            if(N[0] == '2' || N[0] == '4' || N[0] == '8')
                    return 1;
            return 0;
        } else {
            while(Not_one(N) && is_Eve(N)) {
                N = Divide(N, 2);
                if(N.size() == 1 &&  N[0] == '1')
                        break;
            }
            if(Not_one(N))
                    return 0;
            return 1;
        }
    }
};

*/
