class Solution {
public:
    string longestPalindrome(string s) {
        int max = 0;
        int len = s.length();
        int ResS=0;
        if(len <= 0 || len == 1 ) {
            return s;
        }

        for(int i = 0; i < len; i++) {
            int len1 = ExpandCenter(&s, i ,i);
            int len2 = ExpandCenter(&s, i, i+1);
            int res = len1>len2? len1:len2;
            if(res > max) {
                ResS = i - (res-1)/2;
                max = res;
            }
        }
        return s.substr(ResS, max);
    }

    int ExpandCenter(string *s, int L, int R) 
    {
        while(L >= 0 && R < s->length() && s->at(L) == s->at(R)) {
            R++;
            L--;       
        }
        return R-L-1;
    }
};