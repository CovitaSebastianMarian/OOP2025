#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include "Tree.h"



template<typename T>
bool compare(T a, T b) {
	return a > b;
}

template<typename T>
bool compare2(T a) {
	return a == 4;
}

int main() {
	Tree<int> tree;
	tree.add_node(nullptr, 5);
	tree.add_node(tree.node, 10);
	tree.add_node(tree.node, 6);
	tree.add_node(tree.node, 12);
	tree.add_node(tree.node, 4);
	tree.add_node(tree.node->v[2], 2);
	tree.add_node(tree.node->v[2], 3);
	tree.add_node(tree.node->v[2], 1);

	auto x = tree.find(compare2<int>, nullptr);
	std::cout << x->info << "\n";
	tree.insert(tree.node->v[2], 1, 7);
	std::cout << tree.count(nullptr) << "\n";

	tree.delete_node(tree.node->v[2]);


	std::cout << tree.node->info << "\n";
	for (int i = 0; i < tree.node->size; ++i) {
		if (tree.node->v[i] == nullptr) {
			continue;
		}
		std::cout << tree.node->v[i]->info << ": ";
		for (int j = 0; j < tree.node->v[i]->size; ++j) {
			std::cout << tree.node->v[i]->v[j]->info << " ";
		}
		std::cout << "\n";
	}

    return 0;
}