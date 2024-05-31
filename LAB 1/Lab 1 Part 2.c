#include <stdio.h>
#define SIZE 500

// reads numbers from the standard input into arr,
// and stores the number of read elements in the memory cell pointed to by nPtr
void readInput(int arr[], int *nPtr);

// prints the elements in arr[0..(n-1)]
void printNumbers(const int arr[], int n);

// Let n be the minimum of n1 and n2 where n1 and n2 are the number of elements in
// arr1 and arr2, respectively.
// Compare corresponding elements of arr1 and arr2 at each of the first n positions.
//
// If arr1 and arr2 has the same value in each position:
// Return 0 if n1 == n2
// Return 1 if n1 > n2
// Return -1 if n1 < n2
//
// If arr1 has a larger value than arr2 considering the first position from the
// beginning at which arr1 and arr2 have a different value:
// Return 1
//
// If arr1 has a smaller value than arr2 considering the first position from the
// beginning at which arr1 and arr2 have a different value:
// Return -1
int compareTwoArrays(const int arr1[], const int arr2[], int n1, int n2);
int calculateAverage(const int arr[], int n);

int main()
{
    int arr1[SIZE];
    int n1;

    int arr2[SIZE];
    int n2;

    readInput(arr1, &n1);
    printNumbers(arr1, n1);

    readInput(arr2, &n2);
    printNumbers(arr2, n2);

    int result = compareTwoArrays(arr1, arr2, n1, n2);

    if (result == 0)
        printf("\nEqual\n");
    else if (result == -1)
        printf("\nLess than\n");
    else if (result == 1)
        printf("\nGreater than\n");

    int avg1 = calculateAverage(arr1, n1);
    int avg2 = calculateAverage(arr2, n2);

    printf("\nAverage of the first array: %d\n", avg1);
    printf("Average of the second array: %d\n", avg2);

    return 0;
}

void readInput(int arr[], int *nPtr)
{
    printf("Enter the number of elements:\n");
    scanf("%d", nPtr);
    printf("Enter %d elements:\n", *nPtr);
    for (int i = 0; i < *nPtr; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void printNumbers(const int arr[], int n)
{
    printf("Array elements: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int compareTwoArrays(const int arr1[], const int arr2[], int n1, int n2)
{
    int minimum = (n1 < n2) ? n1 : n2;
    for (int s = 0; s < minimum; s++)
    {
        if (arr1[s] > arr2[s])
        {
            return 1;
        }
        else if (arr2[s] > arr1[s])
        {
            return -1;
        }
    }

    if (n1 == n2)
    {
        return 0;
    }
    else if (n1 < n2)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

int calculateAverage(const int arr[], int n)
{
    int sum = 0;
    for (int k = 0; k < n; k++)
    {
        sum += arr[k];
    }
    return (sum / n);
}
