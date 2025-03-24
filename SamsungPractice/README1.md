## Target SAMSUNG Research Institute


### Question 3 : [DONE]

> [Redundant. Refer : Question 32]


### Question 4 : [[Detect cycle in directed Graph]]

Find a cycle, if exists, in a directed graph. If there is none, print 0. If there is one, print the path starting from the first node of the cycle to the last. If there are more than one, print any path.

### Question 5 :

It was a combination of Rat in a Maze and longest subpath problem.

### Question 6 :    [DONE]

Find if given graph is bipartite or not, if it is bipartite then print either white color nodes or black color nodes.

### Question 7 :    [DONE]

Find a cycle in the graph.
> [Refer Question 4]

### Question 8 : [DONE]

Find a cycle in LinkedList.

### Question 9 : [DONE]

Variation of traveling salesman solved using backtracking (Optimization on traveling salesman ).
> [Refer Question 11]

### Question 11 : [DONE]

Mr. Kim has to deliver refrigerators to N customers. From the office, he is going to visit all the customers and then return to his home. Each location of the office, his home, and the customers is given in the form of integer coordinates (x,y) (0≤x≤100, 0≤y≤100) . The distance between two arbitrary locations (x1, y1) and (x2, y2) is computed by |x1-x2| + |y1-y2|, where |x| denotes the absolute value of x; for instance, |3|=|-3|=3. The locations of the office, his home, and the customers are all distinct. You should plan an optimal way to visit all the N customers and return to his among all the possibilities. You are given the locations of the office, Mr. Kim’s home, and the customers; the number of the customers is in the range of 5 to 10. Write a program that, starting at the office, finds a (the) shortest path visiting all the customers and returning to his home. Your program only have to report the distance of a (the) shortest path. You don’t have to solve this problem efficiently. You could find an answer by looking up all the possible ways. If you can look up all the possibilities well, you will get a perfect score.

**Constraints: **

5≤N≤10. Each location (x,y) is in a bounded grid, 0≤x≤100, 0≤y≤100, and x, y are integers.

**Input:**

You are given 10 test cases. Each test case consists of two lines; the first line has N, the number of the customers, and the following line enumerates the locations of the office, Mr. Kim’s home, and the customers in sequence. Each location consists of the coordinates (x,y), which is reprensented by ‘x y’.

**Output:**

Output the 10 answers in 10 lines. Each line outputs the distance of a (the) shortest path. Each line looks like ‘#x answer’ where x is the index of a test case. ‘#x’ and ‘answer’ are separated by a space.

**I/O Example:**

Input (20 lines in total. In the first test case, the locations of the office and the home are (0, 0) and (100, 100) respectively, and the locations of the customers are (70, 40), (30, 10), (10, 5), (90, 70), (50, 20).)

```
5 ← Starting test case #1
0 0 100 100 70 40 30 10 10 5 90 70 50 20

6 ← Starting test case #2
88 81 85 80 19 22 31 15 27 29 30 10 20 26 5 14
.
.
.
10 ← Starting test case #3
39 9 97 61 35 93 62 64 96 39 36 36 9 59 59 96 61 7 64 43 43 58 1 36
```

Output (10 lines in total)

```
#1 200

#2 304

#3 366

...
```

### Question 12 :

You are given old touch smartphone numbers having dial pad and calculator app. Aim: The goal is to type a number on the dial pad. But as the phone is old, some of the numbers and some operations can’t be touched. For eg. 2,3,5,9 keys are not responding, i.e you cannot use them
But you can always make a number using other numbers and operations in Calculator. There could be multiple ways of making a number. Calculator have 1-9 and +,-,\*,/,= as operations. Once you have made the number in Calculator you can copy the number and use it. You have to find the minimum number of touches required to obtain a number.

**Input:**

```
There will be multiple Test cases.Each test case will consist of 4 lines

1) The first line will consist of N, M, O
	N: no of keys working in Dialpad (out of 0,1,2,3,4,5,6,7,8,9)
	M:types of operations supported (+,-,*,/)
	O: Max no of touches allowed

2) Second line of input contains the digits that are working e.g 0,2,3,4,6.

3) Third line contains the valued describing operations, 1(+),2(-),3(*),4(/)

4) Fourth line contains the number that we want to make .
```

