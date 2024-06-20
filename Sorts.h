#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename Comparable>

class Sorts
{
private:


public: 

        static int insertionSort (vector <Comparable> & a) {
        int numberCompares = 0;

        int j;

        for( int p = 1; p < a.size(); p++ )
        {
            Comparable tmp = a[ p ];
            for( j = p; j > 0 && tmp < a[ j - 1 ]; j-- ){
                a[ j ] = a[ j - 1 ];
                numberCompares++;
            }
            a[ j ] = tmp;
            //numberCompares++;
        }
            return numberCompares;
    }


    static int quicksortWithoutCutoff (vector <Comparable> & a) {
        int numberCompares = 0;
        int left = 0;
        int right = a.size();
        int center = (left + right) / 2;
        if (a[center] < a[left]) {
            swap(a[left], a[center]);
            numberCompares++;
            }
        if (a[right] < a[left]) {
            swap(a[left], a[right]);
            numberCompares++;
            }
        if (a[right] < a[center]) {
            swap(a[center], a[right]);
            numberCompares++;
            }

        // Place pivot at position right - 1
        swap(a[center], a[right - 1]);
        return a[right - 1];
        return numberCompares;
    }


    static int quicksortWithCutoff (vector <Comparable> & a, int cutoff){
        int numberCompares = 0;
        int left = 0;
        int right = a.size();

        if (left + cutoff <= right) {

            int center = (left + right) / 2;
            if (a[center] < a[left])
                swap(a[left], a[center]);
            if (a[right] < a[left])
                swap(a[left], a[right]);
            if (a[right] < a[center])
                swap(a[center], a[right]);
            // Place pivot at position right - 1
            swap(a[center], a[right - 1]);
            Comparable pivot = a[right - 1];

            // Begin partitioning
            int i = left, j = right - 1;
            for (;;) {
                while (a[++i] < pivot)
                {
                    numberCompares++;
                }
                while (pivot < a[--j])
                {
                    numberCompares++;
                }
                if (i < j) {
                    swap(a[i], a[j]);
                    numberCompares++;
                }
                else
                    break;
            }

            swap(a[i], a[right - 1]); // Restore pivot

            quicksortWithCutoff(a, cutoff); // Sort small elements
            quicksortWithCutoff(a, cutoff); // Sort large elements
            
            return numberCompares;
            
        }
        else // Do an insertion sort on the subarray
            insertionSort(a);
        
        
        return numberCompares;
    }

};