class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size()-1;
        while(start <= end) {
            if(!isalnum(s[start])) { start++; continue;} 
            if(!isalnum(s[end])) { end--; continue;}   
            if (tolower(s[start]) != towlower (s[end]))
               return false;
            start++;
            end--;   
                   }
                   return true; 
    }
};