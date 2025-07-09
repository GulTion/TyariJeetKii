/*
https://www.careercup.com/question?id=5680648437104640



// // If you have to type 18-> 2 operations. (Each touch is considered an operation),br> If you have to type 5 -> '1+4=' that requires 4 operations. There could be other ways to make '5'.
// // */
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define mod 1000000007
// #define all(v) v.begin(), v.end()
// #define endl '\n'
// int ans;

// bool isHave(vector<int>num_digits, int n)
// {
//     for(int i=0;i<num_digits.size();i++)
//     {
//         if(num_digits[i]==n)
//         {
//             return true;
//         }
//     }
//     return false;
// }

// void func(int n, int m, int o, vector<int> digits, vector<int> operators, int num, int curr, int touch, vector<int>num_digits)
// {
//     if (curr == num)
//     {
//         ans = min(ans, touch);
//         return;
//     }

//     if (touch > o)
//     {
//         return;
//     }

//     for (int i = 0; i < n; i++)
//     {

//         if (curr == 0)
//         {
//             func(n, m, o, digits, operators, num, digits[i], touch + 1,num_digits);
//         }
//         else
//         {
            
//             if (operators[0])
//             {
//                 func(n, m, o, digits, operators, num, curr + digits[i], touch + 3,num_digits);
//             }
//             if (operators[1])
//             {
//                 func(n, m, o, digits, operators, num, curr - digits[i], touch + 3,num_digits);
//             }
//             if (operators[2])
//             {
//                 func(n, m, o, digits, operators, num, curr * digits[i], touch + 3,num_digits);
//             }
//             if (operators[3])
//             {
//                 if(digits[i]!=0)
//                 {
//                     func(n, m, o, digits, operators, num, curr / digits[i], touch + 3,num_digits);
//                 }
//             }

//             if(isHave(num_digits,digits[i])){
//                 func(n, m, o, digits, operators, num, curr*10 + digits[i], touch + 1,num_digits);
//             }
//         }
//     }
// }

// signed main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n, m, o;
//         cin >> n >> m >> o;

//         vector<int> digits(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin >> digits[i];
//         }
//         sort(digits.begin(),digits.end());
//         vector<int> operators(4, 0);
//         for (int i = 0; i < m; i++)
//         {
//             int a;
//             cin >> a;
//             operators[a] = 1;
//         }
//         int num;
//         cin >> num;
//         int tempNum = num;
//         vector<int> num_digits;
//         while(num>0)
//         {
//             int temp = num%10;
//             num_digits.push_back(temp);
//             num = num/10;
//         }
//         ans = INT_MAX;

//         func(n, m, o, digits, operators, tempNum, 0, 0, num_digits);
//         cout<<ans<<endl;
//     }
// }


