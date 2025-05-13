#pragma once



class Compare
{
public:
    virtual int CompareElements(void* e1, void* e2) = 0;
};

class crescator : public Compare {
public:
    virtual int CompareElements(void* e1, void* e2) {
        int a = *reinterpret_cast<int*>(e1);
        int b = *reinterpret_cast<int*>(e2);
        if (a == b) return 0;
        if (a < b) return -1;
        if (a > b) return 1;
    }
};

template<class T>
class ArrayIterator
{
private:
    int Current;
    T** List;
    int Size;
public:
    ArrayIterator(T** a, int size, int index);
    ~ArrayIterator() {
		Current = 0;
		Size = 0;
		List = nullptr;
    }
    ArrayIterator& operator ++ ();
    ArrayIterator& operator -- ();
    bool operator== (const ArrayIterator<T>&) const;
    bool operator!=(const ArrayIterator<T>&) const;
    T* GetElement();
};


template<class T>
class Array
{
private:
    T** List; // lista cu pointeri la obiecte de tipul T*
    int Capacity; // dimensiunea listei de pointeri
    int Size; // cate elemente sunt in lista
public:
    Array(); // Lista nu e alocata, Capacity si Size = 0
    ~Array(); // destructor
    Array(int capacity); // Lista e alocata cu 'capacity' elemente
    Array(const Array<T>& otherArray); // constructor de copiere

    T& operator[] (int index); // arunca exceptie daca index este out of range

    const Array<T>& operator+=(const T& newElem); // adauga un element de tipul T la sfarsitul listei si returneaza this
    const Array<T>& Insert(int index, const T& newElem); // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
    const Array<T>& Insert(int index, const Array<T> otherArray); // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
    const Array<T>& Delete(int index); // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie

    bool operator==(const Array<T>& otherArray) const;

    void Sort(); // sorteaza folosind comparatia intre elementele din T
    void Sort(int(*compare)(const T&, const T&)); // sorteaza folosind o functie de comparatie
    void Sort(Compare* comparator); // sorteaza folosind un obiect de comparatie

    // functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
    int BinarySearch(const T& elem); // cauta un element folosind binary search in Array
    int BinarySearch(const T& elem, int(*compare)(const T&, const T&));//  cauta un element folosind binary search si o functie de comparatie
    int BinarySearch(const T& elem, Compare* comparator);//  cauta un element folosind binary search si un comparator

    int Find(const T& elem); // cauta un element in Array
    int Find(const T& elem, int(*compare)(const T&, const T&));//  cauta un element folosind o functie de comparatie
    int Find(const T& elem, Compare* comparator);//  cauta un element folosind un comparator

    int GetSize();
    int GetCapacity();

    ArrayIterator<T> GetBeginIterator();
    ArrayIterator<T> GetEndIterator();
};

template<class T>
inline Array<T>::Array()
{
    List = nullptr;
    Capacity = 0;
    Size = 0;
}

template<class T>
inline Array<T>::~Array()
{
    for (int i = 0; i < Capacity; ++i) {
        delete List[i];
    }
    delete[] List;
    Capacity = 0;
    Size = 0;
}

template<class T>
inline Array<T>::Array(int capacity)
{
    Capacity = capacity;
    List = new T * [capacity];
    Size = 0;
	for (int i = 0; i < Capacity; ++i) {
		List[i] = nullptr;
	}
}

template<class T>
inline Array<T>::Array(const Array<T>& otherArray)
{
    Size = otherArray.Size;
    Capacity = otherArray.Capacity;
    List = new T*[Capacity];
    for (int i = 0; i < Size; ++i) {
        List[i] = new T;
		*List[i] = *otherArray.List[i];
    }
	for (int i = Size; i < Capacity; ++i) {
		List[i] = nullptr;
	}
}


class exceptie1 : public exception {
    virtual const char* what() const throw() {
        return "Indexul e mai mare decat size\n";
    }
};

template<class T>
inline T& Array<T>::operator[](int index)
{
    if (index < Size) {
        return *List[index];
    }
    else {
        throw exceptie1();
    }
}

class exceptie2 : public exception {
    virtual const char* what() const throw() {
        return "Array-ul e plin\n";
    }
};

template<class T>
inline const Array<T>& Array<T>::operator+=(const T& newElem)
{
    if (Size + 1 > Capacity) {
        throw exceptie2();
    }
    List[Size] = new T(newElem);
    Size++;
    return *this;
}

class exceptie3 : public exception {
    virtual const char* what() const throw() {
        return "Indexul nu exista!\n";
    }
};

class exceptie4 : public exception {
    virtual const char* what() const throw() {
        return "Indexul nu poate sa fie negativ!\n";
    }
};

template<class T>
inline const Array<T>& Array<T>::Insert(int index, const T& newElem)
{
    if (index >= Size) {
        throw exceptie3();
    }
    if (Size + 1 > Capacity) {
        throw exceptie2();
    }
    if (index < 0) {
        throw exceptie4();
    }

    
    List[Size] = new T;
    for (int i = Size; i > index; --i) {
        *List[i] = *List[i - 1];
    }
	*List[index] = newElem;
    Size++;
    return *this;
}

template<class T>
inline const Array<T>& Array<T>::Insert(int index, const Array<T> otherArray)
{
    for (int i = 0; i < otherArray.Size; ++i) {
		Insert(index + i, *otherArray.List[i]);
    }
    return *this;
}

