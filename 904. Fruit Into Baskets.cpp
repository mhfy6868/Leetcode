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
int totalFruit(vector<int>& tree) {
	unordered_map<int, int> m;
	int minval = 0, maxsize = 0, index = 0;

	for(auto it : tree){
		if(!m.count(it) and m.size() == 2){
			int val, pos = INT_MAX;
			for(auto i : m){ // only 2 times that is constant
				if(i.second < pos)
					pos = i.second, val = i.first;
			}
			m.erase(val);
			minval = pos + 1;
		}
		m[it] = index;
		maxsize = max(maxsize, index - minval + 1);
		index++;
	}
	return maxsize;
}

};


int main(){
    vector<int> m = {3,3,3,1,1,2,2};
    //string m = "5/3+1/3";

    Solution s;
    int result = s.totalFruit(m);

    cout<<"result is: "<<result<<endl;
    return 0;

} 
