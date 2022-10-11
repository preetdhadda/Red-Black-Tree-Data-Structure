// Author: Preet Dhadda
// Date: April 2022

#include <vector>
using std::vector;
#pragma once

// ---------------------- NODE CLASS ----------------------
template <class Tk, class Tv>
class NodeT {
public:
    Tk key;
    Tv value;
    NodeT* left;
    NodeT* right;
    NodeT* parent;
    bool isBlack; // node is black if true, red if false
    
    // Constructor
    NodeT(Tk k, Tv v) : key(k), value(v), left(nullptr), right(nullptr), parent(nullptr), isBlack(false) {};
};

// ---------------------- TREE CLASS ----------------------
template <class Tk, class Tv>
class RedBlackTree {
public:
    // default constructor
    RedBlackTree();
    
    // copy constructor
    RedBlackTree(const RedBlackTree & tree);
    
    // overloaded assignment operator
    RedBlackTree& operator=(const RedBlackTree & tree);
    
    // destructor
    ~RedBlackTree();
    
    // insert method
    bool insert(Tk inputKey, Tv inputValue);
    
    // remove method
    bool remove(Tk inputKey);
    
    // boolean search method
    bool search(Tk inputKey) const;
    
    // vector search method
    vector<Tv> search(Tk key1, Tk key2) const;
    
    // values method
    vector<Tv> values() const;
    
    // keys method
    vector<Tk> keys() const;
    
    // size method
    int size() const;
    
    // getRoot method
    NodeT<Tk, Tv>* getRoot() const;
    
private:
    // attributes:
    NodeT<Tk, Tv>* root;
    int treeSize;
    
    // deep copy helper method (used in copy constructor & assignment operator)
    void copyTree(NodeT<Tk, Tv>* &copy, NodeT<Tk, Tv>* newParent, NodeT<Tk, Tv>* original);
    
    // delete tree helper method (used in assignment operator & destructor)
    void deleteTree(NodeT<Tk, Tv>* nd);
    
    // helper method that checks if a node is black or null (used in remove helper)
    bool isBlackHelper(NodeT<Tk, Tv>* nd) const;
    
    // rotate helper methods (used in insert & remove)
    void leftRotate(NodeT<Tk, Tv>* nd);
    void rightRotate(NodeT<Tk, Tv>* nd);
    
    // helper methods for insert public method
    void bstInsert(NodeT<Tk, Tv>* nd);
    void insertHelper(NodeT<Tk, Tv>* nd);
    
    // helper methods for remove public method
    NodeT<Tk, Tv>* getPredecessor(NodeT<Tk, Tv>* target) const;
    NodeT<Tk, Tv>* returnNode(Tk inputKey) const;
    void bstRemove(Tk inputKey);
    void removeFix(NodeT<Tk, Tv>* nd, NodeT<Tk, Tv>* par, bool isLeftChild);
    
    // inOrderTraversal helper methods
    void inOrderValues(NodeT<Tk, Tv>* nd, vector<Tv> & vec) const;
    void inOrderKeys(NodeT<Tk, Tv>* nd, vector<Tk> & vec) const;
};

// -------------- PUBLIC METHODS IMPLEMENTATION ---------------
// default constructor
template <class Tk, class Tv>
RedBlackTree<Tk, Tv>::RedBlackTree() {
    root = nullptr;
    treeSize = 0;
}

// copy constructor
template <class Tk, class Tv>
RedBlackTree<Tk, Tv>::RedBlackTree(const RedBlackTree & tree) {
    // Call copyTree private helper
    copyTree(this->root, nullptr, tree.root);
    this->treeSize = tree.treeSize;
}

// overloaded assignment operator
template <class Tk, class Tv>
RedBlackTree<Tk, Tv>& RedBlackTree<Tk, Tv>::operator=(const RedBlackTree & tree) {
    if (this != &tree) {
        // Call deleteTree private helper
        deleteTree(root);
        root = nullptr;
        // Call copyTree private helper
        copyTree(this->root, nullptr, tree.root);
        this->treeSize = tree.treeSize;
    }
    return *this;
}

// destructor
template <class Tk, class Tv>
RedBlackTree<Tk, Tv>::~RedBlackTree() {
    // Call deleteTree private helper
    deleteTree(root);
    root = nullptr;
}

