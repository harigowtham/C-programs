/*Optimal File Merge Patterns
Difficulty Level : Medium
Last Updated : 27 Aug, 2020
Given n number of sorted files, the task is to find the minimum computations done to reach Optimal Merge Pattern.

When two or more sorted files are to be merged all together to form a single file, the minimum computations done to reach this file are known as Optimal Merge Pattern.

If more than 2 files need to be merged then it can be done in pairs. For example, if need to merge 4 files A, B, C, D. First Merge A with B to get X1, merge X1 with C to get X2, merge X2 with D to get X3 as the output file.

If we have two files of sizes m and n, the total computation time will be m+n. Here, we use greedy strategy by merging two smallest size files among all the files present.

Examples:
Given 3 files with size 2, 3, 4 units.Find optimal way to combine these files

Soln:
sorting and merging will give the most optimal. But this will be nlog n.
So if we use heap, we can do it in O(n). (we arent running heapify as only the popped ele has to be the min)
Once popped, we can added it to the sum and that will be min
Input: n = 3, size = {2, 3, 4}
Output: 14

*/

// C++ program to implement
// Optimal File Merge Pattern
#include<bits/stdc++.h>
using namespace std;

// Function to find minimum computation
int minComputation(int size, int files[])
{
	
	// Create a min heap
	priority_queue<int, vector<int>,
		greater<int>> pq;

	for(int i = 0; i < size; i++)
	{
		
		// Add sizes to priorityQueue
		pq.push(files[i]);
	}
	
	// Variable to count total Computation
	int count = 0;

	while(pq.size() > 1)
	{
		
		// pop two smallest size element
		// from the min heap
		int first_smallest = pq.top();
		pq.pop();
		int second_smallest = pq.top();
		pq.pop();
		
		int temp = first_smallest + second_smallest;

		// Add the current computations
		// with the previous one's
		count += temp;

		// Add new combined file size
		// to priority queue or min heap
		pq.push(temp);
	}
	return count;
}

// Driver code
int main()
{
	
	// No of files
	int n = 6;
	
	// 6 files with their sizes
	int files[] = { 2, 3, 4, 5, 6, 7 };
	
	// Total no of computations
	// do be done final answer
	cout << "Minimum Computations = "
		<< minComputation(n, files);

	return 0;
}

// This code is contributed by jaigoyal1328

