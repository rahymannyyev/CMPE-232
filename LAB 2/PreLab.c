#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void searchKeyword(const char *nameList[], int n, const char keyword[])
{
    for (int i = 0; i < n; i++)
    {
        char copy[100] = "";
        strcpy(copy, nameList[i]);
        char name[100] = "";
        char surname[100] = "";

        char *token = strtok(copy, "_");

        strcat(name, token);
        token = strtok(NULL, "_");
        strcat(surname, token);

        int f = strcmp(name, keyword);
        int s = strcmp(surname, keyword);

        if (s == 0)
        {
            name[0] = toupper(name[0]);
            surname[0] = toupper(surname[0]);
            printf("%s %s \n", name, surname);
        }
    }
}

int main()
{
    char p1[] = "zoe_bale";
    char p2[] = "sam_rodriguez";
    char p3[] = "jack_alonso";
    char p4[] = "david_studi";
    char p5[] = "denzel_feldman";
    char p6[] = "james_bale";
    char p7[] = "james_willis";
    char p8[] = "michael_james";
    char p9[] = "dustin_bale";

    const char *nameList[9] = {p1, p2, p3, p4, p5, p6, p7, p8, p9};

    char keyword[100];
    printf("Enter a keyword: ");
    scanf("%s", keyword);

    printf("\n");

    searchKeyword(nameList, 9, keyword);

    printf("\n");
    for (int i = 0; i < 9; i++)
        printf("%s\n", nameList[i]);

    return 0;
}
