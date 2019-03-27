#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sum=nums1.size()+nums2.size();
        int res=0;
        double res1=0;
        if(sum==1){
            if(nums1.size())
                return nums1[0];
            else
                return nums2[1];
        }else{
            res=sum/2;
        }
        int i=0;
        int j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(i+j<res){
                if(nums1[i]>nums2[j]){
                    j++;
                }else{
                    i++;
                }
            }else{
                break;
            }
        }
        while(i+j<res && i==nums1.size() && j<nums2.size()) j++;
        while(i+j<res && j==nums1.size() && i<nums1.size()) i++;

        if(sum%2!=0) return nums2[j]>nums1[i] ? nums2[j] :nums1[i];
        res1=nums1[i]+nums1[i-1]>nums2[j]+nums2[j-1]? nums1[i]+nums1[i-1] :nums2[j]+nums2[j-1];
        if(res1==nums1[i]+nums1[i-1])
            res1=nums1[i]+nums1[i-1]>nums1[i]+nums2[j] ? nums1[i]+nums1[i-1] :nums1[i]+nums2[j];
        else
            res1=nums2[j]+nums2[j-1]>nums1[i]+nums2[j] ? nums2[j]+nums2[j-1] : nums1[i]+nums2[j];
        return res1/2;
    }
};

int main(){
    vector<int> num1={1,3};
    vector<int> num2={2};

    Solution* m=new Solution();
    cout<<m->findMedianSortedArrays(num1,num2);

    return 0;
}