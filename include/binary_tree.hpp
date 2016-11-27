#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <cstdio>
#include <iostream>

template<typename T>
class BinaryTree;

template<typename T>
class Node;

// class that descibes a node in the tree
template<typename T>
class Node {
    friend BinaryTree<T>;
public:
    // create an empty node with no next and only adding the item
    Node(const T& it) : item(it), next_left(NULL), next_right(NULL) {}

    // create a new node with next nodes
    Node(const T& it, Node<T>* n_left, Node<T> n_right)
        : item(it), next_left(n_left), next_right(n_right) {}

    // nothing needed in destructor
    ~Node() {
        std::cout << "This is the Node destructor" << std::endl;
    }

    // overloading the operators for ease of use
    friend bool operator==(const Node<T>& n1, const Node<T>& n2) {
        return n1.item == n2.item;
    }

    friend bool operator!=(const Node<T>& n1, const Node<T>& n2) {
        return !(n1 == n2);
    }

    friend bool operator<(const Node<T>& n1, const Node<T>& n2) {
        return n1.item < n2.item;
    }

    friend bool operator>(const Node<T>& n1, const Node<T>& n2) {
        return n1.item > n2.item;
    }

    friend bool operator<=(const Node<T>& n1, const Node<T>& n2) {
        return !(n1.item > n2.item);
    }

    friend bool operator>=(const Node<T>& n1, const Node<T>& n2) {
        return !(n1.item < n2.item);
    }

    friend std::ostream& operator<<(std::ostream& out, const Node<T>& n) {
        out << n.item;
        return out;
    }

    // return information of the values from the node
    T get_item() {
        return item;
    }

    Node<T>* get_next_left() {
        return next_left;
    }

    Node<T>* get_next_right() {
        return next_right;
    }

    unsigned int get_height() {
        return height;
    }

    unsigned int get_depth() {
        return depth;
    }

    signed int get_bf() {
        return bf;
    }
protected:
    void set_item(T it) {
        item = it;
    }

    void set_next_left(Node<T> n_left) {
        next_left = n_left;
    }

    void set_next_right(Node<T>* n_right) {
        next_right = n_right;
    }

    void set_next(Node<T>* n_left, Node<T>* n_right) {
        set_next_left(n_left);
        set_next_right(n_right);
    }
private:
    // item stored in the tree
    T item;
    // pointers to the next elements in the tree
    Node<T> *next_left, *next_right;

    // distance from node to leaf
    unsigned int height;
    // distance from node to root
    unsigned int depth;
    // height of the right subtree - height of the left subtree
    signed int bf;
};

// tree of all the nodes
template<typename T>
class BinaryTree {
    typedef Node<T>* node_ptr;
public:
    // empty tree node which will then be created when adding elements
    BinaryTree() : root_node(NULL), tree_height(0) {}
    ~BinaryTree() {
        std::cout << "This is the Binary Tree destructor" << std::endl;
        delete_nodes(root_node);
    }

    // adds an element to the tree
    void push_back(const T& element) {
        // create new node with element
        node_ptr new_node = new Node<T>(element);

        if(root_node == NULL) {
            root_node = new_node;
        } else {
            // make current node
            node_ptr curr_node = root_node;
            bool found = false;

            // go to node that has to be added
            while(!found) {
                if(*new_node < *curr_node) {
                    if(curr_node->next_left != NULL) {
                        curr_node = curr_node->next_left;
                    } else {
                        found = true;
                        curr_node->next_left = new_node;
                    }
                } else {
                    if(curr_node->next_right != NULL) {
                        curr_node = curr_node->next_right;
                    } else {
                        found = true;
                        curr_node->next_right = new_node;
                    }
                }
            }
        }
    }

    void delete_nodes(node_ptr node) {
        if(node != NULL) {
            this->delete_nodes(node->next_left);
            this->delete_nodes(node->next_right);
            std::cout << "deleting node: " << *node << std::endl;
            delete node;
        }
    }

    void print_tree() {
        print_tree(root_node);
    }

    void print_tree(node_ptr node) {
        if(node != NULL) {
            print_tree(node->next_left);
            std::cout << *node << std::endl;
            print_tree(node->next_right);
        }
    }

    Node<T> get_root() {
        return *root_node;
    }
private:
    // root of the tree
    node_ptr root_node;
    // height of the whole tree
    unsigned int tree_height;
};

#endif
