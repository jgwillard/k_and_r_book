#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// compare two integers (used for qsort)
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

/**
 * Takes an array of size `n`, generates `n` random integers, sorts them
 * and populates the array with them.
 */
void rand_sorted_array(int array[], int n)
{
    // generate n random integers
    for (int i = 0; i < n; i++)
    {
        array[i] = rand();
    }

    qsort(array, n, sizeof(int), compare);
}

int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (x < v[mid])
        {
            high = mid - 1;
        }
        else if (x > v[mid])
        {
            low = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int main()
{
    // seed random number generator once at the beginning of the program
    srand(time(NULL));

    int n = 1000;
    int array[n];
    int i;
    int target;
    int found;

    rand_sorted_array(array, n);

    // Print the sorted array
    for (i = 0; i < n * 100; i++)
    {
        target = rand();
        found = binsearch(target, array, n);
        printf("Found %d\n", found);
    }

    return 0;
}
