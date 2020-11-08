#include <string>
#include <stdio.h>
#include <vector>
#include <assert.h>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;

        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord))  return 0;

        unordered_set<string> visited;
        int times = 1;
        q.push(beginWord);

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto curWord = q.front(); q.pop();
                if (visited.count(curWord)) continue;
                if (curWord == endWord) return times;
                
                visited.insert(curWord);
                for (auto& ch : curWord) {
                    for (char c = 'a'; c <= 'z'; c++) {
                        char t = ch;
                        ch = c;
                        if (dict.count(curWord) && t != c) {
                            q.push(curWord);
                        }
                        ch = t;
                    }
                }
            }
            times++;
        }

        return 0;       
    }
};

/*
输入:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

输出: 5

解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
     返回它的长度 5。

 */
int main()
{
	string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

    Solution s;

    assert(5 == s.ladderLength(beginWord,endWord,wordList));


	return 0;
}