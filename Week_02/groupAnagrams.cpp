#include <stdio.h>
#include <assert.h>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map<string, int > groupmap;

        int index = 0;

        for (string s: strs) {
            string t = s;
            sort(t.begin(), t.end());
            auto e = groupmap.find(t);

            if (e != groupmap.end()) {
                res[e->second].push_back(s);
            } else {
                groupmap[t] = index++;
                vector<string> emp= {s};
                res.push_back(emp);
            }
        }
        return res;
    }
};

int main()
{
	Solution s;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> res = s.groupAnagrams(strs);
    printf("");

    for (auto g : res)
    {
        printf("\n[\n");
        for (auto s : g)
        {
            printf("%s ", s.c_str());
        }
        printf("\n]\n");
    }

	return 0;
}