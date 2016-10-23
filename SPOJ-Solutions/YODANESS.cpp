#include <iostream>
#include <string>
#include <queue>
#include <fstream>
#include <stdio.h>
#include <math.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>
#include <set>
using namespace std;
#define MAXSZ 500005


// Returns sum of arr[0..index]. This function assumes
// that the array is preprocessed and partial sums of
// array elements are stored in BITree[].
int getSum(int BITree[], int index)
{
    int sum = 0; // Initialize result
 
    // Traverse ancestors of BITree[index]
    while (index > 0)
    {
        // Add current element of BITree to sum
        sum += BITree[index];
 
        // Move index to parent node in getSum View
        index -= index & (-index);
    }
    return sum;
}
 
// Updates a node in Binary Index Tree (BITree) at given index
// in BITree.  The given value 'val' is added to BITree[i] and
// all of its ancestors in tree.
void updateBIT(int BITree[], int n, int index, int val)
{
    // Traverse all ancestors and add 'val'
    while (index <= n)
    {
       // Add 'val' to current node of BI Tree
       BITree[index] += val;
 
       // Update index to that of parent in update View
       index += index & (-index);
    }
}
 
// Converts an array to an array with values from 1 to n
// and relative order of smaller and greater elements remains
// same.  For example, {7, -90, 100, 1} is converted to
// {3, 1, 4 ,2 }
int temp[MAXSZ];
void convert(int arr[], int n)
{
    // Create a copy of arrp[] in temp and sort the temp array
    // in increasing order

    for (int i=0; i<n; i++)
        temp[i] = arr[i];
    sort(temp, temp+n);
 
    // Traverse all array elements
    for (int i=0; i<n; i++)
    {
        // lower_bound() Returns pointer to the first element
        // greater than or equal to arr[i]
        arr[i] = lower_bound(temp, temp+n, arr[i]) - temp + 1;
    }
}
 
// Returns inversion count arr[0..n-1]
int BIT[MAXSZ];

int getInvCount(int arr[], int n)
{
    int invcount = 0; // Initialize result
 
     // Convert arr[] to an array with values from 1 to n and
     // relative order of smaller and greater elements remains
     // same.  For example, {7, -90, 100, 1} is converted to
    //  {3, 1, 4 ,2 }
    convert(arr, n);
 
    // Create a BIT with size equal to maxElement+1 (Extra
    // one is used so that elements can be directly be
    // used as index)
    for (int i=1; i<=n; i++)
        BIT[i] = 0;
 
    // Traverse all elements from right.
    for (int i=n-1; i>=0; i--)
    {
        // Get count of elements smaller than arr[i]
        invcount += getSum(BIT, arr[i]-1);
 
        // Add current element to BIT
        updateBIT(BIT, n, arr[i], 1);
    }
 
    return invcount;
}
 
string originalSentence[MAXSZ];
string yodaSentence[MAXSZ];
int yodaArr[MAXSZ];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while(t--)
	{
		map<string, int> wordNumber;
		int n;
		cin >> n;
		for(int i = 0; i < n; i ++) cin >> yodaSentence[i];
		for(int i = 0; i < n; i ++) cin >> originalSentence[i], wordNumber[originalSentence[i]] = i;
		for(int i = 0; i < n; i ++) yodaArr[i] = wordNumber[yodaSentence[i]];
		/*set<int> elements;
		int ans = 0;
		for(int i = 0; i < n; i ++)
		{
			int entry = yodaArr[i];
			int elementsGreaterThanEntry;
			if(elements.lower_bound(entry) == elements.end())
				elementsGreaterThanEntry = 0;
			else
				elementsGreaterThanEntry = distance(elements.lower_bound(entry), elements.end());
			ans += elementsGreaterThanEntry;
			elements.insert(entry);
		}*/
		cout << getInvCount(yodaArr, n) << endl;
	}
}
