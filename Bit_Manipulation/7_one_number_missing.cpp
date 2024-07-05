/*
One number is missing from the list of integers from 1 to n. Find that missing number.

Example:

{1, 2, 5, 6, 3, 7} => 4
{2, 4, 6, 5, 1} => 3
Solution Idea:

Method 1: The simple way to find the missing number is to find the xor of numbers from 1 to n and then find the xor of this answer with the xor of all the elements of the given list.
*/

#include<bits/stdc++.h>
typedef long long lli;
using namespace std;
lli mod=1e9+7;
using namespace std;

int find_missing_number(vector<int> &arr)
{
    int m = arr.size();
    int n=m+1;
    int ans=0;
    for(int i=1;i<=n;i++) // find the xor from 1 to n
    {
        ans = ans^i;
    }
    for(int i=0;i<m;i++) // find xor from a[0] to a[n-2]
    {
        ans = ans^arr[i];
    }
    return ans;
}

void solve()
{
    vector<int> arr = {1, 2, 5, 6, 3, 7};
    int ans = find_missing_number(arr);
    cout<<ans<<endl;
}

int main()
{
    lli t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0; 
}
