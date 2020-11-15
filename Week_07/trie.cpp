#include <vector>
#include <string>
#include <assert.h>

using namespace std;


class Trie {
public:
    Trie* leaf[26];
    bool isEnd;
    /** Initialize your data structure here. */
    Trie() {
        isEnd = false;
        for (int i = 0; i < 26; i++) leaf[i] = NULL;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* tmp = this;
        for (char c : word) {

            if (tmp->leaf[c-'a'] == NULL) {
                tmp->leaf[c-'a'] = new Trie();
            }
            tmp = tmp->leaf[c-'a'];
        }
        tmp->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* tmp = this;
        for (char c : word) {
            if (tmp->leaf[c-'a'] == NULL) {
                return false;
            }
            tmp = tmp->leaf[c-'a'];
        }
        return tmp->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* tmp = this;
        for (char c : prefix) {
            if (tmp->leaf[c-'a'] == NULL) {
                return false;
            }
            tmp = tmp->leaf[c-'a'];
        }
        return true;
    }
};

int main() {
    Trie* obj = new Trie();
    obj->insert("apple");
    assert(obj->search("apple"));
    assert(obj->startsWith("app"));
    return 0;
}
