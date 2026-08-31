class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26,0);
        int max_count = 0;

        for(int task : tasks){
            count[task - 'A']++;
            max_count = max(max_count,count[task-'A']);
        }

        int p = 0;
        for(int c : count){
            if(c == max_count){
                p++;
            }
        }

        return max((max_count - 1) * (n+1) + p , (int)tasks.size());
    }
};