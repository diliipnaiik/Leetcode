class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map <int,int> window;

        int ans = 0;
        int left = 0;

        for(int right = 0 ; right < fruits.size() ; right++){
            window[fruits[right]]++;

            while(window.size() > 2){
                window[fruits[left]]--;

                if(window[fruits[left]] == 0){
                    window.erase(fruits[left]);
                }

                left++;
            }

            ans = max(right - left + 1,ans);
        }
        return ans;
    }
};