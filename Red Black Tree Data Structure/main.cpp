// Author: Preet Dhadda
// Date: April 2022

#include <iostream>
#include <stdexcept>
#include <string>
using std::string;
using std::cout;
using std::endl;
#include "RedBlackTree.h"

// -------------------- INT KEY & INT VALUE --------------------
void testIntIntCopies() {
    RedBlackTree<int, int> tree2;
    tree2.insert(14, 101);
    tree2.insert(7, 552);
    tree2.insert(4, 210);
    tree2.insert(18, 809);
    tree2.insert(32, 502);
    cout << "printing tree2: " << endl;
//    tree2.printTree();
    cout << "tree size = " << tree2.size() << endl;
    cout << "tree root = " << tree2.getRoot()->key << endl;
  //  cout << tree2.checkTree() << endl << endl;
    
    RedBlackTree<int, int> tree3 = tree2;
    cout << "printing tree3: " << endl;
    //tree3.printTree();
    cout << "tree size = " << tree3.size() << endl;
    cout << "tree root = " << tree3.getRoot()->key << endl;
 //   cout << tree3.checkTree() << endl << endl;
    
    tree3.insert(19, 808);
    tree3.remove(7);
    tree3.remove(32);
    cout << "printing tree3 after 1 insert and 2 removes: " << endl;
   // tree3.printTree();
    cout << "tree size = " << tree3.size() << endl;
    cout << "tree root = " << tree3.getRoot()->key << endl;
 //   cout << tree3.checkTree() << endl << endl;
    
    
    RedBlackTree<int, int> tree4(tree3);
    cout << "printing tree4: " << endl;
   // tree4.printTree();
    cout << "tree size = " << tree4.size() << endl;
    cout << "tree root = " << tree4.getRoot()->key << endl;
 //   cout << tree4.checkTree() << endl << endl;
    
    tree4.remove(14);
    tree4.remove(19);
    tree4.insert(11, 634);
    cout << "printing tree4 after 1 insert and 2 removes: " << endl;
  //  tree4.printTree();
    cout << "tree size = " << tree4.size() << endl;
    cout << "tree root = " << tree4.getRoot()->key << endl;
//    cout << tree4.checkTree() << endl << endl;
    
    tree4.remove(18);
    tree4.remove(4);
    tree4.remove(11);
    cout << "tree4 after removing all elements:" << endl;
    cout << "tree size = " << tree4.size() << endl << endl;
    
    RedBlackTree<int, int> tree5(tree4);
    cout << "tree5 size (should be 0) = " << tree5.size() << endl;
    tree5.insert(8, 42);
    tree5.insert(1, 35);
    cout << "printing tree5: " << endl;
  //  tree5.printTree();
    tree5.remove(8);
    cout << "printing tree5 after removing 8: " << endl;
  //  tree5.printTree();
    cout << endl;
    
    RedBlackTree<int, int> tree6 = tree4;
    cout << "tree6 size (should be 0) = " << tree6.size() << endl;
    tree6.insert(8, 42);
    tree6.insert(1, 35);
    cout << "printing tree6: " << endl;
  //  tree6.printTree();
    tree6.remove(8);
    cout << "printing tree6 after removing 8: " << endl;
 //   tree6.printTree();
}

