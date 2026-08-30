class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end() , [] (const vector<int> a, const vector<int> b){
            return a[0] < b[0];
        });

        int maxReach = INT_MIN;
        int cuts = 0;
        int curr_end = 0;
        int i = 0;
        int n = clips.size();

        while(curr_end < time){
            while(i < n && clips[i][0] <= curr_end){
                maxReach = max(clips[i][1],maxReach);
                i++;
            }

            if(curr_end == maxReach){
                return -1;
            }

            curr_end = maxReach;
            cuts++;
        }
        return cuts;
    }
};