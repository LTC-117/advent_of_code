#include <stdio.h>

#include "input.h"


int difference(int a, int b)
{
    return a - b;
}


int calculate_safety(const int list[][8])
{
    int safe_reports = 0;
    int level_counter = 0;
    int report_size = 0;
    int current_analysis = 0;

    for(int report = 0; report < 1000; report++) {
        for(int level = 0; level < 7; level++) {
            if(list[report][level + 1] == 0) {
                report_size = level;
                break;
            } else {
                report_size = 7;
            }

            current_analysis = difference(list[report][level], list[report][level + 1]);

            if(current_analysis >= -3 && current_analysis < 0)    level_counter--;
            if(current_analysis <= 3 && current_analysis > 0)     level_counter++;
        }
        if (level_counter == report_size || level_counter == -report_size) {
            safe_reports++;
        }
        level_counter = 0;
        report_size = 0;
    }

    return safe_reports;
}


// parte 2: Tá entre 294 e 361
int main(void)
{
    int safe = calculate_safety(reports);

    printf("Amount of safe reports (part 2): %d\n", safe);

    return 0;
}


