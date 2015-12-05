void msSubarr( int *arr, int n, int *s, int *e, int *ms )
{
    int curSum = 0;
    int prevms = -2147483648;
    int a = b = s = i = 0;
    for( i = 0; i < n; i++ ) {
        curSum += arr[i];
        if ( curSum > prevms ) {
            prevms = curSum;
            a = s;
            b = i;
        }
        if( curSum < 0 ) {
            curSum = 0;
            s = i + 1;
        }
    }
    *s = a;
    *e = b;
    *ms = prevms;
}