#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


int ctoi(char c)
{
    return c - '0';
}


int strtoi(char *str)
{
    int len = strlen(str) - 1;
    int num = 0;

    for (int i = 0; i <= len; i++) {
        num += ctoi(str[i]) * (pow(10, len - i));
    }

    return num;
}


int parser(char *str)
{
    char *ptr1, *ptr2;
    static int counter = 0, results = 0;
    int count1 = 0, count2 = 0;
    int comma = 0, comma_pos = 0, final = 0;

    if (strncmp(str, "mul(", 4) != 0) {
        return 0;
    }

    //printf("str : %s\n", str);
    int res = 0;

    for (int i = 0; i < 12; i++) {
        if (str[i] == ',') {
            comma = 1;
            comma_pos = i;
        }

        if (str[i] == ')') {
            final = 1;
            break;
        }

        if (comma == 0) {
            if (isdigit(str[i]) != 0) {
                count1++;
            }
        } else {
            if (isdigit(str[i]) != 0) {
                count2++;
            }
        }
    }

    if (count1 > 3 || count2 > 3 || final == 0) return 0;

    ptr1 = &str[4];
    ptr1[count1] = '\0';

    ptr2 = &str[comma_pos + 1];
    ptr2[count2] = '\0';

    int num1 = strtoi(ptr1);
    printf("[%3d] - val1 : %3d  |  ", counter, num1);
    int num2 = strtoi(ptr2);
    printf("val2 : %3d  |  ", num2);

    res = (num1 * num2);
    results += res;
    printf("res : %d\n", results);

    counter++;

    return res;
}


int main(void)
{
    int result = 0;
    int i = 0;
    FILE *fp;

        if ((fp = fopen("./input.txt", "r")) == NULL) {
        fprintf(stderr, "Can't open file! Check the file name being passed!\n");
        exit(EXIT_FAILURE);
    }

    char *sample = malloc(13 * sizeof(char));

    while (fgets(sample, 13, fp) != NULL) {
        fseek(fp, (i * sizeof(char)), SEEK_SET);
        //printf("[%3d] : %s\n", i, sample);
        result += parser(sample);
        i++;
    }

    printf("Result = %d\n", result);

    free(sample);
    fclose(fp);

    return 0;
}
