/*	gmem.hpp
 * 内存管理
 * 
 * Copyright (c) GPML团队
 * 编写 Abreto <m@abreto.net>
 * 版本 0.1a
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
	
	void * operator void *(void);
	int * operator int *(void);
	short * operator short *(void);
	long * operator long *(void);
	unsigned int * operator unsigned int *(void);
	unsigned short * operator unsigned short *(void);
	unsigned long * operator unsigned long *(void);
	float * operator float *(void);
	double * operator double *(void);
	long double * operator long double *(void);
	char * operator char *(void);
	unsigned char * operator unsigned char *(void);
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
