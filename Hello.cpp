#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Domino {
public:
    int a, b;

    Domino(int a, int b) {
        this->a = a; this->b = b;
    }

    Domino flip() {
        Domino* dom = new Domino(b, a);
        return *dom;
    }

    string toString() {
        return "[" + to_string(a) + "/" + to_string(b) + "]";
    }
};

bool canAppend(Domino dom, vector <Domino> to) {
    return to.empty() || to[to.size() - 1].b == dom.a;
}

void print(vector <Domino> chained) {
    for (int i = 0; i < chained.size(); i++)
        cout << chained.at(i).toString() << " ";
    cout << endl;
}

void dominoChains(vector <Domino>& chain, vector <Domino> vector) {
    if (vector.empty()) return;
    for (int i = 0; i < vector.size(); ++i) 
    {
        Domino dom = vector.at(i);
        if (canAppend(dom, chain)) 
        {
            chain.push_back(dom);
            print(chain);
            Domino saved = vector.at(i);
            vector.erase(vector.begin() + i);
            dominoChains(chain, vector);
            if (vector.empty()) return;
            vector.insert(vector.begin() + i, saved);
            chain.erase(chain.end() - 1);
        }
        else 
        {
            dom = dom.flip();
            if (canAppend(dom, chain)) 
            {
                chain.push_back(dom);
                print(chain);
                Domino saved = vector.at(i);
                vector.erase(vector.begin() + i);
                dominoChains(chain, vector);
                if (vector.empty()) return;
                vector.insert(vector.begin() + i, saved);
                chain.erase(chain.end() - 1);
            }
        }
    }
}

int main() 
{
    vector <Domino> list;
    Domino* d = new Domino(3, 4);
    list.push_back(*d);
    d = new Domino(6, 1);
    list.push_back(*d);
    d = new Domino(5, 6);
    list.push_back(*d);
    d = new Domino(4, 5);
    list.push_back(*d);
    d = new Domino(3, 4);
    list.push_back(*d);
    d = new Domino(2, 3);
    list.push_back(*d);

    vector <Domino> chained;
    dominoChains(chained, list);

    return 0;
}

