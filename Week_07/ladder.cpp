#include <vector>
#include <string>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s;
        for (auto &i : wordList) s.insert(i);

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        string curr; 
        int step;

        while ( !q.empty() ){
            if ( q.front().first == endWord){
                return (q.front().second);
            }
            curr = q.front().first;
            step = q.front().second;
            q.pop();

            char ch;
            for (int i = 0; i < curr.length(); i++){
                ch = curr[i];
                for (char c = 'a'; c <= 'z'; c++){
                    if ( ch == c) continue;
                    curr[i] = c;
                    if (s.find(curr) != s.end()) {
                        q.push({curr, step+1});
                        s.erase(curr);
                    }
                    curr[i] = ch;
                }
               
            }
        }
        return 0; 
    }
};

int main(int argc, char const *argv[])
{
	
	return 0;
}