class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int start = 0;
        int end = letters.size()-1;
        int pos = -1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(target < letters[mid]){
                pos = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        if(pos == -1)   return letters[0];
        return letters[pos];
    }
};