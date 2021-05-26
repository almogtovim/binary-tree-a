#include "doctest.h"
#include "sources/BinaryTree.hpp"
using namespace std;
using namespace ariel;
const int LOOP=20;



TEST_CASE("add_root test"){
    BinaryTree<int> inTree;
    inTree.add_root(1);
    for (int i = 0; i < LOOP; i++) {
        CHECK_NOTHROW(inTree.add_root(i));
        CHECK_EQ(i, *inTree.begin_preorder());
    }

    CHECK_NOTHROW(inTree.add_root(1).add_root(2).add_root(3));
    BinaryTree<char> charTree;
    charTree.add_root('1');
    for (int i = 0; i < LOOP; i++) {
        CHECK_NOTHROW(charTree.add_root((char)i));
        CHECK_EQ((char)i, *inTree.begin_preorder());
    }
    CHECK_NOTHROW(charTree.add_root('1').add_root('2').add_root('3'));
}

TEST_CASE("add_left child"){
    BinaryTree<int> tree;
    CHECK_THROWS(tree.add_left(8,4));
    tree.add_root(0);
    string str = "0";
    for (int i=0; i < LOOP; i++){
        str += to_string(i+1);
        CHECK_NOTHROW(tree.add_left(i,(i+1)));
    }
    string rev = string(str.rbegin(),str.rend());
    cout << str;
    string it_inorder= "";
    for(auto it= tree.begin_inorder(); it!=tree.end_inorder(); ++it) {
        it_inorder += to_string(*it);
    }
    CHECK_EQ(it_inorder, str);
    BinaryTree<char> cTree;
    CHECK_THROWS(cTree.add_left('1','2'));
    tree.add_root('0');
    CHECK_NOTHROW(tree.add_left('0','1').add_left('1','2').add_left('2','3'));
    it_inorder= "";
    for(auto it= tree.begin_inorder(); it!=tree.end_inorder(); ++it){
        it_inorder+=*it;
    }
    CHECK_EQ(it_inorder, "3210");
}

TEST_CASE("add_right child"){
    BinaryTree<int> t;
}