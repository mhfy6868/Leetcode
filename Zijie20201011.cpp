#include <iostream>
#include <unordered_map>
#include <vector>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<unordered_map>
using namespace std;


class Solution {
    static int cmp(pair<int,int>a,pair<int,int>b){
    return a.second>=b.second;
    
}
public:
    vector<int> getTheTopList (vector<vector<int>>& Collegeinput){
        int n,m;
        n = Collegeinput[0][0];
        m = Collegeinput[0][1];
        int collegSize = Collegeinput.size()-1;
        vector<int> removDupli(collegSize,0);
         for (int i=1; i<=collegSize; i++){
           removDupli[Collegeinput[i][0]] += Collegeinput[i][1]; 
             
        }
        int removDupliSize = removDupli.size();


        vector<int> result(collegSize,0);
        vector<pair<int,int>> map_;
        for (int i=0; i<removDupliSize; i++){
           map_.push_back(make_pair(i,removDupli[i])); 
             
        }
        
        sort(map_.begin(),map_.end(),cmp);
        int mapSize = map_.size();
        for (int i=0; i<mapSize; i++){
            result[i] = map_[i].first; 

        }

        
    return result;


}

   
};

int main(){
    vector<vector<int>> CollegeId = {{4,3},{1,4},{2,5},{3,6},{4,4},{4,4}};

    Solution s;
    vector<int> result = s.getTheTopList(CollegeId);
    for(auto data: result)
        cout<<"result is: "<<data<<endl;
    return 0;

}
