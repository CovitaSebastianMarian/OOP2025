#pragma once

template<class K, class V>
struct triplu {
	K key;
	V value;
	unsigned int index;
};

template<class K, class V>
class Map
{
private:
	triplu<K, V>* v;
	unsigned int size;
public:
	Map();
	~Map();
	V& operator [] (const K key);

	class Iterator {
	private:
		triplu<K, V>* v;
	public:
		Iterator(triplu<K, V>* a);
		triplu<K, V>& operator*();
		Iterator& operator++();
		bool operator!=(const Iterator& a);
	};

	Iterator begin();
	Iterator end();

	void Set(K key, V value);
	bool Get(const K& key, V& value) const;
	unsigned int Count() const;
	void Clear();
	bool Delete(const K& key);
	bool Includes(const Map<K, V>& map);
};

template<class K, class V>
inline Map<K, V>::Map()
{
	v = nullptr;
	size = 0;
}

template<class K, class V>
inline Map<K, V>::~Map()
{
	delete[] v;
	v = nullptr;
	size = 0;
}

template<class K, class V>
inline V& Map<K, V>::operator[](const K key)
{
	for (int i = 0; i < size; ++i) {
		if (v[i].key == key) {
			return v[i].value;
		}
	}
	triplu<K, V>* cpy = new triplu<K, V>[size + 1];
	for (int i = 0; i < size; ++i) {
		cpy[i] = v[i];
	}
	cpy[size].key = key;
	cpy[size].index = size;
	size++;
	delete[] v;
	v = cpy;
	return v[size - 1].value;
}

template<class K, class V>
inline Map<K, V>::Iterator Map<K, V>::begin()
{
	return Iterator(v);
}

template<class K, class V>
inline Map<K, V>::Iterator Map<K, V>::end()
{
	return Iterator(v + size);
}

template<class K, class V>
inline void Map<K, V>::Set(K key, V value)
{
	for (int i = 0; i < size; ++i) {
		if (v[i].key == key) {
			v[i].value = value;
			return;
		}
	}
	triplu<K, V>* cpy = new triplu<K, V>[size + 1];
	for (int i = 0; i < size; ++i) {
		cpy[i] = v[i];
	}
	cpy[size].key = key;
	cpy[size].index = size;
	size++;
	delete[] v;
	v = cpy;
	v[size - 1].value = value;
}

template<class K, class V>
inline bool Map<K, V>::Get(const K& key, V& value) const
{
	for (int i = 0; i < size; ++i) {
		if (v[i].key == key) {
			value = v[i].value;
			return true;
		}
	}
	return false;
}

template<class K, class V>
inline unsigned int Map<K, V>::Count() const
{
	return size;
}

template<class K, class V>
inline void Map<K, V>::Clear()
{
	delete[] v;
	v = nullptr;
	size = 0;
}

template<class K, class V>
inline bool Map<K, V>::Delete(const K& key)
{
	triplu<K, V>* cpy = new triplu<K, V>[size - 1];
	unsigned int cnt = 0;
	bool ok = false;
	for (int i = 0; i < size; ++i) {
		if (v[i].key != key) {
			cpy[cnt] = v[i];
			cpy[cnt].index = cnt;
			cnt++;
			ok = true;
		}
	}
	if (ok) {
		delete[] v;
		size--;
		v = cpy;
	}
	else {
		delete[] cpy;
	}
	return ok;
}

template<class K, class V>
inline bool Map<K, V>::Includes(const Map<K, V>& map)
{
	int nr = 0;
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < map.size; ++j) {
			if (v[i] == map.v[i]) {
				nr++;
			}
		}
	}
	return (nr == map.size);
}

template<class K, class V>
inline Map<K, V>::Iterator::Iterator(triplu<K, V>* a)
{
	v = a;
}

template<class K, class V>
inline triplu<K, V>& Map<K, V>::Iterator::operator*()
{
	return *v;
}

template<class K, class V>
inline Map<K, V>::Iterator& Map<K, V>::Iterator::operator++()
{
	++v;
	return *this;
}

template<class K, class V>
inline bool Map<K, V>::Iterator::operator!=(const Iterator& a)
{
	return a.v != v;
}
