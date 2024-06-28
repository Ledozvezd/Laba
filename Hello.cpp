#include <iostream>
using namespace std;

struct ltree {
    int val;
    ltree* child, * next;
};

ltree n1 = { 2, nullptr, nullptr };
ltree n3 = { 7, nullptr, nullptr };
ltree n2 = { 4, &n1, &n3 };
ltree root = { 5, &n2, nullptr };

int F7(ltree* p) {
    if (p->val > 6)
        return p->val;

    for (ltree* q = p->child; q != nullptr; q = q->next) {
        int vv = F7(q);
        if (vv != -1)
            return vv;
    }

    return -1;
}

int main() {
    int result = F7(&root);
    cout << "Результат выполнения функции F7: " << result << endl;
    return 0;
}
