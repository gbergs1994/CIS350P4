/** program4Test.cpp
 *
 * Desecription: The Test Program for Program 4
 *
 * Assumptions: Three public methods as follows are defined in Sorts class in a file named Sorts.h
 *    static int insertionSort (vector <Comparable> & a)
 *    static int quicksortWithoutCutoff (vector <Comparable> & a)
 *    static int quicksortWithCutoff (vector <Comparable> & a, int cutoff)
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include "Sorts.h"
using namespace std;

void Display(const vector<int>& vi)
{
	for(size_t i=0; i< vi.size(); ++i)
		cout <<vi[i] << ",";
	cout<<endl;
}


int main()
{
	int totalCmp = 0;
	int totalQuickCmp = 0;
	int totalQuickCmp1 = 0;
	int numPerm = 0;

	vector<int> vi;
	vector<int> vi2;
	vector <int> a;

	int n = 1;
	// generate a vector 1..n in the sorted order
	for (int i = 1; i <= n; i++) {
		vi.push_back(i);
	}

	//sort all possible permutations and record the number of element comparisons
	do {
		a = vi;
		totalCmp += Sorts<int>::insertionSort (a);

		a = vi;
		totalQuickCmp += Sorts<int>::quicksortWithoutCutoff (a);

		numPerm++;

	} while(next_permutation(vi.begin(),vi.end()) && numPerm <= 999999); //random subsets <= 1 million to reduce time needed to run experiment

	cout << "Final sorted array: " << endl;
	Display (a);

	cout << "N = " << n << endl; 
	cout << "Number of permutations :" << numPerm <<endl;
	cout << "Insertion sort, number of comparisons: total = " << totalCmp <<", avg = " << double (totalCmp)/numPerm << endl;
	cout << "Quicksort without cutoff, number of comparisons: total = " << totalQuickCmp << ", avg = " <<double (totalQuickCmp)/numPerm << endl;
	cout << endl;

	totalCmp = 0;
	totalQuickCmp = 0;


	//generate an array of size 1000000 in random order
	for (int i = 1000000; i > 0; i--) {
		int j = rand() % 1000000 + 1; //random integer
		vi2.push_back(j);
	}

	/*
	srand(time(0)); 
	for (int i = 999999; i > 1; i--) {
	int j = rand() % i + 1; //random integer such that 0 ≤ j ≤ i
	swap(a[j], a[i]);
	}
	*/


	//a = vi2;
	//totalQuickCmp = Sorts<int>::quicksortWithoutCutoff (a);

	clock_t start, finish;
	start = clock();

	a = vi2;
	int cutoff = 3;
	totalQuickCmp1 = Sorts<int>::quicksortWithCutoff (a, cutoff);
	cout << "Final sorted array: " <<endl;
	Display(a);

	//cout << "Quicksort without cutoff, number of comparisons: " << totalQuickCmp << endl;
	cout << "Quicksort with cutoff, number of comparisons: " << totalQuickCmp1 << endl;
	finish = clock();
	cout << "Time for sort (seconds): " << ((double)(finish - start))/CLOCKS_PER_SEC << endl;

	return 0;
}
