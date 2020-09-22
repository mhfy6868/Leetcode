
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
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,int> map;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int m = 1;
        for (int i=0; i<n;i++){
            if(nums[i]>0  ){
                
                if(nums[i] == m && !map.count(nums[i])){
                    map.insert({nums[i],i});
                    m++;}


                else if (nums[i] != m && map.count(nums[i]))
                    m = m;

                

                else
                    break;
                    
                    
                }
            
        }
        return m;
    }
};

int main(){
    vector<int> m = {0,3,3,1,1,2,2};
    //string m = "5/3+1/3";

    Solution s;
    int result = s.firstMissingPositive(m);

    cout<<"result is: "<<result<<endl;
    return 0;

} 
