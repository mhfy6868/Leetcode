
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
// iterative
    vector<int> grayCode(int n) {
        vector<int> vec{0};
        for(int i = 0; i < n; ++i){
            int tmp = 1 << i;
            for(int j = vec.size() - 1; j >= 0; --j){
                vec.push_back(vec[j] + tmp);
            }
        }
        return vec;
    }
};

int main(){
    //vector<int> m = {3,3,3,1,1,2,2};
    //string m = "5/3+1/3";
    int m = 4;

    Solution s;
    vector<int> result = s.grayCode(m);

    for(auto it:result)
        cout<<"result is: "<<it<<endl;

    return 0;

} 
