/*	system/thread.hpp
 * 线程管理
 * 
 * Copyright (c) GPML团队
 * 编写 Abreto <m@abreto.net>
 * 版本 0.1a
 */
#ifndef	_SYSTEM_THREAD_H
#define _SYSTEM_THREAD_H	1

#include <pthread.h>

class Thread
{
public:
	int operator ==(Thread & thread);

	static void exit(void *retval);
	static pthread_t self(void);
private:
	pthread_t	id;	// 线程ID.
};

#endif	// _SYSTEM_THREAD_H
