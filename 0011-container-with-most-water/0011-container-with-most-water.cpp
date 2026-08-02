class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int amount = 0;
        int maxAmount = 0;
        int min = INT_MAX;

        while(i<j){
            min = height[i] < height[j] ? height[i] : height[j];

            amount = (j-i) * min;

            maxAmount = max(amount,maxAmount);

            if(height[i] < height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return maxAmount;
    }
};