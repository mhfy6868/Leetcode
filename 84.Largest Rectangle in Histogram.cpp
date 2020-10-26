
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
#include <stack>

using namespace std;


// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
      
//     int ans = 0;
//     vector<int> st;
//     heights.insert(heights.begin(), 0);
//     heights.push_back(0);
//     for (int i = 0; i < heights.size(); i++)
//     {
//         while (!st.empty() && heights[st.back()] > heights[i])
//         {
//             int cur = st.back();
//             st.pop_back();
//             int left = st.back() + 1;
//             int right = i - 1;
//             ans = max(ans, (right - left + 1) * heights[cur]);
//         }
//         st.push_back(i);
//     }
//     return ans;
        
//     }
// };
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
      
    int ans = 0;
    stack<int> st;
    //heights.insert(heights.begin(), 0);
    //heights.push_back(0);
    for (int i = 0; i < heights.size()-1; i++)
    {
        while (!st.empty() && heights[st.top()] > heights[i])
        {
            int cur = st.top();
            st.pop();
            int left = cur;
            int right = i - 1;
            ans = max(ans, (right - left + 1) * heights[cur]);
            cout<<"i:"<<i<<endl;
            cout<<"nums_i:"<<heights[i]<<endl;
            cout<<"cur"<<cur<<endl;
            cout<<"left:"<<left<<endl;
            cout<<"right:"<<right<<endl;
            cout<<ans<<endl;

        }
        st.push(i);
    }
    return ans;
        
    }
};



int main(){
    vector<int> m = {1};

    //string m = "5/3+1/3";
    //int m = 4;

    Solution s;
    int result = s.largestRectangleArea(m);

    //for(auto it:result)
        cout<<"result is: "<<result<<endl;

    return 0;

} 
