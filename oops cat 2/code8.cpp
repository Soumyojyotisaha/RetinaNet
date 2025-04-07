#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int arr[n];
    

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    n=sizeof(arr)/sizeof(arr[0]);

    reverse(arr,arr+n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i];
    }
  return 0;

}