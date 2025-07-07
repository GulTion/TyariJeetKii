---
title: Solve Sum of Nodes in Kth Level
source: https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/sum-of-nodes-in-kth-level
author:
  - "[[HackerRank]]"
published: 
created: 2024-12-18
description: Sum of Nodes in Kth Level
tags:
  - clippings
status: Complete
explored: true
---
Given an integer ‘K’ and a tree in string format. print the sum of all elements at Kth level from root.

![image](https://s3.amazonaws.com/hr-assets/0/1573313905-8bbcb8a222-tree.png)

**Input Format**

integer k nexline string

**Constraints**

1 < k < 10

**Output Format**

single integer

**Sample Input 0**

```
2
(0(5(16()())(4()(9()())))(7(1()())(3()())))
```

**Sample Output 0**

```
24
```

```cpp
#include <iostream>
#include<string>
#include <vector>
using namespace std;
int main()
{
	#ifndef ONLINE_JUDGE
 
    freopen("input.txt", "r", stdin);
 
    freopen("output.txt", "w", stdout);

	#endif
	string s;
	int k,i=0,sum=0,level=-1;
	cin>>k>>s;
	while(i<s.size())
	{
		if(s[i]=='(') level++,i++;
		else if (s[i]==')') level--,i++;
		else
		{
			string temp;
			while(i<s.size()&& s[i]>='0' && s[i]<='9')
			{
				
				temp.push_back(s[i]);
				i++;
			}
			
			int ans= stoi(temp);
			if(level==k)
				sum+=ans;
		}
	}
	cout<<sum<<endl;
	return 0;
}
```