---
title: Solve Aragorn is Gone
source: https://www.hackerrank.com/contests/srbd-code-contest-2024-round-1/challenges/aragorn-is-gone
author:
  - "[[HackerRank]]"
published: 
created: 2024-12-18
description: Given an array. Find the total number of subset such that the sum of the subset is divisible by the size of the subset.
tags:
  - clippings
status: 
explored: true
---
![[Aragorn is Gone.pdf]]


**1. Understanding the Core Problem**

First, we read the problem statement carefully. The crucial part is:
*   Sauron needs to form a team by choosing **one or multiple Orcs**.
*   The condition: "the overall energy of the team is **divisible by the size of the team**."
*   We need to find the **total number of ways** to form such a team, modulo $10^9 + 7$.

Let's denote:
*   $N$: total number of Orcs available.
*   $A_i$: energy level of the $i$-th Orc.
*   $s$: the size of a chosen team (number of Orcs in the team). So, $1 \le s \le N$.
*   $E_{chosen}$: the sum of energies of the $s$ Orcs in the chosen team.

The condition translates to: $E_{chosen} \pmod s = 0$.

**2. Initial Thoughts & Brute Force (and why it won't work)**

My first instinct might be to try all possible teams.
*   A team is a subset of the $N$ Orcs.
*   There are $2^N$ possible subsets. If we exclude the empty set (as we need "one or multiple Orcs"), it's $2^N - 1$.
*   For each subset:
    1.  Calculate its size, $s$.
    2.  Calculate the sum of energies of its members, $E_{chosen}$.
    3.  Check if $E_{chosen} \pmod s = 0$. If yes, count it.

Constraints: $N \le 100$.
$2^{100}$ is an astronomically large number (approx $1.26 \times 10^{30}$). This approach is far too slow. We need something more efficient.

**3. Breaking Down the Problem: The Role of Team Size 's'**

The divisibility condition $E_{chosen} \pmod s = 0$ critically depends on $s$, the size of the team. This suggests that maybe we can iterate through all possible team sizes.

Let's fix a team size, say $s_{fixed}$.
Now the problem becomes: "How many ways are there to choose exactly $s_{fixed}$ Orcs from the $N$ available Orcs such that the sum of their energies is divisible by $s_{fixed}$?"

If we can solve this for each $s_{fixed}$ (from $1$ to $N$), then the total number of ways is:
$$ \text{TotalWays} = \sum_{s_{fixed}=1}^{N} \left( \text{Ways to pick } s_{fixed} \text{ Orcs satisfying the condition for } s_{fixed} \right) $$

This decomposition seems promising because it breaks a complex problem into smaller, potentially manageable subproblems.

**4. Solving for a Fixed Team Size $s_{fixed}$: Dynamic Programming**

Now, for a fixed $s_{fixed}$, we need to choose exactly $s_{fixed}$ Orcs out of $N$ such that their sum of energies $\sum E_i \pmod{s_{fixed}} = 0$.

This subproblem has characteristics of a dynamic programming problem:
*   We are making a sequence of decisions (for each Orc, do we include it in our team of $s_{fixed}$ Orcs or not?).
*   We need to keep track of certain state:
    *   How many Orcs have we chosen so far for our team of size $s_{fixed}$?
    *   What is the sum of energies modulo $s_{fixed}$ for the Orcs chosen so far?

Let's define a DP state:
$dp[k][\text{rem}]$ = Number of ways to choose exactly $k$ Orcs from the Orcs considered *so far*, such that the sum of their energies modulo $s_{fixed}$ is $\text{rem}$.

*   $k$ will range from $0$ to $s_{fixed}$.
*   $\text{rem}$ will range from $0$ to $s_{fixed}-1$.

We will iterate through each of the $N$ available Orcs one by one. When we consider a new Orc, say $A_j$ with energy $E_j$:

*   **Initialization:** Before considering any Orcs, $dp[0][0] = 1$ (one way to choose 0 Orcs with a sum of 0). All other $dp[0][\text{rem}]$ are 0, and all $dp[k][\text{rem}]$ for $k > 0$ are 0.

*   **Transition:** When we process Orc $A_j$ (with energy $E_j$):
    We want to update the $dp$ table. For each possible number of chosen Orcs $k$ (from $s_{fixed}$ down to $1$) and for each possible remainder $\text{rem}$:
    If we *include* $A_j$ to form a team of $k$ Orcs with sum $\equiv \text{rem} \pmod{s_{fixed}}$:
    This means that *before* considering $A_j$, we must have already chosen $k-1$ Orcs whose sum of energies was $\text{prev\_rem}$, where
    $$ (\text{prev\_rem} + E_j) \pmod{s_{fixed}} = \text{rem} $$
    $$ \text{prev\_rem} = (\text{rem} - E_j \pmod{s_{fixed}} + s_{fixed}) \pmod{s_{fixed}} $$
    (We add $s_{fixed}$ before the final modulo to ensure the result is non-negative if $\text{rem} - E_j \pmod{s_{fixed}}$ is negative).
    Let $E_{j,mod} = (E_j \pmod{s_{fixed}} + s_{fixed}) \pmod{s_{fixed}}$.
    Then $\text{prev\_rem} = (\text{rem} - E_{j,mod} + s_{fixed}) \pmod{s_{fixed}}$.
    The number of ways to achieve this is $dp[k-1][\text{prev\_rem}]$ (from the state *before* processing $A_j$).

    So, the update rule looks like this:
    For each Orc $A_j$:
        Let $E_{j,mod} = (A_j \pmod{s_{fixed}} + s_{fixed}) \pmod{s_{fixed}}$.
        Iterate $k$ from $s_{fixed}$ down to $1$:  (*Why downwards? See note below*)
            Iterate $\text{rem}$ from $0$ to $s_{fixed}-1$:
                Calculate $\text{prev\_rem\_needed} = (\text{rem} - E_{j,mod} + s_{fixed}) \pmod{s_{fixed}}$.
                $dp[k][\text{rem}] = (dp[k][\text{rem}] + dp[k-1][\text{prev\_rem\_needed}]) \pmod{MOD}$.

    *Note on iterating $k$ downwards:* If we iterate $k$ upwards (e.g., from $1$ to $s_{fixed}$), when we calculate $dp[k][\text{rem}]$ using $dp[k-1][\text{prev\_rem\_needed}]$, the value $dp[k-1][\text{prev\_rem\_needed}]$ might have *already been updated using the current Orc $A_j$*. This would be incorrect, as it would mean we are effectively using Orc $A_j$ multiple times to reach the $k$-th item state. By iterating $k$ downwards, $dp[k-1][\ldots]$ always refers to states formed *without* considering $A_j$ for the $(k-1)$-th item slot, which is what we want.

*   **Final Answer for this $s_{fixed}$:** After processing all $N$ Orcs, the value $dp[s_{fixed}][0]$ will give the number of ways to choose exactly $s_{fixed}$ Orcs such that their total energy sum is divisible by $s_{fixed}$.

**5. Putting It All Together (The Overall Algorithm)**

1.  Initialize $\text{TotalOverallWays} = 0$.
2.  Set $\text{MOD} = 10^9 + 7$.
3.  For each possible team size $s_{val}$ from $1$ to $N$:
    a.  Create a DP table: `dp[s_val + 1][s_val]`, initialized to zeros. `dp[k][rem]`
    b.  Set $dp[0][0] = 1$.
    c.  For each Orc energy $A_i$ in the input array:
        i.  Calculate $a\_mod\_sval = (A_i \pmod{s_{val}} + s_{val}) \pmod{s_{val}}$.
        ii. For $k$ from $s_{val}$ down to $1$:
            iii. For $\text{rem}$ from $0$ to $s_{val}-1$:
                1.  $\text{prev\_rem\_needed} = (\text{rem} - a\_mod\_sval + s_{val}) \pmod{s_{val}}$.
                2.  $dp[k][\text{rem}] = (dp[k][\text{rem}] + dp[k-1][\text{prev\_rem\_needed}]) \pmod{\text{MOD}}$.
    d.  Add $dp[s_{val}][0]$ to $\text{TotalOverallWays}$.
    e.  $\text{TotalOverallWays} = \text{TotalOverallWays} \pmod{\text{MOD}}$.
4.  The final $\text{TotalOverallWays}$ is the answer for the test case.

**6. Complexity Analysis**

*   Outer loop for $s_{val}$: $N$ iterations.
*   Inside this loop:
    *   DP table initialization: $O(s_{val}^2)$, at most $O(N^2)$.
    *   Loop for each Orc $A_i$: $N$ iterations.
        *   Loop for $k$: $s_{val}$ iterations, at most $N$.
        *   Loop for $\text{rem}$: $s_{val}$ iterations, at most $N$.
        *   Total for the DP update part: $N \times s_{val} \times s_{val} = N \cdot s_{val}^2$.
*   So, the total complexity is $\sum_{s_{val}=1}^{N} (O(s_{val}^2) + N \cdot s_{val}^2)$.
    The dominant term is $N \sum_{s_{val}=1}^{N} s_{val}^2$.
    We know that $\sum_{i=1}^{N} i^2 = \frac{N(N+1)(2N+1)}{6}$, which is $O(N^3)$.
    Therefore, the total time complexity is $N \cdot O(N^3) = O(N^4)$.

*   Given $N \le 100$:
    $100^4 = 10^8$. This is on the higher side for a 1-second time limit, but often the "Big O" notation hides smaller constant factors, or the worst-case test data (N=100 for all test cases) is not used. The problem states "overall summation of N is $\le 100$". This means if $T=100$, average $N=1$. If $N=100$, then $T=1$. If $N=50$, $T$ could be $2$. This summation constraint makes $O(N^4)$ feasible. For example, if $N_{max}=70$, $70^4 \approx 2.4 \times 10^7$, which is fine. If $N=100$ for one case, it's $10^8$, which might just pass.

*   Memory Complexity: The DP table for a fixed $s_{val}$ is of size $(s_{val}+1) \times s_{val}$. Max size is for $s_{val}=N$, so $(N+1) \times N$ elements. Each stores a `long long`. For $N=100$, this is roughly $100 \times 100 \times 8 \text{ bytes} = 80 \text{KB}$, which is well within the 512MB limit.

**7. Key Intuitions and Steps Summarized:**

1.  **Decomposition by Parameter:** The condition $S \pmod s = 0$ has $s$ as a varying parameter. Fixing $s$ simplifies the problem. This is a common strategy: if a problem constraint involves multiple interacting variables, try fixing one (or more) and see if the subproblem becomes easier.
2.  **Recognizing DP Pattern:** The subproblem (for fixed $s$) involves making choices (select Orcs) to achieve a target state (sum $\pmod s = 0$, exactly $s$ Orcs chosen). This "counting ways to achieve a state by making selections" is a classic DP scenario, often related to knapsack-type problems or subset sum variations.
3.  **State Definition:** The DP state $dp[k][\text{rem}]$ naturally arises from what we need to track: number of items chosen ($k$) and the property of their sum ($\text{rem}$).
4.  **Order of Iteration:** Iterating $k$ downwards in the DP update is crucial for correctness when using a space-optimized DP (where the "previous Orc" dimension is implicit).
5.  **Modular Arithmetic:** Always perform modulo operations at each addition to prevent overflow and keep numbers within manageable bounds. Be careful with negative numbers in modulo operations; using $(x \pmod m + m) \pmod m$ ensures a positive remainder.

This structured approach—breaking down the problem, identifying standard algorithmic patterns for subproblems, defining states carefully, and analyzing complexity—is how one generally tackles such problems. The specific "aha!" moment is often recognizing that iterating over team size $s$ makes the inner problem a known DP pattern.