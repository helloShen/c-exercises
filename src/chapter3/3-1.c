/******************************************************
 * 还是传统的二分查找好。答案里的处理法可读性不好。
 * 而且性能也没有优化。
 *****************************************************/
#include <stdio.h>

static int binsearch(int x, int v[], int n);

int main(void) {
    int nums[] = {0,1,2,3,4,5,6,7,8,9};
    printf("5 at position %d\n",binsearch(5,nums,10));
}

/* 在v[0]~v[n-1]中搜索x */
static int binsearch(int x, int v[], int n) {
    int lo = 0, hi = n - 1, mid = 0, diff = 0;
    while (lo <= hi) {
        mid = lo + (hi - lo) / 2;
        // printf("Mid number = %d\n",v[mid]);
        diff = v[mid] - x;
        if (diff > 0) {
            hi = mid - 1;
        } else if (diff < 0) {
            lo = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}
