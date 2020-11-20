// max path sum.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

int traverse(Node* root, int& max) {
    int l = INT_MIN;
    int r = INT_MIN;
    if (root == NULL) return INT_MIN;
    l = traverse(root->left, max);
    r = traverse(root->right, max);
    if (l == INT_MIN && r == INT_MIN) return root->data;

    if (l != INT_MIN && r != INT_MIN) {
        int curr = l + r + root->data;
        if (curr > max) {
            max = curr;
        }
    }

    return root->data + (l > r ? l : r);
}

int maxPathSum(Node* root)
{
    int max = INT_MIN;
    traverse(root, max);
    return max;
}

int main()
{
    std::cout << "Hello World!\n";
}