void testIntInt() {
    RedBlackTree<int, int> tree1;
    cout << "insert successful? (should be 1): " << tree1.insert(4, 101) << endl;
    cout << "insert successful? (should be 0): " << tree1.insert(4, 552) << endl;
    cout << "insert successful? (should be 1): " << tree1.insert(7, 120) << endl;
    cout << "insert successful? (should be 1): " << tree1.insert(12, 210) << endl;
    cout << "insert successful? (should be 1): " << tree1.insert(15, 809) << endl;
    cout << "insert successful? (should be 1): " << tree1.insert(3, 502) << endl;
    cout << "insert successful? (should be 1): " << tree1.insert(5, 403) << endl;
    cout << "insert successful? (should be 1): " << tree1.insert(14, 672) << endl;
    cout << "insert successful? (should be 0): " << tree1.insert(12, 900) << endl;
    cout << "insert successful? (should be 1): " << tree1.insert(18, 981) << endl;
    cout << "insert successful? (should be 1): " << tree1.insert(16, 326) << endl;
    cout << "insert successful? (should be 1): " << tree1.insert(17, 457) << endl;
    cout << "insert successful? (should be 0): " << tree1.insert(7, 947) << endl;
    cout << "insert successful? (should be 1): " << tree1.insert(9, 457) << endl;
    cout << "insert successful? (should be 1): " << tree1.insert(2, 457) << endl;
    cout << endl;
    cout << "printing tree1: " << endl;
  //  tree1.printTree();
    cout << "tree size = " << tree1.size() << endl;
    cout << "tree root = " << tree1.getRoot()->key << endl;
    cout << endl;
 //   cout << tree1.checkTree() << endl << endl;
    
    cout << "is 31 in the tree? (should be 0): " << tree1.search(31) << endl;
    cout << "is 4 in the tree? (should be 1): " << tree1.search(4) << endl;
    cout << "is 18 in the tree? (should be 1): " << tree1.search(18) << endl << endl;
    
    cout << "calling values method on tree1:" << endl;
    vector<int> vecValues = tree1.values();
    for (int i = 0; i < static_cast<int>(vecValues.size()); i++) {
        cout << vecValues[i] << endl;
    }
    cout << endl;

    cout << "calling keys method on tree1:" << endl;
    vector<int> vecKeys = tree1.keys();
    for (int i = 0; i < static_cast<int>(vecKeys.size()); i++) {
        cout << vecKeys[i] << endl;
    }
    cout << endl;
    
    cout << "calling ranged values method on tree1 (should have 7 values):" << endl;
    vector<int> searchVec1 = tree1.search(13, -3);
    for (int i = 0; i < static_cast<int>(searchVec1.size()); i++) {
        cout << searchVec1[i] << endl;
    }
    cout << endl;
    
    cout << "calling ranged values method on tree1 (should have 5 values):" << endl;
    vector<int> searchVec2 = tree1.search(14, 20);
    for (int i = 0; i < static_cast<int>(searchVec2.size()); i++) {
        cout << searchVec2[i] << endl;
    }
    cout << endl;
    
    cout << "calling ranged values method on tree1 (should be 1 thing):" << endl;
    vector<int> searchVec3 = tree1.search(9, 9);
    for (int i = 0; i < static_cast<int>(searchVec3.size()); i++) {
        cout << searchVec3[i] << endl;
    }
    cout << endl;

    cout << "calling ranged values method on tree1 (should be empty):" << endl;
    vector<int> searchVec4 = tree1.search(10, 10);
    for (int i = 0; i < static_cast<int>(searchVec4.size()); i++) {
        cout << searchVec4[i] << endl;
    }
    cout << endl;

    cout << "calling ranged values method on tree1 (should be empty):" << endl;
    vector<int> searchVec5 = tree1.search(20, 24);
    for (int i = 0; i < static_cast<int>(searchVec5.size()); i++) {
        cout << searchVec5[i] << endl;
    }
    cout << endl;
    
    cout << "calling ranged values method on tree1 (should be the same as the values print):" << endl;
    vector<int> searchVec6 = tree1.search(24, -2);
    for (int i = 0; i < static_cast<int>(searchVec6.size()); i++) {
        cout << searchVec6[i] << endl;
    }
    cout << endl;
    
    RedBlackTree<int, int> tree2;
    tree2.insert(14, 101);
    tree2.insert(7, 552);
    tree2.insert(21, 502);
    tree2.insert(4, 210);
    tree2.insert(18, 809);
    tree2.insert(32, 502);
    tree2.insert(26, 403);
    tree2.insert(2, 672);
    tree2.insert(11, 900);
    tree2.insert(17, 981);
    tree2.insert(34, 981);
    tree2.insert(23, 981);
    cout << endl;
    cout << "printing tree2: " << endl;
//tree2.printTree();
    cout << "tree size = " << tree2.size() << endl;
    cout << "tree root = " << tree2.getRoot()->key << endl;
    cout << endl;
 //   cout << tree2.checkTree() << endl << endl;

    cout << "calling values method on tree2:" << endl;
    vector<int> vecValues2 = tree2.values();
    for (int i = 0; i < static_cast<int>(vecValues2.size()); i++) {
        cout << vecValues2[i] << endl;
    }
    cout << endl;

    cout << "calling keys method on tree2:" << endl;
    vector<int> vecKeys2 = tree2.keys();
    for (int i = 0; i < static_cast<int>(vecKeys2.size()); i++) {
        cout << vecKeys2[i] << endl;
    }
    cout << endl;
    
    cout << "remove 32 successful? (should be 1): " << tree2.remove(32) << endl;
    cout << "printing tree2: " << endl;
   // tree2.printTree();
    cout << "tree size = " << tree2.size() << endl;
    cout << "tree root = " << tree2.getRoot()->key << endl;
    cout << endl;
  //  cout << tree2.checkTree() << endl << endl;

    cout << "remove 23 successful? (should be 1): " << tree2.remove(23) << endl;
    cout << "printing tree2: " << endl;
   // tree2.printTree();
    cout << "tree size = " << tree2.size() << endl;
    cout << "tree root = " << tree2.getRoot()->key << endl;
    cout << endl;
 //   cout << tree2.checkTree() << endl << endl;

    cout << "remove 11 successful? (should be 1): " << tree2.remove(11) << endl;
    cout << "printing tree2: " << endl;
   // tree2.printTree();
    cout << "tree size = " << tree2.size() << endl;
    cout << "tree root = " << tree2.getRoot()->key << endl;
    cout << endl;
 //   cout << tree2.checkTree() << endl << endl;
    
    cout << "remove 9 successful? (should be 0): " << tree2.remove(9) << endl << endl;

    cout << "remove 21 successful? (should be 1): " << tree2.remove(21) << endl;
    cout << "printing tree2: " << endl;
  //  tree2.printTree();
    cout << "tree size = " << tree2.size() << endl;
    cout << "tree root = " << tree2.getRoot()->key << endl;
    cout << endl;
  //  cout << tree2.checkTree() << endl << endl;
    
    cout << "remove 14 successful? (should be 1): " << tree2.remove(14) << endl;
    cout << "printing tree2: " << endl;
   // tree2.printTree();
    cout << "tree size = " << tree2.size() << endl;
    cout << "tree root = " << tree2.getRoot()->key << endl;
    cout << endl;
//    cout << tree2.checkTree() << endl << endl;
    
    cout << "remove 11 successful? (should be 0): " << tree2.remove(11) << endl << endl;
    
    cout << "remove 2 successful? (should be 1): " << tree2.remove(2) << endl;
    cout << "printing tree2: " << endl;
  //  tree2.printTree();
    cout << "tree size = " << tree2.size() << endl;
    cout << "tree root = " << tree2.getRoot()->key << endl;
    cout << endl;
//    cout << tree2.checkTree() << endl << endl;
    
    cout << "remove 4 successful? (should be 1): " << tree2.remove(4) << endl;
    cout << "printing tree2: " << endl;
   // tree2.printTree();
    cout << "tree size = " << tree2.size() << endl;
    cout << "tree root = " << tree2.getRoot()->key << endl;
    cout << endl;
//    cout << tree2.checkTree() << endl << endl;
    
    cout << "remove 18 successful? (should be 1): " << tree2.remove(18) << endl;
    cout << "printing tree2: " << endl;
   // tree2.printTree();
    cout << "tree size = " << tree2.size() << endl;
    cout << "tree root = " << tree2.getRoot()->key << endl;
    cout << endl;
//    cout << tree2.checkTree() << endl << endl;
    
    cout << "remove 7 successful? (should be 1): " << tree2.remove(7) << endl;
    cout << "printing tree2: " << endl;
  //  tree2.printTree();
    cout << "tree size = " << tree2.size() << endl;
    cout << "tree root = " << tree2.getRoot()->key << endl;
    cout << endl;
//    cout << tree2.checkTree() << endl << endl;
    
    cout << "remove 26 successful? (should be 1): " << tree2.remove(26) << endl;
    cout << "printing tree2: " << endl;
   // tree2.printTree();
    cout << "tree size = " << tree2.size() << endl;
    cout << "tree root = " << tree2.getRoot()->key << endl;
    cout << endl;
  //  cout << tree2.checkTree() << endl << endl;
    
    cout << "remove 17 & 34 successful? (should be 1 1): " << tree2.remove(17) << " " << tree2.remove(34) << endl;
    cout << "printing tree2: " << endl;
  //  tree2.printTree();
    cout << "tree size = " << tree2.size() << endl;
    cout << endl;
//    cout << tree2.checkTree() << endl << endl;
    
    tree2.insert(32, 502);
    tree2.insert(26, 403);
    tree2.insert(2, 672);
    cout << "printing tree2: " << endl;
 //   tree2.printTree();
    cout << "tree root = " << tree2.getRoot()->key << endl;
    cout << "tree size = " << tree2.size() << endl;
    cout << endl;
 //   cout << tree2.checkTree() << endl << endl;
}

