#include "gmem.hpp"
#include <stdexcept>

template <class T>
void Pointer<T>::inc_use(void)
{
	(*use)++;
}

template <class T>
void Pointer<T>::dec_use(void)
{
	if( 0 == (--(*use)) )
	{
		delete ptr;
		delete use;
	}
}

template <class T>
Pointer<T>::Pointer(void)
{
	ptr = new T;
	use = new size_t(0);
	
	inc_use();
}

template <class T>
Pointer<T>::Pointer(T d)
{
	ptr = new T(d);
	use = new size_t(0);
	
	inc_use();
}

template <class T>
Pointer<T>::Pointer(T *p)
{
	ptr = p;
	use = new size_t(0);
	
	inc_use();
}

template <class T>
Pointer<T>::Pointer(const Pointer<T> &p)
{
	ptr = p.ptr;
	use = p.use;
	
	inc_use();
}

template <class T>
Pointer<T>::~Pointer(void)
{
	dec_use();
}

template <class T>
T & Pointer<T>::operator *(void)
{
	if( ptr )
		return (*ptr);
	throw std::runtime_error("错误的NULL指针");
}

template <class T>
const T& Pointer<T>::operator *(void) const
{
	if( ptr )
		return (*ptr);
	throw std::runtime_error("错误的NULL指针");
}

template <class T>
T * Pointer<T>::operator ->(void)
{
	if( ptr )
		return ptr;
	else
		return NULL;
}

template <class T>
const T * Pointer<T>::operator ->(void) const
{
	if( ptr )
		return ptr;
	else
		return NULL;
}

template <class T>
T* Pointer<T>::operator +(unsigned int offset)
{
	if( ptr )
		return (ptr + offset);
	else
		return NULL;
}

template <class T>
const T* Pointer<T>::operator +(unsigned int offset) const
{
	if( ptr )
		return ( ptr + offset );
	else
		return NULL;
}
