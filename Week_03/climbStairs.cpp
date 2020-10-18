#include <stdio.h>



class Solution {
public:
    int climbStairs(int n) {
    	if (n < 2) {
    		return 1;
    	}

    	int res = 1;
    	int n1 = 1; //n-1
    	int n2 = 0; //n-2
    	for (int i = 1; i < n; ++i) {
    		int tmmp = res;
    		res = res+n1;
    		n1=tmmp;
    		n2=n1;
    	}
    	return res;
    }
};

int main()
{
	Solution s;
	for (int i = 0; i < 10; ++i)
	{
		int res = s.climbStairs(i);
	    printf("i=%d res=%d\n",i,res);
	}
	
	return 0;
}