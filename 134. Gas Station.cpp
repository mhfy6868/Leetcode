 
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
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int rest = 0;
        int n = gas.size();
        int p = 0;
        int q = 1;
        int flag = 0;
        for (int j=0;j<n;j++){
            gas.push_back(gas[j]);
            cost.push_back(cost[j]);
        }
        int d = gas.size();
        for (int i= 0; i<d;i++){
            
            if (gas[i]+rest-cost[i]>=0){
                rest += gas[i]-cost[i];
                q++;
                if(q==n+1){
                    p = i;
                    //q = m;
                    flag = 1;
                    break;   
                }
               
           
            } 
            else{
                q = 1;
                rest = 0;
            }
        }
        if (flag)
            return p-q+2;
        else return -1;
        
    }
};

int main(){
    //string m = "ABABBBBB";
    //string m = "5/3+1/3";
    //int k  = 1;
    vector<int> m= {5,1,2,3,4};
    vector<int> k= {4,4,1,5,1};
     

    //vector<int> m= {3,3,4};
    //vector<int> k = {3,4,4};
  

    Solution s;
    int result = s.canCompleteCircuit(m,k);

    //for(auto it:result)
        cout<<"result is: "<<result<<endl;

    return 0;
} 
