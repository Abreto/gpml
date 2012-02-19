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

template <class T>
void * Pointer<T>::operator void *(void)
{
	return (void *)ptr;
}

template <class T>
int * Pointer<T>::operator int *(void)
{
	return (int *)ptr;
}

template <class T>
short * Pointer<T>::operator short *(void)
{
	return (short *)ptr;
}

template <class T>
long * Pointer<T>::operator long *(void)
{
	return (long *)ptr;
}

template <class T>
unsigned int * Pointer<T>::operator unsigned int *(void)
{
	return (unsigned int *)ptr;
}

template <class T>
unsigned short * Pointer<T>::operator unsigned short *(void)
{
	return (unsigned short *)ptr;
}

template <class T>
unsigned long * Pointer<T>::operator unsigned long *(void)
{
	return (unsigned long *)ptr;
}

template <class T>
float * Pointer<T>::operator float *(void)
{
	return (float *)ptr;
}

template <class T>
double * Pointer<T>::operator double *(void)
{
	return (double *)ptr;
}

template <class T>
long double * Pointer<T>::operator long double *(void)
{
	return (long double *)ptr;
}

template <class T>
char * Pointer<T>::operator char *(void)
{
	return (char *)ptr;
}

template <class T>
unsigned char * Pointer<T>::operator unsigned char *(void)
{
	return (unsigned char *)ptr;
}
