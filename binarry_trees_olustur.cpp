#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;

};
struct Node* kokDugum(int key) {
    Node* root = new Node();
    root->data = key;
    root->left = NULL;
    root->right = NULL;
    return root;
}
struct Node* dugumEkle(struct Node* root, int key) {
    if (root == 0) {
       root= kokDugum(key);
    }
    else {
        if (key < root->data) {
            root->left = dugumEkle(root->left, key);
        }
        else {
            root->right = dugumEkle(root->right, key);
        }
    }
    return root;
}
void preOrder(struct Node* root) {
    if (root != NULL) {
        cout << root->data<<"\t";
        preOrder(root->left);
        preOrder(root->right);
    }
}
void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        cout << root->data<<"\t";
        inOrder(root->right);
    }
}
void postOrder(struct Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data<<"\t";
    }
}
int dugumSayisi(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    else {
        return dugumSayisi(root->left) + 1 + dugumSayisi(root->right);
    }
}
int yukseklik(struct Node* root) {
    if (root == NULL)
        return 0;
    else {
        int sol, sag;
        sol = yukseklik(root->left);
        sag = yukseklik(root->right);
        if (sol > sag)
            return sol + 1;
        else
            return sag + 1;
    }
}
void yerDegistir(struct Node* root) {
    struct Node *temp = NULL;
    if (root != NULL) {
        yerDegistir(root->left);
        yerDegistir(root->right);
        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }

}
int main()
{
    struct Node* root = NULL;
    int i = 0;
    int sayi;
    while (i < 7) {
        cout << "eklenecek dugumler: ";
        cin >> sayi;
        root = dugumEkle(root, sayi);
        i++;
    }
    cout << "preOrder: ";
    preOrder(root);
    cout << endl;
    cout << "inOrder: ";
    inOrder(root);
    cout << endl;
    cout << "postOrder: ";
    postOrder(root);
    cout << endl;
    cout << " dugum sayisi: " << dugumSayisi(root) << endl;
    cout << "yukseklik : " << yukseklik(root) << endl;
    cout << "yer degistirildi ! " << endl;
    yerDegistir(root);
    cout << "inOrder: ";
    inOrder(root);
    cout << endl;
    return 0;

}