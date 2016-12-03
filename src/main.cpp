#include "binary_tree.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char *argv[]) {
	srand(time(NULL));
	BinaryTree<int> int_bt;
	BinaryTree<double> double_bt;
	BinaryTree<char> char_bt;

	for(unsigned int i = 0; i < 1000; ++i) {
		int_bt.push_back(rand() % 0xFFFFFFFF);
		double_bt.push_back((double)(rand() % 0xFFFFFFFF) / (double)(rand() % 0xFFFFFFFF));
		char_bt.push_back(rand() % 94 + 33);
	}

	int_bt.print_tree();
	double_bt.print_tree();
	char_bt.print_tree();

	return 0;
}