// insert method
template <class Tk, class Tv>
bool RedBlackTree<Tk, Tv>::insert(Tk inputKey, Tv inputValue) {
    // call search method, if key is already in tree, return false
    if (search(inputKey) == true) {
        return false;
    }
    // otherwise, make a new node, insert it, and return true
    else {
        NodeT<Tk, Tv>* nd = new NodeT<Tk, Tv>(inputKey, inputValue);
        insertHelper(nd);
        treeSize++;
        return true;
    }
}

// remove method
template <class Tk, class Tv>
bool RedBlackTree<Tk, Tv>::remove(Tk inputKey) {
    // call search method, if key isn't in tree, return false
    if (search(inputKey) == false) {
        return false;
    }
    // otherwise, remove the node and return true
    else {
        bstRemove(inputKey);
        treeSize--;
        return true;
    }
}

// boolean search method
template <class Tk, class Tv>
bool RedBlackTree<Tk, Tv>::search(Tk inputKey) const {
    NodeT<Tk, Tv>* temp = root;
    // traverse down left and right sides of tree looking for a match
    while (temp != nullptr) {
        if (inputKey == temp->key) {
            return true;
        }
        else if (inputKey < temp->key) {
            temp = temp->left;
        }
        else {
            temp = temp->right;
        }
    }
    // if we reach here, there was no match and return false
    return false;
}

// vector search method
template <class Tk, class Tv>
vector<Tv> RedBlackTree<Tk, Tv>::search(Tk key1, Tk key2) const {
    // a bunch of variables and vectors:
    vector<Tv> rangedVec;
    vector<Tk> keysVec = keys();
    vector<Tv> valuesVec = values();
    Tk minKey; Tk maxKey;
    int minIndex = 0; int maxIndex = 0; int curr = 0; int prev = -1;
    
    // get the min and max keys from the input keys
    if (key1 <= key2) {
        minKey = key1;
        maxKey = key2;
    }
    else {
        minKey = key2;
        maxKey = key1;
    }
    
    // get index of lower bound
    for (int i = 0; i < size(); i++) {
        if (keysVec[i] < minKey) {
            minIndex = i+1;
        }
        if (keysVec[i] == minKey) {
            minIndex = i;
        }
    }
    
    // get index of upper bound
    while (curr < size()) {
        if (keysVec[curr] == maxKey) {
            maxIndex = curr;
            break;
        }
        else if (keysVec[curr] > maxKey) {
            maxIndex = prev;
            break;
        }
        else {
            maxIndex = size()-1;
        }
        curr++;
        prev++;
    }
    
    // loop through the upper and lower bounds adding the values to the vector
    for (int i = minIndex; i <= maxIndex; i++) {
        rangedVec.push_back(valuesVec[i]);
    }
    
    return rangedVec;
}

// values method
template <class Tk, class Tv>
vector<Tv> RedBlackTree<Tk, Tv>::values() const {
    vector<Tv> vec;
    inOrderValues(root, vec);
    return vec;
}

// keys method
template <class Tk, class Tv>
vector<Tk> RedBlackTree<Tk, Tv>::keys() const {
    vector<Tk> vec;
    inOrderKeys(root, vec);
    return vec;
}

// size method
template <class Tk, class Tv>
int RedBlackTree<Tk, Tv>::size() const {
    return treeSize;
}

// getRoot method
template <class Tk, class Tv>
NodeT<Tk, Tv>* RedBlackTree<Tk, Tv>::getRoot() const {
    return root;
}

// -------------- PRIVATE METHODS IMPLEMENTATION --------------
// deep copy helper method
// referenced: https://stackoverflow.com/questions/65207286/how-to-overloading-operator-in-red-black-tree-c
// to see what parameters to pass into copy
template <class Tk, class Tv>
void RedBlackTree<Tk, Tv>::copyTree(NodeT<Tk, Tv>* &copy, NodeT<Tk, Tv>* newParent, NodeT<Tk, Tv>* original) {
    if (original == nullptr) {
        copy = nullptr;
    }
    else {
        // make new node and copy attributes from original tree
        copy = new NodeT<Tk, Tv>(original->key, original->value);
        copy->parent = newParent;
        copy->isBlack = original->isBlack;
        // recursive call, copying nodes down left and right of tree
        copyTree(copy->left, copy, original->left);
        copyTree(copy->right, copy, original->right);
    }
}

