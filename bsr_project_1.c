#include <stdio.h>

// ---------------- LENGTH FUNCTION FOR STRING ----------------------------------------------- 

int length(char n[]);
int length(char n[])
{
    int count = 0;

    for (int i = 0; i < n[i]; i++)
    {
        count++;
    }
    return count;
}

// ------------------ STRUCT PASSENGER DETAILS -----------------------------------------------

typedef struct passenger
{
    char name[50], contact_no[11], jour_from[50], jour_to[50];
    int dd, mm, yyyy;
} pg;


int main()
{
    pg p1;
    // ---------------------- IMPORTANT DETAILS -----------------------------------------------

    printf("Enter your name: ");
    scanf("%s", p1.name);
    if (length(p1.name) >= 3)
    {
        printf("Enter your phone no. : ");
        scanf("%s", p1.contact_no);
        if (length(p1.contact_no) > 9 && length(p1.contact_no) < 11)
        {
            printf("Enter a date of Journey: ");
            scanf("%d %d %d", &p1.dd, &p1.mm, &p1.yyyy);
            if (p1.dd <= 31 && p1.mm <= 12 && p1.yyyy >= 2024)
            {
                printf("Enter your journey from: ");
                scanf("%s", p1.jour_from);
                if (length(p1.jour_from) > 2)
                {
                    printf("Enter your journey to: ");
                    scanf("%s", p1.jour_to);
                    if (length(p1.jour_to) < 2)
                    {
                        printf("Something went wrong!");
                        return 0;
                    }
                }
                else
                {
                    printf("Something went wrong!");
                    return 0;
                }
            }
            else
            {
                printf("Invalid Date!\n");
                return 0;
            }
        }
        else
        {
            printf("Invalid number!\n");
            return 0;
        }
    }
    else
    {
        printf("Invalid name!\n");
        return 0;
    }

// ---------------------- RECORDS -----------------------------------------------

    FILE* ptr;
    ptr = fopen("detail.txt", "a");
//  NAME
    printf("\nYour name is: %s\n", p1.name);
    fprintf(ptr, "%s ", p1.name);
    for (int i = 1; i < (18 - length(p1.name)); i++)
    {
        fprintf(ptr, " ");
    }
    fprintf(ptr, "| ");
//  CONTACT NO.
    printf("Your Contact number is: %s\n", p1.contact_no);
    fprintf(ptr, "%s ", p1.contact_no);
    fprintf(ptr, " | ");
//  JOURNEY FROM
    printf("Your Journey from is: %s\n", p1.jour_from);
    fprintf(ptr, "%s ", p1.jour_from);
    for (int i = 1; i < (13 - length(p1.jour_from)); i++)
    {
        fprintf(ptr, " ");
    }
    fprintf(ptr, "| ");
//  JOURNEY TO
    printf("Your Journey to is: %s\n", p1.jour_to);
    fprintf(ptr, "%s ", p1.jour_to);
    for (int i = 1; i < (11 - length(p1.jour_to)); i++)
    {
        fprintf(ptr, " ");
    }
    fprintf(ptr, "| ");
//  DATE
    printf("Your Date of journey is: %02d/%02d/%04d\n", p1.dd, p1.mm, p1.yyyy);
    fprintf(ptr, "%02d/%02d/%04d ", p1.dd, p1.mm, p1.yyyy);
    fprintf(ptr, "|\n");

    fclose(ptr);

    return 0;
}