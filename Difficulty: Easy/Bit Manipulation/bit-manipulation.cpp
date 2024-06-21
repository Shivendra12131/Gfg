//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void bitManipulation(int num, int i) {
        i=i-1;
        int x=0;
        if((num&(1<<i))>0){
            cout<<"1 ";
            
        } 
        else{
            cout<<"0 ";
        }
        x=num;
        x=((x|(1<<i)));
        cout<<x<<" ";
       int clearedBitNum = num & ~(1 << i);
    cout << clearedBitNum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n >> i;
        Solution ob;
        ob.bitManipulation(n, i);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends