#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class TreeNode{
public:
    unique_ptr<TreeNode> left;
    unique_ptr<TreeNode> right;
    char key;
    int value;
    TreeNode(char k, int v):
    value(v),left(nullptr),right(nullptr)
    {
        char k_upper = toupper(k);
        if( 'A' <= k_upper && 'Z' >= k_upper ) key = k_upper;
        else { throw runtime_error("Key is not alphabetic! "); }
    }
};

class binaryTree{
private:
    unique_ptr<TreeNode> root;

    void insertHelper(unique_ptr<TreeNode>& node, char key, int val) {
        if(key < node->key){
            if(!node->left) node->left = make_unique<TreeNode>(key, val);
            else insertHelper(node->left, key, val);
        } else if (key > node->key) {
            if(!node->right) node->right = make_unique<TreeNode>(key, val);
            else insertHelper(node->right, key, val);
        } else{
            throw runtime_error("Node already exists!");
        }
    }

    void inorderHelper(const TreeNode* node) const {
        if(!node) return;
        inorderHelper(node->left.get());
        cout << "(Key: "<<node->key << " "
        << "Value: " << node->value << "), ";
        inorderHelper(node->right.get());

    }

    TreeNode* getHelper(const unique_ptr<TreeNode>& node, char key){
        if(node == nullptr) return nullptr;

        if(node->key == key) { return node.get(); }
        else if(node->key < key) { return getHelper(node->right, key); }
        else{ return getHelper(node->left, key); }
    }

    TreeNode* getMin(TreeNode* node){
        while(node->left) node = node->left.get();
        return node;
    }

    void removeHelper(unique_ptr<TreeNode>& node, char key){
        //Search the node
        if(!node) return;
        if(key < node->key){ removeHelper(node->left, key); } 
        else if (key>node->key){ removeHelper(node->right, key); } 
        else {
            if(!node->left){ node = std::move(node->right); } 
            else if(!node->right){ node = std::move(node->left); } 
            else {
                TreeNode* minNode = getMin(node->right.get());
                node->key = minNode->key;
                node->value = minNode->value;
                removeHelper(node->right, minNode->key);
            }
        }

    }

public:
    binaryTree(): root(nullptr) {}
    
    void insert(char key, int val){
        try{
            if(!root)root = make_unique<TreeNode>(key, val);
            else insertHelper(root, key, val);
        } catch(exception& e){
            cout<< "Insert Failed: " << e.what() << endl;
        }
    }

    void remove(char key){ removeHelper(root, key); }

    void inorder() const{
        inorderHelper(root.get());
        cout<<endl;
    }

    TreeNode* get(char key){ return getHelper(root, key); }
};



int main(){
    binaryTree n = binaryTree();
    n.insert('A',1);
    n.insert('B',2);
    n.insert('D',3);
    n.insert('M',10);
    n.remove('A');
    n.inorder();
    
    

    return 0;
}