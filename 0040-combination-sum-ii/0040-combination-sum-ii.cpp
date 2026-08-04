class Solution {
public:
    void printF(vector<int>& candidates, vector<vector<int>>& ds, vector<int>& current, int target,int ind){
        if(target == 0){
            ds.push_back(current);
            return;
        }

        if(target < 0 || ind == candidates.size()){
            return;
        }

        if(candidates[ind] <= target){
            current.push_back(candidates[ind]);
            printF(candidates,ds,current,target - candidates[ind],ind+1);
            current.pop_back();
        }

        int next = ind + 1;

        while(next < candidates.size() && candidates[next] == candidates[ind]){
            next++;
        }

        printF(candidates,ds,current,target,next);

    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ds;
        vector<int> current;

        sort(candidates.begin(),candidates.end());
        printF(candidates,ds,current,target,0);

        return ds;
    }
};