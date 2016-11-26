#include "binary_tree.hpp"

#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    BinaryTree<int> int_bt;
    int_bt.push_back(20);
    Node<int> node(int_bt.get_root());

    cout << "root node int: " << node.get_item() << endl;
    return 0;
}