// -------------------- STR KEY & STR VALUE --------------------
void testStrStrCopies() {
    RedBlackTree<string, string> tree2;
    tree2.insert("cat", "o");
    tree2.insert("bat", "p");
    tree2.insert("dog", "y");
    tree2.insert("frog", "x");
    tree2.insert("cow", "a");
    cout << "printing tree2: " << endl;
  //  tree2.printTree();
    cout << "tree size = " << tree2.size() << endl;
    cout << "tree root = " << tree2.getRoot()->key << endl;
 //   cout << tree2.checkTree() << endl << endl;
    
    RedBlackTree<string, string> tree3 = tree2;
    cout << "printing tree3: " << endl;
  //  tree3.printTree();
    cout << "tree size = " << tree3.size() << endl;
    cout << "tree root = " << tree3.getRoot()->key << endl;
 //   cout << tree3.checkTree() << endl << endl;
    
    tree3.insert("donkey", "l");
    tree3.remove("cat");
    tree3.remove("dog");
    cout << "printing tree3 after 1 insert and 2 removes: " << endl;
  //  tree3.printTree();
    cout << "tree size = " << tree3.size() << endl;
    cout << "tree root = " << tree3.getRoot()->key << endl;
//    cout << tree3.checkTree() << endl << endl;
    
    
    RedBlackTree<string, string> tree4(tree3);
    cout << "printing tree4: " << endl;
 //   tree4.printTree();
    cout << "tree size = " << tree4.size() << endl;
    cout << "tree root = " << tree4.getRoot()->key << endl;
 //   cout << tree4.checkTree() << endl << endl;
    
    tree4.remove("donkey");
    tree4.remove("frog");
    tree4.insert("horse", "q");
    cout << "printing tree4 after 1 insert and 2 removes: " << endl;
  //  tree4.printTree();
    cout << "tree size = " << tree4.size() << endl;
    cout << "tree root = " << tree4.getRoot()->key << endl;
 //   cout << tree4.checkTree() << endl << endl;
    
    tree4.remove("cow");
    tree4.remove("horse");
    tree4.remove("bat");
    cout << "tree4 after removing all elements:" << endl;
    cout << "tree size = " << tree4.size() << endl << endl;
    
    RedBlackTree<string, string> tree5(tree4);
    cout << "tree5 size (should be 0) = " << tree5.size() << endl;
    tree5.insert("zebra", "k");
    tree5.insert("snake", "u");
    cout << "printing tree5: " << endl;
 //   tree5.printTree();
    tree5.remove("zebra");
    cout << "printing tree5 after removing zebra: " << endl;
  //  tree5.printTree();
    cout << endl;
    
    RedBlackTree<string, string> tree6 = tree4;
    cout << "tree6 size (should be 0) = " << tree6.size() << endl;
    tree6.insert("zebra", "n");
    tree6.insert("snake", "i");
    cout << "printing tree6: " << endl;
//    tree6.printTree();
    tree6.remove("snake");
    cout << "printing tree6 after removing snake: " << endl;
 //   tree6.printTree();
}

