// C++ code to print all possible subarrays
// for given array using recursion
// check if the bit corresponding subarray a[] has a bit set for the first value, only then make use of that subarray.
// also make sure the subarray is in ascending order. Then return the result.

#include <iostream>
# include <vector>
using namespace std;

static int c = 0;
static int flag = 1;

// Recursive function to print all possible subarrays
// for given array
int printSubArrays(vector<int> arr, vector<int> a, int start, int end)
{
	// Stop if we have reached the end of the array
	if (end == arr.size())
		return c;

	// Increment the end point and start from 0
	else if (start > end)
		printSubArrays(arr, a, 0, end + 1);

	// Print the subarray and increment the starting point
	else
	{
	        if(a[start] == 0) {
                if (start == end) {
                        flag = 1;
                        cout << "[";
                        cout << arr[end] << "]" << endl;
                        //c = c+1;
                } else {
		cout << "[";
		for (int i = start; i < end; i++){
                        if (arr[i] < arr[i+1]) {
                                cout << arr[i] << ", ";
                                cout << arr[i+1] << ", ";
                                flag = 1;
                        }
                        else {
                                flag = 0;
                                break;
                        }
		}

		cout << arr[end] << "]" << endl;
                }
                if (flag ==1)
                        c = c+1;
                flag = 0;
                }
	        printSubArrays(arr, a, start + 1, end);
	}


	return c;
}

int main()
{
//vector<int> arr = {1, 2, 3, 4, 5};
vector<int> arr = {5, 4, 3, 2, 1};
vector<int> a = {0, 0, 0, 0, 0};
cout << printSubArrays(arr, a, 0, 0);
return 0;
}

