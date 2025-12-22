class Solution {
public:
    bool isPalindrome(int x) {
        bool res = true;
        string str = to_string(x);
        int i = 0;
        int j = str.size()-1;
        while(i<j){
            if(str[i]!=str[j])  return false;
            i++;
            j--;
        }
        return res;
    }
};