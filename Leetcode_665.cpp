#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count = 0;
        //We Consider a Series of 3 Elements;
        for(int i = 1 ; i<nums.size(); i++){
            if(nums[i]<nums[i-1]){ //if 3 rd is less than 2 nd
               if(i==1||nums[i-2]<=nums[i]){//Check if 3 is greater than or equal to 1
                   nums[i-1] = nums[i];//Equal 2 to 3 rd
                   count++;
               }
            else{
                if(nums[i-2]>nums[i]){//Check if 3 is less than 1
                    nums[i] = nums[i-1];//Equal 3 to 2 nd
                    count++;
                }   
               }
            }
            if(count>1)//If there are more than 2 changes done ..return false
                return false;
        }
        return true;
    }
};

//注意这个答案，他是前两个就进行过一次比较， 然后赋值，这样的话后面就只用管后两位数的赋值了 。

// class Solution {
// public:
//     bool checkPossibility(vector<int>& nums) {
//         int count = 0;
//         int n = nums.size();
//         for(int i=1; i< n; i++){
            
//            if(i ==1 || nums[i] < nums[i-1]){
//               if (nums[i-2]<= nums[i]){
//                   nums[i-1] = nums[i];
//                   count ++;
                  
//               } 
//             //    else {
//             //        nums[i] = nums[i-1];
//             //        count ++;
//             //    };
               
               
               
//            } 
//             else
//             {
//                 if (nums[i-1]<nums[i-2]){
//                     nums[i]=nums[i-1];
//                     count ++;
//                 }
//             }
                
            
            
//              if (count > 1) return false;
//         }
       
        
//         return true;
        
//     }
// };

int main(){
    vector<int> nums = {3,2,3};
    // vector<int> nums = {4,2,1};


    Solution s;
    bool result = s.checkPossibility(nums);
    cout<<"result is: "<<result<<endl;
    return 0;

}
