#include <iostream>
using namespace std;

class TreeNode{
private:
    int data;
    TreeNode* left;
    TreeNode* right;
public:
    TreeNode(int d = 0, TreeNode* l = nullptr, TreeNode* r = nullptr){
        data = d;
        left = l;
        right = r;
    }
    void setData(int d){ data = d; }
    void setLeft(TreeNode* l){ left = l; }
    void setRight(TreeNode* r){ right = r; }
    int getData(){ return data; }
    TreeNode* getLeft(){ return left; }
    TreeNode* getRight(){ return right; }
};

class BinaryTree{
private:
    TreeNode* root;
public:
    BinaryTree(TreeNode* r = nullptr){ root = r; }
    void setRoot(TreeNode* r){ root = r; }
    bool isEmpty(){ return root == nullptr; }

    void preorder(){
        cout << "preorder: ";
        preorder(root);
        cout << endl;
    }
    void preorder(TreeNode* r){
        if(r){
            cout << r->getData() << " ";
            preorder(r->getLeft());
            preorder(r->getRight());
        }
    }

    //inorder
    void inorder(){
        cout << "inorder: ";
        inorder(root);
        cout << endl;
    }
    void inorder(TreeNode* r){
        if(r){
            inorder(r->getLeft());
            cout << r->getData() << " ";
            inorder(r->getRight());
        }
    }

    //postorder
    void postorder(){
        cout << "postorder: ";
        postorder(root);
        cout << endl;
    }
    void postorder(TreeNode* r){
        if(r){
            postorder(r->getLeft());
            postorder(r->getRight());
            cout << r->getData() << " ";
        }
    }
};

int main(){
    TreeNode n1 = {1, nullptr, nullptr};
    TreeNode n2 = {16, nullptr, nullptr};
    TreeNode n3 = {25, nullptr, nullptr};
    TreeNode n4 = {4, &n1, nullptr};
    TreeNode n5 = {20, &n2, &n3};
    TreeNode n6 = {15, &n4, &n5};

    BinaryTree t;
    t.setRoot(&n6);

    t.preorder();
    t.postorder();
    t.inorder();
}