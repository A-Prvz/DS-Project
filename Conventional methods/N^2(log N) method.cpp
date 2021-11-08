// Naive algorithm to build suffix array of a given text
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

// ARMAN PARVEJ (2K20/SE/28)
// KARTIK BISHT (2K20/SE/69)

// Store information of a suffix
struct suffix
{
	int index;
	char *suff;
};

// Comparison function used to compare two suffixes
int cmp(struct suffix a, struct suffix b)
{
	return strcmp(a.suff, b.suff) < 0? 1 : 0;
}

// Main function that takes a string 'txt' of size n as an argument,
// builds and return the suffix array for the string
int *buildSuffixArray(char *txt, int n)
{
	// Structure to store suffixes and their indexes
	struct suffix suffixes[n];

	// Store suffixes and their indexes in an array of structures.
	for (int i = 0; i < n; i++)
	{
		suffixes[i].index = i;
		suffixes[i].suff = (txt+i);
	}

	// Sort the suffixes.
	sort(suffixes, suffixes+n, cmp);

	// Store indexes of all sorted suffixes in the suffix array
	int *suffixArr = new int[n];
	for (int i = 0; i < n; i++)
		suffixArr[i] = suffixes[i].index;

	// Return the suffix array
	return suffixArr;
}

// Function to print an array of given size.
void printArr(int arr[], int n)
{
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

// Driver Code
int main()
{
    cout << "Enter the Text: " ;
	char txt[100];
    cin >> txt;
	int n = strlen(txt);
	int *suffixArr = buildSuffixArray(txt, n);
	cout << "Following is suffix array for " << txt << " is :" << endl;
	printArr(suffixArr, n);
	return 0;
}
