class Solution {
public:
    int findMaximizedCapital(int k, int w, std::vector<int>& profits, std::vector<int>& capital) {
        int n = profits.size();
        std::vector<std::pair<int, int>> projects(n);
        
        for (int i = 0; i < n; ++i) {
            projects[i] = {capital[i], profits[i]};
        }
        
        std::sort(projects.begin(), projects.end());
        
        std::priority_queue<int> maxProfit;
        int i = 0;
        
        while (k--) {
            while (i < n && projects[i].first <= w) {
                maxProfit.push(projects[i].second);
                i++;
            }
            
            if (maxProfit.empty()) {
                break;
            }
            
            w += maxProfit.top();
            maxProfit.pop();
        }
        
        return w;
    }
};
