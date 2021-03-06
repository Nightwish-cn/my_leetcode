#include <bits/stdc++.h>
#define INF 2000000000
using namespace std;
typedef long long ll;
int read(){
    int f = 1, x = 0;
    char c = getchar();
    while(c < '0' || c > '9'){if(c == '-') f = -f; c = getchar();}
    while(c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
    return f * x; 
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isLeaf(TreeNode* root) {
    return root->left == NULL && root->right == NULL;
}

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> transformArray(vector<int>& arr) {
        vector<int> ans = arr, ans2 = arr;
        int n = ans.size();
        for (; ; ){
            bool flag = false;
            for (int i = 0; i < n; ++i)
                ans2[i] = ans[i];
            for (int i = 1; i < n - 1; ++i){
                if (ans2[i] < ans2[i - 1] && ans2[i] < ans2[i + 1])
                    flag = true, ++ans[i];
                else if (ans2[i] > ans2[i - 1] && ans2[i] > ans2[i + 1])
                    flag = true, --ans[i];
            }
            if (!flag) break;
        }
        return ans;
    }
};
Solution sol;
void init(){
    
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
