#include <stdio.h>
#define SIZE 500

void readInput(int arr[], int *nPtr);

void printNumbers(const int arr[], int n);

void circularShiftFromLeftToRight(int arr[], int n);

int compareTwoArrays(const int arr1[], const int arr2[], int n1, int n2);

void circularShiftUntilMinArr(int arr[], int n);
int findMax(const int arr[], int n);
int findMin(const int arr[], int n);

int main()
{
    int arr[SIZE];
    int n;
    readInput(arr, &n);
    printNumbers(arr, n);
    circularShiftUntilMinArr(arr, n);
    printf("\nAfter circularShiftUntilMinArr:\n");
    printNumbers(arr, n);

    int maxElement = findMax(arr, n);
    printf("Maximum element of the array: %d\n", maxElement);

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

void circularShiftFromLeftToRight(int arr[], int n)
{
    int temp = arr[n - 1];
    for (int i = n - 1; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = temp;
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

void circularShiftUntilMinArr(int arr[], int n)
{
    int min = findMin(arr, n);
    for (int a = 0; a < n; a++)
    {
        if (arr[0] == min)
        {
            break;
        }
        circularShiftFromLeftToRight(arr, n);
    }
}

int findMax(const int arr[], int n)
{
    int p = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > p)
        {
            p = arr[i];
        }
    }
    return p;
}
int findMin(const int arr[], int n)
{
    int p = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < p)
        {
            p = arr[i];
        }
    }
    return p;
}
