#include <stdio.h>
int main(){
  int array[100], n, c;
  scanf("%d", &n); // n is number of elements in the array.
  for (c = 0; c < n; c++){
    scanf("%d", &array[c]);
  }
  int i; c=n-1;
  for(i=0;i<n/2;i++,c--){
    array[c]=array[c]+array[i];
    array[i]=array[c]-array[i];
    array[c]=array[c]-array[i];
  }
  printf("Reversed array elements are:\n");
  for (c = 0; c < n; c++)
    printf("%d ", array[c]);
  return 0;
}