void testStrStr() {
    RedBlackTree<string, string> tree1;
    cout << "insert successful? (should be 1): " << tree1.insert("snake", "r") << endl;
    cout << "insert successful? (should be 0): " << tree1.insert("snake", "l") << endl;
    cout << "insert successful? (should be 1): " << tree1.insert("zebra", "S") << endl;
    cout << "insert successful? (should be 1): " << tree1.insert("pig", "d") << endl;
    cout << "insert successful? (should be 1): " << tree1.insert("donkey", "q") << endl;
    cout << "insert successful? (should be 1): " << tree1.insert("horse", "w") << endl;
    cout << "insert successful? (should be 1): " << tree1.insert("giraffe", "e") << endl;
    cout << "insert successful? (should be 1): " << tree1.insert("cheetah", "r") << endl;
    cout << "insert successful? (should be 0): " << tree1.insert("horse", "t") << endl;
    cout << "insert successful? (should be 1): " << tree1.insert("cow", "y") << endl;
    cout << "insert successful? (should be 1): " << tree1.insert("frog", "a") << endl;
    cout << "insert successful? (should be 1): " << tree1.insert("monkey", "s") << endl;
    cout << "insert successful? (should be 0): " << tree1.insert("monkey", "d") << endl;
    cout << "insert successful? (should be 1): " << tree1.insert("bird", "d") << endl;
    cout << "insert successful? (should be 1): " << tree1.insert("flamingo", "d") << endl;
    cout << endl;
    cout << "printing tree1: " << endl;
  //  tree1.printTree();
    cout << "tree size = " << tree1.size() << endl;
    cout << "tree root = " << tree1.getRoot()->key << endl;
    cout << endl;
 //   cout << tree1.checkTree() << endl << endl;
    
    cout << "is puma in the tree? (should be 0): " << tree1.search("puma") << endl;
    cout << "is zebra in the tree? (should be 1): " << tree1.search("zebra") << endl;
    cout << "is snake in the tree? (should be 1): " << tree1.search("snake") << endl << endl;
    
    cout << "calling values method on tree1:" << endl;
    vector<string> vecValues = tree1.values();
    for (int i = 0; i < static_cast<int>(vecValues.size()); i++) {
        cout << vecValues[i] << endl;
    }
    cout << endl;

    cout << "calling keys method on tree1:" << endl;
    vector<string> vecKeys = tree1.keys();
    for (int i = 0; i < static_cast<int>(vecKeys.size()); i++) {
        cout << vecKeys[i] << endl;
    }
    cout << endl;

    cout << "calling ranged values method on tree1 (should have 7 values):" << endl;
    vector<string> searchVec1 = tree1.search("hog", "ant");
    for (int i = 0; i < static_cast<int>(searchVec1.size()); i++) {
        cout << searchVec1[i] << endl;
    }
    cout << endl;

    cout << "calling ranged values method on tree1 (should have 5 values):" << endl;
    vector<string> searchVec2 = tree1.search("horse", "zebrasssss");
    for (int i = 0; i < static_cast<int>(searchVec2.size()); i++) {
        cout << searchVec2[i] << endl;
    }
    cout << endl;

    cout << "calling ranged values method on tree1 (should be 1 thing):" << endl;
    vector<string> searchVec3 = tree1.search("frog", "frog");
    for (int i = 0; i < static_cast<int>(searchVec3.size()); i++) {
        cout << searchVec3[i] << endl;
    }
    cout << endl;

    cout << "calling ranged values method on tree1 (should be empty):" << endl;
    vector<string> searchVec4 = tree1.search("hog", "hog");
    for (int i = 0; i < static_cast<int>(searchVec4.size()); i++) {
        cout << searchVec4[i] << endl;
    }
    cout << endl;

    cout << "calling ranged values method on tree1 (should be empty):" << endl;
    vector<string> searchVec5 = tree1.search("zebras", "zebrasss");
    for (int i = 0; i < static_cast<int>(searchVec5.size()); i++) {
        cout << searchVec5[i] << endl;
    }
    cout << endl;

    cout << "calling ranged values method on tree1 (should be the same as the values print):" << endl;
    vector<string> searchVec6 = tree1.search("zebras", "ant");
    for (int i = 0; i < static_cast<int>(searchVec6.size()); i++) {
        cout << searchVec6[i] << endl;
    }
    cout << endl;
    
    RedBlackTree<string, string> tree2;
    tree2.insert("cat", "o");
    tree2.insert("bat", "p");
    tree2.insert("dog", "y");
    tree2.insert("frog", "x");
    tree2.insert("cow", "a");
    tree2.insert("monkey", "l");
    tree2.insert("zebra", "d");
    tree2.insert("horse", "g");
    tree2.insert("bird", "j");
    tree2.insert("flamingo", "x");
    tree2.insert("giraffe", "b");
    tree2.insert("pig", "n");
    cout << endl;
    cout << "printing tree2: " << endl;
 //   tree2.printTree();
    cout << "tree size = " << tree2.size() << endl;
    cout << "tree root = " << tree2.getRoot()->key << endl;
    cout << endl;
 //   cout << tree2.checkTree() << endl << endl;

    cout << "calling values method on tree2:" << endl;
    vector<string> vecValues2 = tree2.values();
    for (int i = 0; i < static_cast<int>(vecValues2.size()); i++) {
        cout << vecValues2[i] << endl;
    }
    cout << endl;

    cout << "calling keys method on tree2:" << endl;
    vector<string> vecKeys2 = tree2.keys();
    for (int i = 0; i < static_cast<int>(vecKeys2.size()); i++) {
        cout << vecKeys2[i] << endl;
    }
    cout << endl;
    
    cout << "remove monkey successful? (should be 1): " << tree2.remove("monkey") << endl;
    cout << "printing tree2: " << endl;
 //   tree2.printTree();
    cout << "tree size = " << tree2.size() << endl;
    cout << "tree root = " << tree2.getRoot()->key << endl;
    cout << endl;
 //   cout << tree2.checkTree() << endl << endl;

    cout << "remove frog successful? (should be 1): " << tree2.remove("frog") << endl;
    cout << "printing tree2: " << endl;
//    tree2.printTree();
    cout << "tree size = " << tree2.size() << endl;
    cout << "tree root = " << tree2.getRoot()->key << endl;
    cout << endl;
 //   cout << tree2.checkTree() << endl << endl;

    cout << "remove bird successful? (should be 1): " << tree2.remove("bird") << endl;
    cout << "printing tree2: " << endl;
 //   tree2.printTree();
    cout << "tree size = " << tree2.size() << endl;
    cout << "tree root = " << tree2.getRoot()->key << endl;
    cout << endl;
  //  cout << tree2.checkTree() << endl << endl;

    cout << "remove puma successful? (should be 0): " << tree2.remove("puma") << endl << endl;

    cout << "remove horse successful? (should be 1): " << tree2.remove("horse") << endl;
    cout << "printing tree2: " << endl;
 //   tree2.printTree();
    cout << "tree size = " << tree2.size() << endl;
    cout << "tree root = " << tree2.getRoot()->key << endl;
    cout << endl;
 //   cout << tree2.checkTree() << endl << endl;

    cout << "remove dog successful? (should be 1): " << tree2.remove("dog") << endl;
    cout << "printing tree2: " << endl;
//    tree2.printTree();
    cout << "tree size = " << tree2.size() << endl;
    cout << "tree root = " << tree2.getRoot()->key << endl;
    cout << endl;
//    cout << tree2.checkTree() << endl << endl;

    cout << "remove ant successful? (should be 0): " << tree2.remove("ant") << endl << endl;

    cout << "remove bat successful? (should be 1): " << tree2.remove("bat") << endl;
    cout << "printing tree2: " << endl;
// tree2.printTree();
    cout << "tree size = " << tree2.size() << endl;
    cout << "tree root = " << tree2.getRoot()->key << endl;
    cout << endl;
 //   cout << tree2.checkTree() << endl << endl;

    cout << "remove cat successful? (should be 1): " << tree2.remove("cat") << endl;
    cout << "printing tree2: " << endl;
  //  tree2.printTree();
    cout << "tree size = " << tree2.size() << endl;
    cout << "tree root = " << tree2.getRoot()->key << endl;
    cout << endl;
 //   cout << tree2.checkTree() << endl << endl;

    cout << "remove giraffe successful? (should be 1): " << tree2.remove("giraffe") << endl;
    cout << "printing tree2: " << endl;
 //   tree2.printTree();
    cout << "tree size = " << tree2.size() << endl;
    cout << "tree root = " << tree2.getRoot()->key << endl;
    cout << endl;
 //   cout << tree2.checkTree() << endl << endl;

    cout << "remove zebra successful? (should be 1): " << tree2.remove("zebra") << endl;
    cout << "printing tree2: " << endl;
//    tree2.printTree();
    cout << "tree size = " << tree2.size() << endl;
    cout << "tree root = " << tree2.getRoot()->key << endl;
    cout << endl;
 //   cout << tree2.checkTree() << endl << endl;

    cout << "remove pig successful? (should be 1): " << tree2.remove("pig") << endl;
    cout << "printing tree2: " << endl;
  //  tree2.printTree();
    cout << "tree size = " << tree2.size() << endl;
    cout << "tree root = " << tree2.getRoot()->key << endl;
    cout << endl;
//    cout << tree2.checkTree() << endl << endl;

    cout << "remove flamingo & cow successful? (should be 1 1): " << tree2.remove("flamingo") << " " << tree2.remove("cow") << endl;
    cout << "printing tree2: " << endl;
 //   tree2.printTree();
    cout << "tree size = " << tree2.size() << endl;
    cout << endl;
//    cout << tree2.checkTree() << endl << endl;

    tree2.insert("cat", "x");
    tree2.insert("dog", "h");
    tree2.insert("frog", "f");
    cout << "printing tree2: " << endl;
 //   tree2.printTree();
    cout << "tree root = " << tree2.getRoot()->key << endl;
    cout << "tree size = " << tree2.size() << endl;
    cout << endl;
 //   cout << tree2.checkTree() << endl << endl;
}

