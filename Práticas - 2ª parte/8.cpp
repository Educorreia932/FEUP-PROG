#include "8.h"

template <class T> 
Vector<T>::Vector() {
	bufferSize = 0;
}

template <class T>
Vector<T>::Vector(unsigned int size) {
	bufferSize = size;
}

template <class T>
Vector<T>::Vector(unsigned int size, const T& initial) {
	buffer = initial;
	bufferSize = size;
}

template <class T> 
size_t Vector<T>:: size() const {
	return bufferSize;
}

template <class T>
bool Vector<T>::empty() const {
	if (!bufferSize)
		return true;
	else
		return false;
} //change