**Output:**

```
Output contains 1 line printing the number of touches required to make the number
```

**Sample Test Case:**
```
1                   // No of test cases
5 3 5            // N ,M, O
1 2 4 6 0     // digits that are working (total number of digits = N),
1 2 3         // describing operations allowed (1–> ‘+’, 2–> ‘-‘, 3–> ‘*’ , 4–> ‘/’ )(total number is equals to M)
5                 // number we want to make

Output:
3

How 4? 1+4=, “=” is also counted as a touch
```
**2nd Sample Case :**
```
3                   // No of Test cases
6 4 5            // N ,M, O
1 2 4 6 9 8  // digits that are working (total number of digits = N),
1 2 3 4        // describing operations allowed (1–> +, 2–> -, 3–> , 4–>/)
91                // number we want to make
6 3 5           // 2nd test case
0 1 3 5 7 9
1 2 4           // +, -, / allowed here
28
5 2 10
1 2 6 7 8
2 3               // -, allowed
981

Output:

2        // 91 can be made by directly entering 91 as 1,9 digits are working, so only 2 operations
5            // 35-7=, other ways are 1+3*7=
9          //62*16-11=
```
Order of computation will be followed as symbols entered if + comes, it will be computed first.

*One more example*: let’s say 1,4,6,7,8,9 works and +,-,* works. 2,3,5 and / doesn’t work.
If you have to type 18-> 2 operations. (Each touch is considered an operation),br> If you have to type 5 -> ‘1+4=’ that requires 4 operations. There could be other ways to make ‘5’.



### Question 14 :   [DONE]

There is an island surrounded by oil mines. You will be given n companies and m oil mines having values. You have to distribute the mines to “n” companies in a fair manner. Remember the companies can have oil mines adjacent to each other but not in between of each other. After distributing them compute the difference of oil mines from the company getting highest and company getting lowest. This number should be minimum.(then only the distribution can be termed as fair).

```
Input
2			-Num Of Test Cases
2 4			- N(companies), M(oil mines)
6 13 10 2	- Oil value of each mine
2 4
6 10 13 2

Output
5			- Company1:  +	   Company2:   +   =>   -  =5
1			- Company1: 6+10   Comapny2: 13+2  => 16-15=1
```

### Question 15 : [DONE]

> [Refer Question 11]

A delivery boy wants to deliver some items on his way from office to home. You need to find the optimized path he should take from office to home and deliver all his deliveries on his way. It is 101 X 101 grid. Office, home , delivery points are represented via coordinated (x,y) where 0 <= x <= 100, 0 <= y <= 100. Distance between two points (x1, y1) and (x2,y2) is computed as |x1 – x2| + |y1 – y2| .You need to find the optimized path from office to home covering all delivery locations and return the optimized path length as output. You will be given the input in the 2 lines.

```
First Line – N (no. of delivery locations)

Second Line – (x,y) coordinates of office, followed by home, followed by all N delivery locations.

3
0 0 100 100 20 30 50 50 70 70

output: The length of the optimized path taken.

For above input, the output is 200
```

### Question 16 :

There are N pots. Every pot has some water in it. They may be partially filled. Every pot is associated with overflow number O which tell how many minimum no. of stones required for that pot to overflow. The crow knows O1 to On(overflow no. for all the pots). Crow wants some K pots to be overflow. So the task is the minimum number of stones he can make K pots overflow in the worst case.

```
An array of overflow no--. {1,...On}
Number of pots--n
No of pots to overflow-- k
```

Let say two pots are there with overflow no.s {5,58}, and the crow has to overflow one pot(k=1). So crow will put 5 stones in the pot with overflow no.(58), it will not overflow, then he will put them in the pot with overflow no.(5), hence the total no. of stones to make overflow one pot is=10.
What is the best algorithm to do it?

### Question 18 :[DONE]

