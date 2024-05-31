#include <stdio.h>
#define SIZE 100

void readInput(int arr[], int *nPtr);
void printNumbers(const int arr[], int number);
void circularShiftFromRightToLeft(int arr[], int number);

int main()
{
  int array[SIZE];
  int number;
  readInput(array, &number);
  printNumbers(array, number);
  circularShiftFromRightToLeft(array, number);
  printf("\nAfter one circular shifts from right to left:\n");
  printNumbers(array, number);
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

void printNumbers(const int arr[], int number)
{
  printf("Array elements: ");
  for (int i = 0; i < number; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void circularShiftFromRightToLeft(int arr[], int number)
{

  for (int i = number - 1; i >= 0; i--)
  {
    int temp = arr[i];
    arr[i] = arr[i - 1];
    arr[i - 1] = temp;
  }
}
