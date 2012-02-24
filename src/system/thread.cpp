#include "thread.hpp"

ThreadAttr::ThreadAttr(void)
{
	pthread_attr_init( &attr );
}

Thread::Thread(void)
{
	; // Do nothing.
}

Thread::Thread(void *(*start_routine) (void *))
{
	thread_func = start_routine;
	pthread_create( &id , NULL , thread_func , NULL );
}

Thread::Thread(pthread_t tid)
{
	id = tid;
}

Thread::~Thread(void)
{
	; // Nothing need to do.
}

int Thread::start(void)
{
	pthread_create( &id, NULL, thread_func, NULL );
	return 1;
}

int Thread::join(void **thread_return)
{
	return pthread_join(id, thread_return);
}

int Thread::detach(void)
{
	return pthread_detach( id );
}

int Thread::cancel(void)
{
	return pthread_cancel( id );
}

int Thread::operator ==(Thread &thread)
{
	return pthread_equal( id, thread.id );
}

void Thread::exit(void *retval)
{
	pthread_exit( retval );
}

Thread Thread::self(void)
{
	return Thread( pthread_self() );
}
