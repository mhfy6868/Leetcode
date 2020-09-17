
#include <iostream>
#include <unordered_set>

#include <cstring>
#include <vector>
#include <memory>
#include <mutex>
#include <string>
using namespace std;


class Solution {
public:
    vector<int> findDuplicate(vector<int>& nums) {
        std::unordered_set<int> set;
        vector<int> result;
        for (auto n:nums){
            set.insert(n);
            if (set.find(n)!=set.end())
                result.push_back(n);
                
                
                
        }
        
        // for(auto itr = result.begin();itr !=result.end();itr++){
        //     cout<<*itr<<" ";
        // }
    
        return result;
    }
    
};


int main(){
    vector<int> m = {2,4,5,6,8,8};
    Solution s;
    vector<int> result = s.findDuplicate(m);

    for(auto itr = result.begin();itr !=result.end();itr++){
           cout<<*itr<<" ";
        }
   // cout<<"result is: "<<result<<endl;
    return 0;

} 