// delete tree helper method
template <class Tk, class Tv>
void RedBlackTree<Tk, Tv>::deleteTree(NodeT<Tk, Tv>* nd) {
    if (nd != nullptr) {
        // recursively go down left and right of tree deleting nodes
        deleteTree(nd->left);
        deleteTree(nd->right);
        delete nd;
    }
}

// helper method that checks if a node is black or null
template <class Tk, class Tv>
bool RedBlackTree<Tk, Tv>::isBlackHelper(NodeT<Tk, Tv>* nd) const {
    if (nd == nullptr || nd->isBlack == true) {
        return true;
    }
    else {
        return false;
    }
}

// left rotate helper method (used in insert & remove)
template <class Tk, class Tv>
void RedBlackTree<Tk, Tv>::leftRotate(NodeT<Tk, Tv>* nd) {
    // Get the right child of nd, and make this child's left child
    // the right child of nd
    NodeT<Tk, Tv>* rightChild = nd->right;
    nd->right = rightChild->left;
    
// Update parent pointers:
    // If nd's right child's left child is null...
    if (rightChild->left != nullptr) {
        // Then make right child = nd
        rightChild->left->parent = nd;
    }
    // Swap nd's parent to be right child's parent
    rightChild->parent = nd->parent;
    
// Update child pointers:
    // If nd's parent is null, then the new root is right child
    if (nd->parent == nullptr) {
        root = rightChild;
    }
    // Replace nd with right child
    else if (nd == nd->parent->left) {
        nd->parent->left = rightChild;
    }
    else {
        nd->parent->right = rightChild;
    }

    // Finally, attach nd to right child
    rightChild->left = nd;
    nd->parent = rightChild;
}

// right rotate helper method (used in insert & remove)
template <class Tk, class Tv>
void RedBlackTree<Tk, Tv>::rightRotate(NodeT<Tk, Tv>* nd) {
    // Get the left child of nd, and make this child's right child
    // the right child of nd
    NodeT<Tk, Tv>* leftChild = nd->left;
    nd->left = leftChild->right;
    
// Update parent pointers:
    // If nd's left child's right child is null...
    if (leftChild->right != nullptr) {
        // Then make left child = nd
        leftChild->right->parent = nd;
    }
    // Swap nd's parent to be left child's parent
    leftChild->parent = nd->parent;
    
// Update child pointers:
    // If nd's parent is null, then the new root is left child
    if (nd->parent == nullptr) {
        root = leftChild;
    }
    // Replace nd with left child
    else if (nd == nd->parent->right) {
        nd->parent->right = leftChild;
    }
    else {
        nd->parent->left = leftChild;
    }

    // Finally, attach nd to left child
    leftChild->right = nd;
    nd->parent = leftChild;
}

// BST insert helper method (used in insert helper method below)
template <class Tk, class Tv>
void RedBlackTree<Tk, Tv>::bstInsert(NodeT<Tk, Tv>* nd) {
    NodeT<Tk, Tv>* next = root;
    
    // If tree is empty, then the new node becomes the root
    if (root == nullptr) {
        root = nd;
    }
    
    // If tree isn't empty...
    else {
        // Find the parent by traversing down left and right subtrees
        while (next != nullptr) {
            nd->parent = next;
            if (nd->key < nd->parent->key) {
                next = nd->parent->left;
            }
            else {
                next = nd->parent->right;
            }
        }
        // Insert node as left or right child of parent
        if (nd->key < nd->parent->key) {
            nd->parent->left = nd;
        }
        else {
            nd->parent->right = nd;
        }
    }
}

