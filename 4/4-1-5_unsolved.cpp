#include <stdio.h>

int max(int a, int b)
{
	return (a>b)?a:b;
}
int maxSubArray4(int *a) {

    int sum = a[0];
    int maxSum = a[0];
    for(int i = 1; i < 4; ++i) {
        sum = max(maxSum + a[i], a[i]);
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}  // is this correct?

int main()
{
	int a[4]={1,-1,1,-1};
	printf("%d\n",maxSubArray4(a));   //??????????????????
}
