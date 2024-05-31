
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_LEN 20
#define MAX_ELEM 10
#define HASHSIZE 1000

unsigned int hash_text(char *list);
void strong_similar(int hval[MAX_ELEM], int map[MAX_ELEM][MAX_ELEM]);
void weak_similar(char list[MAX_ELEM][STR_LEN], int map[MAX_ELEM][MAX_ELEM]);
void print_string_lengths(char list[MAX_ELEM][STR_LEN]);

int main()
{
    unsigned int hashed_vals[MAX_ELEM];
    unsigned int same[MAX_ELEM][MAX_ELEM];
    char list[MAX_ELEM][STR_LEN];

    printf("Enter 10 elements:\n");
    int i = 0;
    for (i = 0; i < MAX_ELEM; i++)
    {
        scanf("%[^\n]%*c", list[i]);
    }

    for (int i = 0; i < 10; i++)
        hashed_vals[i] = hash_text(list[i]);

    strong_similar(hashed_vals, same);

    printf("\nElements with hash values and similarities:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("\n%-20s %5d", list[i], hashed_vals[i]);
        for (int j = 0; j < MAX_ELEM; j++)
            if (same[i][j] == 1)
                printf("%4d", j);
    }

    printf("\n");

    weak_similar(list, same);

    printf("\n\nElements with weak similarities:");
    for (int i = 0; i < 10; i++)
    {
        printf("\n%-20s %5d", list[i], hashed_vals[i]);
        for (int j = 0; j < MAX_ELEM; j++)
            if (same[i][j] == 2)
                printf("%4d", j);
    }

    printf("\n");

    print_string_lengths(list);

    return 0;
}

unsigned int hash_text(char *list)
{
    unsigned long long int hash = 0;
    unsigned long long int N = strlen(list);
    unsigned long long int b = N;
    unsigned long long int power = 1;
    for (int i = 0; i < N; i++)
    {
        hash = hash + (list[i] * (unsigned long long int)(pow(36.0, b - 1)));
        b = b - 1;
    }
    hash = hash % 1000;
    return (int)hash;
}

void strong_similar(int hval[MAX_ELEM], int map[MAX_ELEM][MAX_ELEM])
{
    for (int i = 0; i < MAX_ELEM; i++)
    {
        for (int j = 0; j < MAX_ELEM; j++)
        {
            map[i][j] = 0;
        }
    }

    for (int i = 0; i < MAX_ELEM; i++)
    {
        for (int j = 0; j < MAX_ELEM; j++)
        {
            if (hval[i] == hval[j] && i != j) // Compare the values, not the indices
            {
                map[i][j] = 1;
            }
        }
    }
}

void weak_similar(char list[MAX_ELEM][STR_LEN], int map[MAX_ELEM][MAX_ELEM])
{
    char names[MAX_ELEM][STR_LEN];
    char surnames[MAX_ELEM][STR_LEN];
    int name_hashes[MAX_ELEM];
    int surname_hashes[MAX_ELEM];

    for (int i = 0; i < MAX_ELEM; i++)
    {
        char temp[STR_LEN];
        strcpy(temp, list[i]);
        char *token = strtok(temp, " ");
        strcpy(names[i], token);
        token = strtok(NULL, " ");
        strcpy(surnames[i], token);

        name_hashes[i] = hash_text(names[i]);
        surname_hashes[i] = hash_text(surnames[i]);
    }

    for (int i = 0; i < MAX_ELEM; i++)
    {
        for (int j = i + 1; j < MAX_ELEM; j++)
        {
            if (strcmp(names[i], names[j]) == 0 && strcmp(surnames[i], surnames[j]) == 0)
            {
                continue;
            }
            if (strcmp(names[i], names[j]) == 0 || strcmp(surnames[i], surnames[j]) == 0 || strcmp(names[i], surnames[j]) == 0 || strcmp(surnames[i], names[j]) == 0)
            {
                map[i][j] = map[j][i] = 2;
            }
        }
    }
}

void print_string_lengths(char list[MAX_ELEM][STR_LEN])
{
    printf("String Lengths Without Spaces:\n");
    for (int i = 0; i < MAX_ELEM; i++)
    {
        int N = strlen(list[i]);
        printf("%s - %d\n", list[i], (N - 1));
    }
}
