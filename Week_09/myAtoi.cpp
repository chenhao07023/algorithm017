#include <stdio.h>
#include <assert.h>
#include <string>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
    	long long ans = 0;
    	int first = 0;
    	bool isPo = false;
    	bool hasop = false;

    	for (int i = 0; i < s.size(); ++i) {
    		if (s[i] == ' ')
    		{
    			if (hasop) return 0;
    			first++;
    		}
    		else if (s[first] == '-')
    		{
    			if (hasop) return 0;
    			hasop = true;
                isPo = true;
        	    first++;
    		}
    		else if (s[first] == '+')
    		{
    			if (hasop) return 0;
    			hasop = true;
        	    first++;
    		}
    		else if (s[i] >= '0' && s[i] <= '9')
    		{
    			break;
    		}
    		else
    		{
    			if (first == 0)
    			{
    				return 0;
    			}
    		}
    	}

    	for (int i = first; i < s.size(); ++i)
    	{
    		if (s[i] >= '0' && s[i] <= '9')
    		{
    			ans = ans*10 + (s[i]-'0');
    			if (ans-1 > INT_MAX) break;
    		}
    		else
    		{
    			break;
    		}
    	}
    	if (ans > INT_MAX)
    	{
    		return isPo? INT_MIN : INT_MAX;
    	} 
        return isPo? -ans : ans;
    }
};

int main() {

	assert(42 == Solution().myAtoi("42"));
	assert(-42 == Solution().myAtoi("  -42"));
	assert(4193 == Solution().myAtoi("4193"));
	assert(4193 == Solution().myAtoi("4193 with words"));
	assert(0 == Solution().myAtoi("words and 987"));
	assert(-91283472 == Solution().myAtoi("-91283472"));
	assert(-2147483648 == Solution().myAtoi("-91283472332"));
	assert(0 == Solution().myAtoi("-+42"));
	assert(1 == Solution().myAtoi("+1"));
	assert(0 == Solution().myAtoi("+-12"));
	assert(0 == Solution().myAtoi("- 234"));
	
	printf("ojbk\n");

	return 0;
}