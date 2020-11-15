#include <vector>
#include <string>
#include <unordered_set>
#include <queue>

using namespace std;

struct QM
{
    string mut;
    int step;
};

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        char possible[4] = {'A','C','G','T'};

        unordered_set<string> us_bank;
        for (string& s : bank) us_bank.insert(s);

        struct QM startqm = {start, 0};
        queue<struct QM> q;
        q.push(startqm);

        while (!q.empty()) {
            struct QM& now = q.front(); q.pop();
            if (now.mut == end) return now.step;

            for (char& c : now.mut) {
                char tmp = c;
                for (char p : possible) {
                    c = p;
                    auto itr = us_bank.find(now.mut);
                    if (itr != us_bank.end()) {
                        struct QM nn = {now.mut, now.step+1};
                        q.push(nn);
                        us_bank.erase(itr);
                    }
                }
                c = tmp;
            }
        }
        
        return -1;
    }
};

int main(int argc, char const *argv[])
{
	
	return 0;
}