// -------------------- STR KEY & INT VALUE --------------------
void testStrIntCopies() {
    RedBlackTree<string, int> tree2;
    tree2.insert("cat", 64);
    tree2.insert("bat", 23);
    tree2.insert("dog", 90);
    tree2.insert("frog", 54);
    tree2.insert("cow", 7);
    cout << "printing tree2: " << endl;
 //   tree2.printTree();
    cout << "tree size = " << tree2.size() << endl;
    cout << "tree root = " << tree2.getRoot()->key << endl;
 //   cout << tree2.checkTree() << endl << endl;
    
    RedBlackTree<string, int> tree3 = tree2;
    cout << "printing tree3: " << endl;
 //   tree3.printTree();
    cout << "tree size = " << tree3.size() << endl;
    cout << "tree root = " << tree3.getRoot()->key << endl;
//    cout << tree3.checkTree() << endl << endl;
    
    tree3.insert("donkey", 8);
    tree3.remove("cat");
    tree3.remove("dog");
    cout << "printing tree3 after 1 insert and 2 removes: " << endl;
//    tree3.printTree();
    cout << "tree size = " << tree3.size() << endl;
    cout << "tree root = " << tree3.getRoot()->key << endl;
 //   cout << tree3.checkTree() << endl << endl;
    
    
    RedBlackTree<string, int> tree4(tree3);
    cout << "printing tree4: " << endl;
 //   tree4.printTree();
    cout << "tree size = " << tree4.size() << endl;
    cout << "tree root = " << tree4.getRoot()->key << endl;
 //   cout << tree4.checkTree() << endl << endl;
    
    tree4.remove("donkey");
    tree4.remove("frog");
    tree4.insert("horse", 4);
    cout << "printing tree4 after 1 insert and 2 removes: " << endl;
//    tree4.printTree();
    cout << "tree size = " << tree4.size() << endl;
    cout << "tree root = " << tree4.getRoot()->key << endl;
 //   cout << tree4.checkTree() << endl << endl;
    
    tree4.remove("cow");
    tree4.remove("horse");
    tree4.remove("bat");
    cout << "tree4 after removing all elements:" << endl;
    cout << "tree size = " << tree4.size() << endl << endl;
    
    RedBlackTree<string, int> tree5(tree4);
    cout << "tree5 size (should be 0) = " << tree5.size() << endl;
    tree5.insert("zebra", 6);
    tree5.insert("snake", 3);
    cout << "printing tree5: " << endl;
  //  tree5.printTree();
    tree5.remove("zebra");
    cout << "printing tree5 after removing zebra: " << endl;
//    tree5.printTree();
    cout << endl;
    
    RedBlackTree<string, int> tree6 = tree4;
    cout << "tree6 size (should be 0) = " << tree6.size() << endl;
    tree6.insert("zebra", 8);
    tree6.insert("snake", 31);
    cout << "printing tree6: " << endl;
 //   tree6.printTree();
    tree6.remove("snake");
    cout << "printing tree6 after removing snake: " << endl;
 //   tree6.printTree();
}

