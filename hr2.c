#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);

int parse_int(char*);



/*
 * Complete the 'maxCost' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY cost
 *  2. STRING_ARRAY labels
 *  3. INTEGER dailyCount
 */

int maxCost(int cost_count, int* cost, int labels_count, char** labels, int dailyCount) {
    int c=0,tc=0,n=0,x=0;
    while(n<cost_count+1){
        x=0;
        while(x<dailyCount+1){
            n++;
            if(labels[x][0]=='l'){
                x++;
                tc=tc+cost[x];
            }
            else if(labels[x][0]=='i'){
                tc=tc+cost[x];
            }
        }
        if(tc>c)
            c=tc;   
    }
    return c;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int cost_count = parse_int(ltrim(rtrim(readline())));

    int* cost = malloc(cost_count * sizeof(int));

    for (int i = 0; i < cost_count; i++) {
        int cost_item = parse_int(ltrim(rtrim(readline())));

        *(cost + i) = cost_item;
    }

    int labels_count = parse_int(ltrim(rtrim(readline())));

    char** labels = malloc(labels_count * sizeof(char*));

    for (int i = 0; i < labels_count; i++) {
        char* labels_item = readline();

        *(labels + i) = labels_item;
    }

    int dailyCount = parse_int(ltrim(rtrim(readline())));

    int result = maxCost(cost_count, cost, labels_count, labels, dailyCount);

    fprintf(fptr, "%d\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}
