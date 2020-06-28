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
    multiset<int> mt;
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n = points.size(), cur = 0;
        int ans = INT_MIN;
        mt.insert(points[0][1] - points[0][0]);
        for (int i = 1; i < n; ++i){
            int x = points[i][0], y = points[i][1];
            while (cur < i && points[cur][0] < x - k){
                mt.erase(mt.find(points[cur][1] - points[cur][0]));
                ++cur;
            }
            if (!mt.empty()) ans = max(ans, x + y + *mt.rbegin());
            mt.insert(y - x);
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
