/**
 * Simple insertion sort.
 */
template <typename Comparable>
void insertionSort( vector<Comparable> & a )
{
    insertionSort(a, 0, a.size() - 1);
};

template <typename Comparable>
void insertionSort( vector<Comparable> & a, int left, int right )
{
    int j;

    for( int p = left + 1; p < right + 1 ; p++ )
    {
        Comparable tmp = a[ p ];
        for( j = p; j > left && tmp < a[ j - 1 ]; j-- )
            a[ j ] = a[ j - 1 ];
        a[ j ] = tmp;
    }
};
