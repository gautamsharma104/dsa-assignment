// search an element in an array of infinite size
#include<bits/stdc++.h>
using namespace std;

// Simple binary search algorithm
int binarySearch(int arr[], int low, int high, int key)
{
	if (high>=low)
	{
		int mid = low+ (high - low)/2;
		if (arr[mid] == key)
			return mid;
		if (arr[mid] > key)
			return binarySearch(arr, low, mid-1, key);
		return binarySearch(arr, mid+1, high, key);
	}
	return -1;
}

 
int findPos(int arr[], int key)
{
	int low = 0, high = 1;
	int value = arr[0];

	// Find high to do binary search
	while (value < key)
	{
		low = high;	 
		high = 2*high;	 
		value = arr[high]; 
	}

//  use binary search between updated high and low positions
	return binarySearch(arr, low, high, key);
}

// Driver program
int main()
{
	int arr[] = {2, 4, 5, 8, 10, 35, 113, 121,135, 154, 189};
	int ans = findPos(arr,10);
	if (ans==-1)
		cout << "Element not found";
	else
		cout << "Element found at index " << ans << " and Element is " << arr[ans] << endl;
	return 0;
}

