// C++ code to calculate maximum unique 
// element of every segment of array 
#include <bits/stdc++.h> 
using namespace std; 

void find_max(int A[], int N, int K) 
{ 
	// Storing counts of first K-1 elements 
	// Also storing distinct elements. 
	map<int, int> Count; 
	for (int i = 0; i < K - 1; i++) 
		Count[A[i]]++; 
	set<int> Myset; 
	for (auto x : Count) 
		if (x.second == 1) 
			Myset.insert(x.first); 

	// Before every iteration of this loop, 
	// we maintain that K-1 elements of current 
	// window are processed. 
	for (int i = K - 1; i < N; i++) { 

		// Process K-th element of current window 
		Count[A[i]]++; 
		if (Count[A[i]] == 1) 
			Myset.insert(A[i]); 
		else
			Myset.erase(A[i]); 

		// If there are no distinct 
		// elements in current window 
		if (Myset.size() == 0) 
			printf("Nothing\n"); 
		
		// Set is ordered and last element 
		// of set gives us maximum element. 
		else
			{
                auto it = Myset.rbegin();
                printf("%d\n", *it); 
                }
		
		// Remove first element of current 
		// window before next iteration. 
		int x = A[i - K + 1]; 
		Count[x]--; 
		if (Count[x] == 1) 
			Myset.insert(x); 
		if (Count[x] == 0) 
			Myset.erase(x); 
	} 
} 

// Driver code 
int main() 
{ 
	int a[] = { 1, 2, 2, 3, 3 }; 
	int n = sizeof(a) / sizeof(a[0]); 
	int k = 3; 
	find_max(a, n, k); 
	return 0; 
} 
