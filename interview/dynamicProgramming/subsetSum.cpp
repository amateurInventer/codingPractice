#include <stdio.h>
#define MAX_SUM 1000
#define MAX_ARRAY 1000

int main() {
   int set[] = {3,34,4,12,5,2};
   int len = sizeof(set)/sizeof(int);
   int sum = 9;
   int subsetArr[MAX_SUM][MAX_ARRAY];
   for(int i=0; i<=len; ++i)
      subsetArr[i][0] = 1;
   for(int i=0; i<=sum; ++i)
      subsetArr[0][i] = 0;

   for(int i=1; i<=len; ++i) {
      for(int j=1; j<=sum; ++j) {
         if(j<set[i-1])
            subsetArr[i][j] = subsetArr[i-1][j];
         else
            subsetArr[i][j] = subsetArr[i-1][j-set[i-1]]||subsetArr[i-1][j];
      }
   }
   printf("%d\n",subsetArr[len][sum]);
   return 0;
}