void testStrInt() {
    RedBlackTree<string, int> tree1;
    cout << "insert successful? (should be 1): " << tree1.insert("snake", 5) << endl;
    cout << "insert successful? (should be 0): " << tree1.insert("snake", 6) << endl;
    cout << "insert successful? (should be 1): " << tree1.insert("zebra", 76) << endl;
    cout << "insert successful? (should be 1): " << tree1.insert("pig", 58) << endl;
    cout << "insert successful? (should be 1): " << tree1.insert("donkey", 0) << endl;
    cout << "insert successful? (should be 1): " << tree1.insert("horse", 21) << endl;
    cout << "insert successful? (should be 1): " << tree1.insert("giraffe", 5) << endl;
    cout << "insert successful? (should be 1): " << tree1.insert("cheetah", 32) << endl;
    cout << "insert successful? (should be 0): " << tree1.insert("horse", 6) << endl;
    cout << "insert successful? (should be 1): " << tree1.insert("cow", 76) << endl;
    cout << "insert successful? (should be 1): " << tree1.insert("frog", 8) << endl;
    cout << "insert successful? (should be 1): " << tree1.insert("monkey", 4) << endl;
    cout << "insert successful? (should be 0): " << tree1.insert("monkey", 8) << endl;
    cout << "insert successful? (should be 1): " << tree1.insert("bird", 9) << endl;
    cout << "insert successful? (should be 1): " << tree1.insert("flamingo", 3) << endl;
    cout << endl;
    cout << "printing tree1: " << endl;
 //   tree1.printTree();
    cout << "tree size = " << tree1.size() << endl;
    cout << "tree root = " << tree1.getRoot()->key << endl;
    cout << endl;
//    cout << tree1.checkTree() << endl << endl;
    
    cout << "is puma in the tree? (should be 0): " << tree1.search("puma") << endl;
    cout << "is zebra in the tree? (should be 1): " << tree1.search("zebra") << endl;
    cout << "is snake in the tree? (should be 1): " << tree1.search("snake") << endl << endl;
    
    cout << "calling values method on tree1:" << endl;
    vector<int> vecValues = tree1.values();
    for (int i = 0; i < static_cast<int>(vecValues.size()); i++) {
        cout << vecValues[i] << endl;
    }
    cout << endl;

    cout << "calling keys method on tree1:" << endl;
    vector<string> vecKeys = tree1.keys();
    for (int i = 0; i < static_cast<int>(vecKeys.size()); i++) {
        cout << vecKeys[i] << endl;
    }
    cout << endl;

    cout << "calling ranged values method on tree1 (should have 7 values):" << endl;
    vector<int> searchVec1 = tree1.search("hog", "ant");
    for (int i = 0; i < static_cast<int>(searchVec1.size()); i++) {
        cout << searchVec1[i] << endl;
    }
    cout << endl;

    cout << "calling ranged values method on tree1 (should have 5 values):" << endl;
    vector<int> searchVec2 = tree1.search("horse", "zebrasssss");
    for (int i = 0; i < static_cast<int>(searchVec2.size()); i++) {
        cout << searchVec2[i] << endl;
    }
    cout << endl;

    cout << "calling ranged values method on tree1 (should be 1 thing):" << endl;
    vector<int> searchVec3 = tree1.search("frog", "frog");
    for (int i = 0; i < static_cast<int>(searchVec3.size()); i++) {
        cout << searchVec3[i] << endl;
    }
    cout << endl;

    cout << "calling ranged values method on tree1 (should be empty):" << endl;
    vector<int> searchVec4 = tree1.search("hog", "hog");
    for (int i = 0; i < static_cast<int>(searchVec4.size()); i++) {
        cout << searchVec4[i] << endl;
    }
    cout << endl;

    cout << "calling ranged values method on tree1 (should be empty):" << endl;
    vector<int> searchVec5 = tree1.search("zebras", "zebrasss");
    for (int i = 0; i < static_cast<int>(searchVec5.size()); i++) {
        cout << searchVec5[i] << endl;
    }
    cout << endl;

    cout << "calling ranged values method on tree1 (should be the same as the values print):" << endl;
    vector<int> searchVec6 = tree1.search("zebras", "ant");
    for (int i = 0; i < static_cast<int>(searchVec6.size()); i++) {
        cout << searchVec6[i] << endl;
    }
    cout << endl;
    
    RedBlackTree<string, int> tree2;
    tree2.insert("cat", 43);
    tree2.insert("bat", 5);
    tree2.insert("dog", 2);
    tree2.insert("frog", 54);
    tree2.insert("cow", 63);
    tree2.insert("monkey", 3);
    tree2.insert("zebra", 54);
    tree2.insert("horse", 23);
    tree2.insert("bird", 533);
    tree2.insert("flamingo", 66);
    tree2.insert("giraffe", 23);
    tree2.insert("pig", 5);
    cout << endl;
    cout << "printing tree2: " << endl;
 //   tree2.printTree();
    cout << "tree size = " << tree2.size() << endl;
    cout << "tree root = " << tree2.getRoot()->key << endl;
    cout << endl;
 //   cout << tree2.checkTree() << endl << endl;

    cout << "calling values method on tree2:" << endl;
    vector<int> vecValues2 = tree2.values();
    for (int i = 0; i < static_cast<int>(vecValues2.size()); i++) {
        cout << vecValues2[i] << endl;
    }
    cout << endl;

    cout << "calling keys method on tree2:" << endl;
    vector<string> vecKeys2 = tree2.keys();
    for (int i = 0; i < static_cast<int>(vecKeys2.size()); i++) {
        cout << vecKeys2[i] << endl;
    }
    cout << endl;
    
    cout << "remove monkey successful? (should be 1): " << tree2.remove("monkey") << endl;
    cout << "printing tree2: " << endl;
  //  tree2.printTree();
    cout << "tree size = " << tree2.size() << endl;
    cout << "tree root = " << tree2.getRoot()->key << endl;
    cout << endl;
 //   cout << tree2.checkTree() << endl << endl;

    cout << "remove frog successful? (should be 1): " << tree2.remove("frog") << endl;
    cout << "printing tree2: " << endl;
 //   tree2.printTree();
    cout << "tree size = " << tree2.size() << endl;
    cout << "tree root = " << tree2.getRoot()->key << endl;
    cout << endl;
 //   cout << tree2.checkTree() << endl << endl;

    cout << "remove bird successful? (should be 1): " << tree2.remove("bird") << endl;
    cout << "printing tree2: " << endl;
 //   tree2.printTree();
    cout << "tree size = " << tree2.size() << endl;
    cout << "tree root = " << tree2.getRoot()->key << endl;
    cout << endl;
//    cout << tree2.checkTree() << endl << endl;

    cout << "remove puma successful? (should be 0): " << tree2.remove("puma") << endl << endl;

    cout << "remove horse successful? (should be 1): " << tree2.remove("horse") << endl;
    cout << "printing tree2: " << endl;
//    tree2.printTree();
    cout << "tree size = " << tree2.size() << endl;
    cout << "tree root = " << tree2.getRoot()->key << endl;
    cout << endl;
 //   cout << tree2.checkTree() << endl << endl;

    cout << "remove dog successful? (should be 1): " << tree2.remove("dog") << endl;
    cout << "printing tree2: " << endl;
 //   tree2.printTree();
    cout << "tree size = " << tree2.size() << endl;
    cout << "tree root = " << tree2.getRoot()->key << endl;
    cout << endl;
 //   cout << tree2.checkTree() << endl << endl;

    cout << "remove ant successful? (should be 0): " << tree2.remove("ant") << endl << endl;

    cout << "remove bat successful? (should be 1): " << tree2.remove("bat") << endl;
    cout << "printing tree2: " << endl;
 //   tree2.printTree();
    cout << "tree size = " << tree2.size() << endl;
    cout << "tree root = " << tree2.getRoot()->key << endl;
    cout << endl;
//    cout << tree2.checkTree() << endl << endl;

    cout << "remove cat successful? (should be 1): " << tree2.remove("cat") << endl;
    cout << "printing tree2: " << endl;
  //  tree2.printTree();
    cout << "tree size = " << tree2.size() << endl;
    cout << "tree root = " << tree2.getRoot()->key << endl;
    cout << endl;
 //   cout << tree2.checkTree() << endl << endl;

    cout << "remove giraffe successful? (should be 1): " << tree2.remove("giraffe") << endl;
    cout << "printing tree2: " << endl;
 //   tree2.printTree();
    cout << "tree size = " << tree2.size() << endl;
    cout << "tree root = " << tree2.getRoot()->key << endl;
    cout << endl;
  //  cout << tree2.checkTree() << endl << endl;

    cout << "remove zebra successful? (should be 1): " << tree2.remove("zebra") << endl;
    cout << "printing tree2: " << endl;
 //   tree2.printTree();
    cout << "tree size = " << tree2.size() << endl;
    cout << "tree root = " << tree2.getRoot()->key << endl;
    cout << endl;
 //   cout << tree2.checkTree() << endl << endl;

    cout << "remove pig successful? (should be 1): " << tree2.remove("pig") << endl;
    cout << "printing tree2: " << endl;
 //   tree2.printTree();
    cout << "tree size = " << tree2.size() << endl;
    cout << "tree root = " << tree2.getRoot()->key << endl;
    cout << endl;
 //   cout << tree2.checkTree() << endl << endl;

    cout << "remove flamingo & cow successful? (should be 1 1): " << tree2.remove("flamingo") << " " << tree2.remove("cow") << endl;
    cout << "printing tree2: " << endl;
 //   tree2.printTree();
    cout << "tree size = " << tree2.size() << endl;
    cout << endl;
 //   cout << tree2.checkTree() << endl << endl;

    tree2.insert("cat", 21);
    tree2.insert("dog",4);
    tree2.insert("frog", 6);
    cout << "printing tree2: " << endl;
 //   tree2.printTree();
    cout << "tree root = " << tree2.getRoot()->key << endl;
    cout << "tree size = " << tree2.size() << endl;
    cout << endl;
 //   cout << tree2.checkTree() << endl << endl;
}

