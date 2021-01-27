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
 * Complete the 'getMinCost' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY crew_id
 *  2. INTEGER_ARRAY job_id
 */

long getMinCost(int crew_id_count, int* crew_id, int job_id_count, int* job_id) {
    long dist=0;
    int t=0;
    for(int i=1;i<crew_id_count;i++){
        for(int j=0;j<crew_id_count-i;j++){
            if(crew_id[j]>crew_id[j+1]){
                t=crew_id[j];
                crew_id[j]=crew_id[j+1];
                crew_id[j+1]=t;
            }
        }
    }
    for(int i=1;i<job_id_count;i++){
        for(int j=0;j<job_id_count-i;j++){
            if(job_id[j]>job_id[j+1]){
                t=job_id[j];
                job_id[j]=job_id[j+1];
                job_id[j+1]=t;
            }
        }
    }
    for (int i=0; i<crew_id_count ; i++) {
        t=job_id[i]-crew_id[i];
        printf("%d - %d = %d\n",job_id[i],crew_id[i],t);
        if(t<0)
            t=-t;
        dist=dist+t;
    }
    return dist;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int crew_id_count = parse_int(ltrim(rtrim(readline())));

    int* crew_id = malloc(crew_id_count * sizeof(int));

    for (int i = 0; i < crew_id_count; i++) {
        int crew_id_item = parse_int(ltrim(rtrim(readline())));

        *(crew_id + i) = crew_id_item;
    }

    int job_id_count = parse_int(ltrim(rtrim(readline())));

    int* job_id = malloc(job_id_count * sizeof(int));

    for (int i = 0; i < job_id_count; i++) {
        int job_id_item = parse_int(ltrim(rtrim(readline())));

        *(job_id + i) = job_id_item;
    }

    long result = getMinCost(crew_id_count, crew_id, job_id_count, job_id);

    fprintf(fptr, "%ld\n", result);

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
