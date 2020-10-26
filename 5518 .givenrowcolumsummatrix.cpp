//5518 . 给定行和列的和求可行矩阵

#include <iostream>
#include <unordered_set>
#include<algorithm>
#include <cstring>
#include <vector>
#include <memory>
#include <mutex>
#include <string>
#include <sstream>
#include <unordered_map>
#include <limits.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int h = rowSum.size(), w = colSum.size();
        vector<vector<int>> ret(h, vector<int>(w, 0));
        
        for (int k = 0; k < h + w; k++) {
            int pi = -1, pj = -1;
            for (int i = 0; i < h; i++) {
                if (rowSum[i] == 0) continue;
                if (pi == -1 || (rowSum[i] < rowSum[pi])) {
                    pi = i;
                }
            }
            for (int j = 0; j < w; j++) {
                if (colSum[j] == 0) continue;
                if (pj == -1 || colSum[j] < colSum[pj]) {
                    pj = j;
                }
            }
            if (pi == -1 || pj == -1) break;
            
            int val = min(rowSum[pi], colSum[pj]);
            ret[pi][pj] = val;
            rowSum[pi] -= val;
            colSum[pj] -= val;
        }
        return ret;
    }
};



// a  b 3
// c  d 8  
// 4  7

int main(){
    vector<int> m = {3,8};
    vector<int> n = {4,7};

    //string m = "5/3+1/3";

    Solution s;
    vector<vector<int>> result = s.restoreMatrix(m,n);

    for (auto it : result)
        for (auto it1 : it)
            cout<<"result is: "<<it1<<endl;
    return 0;

} 
