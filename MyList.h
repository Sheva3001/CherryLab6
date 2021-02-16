#pragma once
#include <iostream>
#include <iterator>
using namespace std;

template<typename T>
class Array {
public:
// ����
	typedef T				value_type;
	typedef T*				iterator;
	typedef const T*		const_iterator;
	typedef T&				reference;
	typedef const T&		const_reference;
	typedef size_t				size_type;
// ������������/�����./����������
	Array(const size_type& n = minsize);
	Array(const Array& array);
	~Array();
	Array& operator=(const Array& right);
// ���������
	iterator begin() { return elems; }
	const_iterator begin() const { return elems; }
	iterator end() { return elems + Count; }
	const_iterator end() const { return elems + Count; }
// �������
	size_type size() const;				// ������� ������ �������
	bool empty() const;					// ���� �� ��������
	size_t capacity() const;			// ������������� ������
	void resize(size_type newsize);		// �������� ������
// ������ � ���������
	T& operator[](size_type index);
	const T& operator[](size_type index) const;
	reference front() { return elems[0]; }
	const_reference front() const { return elems[0]; }
	reference back() { return elems[size() - 1]; }
	const_reference back() const { return elems[size() - 1]; }
// ������ ������������
	void push_back(const value_type& v);
	void pop_back();											// ������� ��������� �������
	void clear() { Count = 0; }									// �������� ������
	void assign();												// ��������� ������
	void push_to_position(const value_type& v, size_type& i);	// ������� �� ������
	void print();
// ���������
	Array& operator+(const Array& a) {
		if (size() == a.size()) {
			for (int i = 0; i < a.size(); i++) {
				elems[i] += a[i];
			}
		}
		else throw out_of_range("Index out of range!");
		return *this;
	}
	Array& operator-(const Array& a) {
		if (size() == a.size()) {
			for (int i = 0; i < a.size(); i++) {
				elems[i] -= a[i];
			}
		}
		else throw out_of_range("Index out of range!");
		return *this;
	}
	Array& operator*(const Array& a) {
		if (size() == a.size()) {
			for (int i = 0; i < a.size(); i++) {
				elems[i] *= a[i];
			}
		}
		else throw out_of_range("Index out of range!");
		return *this;
	}
	Array& operator/(const Array& a) {
		if (size() == a.size()) {
			for (int i = 0; i < a.size(); i++) {
				elems[i] /= a[i];
			}
		}
		else throw out_of_range("Index out of range!");
		return *this;
	}
	Array& operator%(const Array& a) {
		if (size() == a.size()) {
			for (int i = 0; i < a.size(); i++) {
				elems[i] %= a[i];
			}
		}
		else throw out_of_range("Index out of range!");
		return *this;
	}
	bool operator==(const Array& a) {
		if (size() != a.size())
			return 0;
		else
			for (int i = 0; i < size(); i++) {
				if (elems[i] != a[i])
					return 0;
			}
		return 1;
	}
	bool operator<(const Array& a) {
		T sum = 0;
		for (int i = 0; i < size(); i++)
			sum += elems[i];
		for (int i = 0; i < a.size(); i++)
			sum -= a[i];
		if (sum < 0)
			return 1;
		else
			return 0;
	}
	bool operator>(const Array& a) {
		T sum = 0;
		for (int i = 0; i < size(); i++)
			sum += elems[i];
		for (int i = 0; i < a.size(); i++)
			sum -= a[i];
		if (sum < 0)
			return 0;
		else
			return 1;
	}
private:
	static const size_type minsize = 10;	// ����������� ������ �������
	size_type Size;							// �������� ��������� � ������
	size_type Count;						// ���-�� ��������� � �������
	value_type* elems;						// ��������� �� ������
};

template<typename T>
inline Array<T>::Array(const size_type& n) {
	Size = n;
	Count = 0;
	elems = new T[Size];
}

template<typename T>
inline Array<T>::Array(const Array& array) {
	Size = array.Size;
	Count = array.Count;
	elems = new T[Size];
	for (int i = 0; i < Size; i++)
		elems[i] = array[i];
}

template<typename T>
inline Array<T>::~Array() {
	delete[] elems;
	elems = 0;
}

template<typename T>
inline Array<T> & Array<T>::operator=(const Array<T>& right)
{
	if (this != &right) {
		Size = right.Size;
		Count = right.Count;
		T* new_elem = new T[Size];
		for (int i = 0; i < Size; i++)
			new_elem[i] = right[i];
		delete[]elems;
		elems = new_elem;
	}
	return *this;
}

template<typename T>
inline size_t Array<T>::size() const {
	return Count;
}

template<typename T>
inline bool Array<T>::empty() const {
	return Count == 0;
}

template<typename T>
inline size_t Array<T>::capacity() const {
	return Size - Count;
}

template<typename T>
inline void Array<T>::resize(size_type newsize) throw(bad_alloc) {
	if (newsize > capacity()) {
		value_type* data = new value_type[newsize];
		for (size_type i = 0; i < Count; ++i)
			data[i] = elems[i];
		delete[]elems;
		elems = data;
		Size = newsize;
	}
}

template<typename T>
inline T& Array<T>::operator[](size_type index) {
	if (index < Size)return elems[index];
	else throw out_of_range("Index out of range!");
}

template<typename T>
inline const T& Array<T>::operator[](size_type index) const {
	if (index < Size)return elems[index];
	else throw out_of_range("Index out of range!");
}

template<typename T>
inline void Array<T>::push_back(const value_type& v) {
	if (Count == Size)
		resize(Size * 2);
	elems[Count++] = v;
}

template<typename T>
inline void Array<T>::pop_back() {
	Count--;
}

template<typename T>
inline void Array<T>::assign() {
	value_type temp; int s = 0;
	cout << "������� ���-�� ���������" << endl;
	cin >> s;
	for (int i = 0; i < s; i++) {
		cin >> temp;
		push_back(temp);
	}
}

template<typename T>
inline void Array<T>::push_to_position(const value_type& v, size_type& i) {
	if (Count == Size)
		resize(Size * 2);
	Count++;
	for (size_type j = Count - 2; j > i; j--)
		elems[j + 1] = elems[j];
	elems[i] = v;
}

template<typename T>
inline void Array<T>::print() {
	for (int i = 0; i < size(); i++)
		cout << elems[i] << endl;
}
