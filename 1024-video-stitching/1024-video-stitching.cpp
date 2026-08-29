class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end() , [](const vector<int> a, const vector<int> b){
            return a[0] < b[0];
        });

        int cut = 0;
        int maxReach = INT_MIN;
        int curr_End = 0;
        int n = clips.size();
        int i = 0;

        while(curr_End < time){
            while(i < n && clips[i][0] <= curr_End){
                maxReach = max(maxReach , clips[i][1]);
                i++;
            }

            if(maxReach == curr_End){
                return -1;
            }

            curr_End = maxReach;
            cut++;
        }
        return cut;
    }
};