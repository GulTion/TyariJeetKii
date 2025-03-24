---
source: 
status: Pending
---

Given a Binary search tree. Your task is to complete the function `kthLargest` which will return the Kth largest element without doing any modification in Binary Search Tree.

```cpp
#include <iostream>
using namespace std;
struct Node
{
    int key;
    Node *left, *right;
};
Node *newNode(int item)
{
    Node *temp = new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
void kthLargest(Node *root, int k);
Node *insert(Node *node, int key)
{
    if (node == NULL)
        return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    return node;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node *root = NULL;
        int n;
        cin >> n;
        int a;
        cin >> a;
        root = insert(root, a);
        for (int i = 0; i < n - 1; i++)
        {
            cin >> a;
            insert(root, a);
        }
        int k;
        cin >> k;
        kthLargest(root, k);
    }
    return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The Node structure is defined as
struct Node
{
    int key;
    Node *left, *right;
}; */
/*Complete the function below*/
void kthLargest(Node *root, int k)
{
    //Your code here
}
```

**Input:**
The first line of input contains an integer $T$, denoting the no of test cases. Then $T$ test cases follow. Each test case consists of three lines. The first line of each test case contains an integer $N$ denoting the no of elements in BST. Then in the next line are $N$ space separated values of the BST. The third line of each test case contains an integer $k$ for $k$ largest element.

**Output:**
Print the $k^{th}$ largest element in each line.

**Constraints:**
- $1 \leq T \leq 20$
- $1\leq N$
- $k \leq 20$


**Example(To be used only for expected output):**
```
Input:
1
7
50 30 20 40 70 60 80
3

Output:
60
```

## approach 1
```cpp

void actualKthLargest(Node *root, int *k){
    if (*k < 0)
    {
        return;
    }
    if (root == NULL)
    {
        return;
    }
    actualKthLargest(root->right, k);
    *k-=1;
    //cout << "\t" << root->key << "\t" << *k << endl;
    if (*k == 0)
    {
        cout << root->key << endl;
        *k -= 1;
        return;
    }
    actualKthLargest(root->left, k);
}

void kthLargest(Node *root, int k)
{
    //Your code here
    actualKthLargest(root, &k);
}

```