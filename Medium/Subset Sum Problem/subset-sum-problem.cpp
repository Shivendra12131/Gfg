//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++
class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        bool t[n+1][sum+1];//creating DP table for memoization
        
        //initializing the DP table with base case
        for(int i = 0; i<n+1; i++){
            for(int j = 0; j<sum+1; j++){
                if(i == 0){//if the array is empty, no sum can be formed
                    t[i][j] = false;
                }
                if(j == 0){//if the sum is 0, an empty sumbest can be formed with any number of elements
                    t[i][j] = true;
                }
            }
        }
        
        //populate the dp table with bottom up approach
        for(int i = 1; i<n+1; i++){
            for(int j = 1; j<sum+1; j++){
                if(arr[i-1] <= j){//if the current element is less than or equal to the current sum
             t[i][j] = (t[i-1][j-arr[i-1]] || t[i-1][j]);
        }
        else{//if the current element is greater than the current sum
             t[i][j] = t[i-1][j];
        }
            }
        }
        
        return t[n][sum];//Returning whether the sum is formed with 'n' elements or not
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends