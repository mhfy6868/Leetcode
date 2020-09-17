
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
    int findDuplicate(vector<int>& nums) {
        int l = 0;
        int r = nums.size();
        while(l<r){
            int mid = l + (r-l)/2;
            int count = 0;
            for(int num:nums)
                if(num <= mid) count++;
            if (count <= mid){
                l = mid +1;
            }
            else {
                r = mid;
            }
     
            
        }
        
        return l;
    }
    
};


int main(){
    vector<int> m = {1,3,4,2,2};
    Solution s;
    int result = s.findDuplicate(m);

    cout<<"result is: "<<result<<endl;
    return 0;

} 