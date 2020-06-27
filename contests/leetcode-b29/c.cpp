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

template<typename T>
ostream& operator << (ostream& os, const vector<T>& vec){
    for (auto x: vec)
        os << x << " ";
    os << endl;
    return os;
}

template<typename T>
ostream& operator << (ostream& os, const vector<vector<T>>& vec){
    for (auto& v: vec){
        for (auto x: v)
            os << x << " ";
        os << endl;
    }
    return os;
}

class Solution {
    int a[100005], b[100005];
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        a[0] = 0;
        for (int i = 1; i <= n; ++i)
            a[i] = (nums[i - 1] == 0 ? 0: a[i - 1] + 1);
        b[n + 1] = 0;
        for (int i = n; i >= 1; --i)
            b[i] = (nums[i - 1] == 0 ? 0: b[i + 1] + 1);
        int ans = 0;
        for (int i = 1; i <= n; ++i)
            ans = max(ans, a[i - 1] + b[i + 1]);
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