// Insert helper method (used in insert)
template <class Tk, class Tv>
void RedBlackTree<Tk, Tv>::insertHelper(NodeT<Tk, Tv>* nd) {
    // Call binary search tree insert method
    bstInsert(nd); // nd's colour is red by default
    
    // While loop until the root or black parent is found
    while (nd != root && nd->parent->isBlack == false) {
        // If nd's parent is itself a left child...
        if (nd->parent == nd->parent->parent->left) {
            // Set the uncle of nd to be the grandparent's right child
            NodeT<Tk, Tv>* uncle = nd->parent->parent->right;
            
            // If the uncle is red, do some recolouring:
            if (uncle != nullptr && uncle->isBlack == false) {
                // Make nd's parent and uncle black, and nd's grandparent red
                nd->parent->isBlack = true;
                uncle->isBlack = true;
                nd->parent->parent->isBlack = false;
                // Replace the grandparent with nd
                nd = nd->parent->parent;
            }
            
            // If uncle is black, do some rotations:
            else {
                // If nd is a right child, call left rotate on the parent
                if (nd == nd->parent->right) {
                    nd = nd->parent;
                    leftRotate(nd);
                }
                // Make the parent black, grandparent red, and call right rotate on grandparent
                nd->parent->isBlack = true;
                nd->parent->parent->isBlack = false;
                rightRotate(nd->parent->parent);
            }
        }
        
    // SAME AS PREVIOUS IF STATEMENT, just flipped:
        // If nd's parent is itself a right child...
        else if (nd->parent == nd->parent->parent->right) {
            // Set the uncle of nd to be the grandparent's left child
            NodeT<Tk, Tv>* uncle = nd->parent->parent->left;

            // If the uncle is red, do some recolouring:
            if (uncle != nullptr && uncle->isBlack == false) {
                // Make nd's parent and uncle black, and nd's grandparent red
                nd->parent->isBlack = true;
                uncle->isBlack = true;
                nd->parent->parent->isBlack = false;
                // Replace the grandparent with nd
                nd = nd->parent->parent;
            }

            // If uncle is black, do some rotations:
            else {
                // If nd is a left child, call right rotate on the parent
                if (nd == nd->parent->left) {
                    nd = nd->parent;
                    rightRotate(nd);
                }
                // Make the parent black, grandparent red, and call left rotate on grandparent
                nd->parent->isBlack = true;
                nd->parent->parent->isBlack = false;
                leftRotate(nd->parent->parent);
            }
        }
    }
    
    // Finally, make the root black
    root->isBlack = true;
}

// getPredecessor helper method (used in remove)
template <class Tk, class Tv>
NodeT<Tk, Tv>* RedBlackTree<Tk, Tv>::getPredecessor(NodeT<Tk, Tv>* target) const {
    // locate predecessor and return
    NodeT<Tk, Tv>* curr = target->left;
    while (curr->right != nullptr) {
        curr = curr->right;
    }
    return curr;
}

// returnNode helper method (used in remove helper)
template <class Tk, class Tv>
NodeT<Tk, Tv>* RedBlackTree<Tk, Tv>::returnNode(Tk inputKey) const {
    // acts the same way as search method, except it returns the key's node
    NodeT<Tk, Tv>* temp = root;
    while (temp != nullptr) {
        if (inputKey == temp->key) {
            return temp;
        }
        else if (inputKey < temp->key) {
            temp = temp->left;
        }
        else {
            temp = temp->right;
        }
    }
    return temp;
}

// BST remove helper method (used in red black tree remove)
template <class Tk, class Tv>
void RedBlackTree<Tk, Tv>::bstRemove(Tk inputKey) {
    // Locate the node associated with the input key
    NodeT<Tk, Tv>* target = returnNode(inputKey);
    NodeT<Tk, Tv>* removedNode = nullptr;
    NodeT<Tk, Tv>* removedChild;
    
    // Case 1: target has no children or 1 child
    if (target->left == nullptr || target->right == nullptr) {
        removedNode = target;
    }
    // Case 2: target has 2 children
    else {
        removedNode = getPredecessor(target);
    }
    
    // Check if the node to be removed's child is left or right
    if (removedNode->left != nullptr) {
        removedChild = removedNode->left;
    }
    else {
        removedChild = removedNode->right;
    }
    
    // Detach child from node to be removed
    if (removedChild != nullptr) {
        removedChild->parent = removedNode->parent;
    }
    
    // If the node to be removed is null, make its child the root
    if (removedNode->parent == nullptr) {
        root = removedChild;
    }
    // Otherwise, attach the child to the node's parent
    else {
        if (removedNode == removedNode->parent->left) {
            removedNode->parent->left = removedChild;
        }
        else {
            removedNode->parent->right = removedChild;
        }
    }
    
    // Replace the target's data with the node to be removed's data
    if (removedNode != target) {
        target->key = removedNode->key;
        target->value = removedNode->value;
    }
    
    // Call fix method
    if (isBlackHelper(removedNode) && removedNode->parent != nullptr) {
        // Child could be null, so pass in a parent and whether the child is left or right
        // this way, these attributes about child don't need to be accessed in fix, which
        // would throw seg faults if child is null
        removeFix(removedChild, removedNode->parent, (removedChild == removedNode->parent->left));
    }
    
    // Update root's colour
    if (root != nullptr) {
        root->isBlack = true;
    }
    
    delete removedNode;
}

