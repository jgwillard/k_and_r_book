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

int alt_binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low < high)
    {
        mid = (low + high) / 2;
        if (x <= v[mid])
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }

    if (x == v[mid])
    {
        return mid;
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
    struct timespec start, end;
    long seconds;
    long nanoseconds;

    rand_sorted_array(array, n);

    // start timer
    clock_gettime(CLOCK_MONOTONIC, &start);

    for (i = 0; i < n * 10000; i++)
    {
        target = rand();
        found = binsearch(target, array, n);
        if (found != -1)
        {
            printf("Found %d\n", array[found]);
        }
    }

    // stop timer
    clock_gettime(CLOCK_MONOTONIC, &end);

    seconds = end.tv_sec - start.tv_sec;
    nanoseconds = end.tv_nsec - start.tv_nsec;
    printf("Elapsed time for binsearch:     %ld seconds %ld nanoseconds\n", seconds, nanoseconds);

    // start timer
    clock_gettime(CLOCK_MONOTONIC, &start);

    for (i = 0; i < n * 10000; i++)
    {
        target = rand();
        found = alt_binsearch(target, array, n);
        if (found != -1)
        {
            printf("Found %d\n", array[found]);
        }
    }

    // stop timer
    clock_gettime(CLOCK_MONOTONIC, &end);

    seconds = end.tv_sec - start.tv_sec;
    nanoseconds = end.tv_nsec - start.tv_nsec;
    printf("Elapsed time for alt_binsearch: %ld seconds %ld nanoseconds\n", seconds, nanoseconds);

    return 0;
}
