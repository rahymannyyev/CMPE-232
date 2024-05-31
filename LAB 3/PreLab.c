#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SKATERS 20
#define AMOUNT 6

typedef struct
{
  char name[MAX_SKATERS];
  char surname[MAX_SKATERS];
  double scores[AMOUNT];
  double average;
} skater_t;

double calculateAverageScore(const skater_t *skaterp);
int scanSkater(FILE *filep, skater_t *skaterp);
int loadSkaters(skater_t skaters[]);
void printSkater(const skater_t *skaterp);
int findPrintWinner(skater_t skaters[], int numOfSkaters);
int moveToNextLine(FILE *file);

int main(void)
{
  skater_t skaters[MAX_SKATERS];

  int numOfSkaters;

  numOfSkaters = loadSkaters(skaters);

  printf("Skaters:\n");
  for (int i = 0; i < numOfSkaters; i++)
    printSkater(&skaters[i]);

  findPrintWinner(skaters, numOfSkaters);

  return 0;
}

double calculateAverageScore(const skater_t *skaterp)
{
  double max = skaterp->scores[0];
  double min = skaterp->scores[0];
  double sum = 0.0;

  for (int i = 0; i < AMOUNT; i++)
  {
    if (skaterp->scores[i] > max)
    {
      max = skaterp->scores[i];
    }
    if (skaterp->scores[i] < min)
    {
      min = skaterp->scores[i];
    }
    sum += skaterp->scores[i];
  }

  double average = (sum - max - min) / (AMOUNT - 2);
  return average;
}

int scanSkater(FILE *infile, skater_t *skaterp)
{
  int result = fscanf(infile, "%99s %99s %lf %lf %lf %lf %lf %lf",
                      skaterp->name, skaterp->surname,
                      &skaterp->scores[0], &skaterp->scores[1], &skaterp->scores[2],
                      &skaterp->scores[3], &skaterp->scores[4], &skaterp->scores[5]);

  return result == 8 ? 0 : 1;
}

int loadSkaters(skater_t skaters[])
{
  FILE *skaterlib = fopen("skaters.txt", "r");
  if (skaterlib == NULL)
  {
    perror("Error opening file");
    return 0;
  }

  printf("Enter the file name to read: skaters.txt\n");
  printf("Opening skaters.txt\n");

  int position = 0;
  int checker = 0;

  while (checker == 0 && position < MAX_SKATERS)
  {
    if (scanSkater(skaterlib, &skaters[position]) != 0)
      break;
    skaters[position].average = calculateAverageScore(&skaters[position]);
    position++;
    checker = moveToNextLine(skaterlib);
  }

  printf("Loading complete\n");
  printf("Closing skaters.txt\n");
  fclose(skaterlib);

  return position;
}

void printSkater(const skater_t *skaterp)
{
  printf("%s %s %.2f\n", skaterp->name, skaterp->surname, skaterp->average);
}

int findPrintWinner(skater_t skaters[], int numOfSkaters)
{
  int index = 0;
  double max = skaters[0].average;
  for (int i = 1; i < numOfSkaters; i++)
  {
    if (skaters[i].average > max)
    {
      max = skaters[i].average;
      index = i;
    }
  }

  printf("Winner:\n%s %s %.2f\n", skaters[index].name, skaters[index].surname, skaters[index].average);

  return 0;
}

int moveToNextLine(FILE *file)
{
  int ch;
  while ((ch = fgetc(file)) != '\n' && ch != EOF)
  {
  }
  return ch == EOF ? 1 : 0;
}
