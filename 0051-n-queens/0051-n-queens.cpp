class Solution {
    unordered_set<int>col;
    unordered_set<int> diag1;
    unordered_set<int> diag2;

private:
    void backTrack(vector<vector<string>>& ans, int row, int n, vector<string>& board){
        if(n == row){
            ans.push_back(board);
            return;
        }

        for(int c = 0 ; c < n ; c++){
            int d1 = row - c;
            int d2 = row + c;

            if(col.count(c) || diag1.count(d1) || diag2.count(d2)){
                continue;
            }

            board[row][c] = 'Q';
            col.insert(c);
            diag1.insert(d1);
            diag2.insert(d2);
            
            backTrack(ans,row+1,n,board);

            board[row][c] = '.';
            col.erase(c);
            diag1.erase(d1);
            diag2.erase(d2);
        }
    }

    
public:
    vector<vector<string>> solveNQueens(int n) {
        col.clear();
        diag1.clear();
        diag2.clear();

        vector<string> board(n,string(n,'.'));
        vector<vector<string>> ans;
        backTrack(ans,0,n,board);

        return ans;
    }
};