// -------------------- INT KEY & STR VALUE --------------------
void testIntStrCopies() {
    RedBlackTree<int, string> tree2;
    tree2.insert(14, "l");
    tree2.insert(7, "p");
    tree2.insert(4, "gf");
    tree2.insert(18, "tr");
    tree2.insert(32, "ree");
    cout << "printing tree2: " << endl;
 //   tree2.printTree();
    cout << "tree size = " << tree2.size() << endl;
    cout << "tree root = " << tree2.getRoot()->key << endl;
//    cout << tree2.checkTree() << endl << endl;
    
    RedBlackTree<int, string> tree3 = tree2;
    cout << "printing tree3: " << endl;
 //   tree3.printTree();
    cout << "tree size = " << tree3.size() << endl;
    cout << "tree root = " << tree3.getRoot()->key << endl;
//    cout << tree3.checkTree() << endl << endl;
    
    tree3.insert(19, "uii");
    tree3.remove(7);
    tree3.remove(32);
    cout << "printing tree3 after 1 insert and 2 removes: " << endl;
 //   tree3.printTree();
    cout << "tree size = " << tree3.size() << endl;
    cout << "tree root = " << tree3.getRoot()->key << endl;
 //   cout << tree3.checkTree() << endl << endl;
    
    
    RedBlackTree<int, string> tree4(tree3);
    cout << "printing tree4: " << endl;
//    tree4.printTree();
    cout << "tree size = " << tree4.size() << endl;
    cout << "tree root = " << tree4.getRoot()->key << endl;
//    cout << tree4.checkTree() << endl << endl;
    
    tree4.remove(14);
    tree4.remove(19);
    tree4.insert(11, "op");
    cout << "printing tree4 after 1 insert and 2 removes: " << endl;
 //   tree4.printTree();
    cout << "tree size = " << tree4.size() << endl;
    cout << "tree root = " << tree4.getRoot()->key << endl;
  //  cout << tree4.checkTree() << endl << endl;
    
    tree4.remove(18);
    tree4.remove(4);
    tree4.remove(11);
    cout << "tree4 after removing all elements:" << endl;
    cout << "tree size = " << tree4.size() << endl << endl;
    
    RedBlackTree<int, string> tree5(tree4);
    cout << "tree5 size (should be 0) = " << tree5.size() << endl;
    tree5.insert(8, "il");
    tree5.insert(1, "mnmb");
    cout << "printing tree5: " << endl;
 //   tree5.printTree();
    tree5.remove(8);
    cout << "printing tree5 after removing 8: " << endl;
 //   tree5.printTree();
    cout << endl;
    
    RedBlackTree<int, string> tree6 = tree4;
    cout << "tree6 size (should be 0) = " << tree6.size() << endl;
    tree6.insert(8, "yey");
    tree6.insert(1, "pll");
    cout << "printing tree6: " << endl;
  //  tree6.printTree();
    tree6.remove(8);
    cout << "printing tree6 after removing 8: " << endl;
 //   tree6.printTree();
}