template<class T>
inline const Array<T>& Array<T>::Delete(int index)
{
    if (index >= Size) {
        throw exceptie3();
    }

    for (int i = index; i < Size - 1; ++i) {
        *List[i] = *List[i + 1];
    }
    Size--;
    delete List[Size];
	List[Size] = nullptr;

    return *this;
}

template<class T>
inline bool Array<T>::operator==(const Array<T>& otherArray) const
{
	if (Size != otherArray.Size) return false;
	for (int i = 0; i < Size; ++i) {
		if (*List[i] != *otherArray.List[i]) return false;
	}
	return true;
}

template<class T>
inline void Array<T>::Sort()
{
    bool ok = true;
    while (ok) {
        ok = false;
        for (int i = 0; i < Size - 1; ++i) {
            if (!(*List[i] < *List[i + 1])) {
                swap(*List[i], *List[i + 1]);
                ok = true;
            }
        }
    }
}

template<class T>
inline void Array<T>::Sort(int(*compare)(const T&, const T&))
{
    bool ok = true;
    while (ok) {
        ok = false;
        for (int i = 0; i < Size - 1; ++i) {
            if (compare(*List[i], *List[i + 1])) {
                swap(*List[i], *List[i + 1]);
                ok = true;
            }
        }
    }
}

template<class T>
inline void Array<T>::Sort(Compare* comparator)
{
    bool ok = true;
    while (ok) {
        ok = false;
        for (int i = 0; i < Size - 1; ++i) {
            if (comparator->CompareElements((void*)(List[i]), (void*)(List[i + 1])) == 1) {
                swap(*List[i], *List[i + 1]);
                ok = true;
            }
        }
    }
}

template<class T>
inline int Array<T>::BinarySearch(const T& elem)
{
    int st = 0, dr = Size - 1;
    while (st <= dr) {
        int mij = (st + dr) >> 1;
        if (*List[mij] == elem) {
            return mij;
        }
        if (*List[mij] > elem) {
            dr = mij - 1;
        }
        else {
            st = mij + 1;
        }
    }
    return -1;
}

template<class T>
inline int Array<T>::BinarySearch(const T& elem, int(*compare)(const T&, const T&))
{
    //compare returneaza 0 la egal, -1 la mai mic si 1 la mai mare
    int st = 0, dr = Size - 1;
    while (st <= dr) {
        int mij = (st + dr) >> 1;
        if (compare(*List[mij], elem) == 0) {
            return mij;
        }
        if (compare(*List[mij], elem) == 1) {
            dr = mij - 1;
        }
        else {
            st = mij + 1;
        }
    }
    return -1;
}

template<class T>
inline int Array<T>::BinarySearch(const T& elem, Compare* comparator)
{
    //compare returneaza 0 la egal, -1 la mai mic si 1 la mai mare
    int st = 0, dr = Size - 1;
    while (st <= dr) {
        int mij = (st + dr) >> 1;
        if (comparator->CompareElements((void*)(List[mij]), (void*)(&elem)) == 0) {
            return mij;
        }
        if (comparator->CompareElements((void*)(List[mij]), (void*)(&elem)) == 1) {
            dr = mij - 1;
        }
        else {
            st = mij + 1;
        }
    }
    return -1;
}

template<class T>
inline int Array<T>::Find(const T& elem)
{
    for (int i = 0; i < Size; ++i) {
        if (*List[i] == elem) return i;
    }
    return -1;
}

template<class T>
inline int Array<T>::Find(const T& elem, int(*compare)(const T&, const T&))
{
    for (int i = 0; i < Size; ++i) {
        if (compare(*List[i], elem)) return i;
    }
    return -1;
}

template<class T>
inline int Array<T>::Find(const T& elem, Compare* comparator)
{
    for (int i = 0; i < Size; ++i) {
        if (comparator->CompareElements((void*)(List[i]), (void*)(&elem)) == 0) return i;
    }
    return -1;
}

template<class T>
inline int Array<T>::GetSize()
{
    return Size;
}

template<class T>
inline int Array<T>::GetCapacity()
{
    return Capacity;
}

template<class T>
inline ArrayIterator<T> Array<T>::GetBeginIterator()
{
    return ArrayIterator<T>(List, Size, 0);
}

template<class T>
inline ArrayIterator<T> Array<T>::GetEndIterator()
{
    return ArrayIterator<T>(List, Size, Size);
}



template<class T>
inline ArrayIterator<T>::ArrayIterator(T** a, int size, int index)
{
	List = a;
	Size = size;
	Current = index;
}

template<class T>
ArrayIterator<T>& ArrayIterator<T>::operator++() {
    if (Current < Size) Current++;
    return *this;
}

template<class T>
ArrayIterator<T>& ArrayIterator<T>::operator--() {
    if (Current > 0) Current--;
    return *this;
}

template<class T>
bool ArrayIterator<T>::operator==(const ArrayIterator<T>& other) const {
    return Current == other.Current;
}

template<class T>
bool ArrayIterator<T>::operator!=(const ArrayIterator<T>& other) const {
    return !(*this == other);
}

template<class T>
T* ArrayIterator<T>::GetElement() {
    if (Current >= 0 && Current < Size)
        return List[Current];
    return nullptr;
}