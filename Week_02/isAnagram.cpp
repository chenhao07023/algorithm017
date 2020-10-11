#include <stdio.h>
#include <assert.h>
#include <map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
    	if (s.size() != t.size()) return false;
    	int hs['z'-'a'+1] = {0};
    	for (char cs : s) {
    		hs[cs-'a']++;
    	}
    	for (char ct : t) {
    		if (hs[ct-'a'] <= 0)
    			return false;
    		else
    			hs[ct-'a']--;
    	}
    	return true;
    }

    
};

int main()
{
	Solution s;
    assert(!s.isAnagram("aacc","ccac"));
    assert(!s.isAnagram("zlgh","ccac"));
	return 0;
}