Dijkstra code.

### Question 19 :

Kahn’s algorithm.

### Question 20 : [DONE]

Topological Sort.

### Question 21 :

How to implement a stack using BST

### Question 22 :

Write a program to convert char\* mac_address to int array.
Eg: mac_address ="ab : cd : ef : 12 : 34 : 56" to
result= [ab, cd, ef, 12,34,56]

### Question 23 :

Write a MergeSort for Two Different Sorted Link List… Emphasis on TO and SO with all Error Conditions..

### Question 24 :   [DONE]

Stock Buy Sell to Maximize Profit

### Question 25 :   [DONE]

Next greater number set digits

### Question 26 :

Smallest Positive missing number
> [Refer Question 1]

### Question 27 :

Kadane’s Algorithm

### Question 28 :   [DONE]

Given an integer ‘K’ and a tree in string format. We had to print the sum of all elements at Kth level from root.
For example:-

```
        0
    /     \
  5         7
/    \      /   \
6       4    1     3
\
9
```

Tree was given in the form: (node value(left subtree)(right subtree))

For tree given above: (0(5(6()())(4()(9()())))(7(1()())(3()())))

Input format: K Tree

Output format: Sum

For example, for given tree:

Input: 2 (0(5(6()())(4()(9()())))(7(1()())(3()())))

Output: 14

### Question 29 :

A company sells its products with a unique serial number on it. Company has has found that there are some products that don’t sell well which are identified to have ominous numbers in the serial number of the product. So if a serial number of the product contains atmost ’k’ ominous number then it won’t sell.Given a range form s to e, you need to find number of products that would sell, leaving out the products that contains atmost ’k’ ominous numbers.

Input: First line contains the number of test cases, followed buy the range s to e, 1



### Question 31 : [DONE]

A Doctor travels from a division to other division where divisions are connected like a graph(directed graph) and the edge weights are the probabilities of the doctor going from that division to other connected division but the doctor stays 10mins at each division now there will be given time and had to find the division in which he will be staying by that time and is determined by finding division which has high probability.
Input is number of test cases followed by the number of nodes, edges, time after which we need to find the division in which he will be there, the edges starting point, end point, probability.
Note: If he reaches a point where there are no further nodes then he leaves the lab after 10 mins and the traveling time is not considered and during that 10min at 10th min he will be in next division, so be careful.

### Question 32 :   [DONE]

Fishing Spots: 1 to N
3 Gates with gate position and number of fishermen waiting to get in
Distance between consecutive spots = distance between gate and nearest spot = 1 m.
Fishermen are waiting at the gates to get in and occupy nearest fishing spot. Only 1 gate can be opened at a time and all fishermen of that gate must occupy spots before next gate is open.
There could be 2 spots closest to the gate. Assign only 1 spot to the last fisherman in such a way that we get minimum walking distance. For rest of the fishermen, ignore and assign any one.
Write a program to return sum of minimum distance need to walk for fishermen.
Note : The problem can be solved using Recursion and Backtracking by considering all possible combinations.

### Question 33 : [DONE]

Given a string, your task is to find the number of patterns of form 1[0]1 where [0] represents any number of zeroes (minimum requirement is one 0) there should not be any other character except 0 in the [0] sequence.

**Input:**

The first line contains T denoting the number of testcases. Then follows description of testcases. Each case contains a string.

**Output:**

For each test case, output the number of patterns.

**Constraints:**

1<=T<=20

1<=Length of String<=2000

**Example:**
```
Input:
2
100001abc101
1001ab010abc01001

Output:
2
2
```

### Question 34 : [DONE]

You are given a pointer/reference to a node to be deleted in a linked list. The task is to delete the node.  Pointer/reference to head node is not given.  You may assume that the node to be deleted is not the last node.

**Input:**

You have to complete a method which takes one argument: pointer/reference to a node to be deleted.  There are multiple test cases. For each test case, this method will be called individually.


**Example:**
```
Input :
2
2
1 2
1
4
10 20 4 30
20

Output :
2
10 4 30
```

