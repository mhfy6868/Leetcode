 
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
#include <map>
using namespace std;
 
 
class MyCalendarThree {
    
public:

    MyCalendarThree() {}
    //std::map<int, int> deltas_;

    int book(int start, int end) {
        ++deltas_[start];
        --deltas_[end];
        int ans = 0;
        int curr = 0;
        for (const auto& kv : deltas_)            
            ans = max(ans, curr += kv.second);
        return ans;
    }
private:
    std::map<int, int> deltas_;

};

int main(){
  
    vector<vector<int>> m = {{10,20},{50,60},{10,40},{5,15},{5,10},{25,55}};
    vector<int> param_1;
    //vector<int> k= {4,4,1,5,1};
     MyCalendarThree* obj = new MyCalendarThree();
    for (auto it:m){
         param_1.push_back(obj->book(it[0],it[1]));
    }

    //vector<int> m= {3,3,4};
    //vector<int> k = {3,4,4};
  

    // Solution s;
    // vector<vector<int>> result = s.book(m);

    for(auto it:param_1)
            cout<<"result is: "<<it<<endl;

    return 0;
} 
