/*
 * Copyright (c) Abreto <m@abreto.net>
 * 
 */
#ifndef H_GMEM
#define H_GMEM

#include <stddef.h>

template <class T>
class Pointer
{
public:
	Pointer(void);
#if T != void
	Pointer(T);
#endif	// T != void
	Pointer(T *);
	Pointer(const GPointer<T> &);
	~Pointer();
	
#if T != void
	T & operator *(void);
	const T & operator *(void) const;
#endif	// T != void
	T * operator ->(void);
	const T * operator ->(void) const;
	
	T * operator +(unsigned int);
	const T * operator +(unsigned int) const;
	
	operator void *(void);
	operator int *(void);
	operator short *(void);
	operator long *(void);
	operator unsigned int *(void);
	operator unsigned short *(void);
	operator unsigned long *(void);
	operator float *(void);
	operator double *(void);
	operator long double *(void);
	operator char *(void);
	operator unsigned char *(void);
private:
	T* 		ptr;
	size_t*	use;
	
	void inc_use(void);
	void dec_use(void);
};

typedef Pointer<void> 				pvoid_t;
typedef Pointer<int> 				pint_t;
typedef Pointer<short>				pshort_t;
typedef Pointer<long> 				plong_t;
typedef Pointer<unsigned int>		puint_t;
typedef Pointer<unsigned short>	pushort_t;
typedef Pointer<unsigned long>		pulong_t;
typedef Pointer<float>				pfloat_t;
typedef Pointer<double>			pdouble_t;
typedef Pointer<long double>		pldouble_t;
typedef Pointer<char>				pchar_t;
typedef Pointer<unsigned char>		puchar_t;


class Memory
{
public:
	Memory();
	Memory(const GMemory &);
	~Memory();
private:
	pvoid_t data;
	size_t	size;
};

class MemManager
{
public:
private:
};

#endif	// H_GMEM
