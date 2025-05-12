//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    long long divide(long long dividend, long long divisor) {
        // code here
        if (divisor == 0) throw std::invalid_argument("Division by zero");

        // Handle sign
        int neg = 1;
        if ((dividend < 0) ^ (divisor < 0)) neg = -1;

        unsigned long long u_dividend = abs(dividend);
        unsigned long long u_divisor = abs(divisor);

        unsigned long long quotient = 0;
        unsigned long long remainder = 0;

        for (int i = 63; i >= 0; i--) {
            remainder = (remainder << 1) | ((u_dividend >> i) & 1);

            if (remainder >= u_divisor) {
                remainder -= u_divisor;
                quotient |= (1ULL << i); // Set bit i
            }
        }

        return neg * static_cast<long long>(quotient);
    }
};


//{ Driver Code Starts.
int main() {
	int t;
	cin >> t;

	while (t--)
	{

		long long a, b;
		cin >> a >> b;
		
		Solution ob;
		cout << ob.divide(a, b) << "\n";
	
cout << "~" << "\n";
}

	return 0;
}

// } Driver Code Ends