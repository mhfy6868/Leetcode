#include <iostream>
#include <unordered_set>
#include<algorithm>
#include <cstring>
#include <vector>
#include <memory>
#include <mutex>
#include <string>
#include <sstream>

using namespace std;



class Solution {
public:
    string fractionAddition(string expression) {
        stringstream  s (expression);
        int A=0,B=1,a,b;
        char c;
        while(s>>a>>c>>b){
            A=A*b+a*B;
            B=b*B;
            int g=__gcd(abs(A),abs(B));
            A/=g;
            B/=g;
        }
        return to_string(A)+"/"+to_string(B);
    }
};


int main(){
    //vector<int> m = {1,3,4,2,2};
    string m = "5/3+1/3";

    Solution s;
    string result = s.fractionAddition(m);

    cout<<"result is: "<<result<<endl;
    return 0;

} 

