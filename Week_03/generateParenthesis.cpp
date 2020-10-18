#include <stdio.h>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    vector<string> generateParenthesis(int n) {
    	if (n <= 1) {
    		return {"()"};
    	}

    	vector<string> res;
        vector<string> last = generateParenthesis(n-1);

        for (auto s : last)
        {
            string t1 = string("()").append(s);
            string t2 = string("(").append(s).append(string(")"));
            string t3 = s.append("()");
            res.push_back(t1);
            res.push_back(t2);
            if (t3 != t1)
            {
                res.push_back(t3);
            }
            
        }
    	return res;
    }
};

int main()
{
	Solution s;
	vector<string> res = s.generateParenthesis(3);

    for (auto s : res)
    { 
        printf("%s\n",s.c_str());
    }
	
	return 0;
}