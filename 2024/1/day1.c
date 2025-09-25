#include <stdio.h>

#include "input.h"


int diff(int a, int b)
{
    int result = (a > b) ? (a - b) : (b - a);

    return result;
}


void quick_sort(int *item, int left, int right)
{
    register int i, j;
    int x, y;

    i = left;
    j = right;
    x = item[(left + right) / 2]; // centro

    do {
        while(item[i] < x && i < right) i++;
        while(x < item[j] && j > left) j--;

        if(i <= j) {
            y = item[i];
            item[i] = item[j];
            item[j] = y;
            i++;
            j--;
        }
    } while(i <= j);

    if(left < j)
        quick_sort(item, left, j);
    if(i < right)
        quick_sort(item, i, right);
}


void quick(int *item, int count)
{
    quick_sort(item, 0, count-1);
}


int compare_lists(int *list1, int *list2)
{
    int result = 0;

    for(int i = 0; i < 1000; i++) {
        for(int j = 0; j < 1000; j++) {
            if(list1[i] == list2[j]) {
                result += list1[i];
            }
        }
    }

    return result;
}


int main(void)
{
    int difference[1000] = {0};

    quick(left_list, 1000);
    quick(right_list, 1000);

    for(int i = 0; i < 1000; i++) {
        difference[i] = diff(left_list[i], right_list[i]);
    }

    int result = 0;

    for(int j = 0; j < 1000; j++) {
        result += difference[j];
    }

    printf("Result is: %d\n", result);

    int similarity = compare_lists(left_list, right_list);

    printf("similarity = %d\n", similarity);

    return 0;
}
