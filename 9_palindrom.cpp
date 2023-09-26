class Solution {
public:
    bool isPalindrome(int x) {
        int y=0;
        if(x < 0)
        {
            return false;
        }
        while(x>0)
        {
            int digit = x % 10;
            y = y*10+digit;
            x = x/10;
        }
        return x==y;
    }
};