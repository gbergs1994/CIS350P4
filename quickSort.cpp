/**
 * Quicksort algorithm (driver).
 */

template <typename Comparable>
void quicksort(vector<Comparable> & a)
{
    quicksort(a, 0, a.size() - 1);
};

/**
 * Return median of left, center, and right.
 * Order these and hide the pivot.
 */
template <typename Comparable>
const Comparable &median3(vector<Comparable> &a, int left, int right)
{
    int center = (left + right) / 2;
    if (a[center] < a[left])
        swap(a[left], a[center]);
    if (a[right] < a[left])
        swap(a[left], a[right]);
    if (a[right] < a[center])
        swap(a[center], a[right]);

    // Place pivot at position right - 1
    swap(a[center], a[right - 1]);
    return a[right - 1];
}

/**
 * Internal quicksort method that makes recursive calls.
 * Uses median-of-three partitioning and a cutoff of 10.
 * a is an array of Comparable items.
 * left is the left-most index of the subarray.
 * right is the right-most index of the subarray.
 */
void quicksort(vector<Comparable> &a, int left, int right)
{
    if (left + 10 <= right)
    {
        Comparable pivot = median3(a, left, right);

        // Begin partitioning
        int i = left, j = right - 1;
        for (;;)
        {
            while (a[++i] < pivot)
            {
            }
            while (pivot < a[--j])
            {
            }
            if (i < j)
                swap(a[i], a[j]);
            else
                break;
        }

        swap(a[i], a[right - 1]); // Restore pivot

        quicksort(a, left, i - 1);  // Sort small elements
        quicksort(a, i + 1, right); // Sort large elements
    }
    else // Do an insertion sort on the subarray
        insertionSort(a, left, right);
};


