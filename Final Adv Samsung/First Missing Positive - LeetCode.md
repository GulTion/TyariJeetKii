---
title: First Missing Positive - LeetCode
source: https://leetcode.com/problems/first-missing-positive/description/
author:
  - "[[LeetCode]]"
published: 
created: 2024-12-18
description: "Can you solve this real interview question? First Missing Positive - Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space. Example 1:Input: nums = [1,2,0]Output: 3Explanation: The numbers in the range [1,2] are all in the array.Example 2:Input: nums = [3,4,-1,1]Output: 2Explanation: 1 is in the array but 2 is missing.Example 3:Input: nums = [7,8,9,11,12]Output: 1Explanation: The smallest positive integer 1 is missing. Constraints: * 1 <= nums.length <= 105 * -231 <= nums[i] <= 231 - 1"
tags:
  - clippings
status: ""
explored: true
---
Given an unsorted integer array `nums`. Return the *smallest positive integer* that is *not present* in `nums`.

You must implement an algorithm that runs in `O(n)` time and uses `O(1)` auxiliary space.

**Example 1:**

```
Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.
```

**Example 2:**

```
Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.
```

**Example 3:**

```
Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.
```

**Example 4**
```
Input:
2
5
1 2 3 4 5
5
0 -10 1 3 -20
Output:
6
2
```
**Constraints:**

- `1 <= nums.length <= 10<sup>5</sup>`
- `-2<sup>31</sup> <= nums[i] <= 2<sup>31</sup> - 1`

## Approach 1
```cpp


#include <iostream>
using namespace std;

int abs(int x){
    if(x>=0)
        return x;
    else
        return -x;
}

int main(){
    int test_cases;
    cin>>test_cases;
    while(test_cases>0){
        test_cases--;

        //Input Stage
        int size;
        cin>>size;
        int arr[size];
        int f=0;
        for(int i=0; i<size; i++){
            cin>>arr[i];
            if(arr[i]>0)
                f=1;
        }


        //Handling all non-positives
        if(f==0){
            cout<<1<<endl;
            continue;
        }

        //First move all negative nos. to the left side
        int neg_final_idx=0;
        int start=0;
        while(start<size){
            if(arr[start]<=0){
                int temp=arr[start];
                arr[start]=arr[neg_final_idx];
                arr[neg_final_idx]=temp;
                neg_final_idx++;
            }
            start++;
        }


        /*cout<<"NEG_FINAL_IDX ="<<neg_final_idx<<"\n";
        for(int i=0; i<size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;*/

        //Now the positive array lies from neg_final_idx to end
        for(int i=neg_final_idx; i<size; i++){
            int actual_idx = i;
            int item = (abs(arr[actual_idx])-1)+neg_final_idx;
            if(item<size && arr[item]>0)
                arr[item] *= -1;
        }
        int flag=0;


        /*for(int i=0; i<size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        */

        for(int i=0; i<size; i++){
            if(arr[i]>0 && flag==0){
                cout<<i-neg_final_idx+1<<endl;
                flag=1;
            }
        }
        if(flag==0){
            if(neg_final_idx==0)
                cout<<size+1<<endl;
        }
    }
}

```