// red black tree fix method (used in remove)
template <class Tk, class Tv>
void RedBlackTree<Tk, Tv>::removeFix(NodeT<Tk, Tv>* nd, NodeT<Tk, Tv>* par, bool isLeftChild) {
    NodeT<Tk, Tv>* sibling = nullptr;
    while (nd != root && isBlackHelper(nd) == true) {
        // if nd is a left child...
        if (isLeftChild == true) {
            // update the sibling
            sibling = par->right;
            // if sibling is red, update colours and do a left rotate
            if (sibling->isBlack == false) {
                sibling->isBlack = true;
                par->isBlack = false;
                leftRotate(par);
                sibling = par->right;
            }
            // if sibling's children are black, update colours and parent pointers
            if (isBlackHelper(sibling->left) == true && isBlackHelper(sibling->right) == true) {
                sibling->isBlack = false;
                nd = par;
                par = nd->parent;
                if (par != nullptr) {
                    isLeftChild = (nd == par->left);
                }
            }
            // otherwise...
            else {
                // if sibling is a right child, update colours and do a right rotate
                if (isBlackHelper(sibling->right) == true) {
                    sibling->left->isBlack = true;
                    sibling->isBlack = false;
                    rightRotate(sibling);
                    sibling = par->right;
                }
                // update more colours, do a left rotate, and update nd parameter
                sibling->isBlack = par->isBlack;
                par->isBlack = true;
                sibling->right->isBlack = true;
                leftRotate(par);
                nd = root;
                break;
            }
        }
    // SAME AS PREVIOUS IF STATEMENT, just flipped:
        // if nd is a right child...
        else {
            // update the sibling
            sibling = par->left;
            // if sibling is red, update colours and do a right rotate
            if (sibling->isBlack == false) {
                sibling->isBlack = true;
                par->isBlack = false;
                rightRotate(par);
                sibling = par->left;
            }
            // if sibling's children are black, update colours and parent pointers
            if (isBlackHelper(sibling->right) == true && isBlackHelper(sibling->left) == true) {
                sibling->isBlack = false;
                nd = par;
                par = nd->parent;
                if (par != nullptr) {
                    isLeftChild = (nd == par->left);
                }
            }
            // otherwise...
            else {
                // if sibling is a left child, update colours and do a left rotate
                if (isBlackHelper(sibling->left) == true) {
                    sibling->right->isBlack = true;
                    sibling->isBlack = false;
                    leftRotate(sibling);
                    sibling = par->left;
                }
                // update more colours, do a right rotate, and update nd parameter
                sibling->isBlack = par->isBlack;
                par->isBlack = true;
                sibling->left->isBlack = true;
                rightRotate(par);
                nd = root;
                break;
            }
        }
    }
    // finally, make nd black
    nd->isBlack = true;
}

// in order traversal helper method for values method
template <class Tk, class Tv>
void RedBlackTree<Tk, Tv>::inOrderValues(NodeT<Tk, Tv>* nd, vector<Tv> & vec) const {
    // in order traversal thru tree, pushing values into a vector
    if (nd != nullptr) {
        inOrderValues(nd->left, vec);
        vec.push_back(nd->value);
        inOrderValues(nd->right, vec);
    }
}

// in order traversal helper method for keys method
template <class Tk, class Tv>
void RedBlackTree<Tk, Tv>::inOrderKeys(NodeT<Tk, Tv>* nd, vector<Tk> & vec) const {
    // in order traversal thru tree, pushing keys into a vector
    if (nd != nullptr) {
        inOrderKeys(nd->left, vec);
        vec.push_back(nd->key);
        inOrderKeys(nd->right, vec);
    }
}
