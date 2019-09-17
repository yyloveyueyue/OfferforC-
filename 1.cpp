#include <iostream>
#include <deque>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

typedef struct HuffumanTree
{
    int weight;//权值
    HuffumanTree *left;//左儿子节点
    HuffumanTree *right;//右儿子节点
}*htree;

tuple<htree, int> creat_tree(vector<int> &vec)
{
    int ans = 0;
    deque<htree> forest;//森林
    const int sz = vec.size();
    for (int i = 0; i < sz; ++i)//将所有节点看作n棵树的森林
    {
        htree ptr = new HuffumanTree;
        ptr->weight = vec[i];
        ptr->left = ptr->right = nullptr;
        forest.push_back(ptr);
    }
    for (int i = 0; i < sz - 1; ++i)
    {
        //对所有节点的权值排序（也可以使用优先级队列）
        sort(forest.begin(), forest.end(), [](htree a, htree b) { return a->weight < b->weight; });
        //选取权值最小的两棵树，并删除
        auto a = forest.front();
        forest.pop_front();
        auto b = forest.front();
        forest.pop_front();
        //构建新的树，加入到队列
        htree ptr2 = new HuffumanTree;
        ptr2->weight = a->weight + b->weight;
        ptr2->left = a;
        ptr2->right = b;
        forest.push_back(ptr2);
        //累加权值
        ans += ptr2->weight;
    }
    auto root = forest.front();
    deque<htree>().swap(forest);
    return make_tuple(root, ans);
}

void print_tree(htree root)
{
    if (root != nullptr)
    {
        //打印所有节点及其左右儿子的权值
        cout << root->weight << endl;
        if (root->left != nullptr)
            cout << root->left->weight << endl;
        else
            cout << "no left child" << endl;
        if (root->right != nullptr)
            cout << root->right->weight << endl;
        else
            cout << "no right child" << endl;
        print_tree(root->left);
        print_tree(root->right);
    }
}

int main(int argc, char const *argv[])
{
    vector<int> a = { 5,7,10,12,18,20,28 };
    htree root;
    int sum;
    tie(root, sum) = creat_tree(a);
    cout << sum << endl;
    print_tree(root);
    
    int ^-^ = 0;return 0;
}
