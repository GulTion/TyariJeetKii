---
title: Coronavirus Statistics
source: https://www.hackerrank.com/contests/swc-monthly-contest-december2020/challenges/coronavirus-statistics
author:
  - "[[HackerRank]]"
published: 
created: 2025-02-24
description: Practice problem
tags:
  - clippings
---
**\[Limits\]**

| Execution Time | 3 sec (C/C++) / 6 sec (Java) for 5 test cases combined |
| --- | --- |
| Memory Limit | Maximum 256MB is available for heap and static memory combined |

**\[Warnings\]**

Make sure not to add any extra library except the allowed ones in your submission. Otherwise, you will be ***disqualified***.

Allowed libraries for C/C++:   stdio.h, malloc.h, iostream  
Allowed libraries for Java:       java.io.BufferedReader, java.io.InputStreamReader, java.util.StringTokenizer

---

**\[Problem Description\]**

We all know how coronavirus affected our lives in 2020. We have been fighting so hard to overcome the situation. Data analysis is very important when we need to fight any kind of battle situation. From that point of view, here we will collect and store data about coronavirus and how it affected people.

In short, here we will build a system which will collect and store data about the effects of coronavirus (number of cases, recoveries and deaths) for countries on day basis.

The system will perform two types of operations -

1. Add a info to the sytem.

```
Add(COUNTRY, DAY, CASES, RECOVERIES, DEATHS)
```

2. Query a value from the system.

```
Query(COUNTRY, TYPE, DAY, NUMBER)
```

Here are the details about the parameters in these operations -

***COUNTRY*** - a string not more than **10** uppercase characters (e.g. BANGLADESH, KOREA).

***DAY*** – an integer number between **1** to **10<sup>9</sup>** or a question mark character (**?**).

***CASES***, ***RECOVERIES***, ***DEATHS*** - integer numbers between **1** to **10<sup>9</sup>**.

***TYPE*** – a character which can be any of these 3 values –

1. ***C*** - *CASES* in a *DAY*
2. ***R*** - *RECOVERIES* in a *DAY*
3. ***D*** - *DEATHS* in a *DAY*

***NUMBER*** – a 64 bit integer number between between **1** to **10<sup>18</sup>** or a question mark character (**?**).

Here are the properties of the system -

- We will start managing data from day 1 to beyond (2, 3,...,100, 101,...). In each day we will get report (cases, recoveries and deaths) from some countries (can be 0). Some countries may send their report daily, some may send weekly or some may send with a random day difference. *But no country will send their report more than once in a day.* Those countries who didn't provide report in a day, we can assume their cases, recoveries and deaths were 0 for that day. For example - we want to check the data up to day 5. The country ABC send their report in day 2 and 4. We can assume, they had 0 cases, 0 recoveries and 0 deaths on day 1, 3 and 5.
- The days in add operations will be in non-decreasing order. But the days in query opertions will be in random order.
- In query operations, we are only interested about the total number of cases, recoveries or deaths for countries up to some day (e.g. day 100) or on which day the total number of cases, recoveries or deaths reached a certain number (e.g. 1 million).
- A question mark (?) as a value of *DAY* or *NUMBER* will be applied only for query operations. Only one of the values of *DAY* and *NUMBER* will be a question mark (?), which indicates the value needs to be returned.

1. *Query(COUNTRY, TYPE, DAY, ?)* – need to return the total number of that *TYPE* up to that DAY in that *COUNTRY*. For example - *Query(KOREA, C, 20, ?)* means we need to return the total number of cases up to day 20 in Korea.
2. *Query(COUNTRY, TYPE, ?, NUMBER)* – need to return the DAY when total number of that type reached (equal or more) the *NUMBER* in that *COUNTRY*. For example - *Query(KOREA, D, ?, 100)* means we need to return number of the day when total deaths reached 100 in Korea.
- If a query is involved a country which wasn't added yet, we can assume the country isn't affected yet and consider the values (cases, recoveries and deaths) **0**. (Check sample data for better understanding)
- If a query is asked for a day with such number (cases, recoveries or deaths) which isn't reached yet, we can consider this as invalid scenario (may reach in future or may not reach at all, we don't know) and return the day as **\-1**. (Check sample data for better understanding)
- There can be a special value of country (***WORLD***) in query operations. When *COUNTRY = WORLD* is given, the answer to be returned is the summation of all values of all countries. For example – *Query(WORLD, D, ?, 100000)* means we need to return the day when the number of total deaths in the world (summation of all countries) reached 100000.

**Input Format**

Take the number of test cases in first line.

For each of the test cases, take a integer number which indicates the number of operations for that test case.

For each operation take a character (**A** or **Q**). A means Add operation, Q means Query operation.

For operation A, take 5 more values described above and for Q, take 4 more.

Multiple values in single line will be space separated.

**Constraints**

- The number of total test cases can be at most **5**.
- The number of total queries in all test cases can be at most **500000 (5 x 10<sup>5</sup>)**.
- The number of total countries in all test cases can be at most **5000**.

**Output Format**

Output a value in a single line for each of the query operations.

**Sample Input 0**

```
1
14
A ABC 1 2 3 4
A XYZ 2 4 3 2
A ABC 2 2 3 4
A ABC 3 2 3 4
A XYZ 4 4 3 2
Q ABC R 2 ?
A ABC 5 2 3 4
Q PQR C 5 ?
A ABC 8 2 3 4
A XYZ 9 4 3 2
Q ABC C ? 10
Q ABC D 10 ?
Q WORLD R 5 ?
Q XYZ D ? 20
```

**Sample Output 0**

```
6
0
8
20
18
-1
```