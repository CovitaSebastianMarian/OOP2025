#pragma once

template<typename T>
class Node {
public:
	T info;
	Node<T>** v;
	unsigned long long size;
	Node(T x) : v(nullptr), size(0), info(x) {}
	~Node() {
		for (int i = 0; i < size; ++i) {
			delete v[i];
		}
		delete[] v;
		size = 0;
	}
};


template<class T>
class Tree
{
public:
	Node<T>* node;

	Tree();
	void add_node(Node<T>* p, T value);
	Node<T>* get_node(Node<T>* p, int index);
	void delete_node(Node<T>*&p);
	template<typename Func>
	Node<T>* find(Func&& func, Node<T>*p = nullptr);
	void insert(Node<T>* p, unsigned long long index, T value);
	template<typename Func>
	void sort(Func&& func, Node<T>*p = nullptr);
	unsigned long long count(Node<T>* p);
};



template<class T>
inline Tree<T>::Tree()
{
	node = nullptr;
}

template<class T>
inline void Tree<T>::add_node(Node<T>* p, T value)
{
	if (!p) {
		node = new Node<T>(value);
		return;
	}


	for (int i = 0; i < p->size; ++i) {
		if (p->v[i] == nullptr) {
			p->v[i] = new Node<T>(value);
			return;
		}
	}

	Node<T>** w = new Node<T>*[p->size + 1];
	for (int i = 0; i < p->size; ++i) {
		w[i] = p->v[i];
	}
	w[p->size] = new Node<T>(value);
	delete[] p->v;
	p->v = w;
	p->size += 1;
}

template<class T>
inline Node<T>* Tree<T>::get_node(Node<T>* p, int index)
{
	if (p == nullptr) {
		return node;
	}
	else {
		if (index < p->size) {
			return p->v[index];
		}
		else {
			return nullptr;
		}
	}
}

template<class T>
void Tree<T>::delete_node(Node<T>*& p) {
	if (p == nullptr) {
		return;
	}
	else {
		delete p;
		p = nullptr;
	}
}

template<class T>
template<typename Func>
inline Node<T>* Tree<T>::find(Func&& func, Node<T>* p)
{
	if (p == nullptr) {
		return this->find(func, node);
	}

	if (func(p->info)) {
		return p;
	}
	else {
		for (int i = 0; i < p->size; ++i) {
			if (p->v[i] != nullptr) {
				Node<T>* result = this->find(func, p->v[i]);
				if (result != nullptr) {
					return result;
				}
			}
		}
		return nullptr;
	}
}


template<class T>
void Tree<T>::insert(Node<T>* p, unsigned long long index, T value)
{
	if (p == nullptr) {
		return;
	}

	if (index <= p->size) {
		Node<T>** w = new Node<T>*[p->size + 1];
		for (int i = 0; i < index; ++i) {
			w[i] = p->v[i];
		}
		for (int i = index; i < p->size; ++i) {
			w[i + 1] = p->v[i];
		}
		w[index] = new Node<T>(value);
		delete[] p->v;
		p->v = w;
		p->size += 1;
	}
	else {
		Node<T>** w = new Node<T>*[index + 1];
		for (int i = 0; i < p->size; ++i) {
			w[i] = p->v[i];
		}
		for (int i = p->size; i < index; ++i) {
			w[i] = nullptr;
		}
		w[index] = new Node<T>(value);
		delete[] p->v;
		p->v = w;
		p->size = index + 1;
	}
}

template<class T>
template<typename Func>
inline void Tree<T>::sort(Func&& func, Node<T>* p)
{
	if (p == nullptr) {
		this->sort(func, node);
		return;
	}

	for (int i = 0; i < p->size; ++i) {
		for (int j = i + 1; j < p->size; ++j) {
			if (p->v[i] != nullptr && p->v[j] != nullptr) {
				if (func == nullptr) {
					if (p->v[i]->info > p->v[j]->info) {
						Node<T>* temp = p->v[j];
						p->v[j] = p->v[i];
						p->v[i] = temp;
					}
				}
				else if (func(p->v[i]->info, p->v[j]->info)) {
					Node<T>* temp = p->v[j];
					p->v[j] = p->v[i];
					p->v[i] = temp;
				}
			}
		}
	}

	for (int i = 0; i < p->size; ++i) {
		if (p->v[i] != nullptr) {
			this->sort(func, p->v[i]);
		}
	}
}

template<class T>
unsigned long long Tree<T>::count(Node<T>* p)
{
	unsigned long long cnt = 0;
	if (!p) {
		return 1 + this->count(node);
	}

	for (int i = 0; i < p->size; ++i) {
		if (p->v[i] != nullptr) {
			cnt += 1 + this->count(p->v[i]);
		}
	}
	return cnt;
}