#pragma once
template<typename T>
class Vector
{
private:
	T* data;
	int size;
public:
	Vector();
	Vector(const Vector& other);
	void insert(int index, T value);
	void remove(int index);
	template<typename Func>
	void sort(Func && func);
	void sort();
	T operator[](int index);
	void print();
};

template<typename T>
inline Vector<T>::Vector()
{
	data = nullptr;
	size = 0;
}

template<typename T>
inline Vector<T>::Vector(const Vector& other)
{
	data = new T[other.size];
	size = other.size;
	for (int i = 0; i < size; i++)
	{
		data[i] = other.data[i];
	}
}

template<typename T>
inline void Vector<T>::insert(int index, T value)
{
	if (index < 0 || index > size)
	{
		return;
	}
	T* newData = new T[size + 1];
	for (int i = 0; i < size + 1; i++)
	{
		if (i < index)
		{
			newData[i] = data[i];
		}
		else if (i == index)
		{
			newData[i] = value;
		}
		else
		{
			newData[i] = data[i - 1];
		}
	}
	delete[] data;
	data = newData;
	size++;
}

template<typename T>
inline void Vector<T>::remove(int index)
{
	if (index < 0 || index >= size)
	{
		return;
	}
	T* newData = new T[size - 1];
	for (int i = 0; i < size; i++)
	{
		if (i < index)
		{
			newData[i] = data[i];
		}
		else if (i > index)
		{
			newData[i - 1] = data[i];
		}
	}
	delete[] data;
	data = newData;
	size--;
}

template<typename T>
template<typename Func>
inline void Vector<T>::sort(Func && func)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (func(data[i], data[j]))
			{
				T temp = data[j];
				data[j] = data[i];
				data[i] = temp;
			}
		}
	}
}

template<typename T>
inline void Vector<T>::sort()
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (data[i] > data[j])
			{
				T temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}
		}
	}
}

template<typename T>
inline T Vector<T>::operator[](int index)
{
	return data[index];
}

template<typename T>
inline void Vector<T>::print()
{
	for (int i = 0; i < size; i++)
	{
		std::cout << data[i] << " ";
	}
	std::cout << std::endl;
}
