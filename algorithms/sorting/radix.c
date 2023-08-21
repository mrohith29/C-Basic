#include <stdio.h>

// Function to get the maximum element in the array
int getMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

// Function to perform bucket sort on the array based on the given digit
void bucketSort(int arr[], int n, int exp)
{
    int output[n];
    int i, buckets[10] = {0};

    // Count the number of elements in each bucket
    for (i = 0; i < n; i++)
    {
        buckets[(arr[i] / exp) % 10]++;
    }

    // Calculate the starting index of each bucket
    for (i = 1; i < 10; i++)
    {
        buckets[i] += buckets[i - 1];
    }

    // Place the elements into the buckets
    for (i = n - 1; i >= 0; i--)
    {
        output[buckets[(arr[i] / exp) % 10] - 1] = arr[i];
        buckets[(arr[i] / exp) % 10]--;
    }

    // Copy the sorted elements back into the original array
    for (i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

// Function to perform radix sort on the array
void radixSort(int arr[], int n)
{
    int max = getMax(arr, n);

    // Perform bucket sort for each digit position, starting from the least
    // significant
    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        bucketSort(arr, n, exp);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    radixSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
