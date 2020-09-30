
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
#include <cstddef>


using namespace std;

 struct ListNode{
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
     
 };
    
 
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {

    ListNode* dummy1 = new ListNode(0), *dummy2 = new ListNode(0), *node1, *node2;
    node1 = dummy1;
    node2 = dummy2;
    while (head) {
        if (head->val < x) {
            node1->next = head;
            node1 = node1->next;
        } else {
            node2->next = head;
            node2 = node2->next;
        }
        head = head->next;
    }
    node2->next = NULL;
    node1->next = dummy2->next;
    return dummy1->next;
}
};

int main(){
    
    int values[] = {2,1,1,3,6,7,9,4,3};
    ListNode* list = new ListNode(values[0]);
    ListNode* cur = list;
    int n = sizeof(values)/sizeof(values[0]);
    for (int i = 1; i < n; ++i) {
    cur->next = new ListNode(values[i]);
    cur = cur->next;
    }

    Solution s;
    ListNode* result = s.partition(list,3);
    ListNode* cur1 = result;
    while(cur1){
        cout<<cur1->val<<endl;
        cur1 = cur1->next;
    }
    return 0;
} 
