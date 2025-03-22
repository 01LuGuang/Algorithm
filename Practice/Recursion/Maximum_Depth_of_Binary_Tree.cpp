#include <iostream>
#include <vector>

using namespace std;

struct BinaryTreeNode {
    int left = 0;
    int right = 0;
};

//求最大深度
int maxDepth(int root, vector<BinaryTreeNode> &tree) {
    if(root == 0) {
        return 0;
    }
    return 1 + max(maxDepth(tree[root].left, tree), maxDepth(tree[root].right, tree));
}

int main() {
    int n;
    cin >> n;

    vector<BinaryTreeNode> tree(n + 1);

    for(int i = 0; i < n - 1; i ++) {
        int parent, son;
        cin >> parent >> son;

        if(tree[parent].left == 0){
            tree[parent].left = son;
        }
        else {
            tree[parent].right = son;
        }
    }
    
    cout << maxDepth(1, tree) << endl;

    return 0;
}