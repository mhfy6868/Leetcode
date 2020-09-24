
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
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;   
        std::vector<int>::iterator it;
        int n = nums1.size();
        
        for(int i=0;i<n;i++){
           // nums2[nums1[i]]
            int flag = 0;

            it = find (nums2.begin(), nums2.end(), nums1[i]);
            if (it != nums2.end()){
                while(it !=nums2.end()){
                    if (*it>nums1[i]){
                        result.push_back(*it);
                        flag = 1;
                        break;
                    }

                    it++;
                    
            
                 }
                 //result.push_back(-1);
            }
            if (!flag)
                result.push_back(-1);
        }
        return result;
    }
    
};


int main(){
    vector<int> m = {4,1,2};
    //string m = "5/3+1/3";
    vector<int> n = {1,2,3,4};


    Solution s;
    vector<int> result = s.nextGreaterElement(m,n);

    for(auto it:result)
        cout<<"result is: "<<it<<endl;

    return 0;
} 
