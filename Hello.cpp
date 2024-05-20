#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

class TNode {
public:
    TNode(int a, int b)
    {
        min = std::min(a, b);
        max = std::max(a, b);
        Left = 0;
        Right = 0;
        Middle = 0;
    }

    int min;
    int max;
    TNode* Left;
    TNode* Right;
    TNode* Middle;
};

class Tree {
public:
    Tree()
        : Root(0)
    {
    }

    void Insert(int a, int b)
    {
        TNode** cur = &Root;
        while (*cur)
        {
            TNode& node = **cur;
            if (std::min(a, b) < node.min && std::max(a, b) > node.max)
            {
                cur = &node.Left;
            }
            else if (std::min(a, b) > node.max)
            {
                cur = &node.Right;
            }
            else
            {
                cur = &node.Middle;
            }
        }
        *cur = new TNode(a, b);
    }

    TNode* Root;
};

void printTree(TNode* root) {
    if (root == nullptr) {
        return;
    }

    std::queue<TNode*> q;
    q.push(root);

    while (!q.empty()) {
        TNode* current = q.front();
        q.pop();

        std::cout << current->min << ", " << current->max << std::endl;

        if (current->Left != nullptr) {
            q.push(current->Left);
        }

        if (current->Middle != nullptr) {
           q.push(current->Middle);
        }

        if (current->Right != nullptr) {
            q.push(current->Right);
        }
    }
}


void main()
{
    Tree tree;

    tree.Insert(12, 1);
    tree.Insert(14, -8);
    tree.Insert(100,10000);
    tree.Insert(-6,0);
    tree.Insert(-10,130);
    tree.Insert(5,10);

    //tree.preorderPrint(tree.Root);
    printTree(tree.Root);
}
