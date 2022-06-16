#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct Job {
    int id;
    int deadline;
    int profit;
} Job;
int min(int a, int b) { return (a < b) ? a : b; }
void jobSequencingWithDeadline(Job jobs[], int n, int*ops) {
    int i, j, k, maxprofit;
    Job temp;
    //sort the jobs profit wise in descending order
    for(i = 1; i < n; i++) {
        for(j = 0; j < n - i; j++) {
            if(jobs[j+1].profit > jobs[j].profit) {
                temp = jobs[j+1];
                jobs[j+1] = jobs[j];
                jobs[j] = temp;
            }
        }
    }
    printf("%10s %10s %10s\n", "Job", "Deadline", "Profit");
    for(i = 0; i < n; i++) {
        printf("%10d %10d %10d\n", jobs[i].id, jobs[i].deadline, jobs[i].profit);
    }
    //free time slots
    int timeslot[MAX];
    //filled time slots
    int filledTimeSlot = 0;
    //find max deadline value
    int dmax = 0;
    for(i = 0; i < n; i++) {
        (*ops)++;
        if(jobs[i].deadline > dmax) {
            dmax = jobs[i].deadline;
        }
    }
    //free time slots initially set to -1 [-1 denotes EMPTY]
    for(i = 1; i <= dmax; i++) {
        timeslot[i] = -1;
    }
    printf("Max deadline: %d\n", dmax);
    for(i = 1; i <= n; i++) {
        (*ops)++;
        k = min(dmax, jobs[i - 1].deadline);
        while(k >= 1) {
            if(timeslot[k] == -1) {
            timeslot[k] = i-1;
            filledTimeSlot++;
            break;
            }
            k--;
        }
        if(filledTimeSlot == dmax) {
            break;
        }
    }
    //required jobs
    printf("\nRequired Jobs: ");
    for(i = 1; i <= dmax; i++) {
        printf("job %d", jobs[timeslot[i]].id);
        if(i < dmax) {
            printf("--> ");
        }
    }
    printf("-->finish ");
    //required profit
    maxprofit = 0;
    for(i = 1; i <= dmax; i++) {
        maxprofit += jobs[timeslot[i]].profit;
    }
    printf("\nMax Profit: %d\n", maxprofit);
}
void unionSet(int A[], int* A_size, int newItem){
    int i, isPresent=0;
    for(i=0;i<(*A_size);i++){
        if(A[i]==newItem)
            isPresent=1;
    }
    if(!isPresent){
        A[(*A_size)]=newItem;
        (*A_size)++;
    }
}
void scheduleActivities(int s[], int f[], int n, int *ops){
    int k=0,size=0,j,A[n];
    unionSet(A,&size,0);
    for(j=1;j<n;j++){
        (*ops)++;
        if(s[j]>=f[k]){
            unionSet(A,&size,j);
            k=j;
        }
    }
    printf ("---- Selected Activities ----\n");
    for(j=0;j<size;j++)
        printf("[a %d s-%d f-%d] ",A[j]+1,s[A[j]],f[A[j]]);
}
void printAllActivities(int s[], int f[], int n){
    int i;
    printf("\n\n** all activities [idx start finish] **\n\n");
    for(i=0;i<n;i++){
        printf("[a %d s-%d f-%d] ",(i+1),s[i],f[i]);
    }
    printf("\n\n");
}
int main(void) {
    printf("\n\n--JobSequencing--\n\n");
    //jobs with id, deadline and profit
    Job jobs1[6] = {{1, 1, 60},{2, 3, 10},{3, 3, 30},{4, 2, 90},{5, 2, 40},{6, 4, 70}};
    int n11 = 6;
    int ops11=0;
    jobSequencingWithDeadline(jobs1, n11, &ops11);
    printf("\n\n**** Number of ops (not considering sorting): %d\n\n",ops11);

    Job jobs2[8] = {{1, 2, 40},{2, 3, 10},{3, 3, 40},{4, 4, 80},{5, 2, 70},{6, 2, 90},{7, 4, 100},{8, 1, 50}};
    int n12 = 8;
    int ops12=0;
    jobSequencingWithDeadline(jobs2, n12, &ops12);
    printf("\n\n**** Number of ops (not considering sorting): %d\n\n",ops12);

    Job jobs3[4] = {{1, 1, 20},{2, 3, 80},{3, 3, 50},{4, 2, 70}};
    int n13 = 4;
    int ops13=0;
    jobSequencingWithDeadline(jobs3, n13, &ops13);
    printf("\n\n**** Number of ops (not considering sorting): %d\n\n",ops13);

    printf("\n\n--ActivityScheduling--\n\n");

    int start_time[] = {1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
    int finish_time[] = {4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16};
    int n21 = 11;
    int ops21=0;
    printAllActivities(start_time,finish_time,n21);
    scheduleActivities(start_time,finish_time,n21,&ops21);
    printf("\n\n**** Total Ops: %d\n",ops21);

    int start_time2[] = {2, 0, 5, 5, 5, 7, 7, 8, 10, 10, 10, 14, 14, 17, 18};
    int finish_time2[] = {4, 5, 7, 8, 9, 9, 10, 12, 14, 12, 15, 18, 16, 18, 22};
    int n22 = 15;
    int ops22=0;
    printAllActivities(start_time2,finish_time2,n22);
    scheduleActivities(start_time2,finish_time2,n22,&ops22);
    printf("\n\n**** Total Ops: %d\n",ops22);

    int start_time3[] = {1, 1, 2, 2, 4, 4, 4, 8, 8, 10, 10, 12};
    int finish_time3[] = {2, 3, 4, 6, 10, 12, 14, 16, 14, 16, 14, 15};
    int n23 = 12;
    int ops23=0;
    printAllActivities(start_time3,finish_time3,n23);
    scheduleActivities(start_time3,finish_time3,n23,&ops23);
    printf("\n\n**** Total Ops: %d\n",ops23);

    return 0;
}