void testIntStr() {
    cout << "TESTING INT KEY & STR VALUE:" << endl << endl;
    
    RedBlackTree<int, string> tree1;
    cout << "insert successful? (should be 1): " << tree1.insert(4, "ul") << endl;
    cout << "insert successful? (should be 0): " << tree1.insert(4, "gf") << endl;
    cout << "insert successful? (should be 1): " << tree1.insert(7, "ew") << endl;
    cout << "insert successful? (should be 1): " << tree1.insert(12, "gr") << endl;
    cout << "insert successful? (should be 1): " << tree1.insert(15, "ilo") << endl;
    cout << "insert successful? (should be 1): " << tree1.insert(3, "sfs") << endl;
    cout << "insert successful? (should be 1): " << tree1.insert(5, "srwe") << endl;
    cout << "insert successful? (should be 1): " << tree1.insert(14, "f") << endl;
    cout << "insert successful? (should be 0): " << tree1.insert(12, "asad") << endl;
    cout << "insert successful? (should be 1): " << tree1.insert(18, "re") << endl;
    cout << "insert successful? (should be 1): " << tree1.insert(16, "gfd") << endl;
    cout << "insert successful? (should be 1): " << tree1.insert(17, "re") << endl;
    cout << "insert successful? (should be 0): " << tree1.insert(7, "Gdc") << endl;
    cout << "insert successful? (should be 1): " << tree1.insert(9, "dc") << endl;
    cout << "insert successful? (should be 1): " << tree1.insert(2, "gew") << endl;
    cout << endl;
    cout << "printing tree1: " << endl;
 //   tree1.printTree();
    cout << "tree size = " << tree1.size() << endl;
    cout << "tree root = " << tree1.getRoot()->key << endl;
    cout << endl;
 //   cout << tree1.checkTree() << endl << endl;
    
    cout << "is 31 in the tree? (should be 0): " << tree1.search(31) << endl;
    cout << "is 4 in the tree? (should be 1): " << tree1.search(4) << endl;
    cout << "is 18 in the tree? (should be 1): " << tree1.search(18) << endl << endl;
    
    cout << "calling values method on tree1:" << endl;
    vector<string> vecValues = tree1.values();
    for (int i = 0; i < static_cast<int>(vecValues.size()); i++) {
        cout << vecValues[i] << endl;
    }
    cout << endl;

    cout << "calling keys method on tree1:" << endl;
    vector<int> vecKeys = tree1.keys();
    for (int i = 0; i < static_cast<int>(vecKeys.size()); i++) {
        cout << vecKeys[i] << endl;
    }
    cout << endl;
    
    cout << "calling ranged values method on tree1 (should have 7 values):" << endl;
    vector<string> searchVec1 = tree1.search(13, -3);
    for (int i = 0; i < static_cast<int>(searchVec1.size()); i++) {
        cout << searchVec1[i] << endl;
    }
    cout << endl;
    
    cout << "calling ranged values method on tree1 (should have 5 values):" << endl;
    vector<string> searchVec2 = tree1.search(14, 20);
    for (int i = 0; i < static_cast<int>(searchVec2.size()); i++) {
        cout << searchVec2[i] << endl;
    }
    cout << endl;
    
    cout << "calling ranged values method on tree1 (should be 1 thing):" << endl;
    vector<string> searchVec3 = tree1.search(9, 9);
    for (int i = 0; i < static_cast<int>(searchVec3.size()); i++) {
        cout << searchVec3[i] << endl;
    }
    cout << endl;

    cout << "calling ranged values method on tree1 (should be empty):" << endl;
    vector<string> searchVec4 = tree1.search(10, 10);
    for (int i = 0; i < static_cast<int>(searchVec4.size()); i++) {
        cout << searchVec4[i] << endl;
    }
    cout << endl;

    cout << "calling ranged values method on tree1 (should be empty):" << endl;
    vector<string> searchVec5 = tree1.search(20, 24);
    for (int i = 0; i < static_cast<int>(searchVec5.size()); i++) {
        cout << searchVec5[i] << endl;
    }
    cout << endl;
    
    cout << "calling ranged values method on tree1 (should be the same as the values print):" << endl;
    vector<string> searchVec6 = tree1.search(24, -2);
    for (int i = 0; i < static_cast<int>(searchVec6.size()); i++) {
        cout << searchVec6[i] << endl;
    }
    cout << endl;
    
    RedBlackTree<int, string> tree2;
    tree2.insert(14, "fs");
    tree2.insert(7, "QEr");
    tree2.insert(21, "GFd");
    tree2.insert(4, "fbr");
    tree2.insert(18, "hh");
    tree2.insert(32, "sd");
    tree2.insert(26, "g");
    tree2.insert(2, "tre");
    tree2.insert(11, "Gd");
    tree2.insert(17, "bg");
    tree2.insert(34, "ss");
    tree2.insert(23, "GTe");
    cout << endl;
    cout << "printing tree2: " << endl;
 //   tree2.printTree();
    cout << "tree size = " << tree2.size() << endl;
    cout << "tree root = " << tree2.getRoot()->key << endl;
    cout << endl;
 //   cout << tree2.checkTree() << endl << endl;

    cout << "calling values method on tree2:" << endl;
    vector<string> vecValues2 = tree2.values();
    for (int i = 0; i < static_cast<int>(vecValues2.size()); i++) {
        cout << vecValues2[i] << endl;
    }
    cout << endl;

    cout << "calling keys method on tree2:" << endl;
    vector<int> vecKeys2 = tree2.keys();
    for (int i = 0; i < static_cast<int>(vecKeys2.size()); i++) {
        cout << vecKeys2[i] << endl;
    }
    cout << endl;
    
    cout << "remove 32 successful? (should be 1): " << tree2.remove(32) << endl;
    cout << "printing tree2: " << endl;
 //   tree2.printTree();
    cout << "tree size = " << tree2.size() << endl;
    cout << "tree root = " << tree2.getRoot()->key << endl;
    cout << endl;
  //  cout << tree2.checkTree() << endl << endl;

    cout << "remove 23 successful? (should be 1): " << tree2.remove(23) << endl;
    cout << "printing tree2: " << endl;
 //   tree2.printTree();
    cout << "tree size = " << tree2.size() << endl;
    cout << "tree root = " << tree2.getRoot()->key << endl;
    cout << endl;
  //  cout << tree2.checkTree() << endl << endl;

    cout << "remove 11 successful? (should be 1): " << tree2.remove(11) << endl;
    cout << "printing tree2: " << endl;
  //  tree2.printTree();
    cout << "tree size = " << tree2.size() << endl;
    cout << "tree root = " << tree2.getRoot()->key << endl;
    cout << endl;
 //   cout << tree2.checkTree() << endl << endl;
    
    cout << "remove 9 successful? (should be 0): " << tree2.remove(9) << endl << endl;

    cout << "remove 21 successful? (should be 1): " << tree2.remove(21) << endl;
    cout << "printing tree2: " << endl;
//  tree2.printTree();
    cout << "tree size = " << tree2.size() << endl;
    cout << "tree root = " << tree2.getRoot()->key << endl;
    cout << endl;
  //  cout << tree2.checkTree() << endl << endl;
    
    cout << "remove 14 successful? (should be 1): " << tree2.remove(14) << endl;
    cout << "printing tree2: " << endl;
 //   tree2.printTree();
    cout << "tree size = " << tree2.size() << endl;
    cout << "tree root = " << tree2.getRoot()->key << endl;
    cout << endl;
 //   cout << tree2.checkTree() << endl << endl;
    
    cout << "remove 11 successful? (should be 0): " << tree2.remove(11) << endl << endl;
    
    cout << "remove 2 successful? (should be 1): " << tree2.remove(2) << endl;
    cout << "printing tree2: " << endl;
//    tree2.printTree();
    cout << "tree size = " << tree2.size() << endl;
    cout << "tree root = " << tree2.getRoot()->key << endl;
    cout << endl;
 //   cout << tree2.checkTree() << endl << endl;
    
    cout << "remove 4 successful? (should be 1): " << tree2.remove(4) << endl;
    cout << "printing tree2: " << endl;
//    tree2.printTree();
    cout << "tree size = " << tree2.size() << endl;
    cout << "tree root = " << tree2.getRoot()->key << endl;
    cout << endl;
//    cout << tree2.checkTree() << endl << endl;
    
    cout << "remove 18 successful? (should be 1): " << tree2.remove(18) << endl;
    cout << "printing tree2: " << endl;
 //   tree2.printTree();
    cout << "tree size = " << tree2.size() << endl;
    cout << "tree root = " << tree2.getRoot()->key << endl;
    cout << endl;
   // cout << tree2.checkTree() << endl << endl;
    
    cout << "remove 7 successful? (should be 1): " << tree2.remove(7) << endl;
    cout << "printing tree2: " << endl;
 //   tree2.printTree();
    cout << "tree size = " << tree2.size() << endl;
    cout << "tree root = " << tree2.getRoot()->key << endl;
    cout << endl;
//    cout << tree2.checkTree() << endl << endl;
    
    cout << "remove 26 successful? (should be 1): " << tree2.remove(26) << endl;
    cout << "printing tree2: " << endl;
 //   tree2.printTree();
    cout << "tree size = " << tree2.size() << endl;
    cout << "tree root = " << tree2.getRoot()->key << endl;
    cout << endl;
  //  cout << tree2.checkTree() << endl << endl;
    
    cout << "remove 17 & 34 successful? (should be 1 1): " << tree2.remove(17) << " " << tree2.remove(34) << endl;
    cout << "printing tree2: " << endl;
 //   tree2.printTree();
    cout << "tree size = " << tree2.size() << endl;
    cout << endl;
 //   cout << tree2.checkTree() << endl << endl;
    
    tree2.insert(32, "pll");
    tree2.insert(26, "qw");
    tree2.insert(2, "fsv");
    cout << "printing tree2: " << endl;
 //   tree2.printTree();
    cout << "tree root = " << tree2.getRoot()->key << endl;
    cout << "tree size = " << tree2.size() << endl;
    cout << endl;
  //  cout << tree2.checkTree() << endl << endl;
}

int main() {

    testIntIntCopies();
    testIntInt();
    
    testStrStrCopies();
    testStrStr();
    
    testStrIntCopies();
    testStrInt();

    testIntStrCopies();
    testIntStr();
}
