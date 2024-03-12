#pragma once

template <class T>
class Vector{
public:
	Vector();
	Vector(unsigned int size);
	Vector(unsigned int size, const T& initial);
	Vector(const Vector<T>& v);
	~Vector();
	size_t size() const;
	bool empty() const;
	T& front();
	T& back();
	T& at(size_t index);
	void push_back(const T& value);
	void pop_back();
	void clear();
private:
	T* buffer;
	size_t bufferSize;
};