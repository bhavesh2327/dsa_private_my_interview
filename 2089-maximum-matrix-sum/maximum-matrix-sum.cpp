class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int min_abs = INT_MAX;
        int neg_cnt = 0;
        for(auto row : matrix){
            for(auto cell : row){
                if(cell < 0){
                    neg_cnt += 1;
                }
                sum += abs(cell);
                min_abs = min(min_abs, abs(cell));
            }
        }
        if(neg_cnt % 2){
            sum -= 2 * min_abs;
        }
        return sum;
    }
};