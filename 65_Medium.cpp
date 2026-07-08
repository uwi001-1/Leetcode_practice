// As we need to handle the MOD
/****************
class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) 
    {
        vector<int> arr;

        for(int i = 0; i < queries.size(); i++)
        {
            int l = queries[i][0];
            int r = queries[i][1];
            long long n = stoll(s.substr(l, r - l + 1));

            if(n == 0)
            {
                arr.push_back(0);
                continue;
            }

            int digit;
            long long  sum = 0; 
            long long  x = 0;
            int j = 1; 

            while(n > 0)
            {
                // remainder
                digit = n % 10;

                // remove one digit from back 
                n = n / 10;

                // skip if zero
                if(digit == 0) continue;

                    sum += digit; 
                x += digit * j;
                j *= 10;
            }
        
            long long ans = sum * x;

            arr.push_back(ans);
        }
        
        return arr;
    }
};
**************/