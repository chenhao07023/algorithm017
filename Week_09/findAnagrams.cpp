#include <string>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> memo(26, 0);
        vector<int> window(26, 0);
        vector<int> res;

        for (char c: p) memo[c-'a']++;
        
        int plen = p.size();
        for (int i = 0; i < s.size(); ++i) {
        	if (i >= plen)
        		window[ s[i-plen] - 'a']--;
            window[s[i] - 'a']++;
            if (window == memo)
            	res.push_back(i-plen+1);
        }
        return res;
    }
};

int main() {
	return 0;
}