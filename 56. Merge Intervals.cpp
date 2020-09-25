 
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
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(),intervals.end(),[](vector<int> a,vector<int> b){
            return (a[0]<b[0] || a[0]==b[0] && a[1]<=b[1]);
        });
        int flag = 0;
          if (intervals.size()==1){
            result = intervals;
            
        }
        else{
            for(int i=0;i<intervals.size();i++){
            if(i==intervals.size()-1){
                if(!flag)
                    result.push_back(intervals[i]);
            }
            else{
                 if(intervals[i][1]>=intervals[i+1][0]){
               
                    result.push_back({intervals[i][0],intervals[i+1][1]});
                    i++;
                    if(i==intervals.size()-2){
                        flag = 1;
                    }

            }
            else{
                result.push_back(intervals[i]);
            }
            }

           
        } 
        }
       
        return result;
    }
};

int main(){
    //string m = "ABABBBBB";
    //string m = "5/3+1/3";
    //int k  = 1;
    //vector<vector<int>> m= {{1,3},{2,6},{8,10},{13,15}};
    vector<vector<int>> m= {{1,3},{0,3},{8,10},{13,15}};

    //vector<int> k= {4,4,1,5,1};
     

    //vector<int> m= {3,3,4};
    //vector<int> k = {3,4,4};
  

    Solution s;
    vector<vector<int>> result = s.merge(m);

    for(auto it:result)
        for(auto it1:it)
            cout<<"result is: "<<it1<<endl;

    return 0;
} 
