You are given an old touch smartphone numbers having dial pad and calculator app.
Aim: The goal is to type a number on dialpad.

But as phone is old, some of the numbers and some operations can't be touched.
For eg. 2,3,5,9 keys are not responding , i.e you cannot use them
But you can always make a number using other numbers and operations in Calculator. There could be multiple ways of making a number

Calculator have 1-9 and +,-,*,/,= as operations. Once you have made the number in Calculator you can copy the number and use it.

You have to find minimum number to touches required to obtain a number.

**Input:#**
There will be multiple Test cases .Each test case will consist of 4 lines
1) First line will consist of N,M,O
    N: no of keys working in Dialpad (out of 0,1,2,3,4,5,6,7,8,9)
    M:types of operations supported (+,-,*,/)
    O: Max no of touches allowed
2) second line of input contains the digits that are working e.g 0,2,3,4,6.
3) Third line contains the valued describing operations, 1(+),2(-),3(*),4(/)
4) fourth line contains the number that we want to make .

**Output:#**
Output contains 1 line printing the number of touches required to make the number


#Sample Test Case:#
```
5
5 3 5
1 2 4 6 0
1 2 3
5
6 4 5
1 2 4 6 9 8
1 2 3 4
91
6 2 4
0 1 3 5 7 9
1 2 4
28
5 2 10
1 2 6 7 8
2 3
981
6 3 5
1 4 6 7 8 9
1 2 3
18
```

#Output:#
```
4
2
-1
7
2
```

