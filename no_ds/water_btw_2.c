// C++ implementation of the approach
// optimal implementation: O(n)
// below is the easy approach :
//
/*
 * just find which of the two build left will have the most water.
 * Input: arr[] = {1, 3, 4}
Output: 1
We have to calculate the maximum water that can be stored between any 2 buildings.
Water between the buildings of height 1 and height 3 = 0.
Water between the buildings of height 1 and height 4 = 1.
Water between the buildings of height 3 and height 4 = 0.
Hence maximum of all the cases is 1.

Input: arr[] = {2, 1, 3, 4, 6, 5}
Output: 8
*/

#include<bits/stdc++.h>
using namespace std;

// Return the maximum water that can be stored
int maxWater(int height[], int n)
{

	// To store the maximum water so far
	int maximum = 0;

	// Both the pointers are pointing at the first
	// and the last buildings respectively
	int i = 0, j = n - 1;

	// While the water can be stored between
	// the currently chosen buildings
	while (i < j)
	{

		// Update maximum water so far and increment i
		if (height[i] < height[j])
		{
			maximum = max(maximum, (j - i - 1) * height[i]);
			i++;
		}

		// Update maximum water so far and decrement j
		else if (height[j] < height[i])
		{
			maximum = max(maximum, (j - i - 1) * height[j]);
			j--;
		}

		// Any of the pointers can be updated (or both)
		else
		{
			maximum = max(maximum, (j - i - 1) * height[i]);
			i++;
			j--;
		}
	}

	return maximum;
}


// Driver code
int main()
{

	int height[] = { 2, 1, 3, 4, 6, 5 };

	int n = sizeof(height)/sizeof(height[0]);

	cout<<(maxWater(height, n));
}

// This code is contributed by CrazyPro


// CPP implementation of the above approach
#include <bits/stdc++.h>
using namespace std;

// Return the maximum water that can be stored
int maxWater(int height[], int n)
{
	int maximum = 0;

	// Check all possible pairs of buildings
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			int current = (min(height[i],
							height[j])
						* (j - i - 1));

			// Maximum so far
			maximum = max(maximum, current);
		}
	}
	return maximum;
}

// Driver code
int main()
{
	int height[] = { 2, 1, 3, 4, 6, 5 };
	int n = sizeof(height) / sizeof(height[0]);
	cout << maxWater(height, n);
	return 0;
}

// This code is contributed by ihritik

