
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
    int nthUglyNumber(int n) 
    {
        vector<int>q({1});
        int a=0, b=0, c=0;
        for (int i=0; i<n-1; i++)
        {
            int num = min(min(q[a]*2,q[b]*3),q[c]*5);
            if (q[a]*2==num) a++;
            if (q[b]*3==num) b++;
            if (q[c]*5==num) c++;
            q.push_back(num);
        }
        return q[n-1];
    }
};


int main(){
    int m = 12;

    //string m = "5/3+1/3";
    //int m = 4;

    Solution s;
    int result = s.nthUglyNumber(m);

    //for(auto it:result)
        cout<<"result is: "<<result<<endl;

    return 0;

} 
