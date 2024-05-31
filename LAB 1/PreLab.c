#include <stdio.h>
#define SIZE 1000

void readInput(int arr[], int *nPtr);
void swap(int *xPtr, int *yPtr);
void printNumbers(const int arr[], int n);
void circularShiftFromRightToLeft(int arr[], int number);

int main(void)
{
  int num;
  int *nPtr = &num;
  int arr[SIZE];

  printf("Enter the number of elements:\n");
  scanf("%d", &num);

  printf("Enter %d elements:\n", num);
  readInput(arr, nPtr);

  printf("Array elements: ");
  printNumbers(arr, num);

  // int a, b;
  // printf("Enter the first index to be swapped:\n");
  // scanf("%d", &a);
  // printf("Enter the second index to be swapped:\n");
  // scanf("%d", &b);

  // swap(&arr[a], &arr[b]);
  circularShiftFromRightToLeft(arr, num);
  printf("After one circular shift from right to left: ");
  printNumbers(arr, num);

  return 0;
}

void readInput(int arr[], int *nPtr)
{
  for (int i = 0; i < *nPtr; i++)
  {
    scanf("%d", &arr[i]);
  }
}

void printNumbers(const int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void swap(int *xPtr, int *yPtr)
{
  int temp = *xPtr;
  *xPtr = *yPtr;
  *yPtr = temp;
}
void circularShiftFromRightToLeft(int arr[], int number)
{

  for (int i = number - 1; i > 0; i--)
  {
    int temp = arr[i];
    arr[i] = arr[i - 1];
    arr[i - 1] = temp;
  }
}