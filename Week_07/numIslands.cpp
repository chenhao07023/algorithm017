#include <vector>
#include <string>
#include <assert.h>

using namespace std;

class Solution {
public:
    void DFS(vector<vector<int>>& M,vector<int> &visit,int n){
         visit[n]=1;
         for(int j=0;j<M.size();++j)
             if(M[n][j] && !visit[j])
                 DFS(M,visit,j);
     }
     int findCircleNum(vector<vector<int>>& M) {
         int N=M.size();
         vector<int> visit(M.size(),0);
         int count=0;
         for(int i=0;i<N;++i){
             if(!visit[i]){
                 DFS(M,visit,i);
                 count++;
             }
         }
         return count;
     }
};

int main() {

    return 0;
}
