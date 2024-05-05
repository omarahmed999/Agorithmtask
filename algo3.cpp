#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    unordered_map<int, int> mp;
    int x;
    cin >> x;
    int arr[x];
    for (int i = 0; i < x; i++)
    {
        cin >> arr[i];
        mp[arr[i]]++;
    }
    int mx = mp[arr[0]];
    int maxe = arr[0];
    for (int i = 0; i < x; i++)
    {
        if (mx < mp[arr[i]])
        {
            mx = mp[arr[i]];
            maxe = arr[i];
        }
    }
    // cout<<mx<<"\n"<<maxe<<"\n";
    if (mx <= (x / 2))
    {
        cout << -1;
    }
    else
    {
        for (int i = 0; i < x; i++)
        {
            if (arr[i] == maxe)
                cout << i << " ";
        }
    }
    return 0;
}