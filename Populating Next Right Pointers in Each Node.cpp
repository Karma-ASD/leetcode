/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void run(vector<Node*>& v) {
        int s = v.size();
        int i = 0;
        while ((i + 1) != s) {
            v[i]->next = v[i + 1];
            i++;
        }
        v[i]->next = NULL;
    }

    Node* connect(Node* root) {
        if (!root) return NULL;  // Handle null root

        Node* ans = root;  // Explicitly declare as Node*
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int s = q.size();
            vector<Node*> v;

            while (s--) {
                Node* f = q.front();
                q.pop();
                v.push_back(f);
                if (f->left) q.push(f->left);
                if (f->right) q.push(f->right);
            }

            run(v);
        }

        return ans;
    }
};
