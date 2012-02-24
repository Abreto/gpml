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

class ThreadAttr
{
public:
	ThreadAttr(void);
private:
	pthread_attr_t	attr;
};

class Thread
{
public:
	Thread(void);
	Thread(void *(*start_routine) (void *));
	Thread(pthread_t thread);
	~Thread(void);

	int start(void);
	int join(void **thread_return);
	int detach(void);
	int cancel(void);

	int operator ==(Thread & thread);

	static void exit(void *retval);
	static Thread self(void);
private:
	pthread_t	id;	// 线程ID.
	void *(*thread_func)(void *);
};

#endif	// _SYSTEM_THREAD_H
