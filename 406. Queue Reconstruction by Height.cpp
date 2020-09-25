
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
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> result;
        sort (people.begin(),people.end(),[](const vector<int>& a, const vector<int>& b ){
        return (a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]));
        });
        
        for (vector<int> x: people)
            result.insert(result.begin() + x[1],x);
        
        return result;
        
        
    }
};

int main(){
    //string m = "ABABBBBB";
    //string m = "5/3+1/3";
    //int k  = 1;
    //vector<int> m= {5,1,2,3,4};
    vector<vector<int>> k= {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
     

    //vector<int> m= {3,3,4};
    //vector<int> k = {3,4,4};
  

    Solution s;
    vector<vector<int>> result = s.reconstructQueue(k);

    for(auto it:result)
        for (auto it1:it)
            cout<<"result is: "<<it1<<endl;

    return 0;
} 
