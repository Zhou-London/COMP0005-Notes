#include <iostream>
#include <memory>

using namespace std;

//Key-Value binding
class Node{
public:
    int key;
    int val;
    unique_ptr<Node> left;
    unique_ptr<Node> right;
    //Constructor
    Node(int key, int val):key(key), val(val), left(nullptr), right(nullptr) {}
};

class binaryTree{
private:
    unique_ptr<Node> root;

    //Hepler function of insertion
    void insertHelper(unique_ptr<Node>& node, int key, int val){

        //If find the key, throw error
        if(node->key == key) throw runtime_error("Key already exists!");

        //Search the place to insert the key
        //If find the place, insert
        if(key > node->key){
            if(!node->right) node->right = make_unique<Node>(key, val);
            else insertHelper(node->right, key, val);
        } else {
            if(!node->left) node->left = make_unique<Node>(key, val);
            else insertHelper(node->left, key, val);
        }
    }

    //Helper function of inorder iteration
    void inorderHelper(unique_ptr<Node>& node){
        //Not found
        if(!node) return;

        //Iterate right
        inorderHelper(node->right);
        //Print
        cout << "(Key: " << node->key <<", Val: " << node->val << ")" << endl;
        //Iterate left
        inorderHelper(node->left);
    }

    //Helper function of searching
    Node* searchHelper(const unique_ptr<Node>& node, int key){
        
        //Not found
        if(!node) return nullptr;

        //If found, return a simple pointer
        if(node->key == key) return node.get();

        //Keep searching
        else if(node->key > key) return searchHelper(node->left, key);
        else return searchHelper(node->right, key);
    }

    //Function to find the minimum value in the right
    Node* searchMin(Node* node){
        while(node->left) node = node->left.get();
        return node;
    }

    //Helper function of remove
    void removeHelper(unique_ptr<Node>& node, int key){
        //Not found
        if(!node) return;

        //Search the key to remove
        if(key < node->key) removeHelper(node->left, key);
        else if (key > node->key) removeHelper(node->right, key);
        else{
            //Found the key
            //No left, then move its right to this node
            if(!node->left) node = std::move(node->right);
            //No right, then move its left to this node
            else if(!node->right) node = std::move(node->left);
            else{
                //Has more than 2 children, move its minimum node in the right
                Node* min = searchMin(node->right.get());
                node->key = min->key;
                node->val = min->val;
                removeHelper(node->right, min->key);
            }
        }
    }


public:
    void insert(int key, int val){
        try{
            //Try insert
            if(!root) root = make_unique<Node>(key, val);
            else { insertHelper(root, key, val);}
        } catch (exception& e){
            //Node already exists
            //Throw error
            cout << "Insert Failed: " << e.what() << endl;
        }
    }

    //Inorder iteration
    void inorder(){ inorderHelper(root); }

    //Search the node
    Node* search(int key){ return searchHelper(root,key); }

    //Remove the node
    void remove(int key){ removeHelper(root, key); }
};

int main(){
    binaryTree bt = binaryTree();
    bt.insert(10,1);
    bt.insert(20,10);
    bt.insert(2,1);
    bt.insert(483,234);
    bt.insert(48,23);
    bt.insert(10,12);
    bt.remove(10);
    bt.inorder();
    return 0;
}

//         9
//    4       10
//   2 5     9  23
            