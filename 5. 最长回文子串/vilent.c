class Solution {
public:
    string longestPalindrome(string s) {
        int max = 0;
        int len = s.length();
        int ResS=0, ResE=0;
        if(len <= 0 || len == 1 ) {
            return s;
        }

        for(int start = 0; start < len; start++) {
            for(int end = start; end < len; end++ ) {
                if(IsHuiwen(&s, start, end) && end-start+1 > max) {
                    max = end-start+1;
                    ResS=start;
                    ResE=end;
                }
            }
        }
        return s.substr(ResS, ResE-ResS+1);
    }
    
    bool IsHuiwen(string *s, int start, int end)
    {
        if (end-start+1  == 1 ) {
            return true;
        }
        
        for(int i = 0; i < (end-start+1)/2; i++) {
            if(s->at(start+i) != s->at(end-i)) {
                return false;
            }
        }
        
        return true;
    }
};