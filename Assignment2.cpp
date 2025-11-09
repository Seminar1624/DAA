
/*Huffman coding*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *l, *r;
    Node(char c, int f) {
        ch = c;
        freq = f;
        l = r = NULL;
    }
};

struct cmp {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void print(Node* root, string s) {
    if (!root) return;
    if (!root->l && !root->r)
        cout << root->ch << ": " << s << "\n";
    print(root->l, s + "0");
    print(root->r, s + "1");
}

int main() {
    // char ch[] = {'a','b','c','d','e','f'};
    // int f[] = {5,9,12,13,16,45};
    // int n = sizeof(f)/sizeof(f[0]);
    int n;

    cout << "Enter number of characters: ";
    cin >> n;

    char ch[n];
    int f[n];

    cout << "Enter " << n << " characters:\n";
    for (int i = 0; i < n; i++) {
        cin >> ch[i];
    }

    cout << "Enter frequencies of these characters:\n";
    for (int i = 0; i < n; i++) {
        cin >> f[i];
    }

    priority_queue<Node*, vector<Node*>, cmp> q;
    for (int i = 0; i < n; i++)
        q.push(new Node(ch[i], f[i]));

    while (q.size() > 1) {
        Node* x = q.top(); 
        q.pop();
        Node* y = q.top(); 
        q.pop();
        Node* z = new Node('-', x->freq + y->freq);
        z->l = x;
        z->r = y;
        q.push(z);
    }

    Node* root = q.top();
    print(root, "");
    return 0;
}
