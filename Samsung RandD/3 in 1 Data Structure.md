---
title: Solve 3 in 1 Data Structure
source: https://www.hackerrank.com/contests/srin-aadc01/challenges/3-in-1-data-structure
author:
  - "[[HackerRank]]"
published: 
created: 2024-12-18
description: Learn about Stack, Queue, and Priority Queue in one problem. Thats why I called it 3 in 1
tags:
  - clippings
status: ""
explored: true
---
## 3 in 1 Data Structure

locked

- [Problem](https://www.hackerrank.com/contests/srin-aadc01/challenges/3-in-1-data-structure)
- [Submissions](https://www.hackerrank.com/contests/srin-aadc01/challenges/3-in-1-data-structure/submissions)
- [Leaderboard](https://www.hackerrank.com/contests/srin-aadc01/challenges/3-in-1-data-structure/leaderboard)
- [Discussions](https://www.hackerrank.com/contests/srin-aadc01/challenges/3-in-1-data-structure/forum)
- [Editorial](https://www.hackerrank.com/contests/srin-aadc01/challenges/3-in-1-data-structure/editorial)

Your friend is studying about stack, queue and priority queue.  
In case you forget about what is stack, queue, and priority queue, we provide link to refresh your memorize.  
Link to learn [Stack and Queue](https://www.hackerrank.com/external_redirect?to=https://www.hackerearth.com/notes/stacks-and-queues/)  
Link to learn [Priority Queue](https://www.hackerrank.com/external_redirect?to=https://www.hackerearth.com/notes/heaps-and-priority-queues/)

Now you asked by your friend to do some N queries.  
There are 3 kinds of queries :  
1\. "1 x" - Add number x into stack, queue, and min priority queues  
2\. "2" - Remove top element from stack, front element from queue, and minimum element from priority queue. If not possible, print "impossible" (without the quotes).  
3\. "3" - Print top element from stack, front element from queue, and min element from priority queues in format "x y z", where x is stack's top element, y is queue's front element, and z is priority queue's front/minimum element. If not possible, print "empty" (without the quotes).

**Constraint :**  
1 ≤ N≤ 100000  
1 ≤ x≤ 100000

**Notes :**  
For exercise purpose, please don't use library, but you can make stack, queue, and priority queue from scratch. Yes, you can take a look from link that we provide above.

**Input Format**

The first line contains the integer N, that is number of queries.  
The next N lines will each contain a query like the ones mentioned above.

**Output Format**

Print the answer like the ones mentioned above line by line.

**Sample Input**

```
14
1 3
1 1
1 2
1 5
1 4
3
2
3
2
2
2
2
2
3
```

**Sample Output**

```
4 3 1
5 1 2
impossible
empty
```