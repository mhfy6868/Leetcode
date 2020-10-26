// 避免重复字母的最小删除成本

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
#include <queue> 
using namespace std;

class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int sum =0;
        priority_queue<int,vector<int>, greater<int>> q;
        s.push_back('0');
        for(int j=0;j<s.size()-1;j++){
            if(s[j]==s[j+1]){
                q.push(cost[j]);
                
                while(q.size()!=1){
                    sum +=q.top();
                    q.pop();
                }
                
           }
           else if(s[j]==s[j-1] && s[j]!=s[j+1]){
               q.push(cost[j]);
                
                while(q.size()!=1){
                    sum +=q.top();
                    q.pop();
                }
                q.pop();
           }
           
        }       
            
        return sum;

    }
};



// a  b 3
// c  d 8  
// 4  7

int main(){
    vector<int> m = {38,8,17,6,1,32,21,18,29,26,30,31,22,26,2,28,27,4,38,28,19,23,27,17,33,16,4,11,19,34,1,22,8,12,31,35};
    //vector<int> n = {4,7};

    //string m = "5/3+1/3";
    Solution S;
    string s = "acacdcacdbdaadaadadcdaababaacdccabbd";
    int result = S.minCost(s,m);

    // for (auto it : result)
    //     for (auto it1 : it)
            cout<<"result is: "<<result<<endl;
    return 0;

} 
