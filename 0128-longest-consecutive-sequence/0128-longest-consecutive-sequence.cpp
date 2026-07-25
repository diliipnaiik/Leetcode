class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }

        unordered_set<int> st;

        for(int num : nums){
            st.insert(num);
        }

        int longest = 0;

        for(int num : st){

            if(st.find(num - 1) == st.end()){

                int currentNum = num;
                int currentLen = 1;

                while(st.find(currentNum + 1) != st.end()){
                    currentNum++;
                    currentLen++;
                }
                longest = max(longest , currentLen);
            }
        }
        return longest;
    }
};