
#pragma once

#if _POSIX_THREADS

#include <pthread.h>

int include_pthread_barriers(Lib *self, FILE *file) {
#   if _POSIX_BARRIERS > 0
#       ifndef BLTN_PTHREAD_BARRIERATTR_DESTROY
#       define BLTN_PTHREAD_BARRIERATTR_DESTROY pthread_barrierattr_destroy
#       endif
#       ifndef BLTN_PTHREAD_BARRIERATTR_GETPSHARED
#       define BLTN_PTHREAD_BARRIERATTR_GETPSHARED pthread_barrierattr_getpshared
#       endif
#       ifndef BLTN_PTHREAD_BARRIERATTR_INIT
#       define BLTN_PTHREAD_BARRIERATTR_INIT pthread_barrierattr_init
#       endif
#       ifndef BLTN_PTHREAD_BARRIERATTR_SETPSHARED
#       define BLTN_PTHREAD_BARRIERATTR_SETPSHARED pthread_barrierattr_setpshared
#       endif
#       ifndef BLTN_PTHREAD_BARRIER_DESTROY
#       define BLTN_PTHREAD_BARRIER_DESTROY pthread_barrier_destroy
#       endif
#       ifndef BLTN_PTHREAD_BARRIER_INIT
#       define BLTN_PTHREAD_BARRIER_INIT pthread_barrier_init
#       endif
#       ifndef BLTN_PTHREAD_BARRIER_WAIT
#       define BLTN_PTHREAD_BARRIER_WAIT pthread_barrier_wait
#       endif
        self->pthread.barrier.destroy       = BLTN_PTHREAD_BARRIER_DESTROY;
        self->pthread.barrier.init          = BLTN_PTHREAD_BARRIER_INIT;
        self->pthread.barrier.wait          = BLTN_PTHREAD_BARRIER_WAIT;
        self->pthread.barrierattr.destroy   = BLTN_PTHREAD_BARRIERATTR_DESTROY;
        self->pthread.barrierattr.init      = BLTN_PTHREAD_BARRIERATTR_INIT;
        self->pthread.barrierattr.getpshared= BLTN_PTHREAD_BARRIERATTR_GETPSHARED;
        self->pthread.barrierattr.setpshared= BLTN_PTHREAD_BARRIERATTR_SETPSHARED;
#   endif // _POSIX_BARRIERS
    return 0;
}

int include_pthread_rwlock(Lib *self, FILE *file) {

#   if _POSIX_READER_WRITER_LOCKS > 0
#       ifndef BLTN_PTHREAD_RWLOCK_DESTROY
#       define BLTN_PTHREAD_RWLOCK_DESTROY pthread_rwlock_destroy
#       endif
#       ifndef BLTN_PTHREAD_RWLOCK_INIT
#       define BLTN_PTHREAD_RWLOCK_INIT pthread_rwlock_init
#       endif
#       ifndef BLTN_PTHREAD_RWLOCK_RDLOCK
#       define BLTN_PTHREAD_RWLOCK_RDLOCK pthread_rwlock_rdlock
#       endif
#       ifndef BLTN_PTHREAD_RWLOCK_TIMEDRDLOCK
#       define BLTN_PTHREAD_RWLOCK_TIMEDRDLOCK pthread_rwlock_timedrdlock
#       endif
#       ifndef BLTN_PTHREAD_RWLOCK_TIMEDWRLOCK
#       define BLTN_PTHREAD_RWLOCK_TIMEDWRLOCK pthread_rwlock_timedwrlock
#       endif
#       ifndef BLTN_PTHREAD_RWLOCK_TRYRDLOCK
#       define BLTN_PTHREAD_RWLOCK_TRYRDLOCK pthread_rwlock_tryrdlock
#       endif
#       ifndef BLTN_PTHREAD_RWLOCK_TRYWRLOCK
#       define BLTN_PTHREAD_RWLOCK_TRYWRLOCK pthread_rwlock_trywrlock
#       endif
#       ifndef BLTN_PTHREAD_RWLOCK_UNLOCK
#       define BLTN_PTHREAD_RWLOCK_UNLOCK pthread_rwlock_unlock
#       endif
#       ifndef BLTN_PTHREAD_RWLOCK_WRLOCK
#       define BLTN_PTHREAD_RWLOCK_WRLOCK pthread_rwlock_wrlock
#       endif
#       ifndef BLTN_PTHREAD_RWLOCKATTR_DESTROY
#       define BLTN_PTHREAD_RWLOCKATTR_DESTROY pthread_rwlockattr_destroy
#       endif
#       ifndef BLTN_PTHREAD_RWLOCKATTR_GETPSHARED
#       define BLTN_PTHREAD_RWLOCKATTR_GETPSHARED pthread_rwlockattr_getpshared
#       endif
#       ifndef BLTN_PTHREAD_RWLOCKATTR_INIT
#       define BLTN_PTHREAD_RWLOCKATTR_INIT pthread_rwlockattr_init
#       endif
#       ifndef BLTN_PTHREAD_RWLOCKATTR_SETPSHARED
#       define BLTN_PTHREAD_RWLOCKATTR_SETPSHARED pthread_rwlockattr_setpshared
#       endif
        self->pthread.rwlockattr.destroy    = BLTN_PTHREAD_RWLOCKATTR_DESTROY;
        self->pthread.rwlockattr.getpshared = BLTN_PTHREAD_RWLOCKATTR_GETPSHARED;
        self->pthread.rwlockattr.init       = BLTN_PTHREAD_RWLOCKATTR_INIT;
        self->pthread.rwlockattr.setpshared = BLTN_PTHREAD_RWLOCKATTR_SETPSHARED;
        self->pthread.rwlock.destroy    = BLTN_PTHREAD_RWLOCK_DESTROY;
        self->pthread.rwlock.init       = BLTN_PTHREAD_RWLOCK_INIT;
        self->pthread.rwlock.rdlock     = BLTN_PTHREAD_RWLOCK_RDLOCK;
        self->pthread.rwlock.timedrdlock= BLTN_PTHREAD_RWLOCK_TIMEDRDLOCK;
        self->pthread.rwlock.timedwrlock= BLTN_PTHREAD_RWLOCK_TIMEDWRLOCK;
        self->pthread.rwlock.tryrdlock  = BLTN_PTHREAD_RWLOCK_TRYRDLOCK;
        self->pthread.rwlock.trywrlock  = BLTN_PTHREAD_RWLOCK_TRYWRLOCK;
        self->pthread.rwlock.unlock     = BLTN_PTHREAD_RWLOCK_UNLOCK;
        self->pthread.rwlock.wrlock     = BLTN_PTHREAD_RWLOCK_WRLOCK;
#   endif // _POSIX_READER_WRITER_LOCKS
    return 0;
}

int include_pthread_spin(Lib *self, FILE *file) {

#   if _POSIX_SPIN_LOCKS > 0
#       ifndef BLTN_PTHREAD_SPIN_DESTROY
#       define BLTN_PTHREAD_SPIN_DESTROY pthread_spin_destroy
#       endif
#       ifndef BLTN_PTHREAD_SPIN_INIT
#       define BLTN_PTHREAD_SPIN_INIT pthread_spin_init
#       endif
#       ifndef BLTN_PTHREAD_SPIN_LOCK
#       define BLTN_PTHREAD_SPIN_LOCK pthread_spin_lock
#       endif
#       ifndef BLTN_PTHREAD_SPIN_TRYLOCK
#       define BLTN_PTHREAD_SPIN_TRYLOCK pthread_spin_trylock
#       endif
#       ifndef BLTN_PTHREAD_SPIN_UNLOCK
#       define BLTN_PTHREAD_SPIN_UNLOCK pthread_spin_unlock
#       endif
        self->pthread.spin.destroy  = BLTN_PTHREAD_SPIN_DESTROY;
        self->pthread.spin.init     = BLTN_PTHREAD_SPIN_INIT;
        self->pthread.spin.lock     = BLTN_PTHREAD_SPIN_LOCK;
        self->pthread.spin.trylock  = BLTN_PTHREAD_SPIN_TRYLOCK;
        self->pthread.spin.unlock   = BLTN_PTHREAD_SPIN_UNLOCK;
#   endif // _POSIX_SPIN_LOCKS
    return 0;
}

int include_pthread_h(Lib *self, FILE *file) {

#   ifndef BLTN_PTHREAD_ATTR_GETDETACHSTATE
#   define BLTN_PTHREAD_ATTR_GETDETACHSTATE pthread_attr_getdetachstate
#   endif
#   ifndef BLTN_PTHREAD_ATTR_GETGUARDSIZE
#   define BLTN_PTHREAD_ATTR_GETGUARDSIZE pthread_attr_getguardsize
#   endif
#   ifndef BLTN_PTHREAD_ATTR_GETINHERITSCHED
#   define BLTN_PTHREAD_ATTR_GETINHERITSCHED pthread_attr_getinheritsched
#   endif
#   ifndef BLTN_PTHREAD_ATTR_GETSCHEDPARAM
#   define BLTN_PTHREAD_ATTR_GETSCHEDPARAM pthread_attr_getschedparam
#   endif
#   ifndef BLTN_PTHREAD_ATTR_GETSCHEDPOLICY
#   define BLTN_PTHREAD_ATTR_GETSCHEDPOLICY pthread_attr_getschedpolicy
#   endif
#   ifndef BLTN_PTHREAD_ATTR_GETSCOPE
#   define BLTN_PTHREAD_ATTR_GETSCOPE pthread_attr_getscope
#   endif
#   ifndef BLTN_PTHREAD_ATTR_GETSTACK
#   define BLTN_PTHREAD_ATTR_GETSTACK pthread_attr_getstack
#   endif
#   ifndef BLTN_PTHREAD_ATTR_GETSTACKSIZE
#   define BLTN_PTHREAD_ATTR_GETSTACKSIZE pthread_attr_getstacksize
#   endif
#   ifndef BLTN_PTHREAD_ATTR_INIT
#   define BLTN_PTHREAD_ATTR_INIT pthread_attr_init
#   endif
#   ifndef BLTN_PTHREAD_ATTR_DESTROY
#   define BLTN_PTHREAD_ATTR_DESTROY pthread_attr_destroy
#   endif
#   ifndef BLTN_PTHREAD_ATTR_SETDETACHSTATE
#   define BLTN_PTHREAD_ATTR_SETDETACHSTATE pthread_attr_setdetachstate
#   endif
#   ifndef BLTN_PTHREAD_ATTR_SETGUARDSIZE
#   define BLTN_PTHREAD_ATTR_SETGUARDSIZE pthread_attr_setguardsize
#   endif
#   ifndef BLTN_PTHREAD_ATTR_SETINHERITSCHED
#   define BLTN_PTHREAD_ATTR_SETINHERITSCHED pthread_attr_setinheritsched
#   endif
#   ifndef BLTN_PTHREAD_ATTR_SETSCHEDPARAM
#   define BLTN_PTHREAD_ATTR_SETSCHEDPARAM pthread_attr_setschedparam
#   endif
#   ifndef BLTN_PTHREAD_ATTR_SETSCHEDPOLICY
#   define BLTN_PTHREAD_ATTR_SETSCHEDPOLICY pthread_attr_setschedpolicy
#   endif
#   ifndef BLTN_PTHREAD_ATTR_SETSCOPE
#   define BLTN_PTHREAD_ATTR_SETSCOPE pthread_attr_setscope
#   endif
#   ifndef BLTN_PTHREAD_ATTR_SETSTACK
#   define BLTN_PTHREAD_ATTR_SETSTACK pthread_attr_setstack
#   endif
#   ifndef BLTN_PTHREAD_ATTR_SETSTACKSIZE
#   define BLTN_PTHREAD_ATTR_SETSTACKSIZE pthread_attr_setstacksize
#   endif
#   ifndef BLTN_PTHREAD_COND_BROADCAST
#   define BLTN_PTHREAD_COND_BROADCAST pthread_cond_broadcast
#   endif
#   ifndef BLTN_PTHREAD_COND_DESTROY
#   define BLTN_PTHREAD_COND_DESTROY pthread_cond_destroy
#   endif
#   ifndef BLTN_PTHREAD_COND_INIT
#   define BLTN_PTHREAD_COND_INIT pthread_cond_init
#   endif
#   ifndef BLTN_PTHREAD_COND_SIGNAL
#   define BLTN_PTHREAD_COND_SIGNAL pthread_cond_signal
#   endif
#   ifndef BLTN_PTHREAD_COND_TIMEDWAIT
#   define BLTN_PTHREAD_COND_TIMEDWAIT pthread_cond_timedwait
#   endif
#   ifndef BLTN_PTHREAD_COND_WAIT
#   define BLTN_PTHREAD_COND_WAIT pthread_cond_wait
#   endif
#   ifndef BLTN_PTHREAD_CONDATTR_DESTROY
#   define BLTN_PTHREAD_CONDATTR_DESTROY pthread_condattr_destroy
#   endif
#   ifndef BLTN_PTHREAD_CONDATTR_GETCLOCK
#   define BLTN_PTHREAD_CONDATTR_GETCLOCK pthread_condattr_getclock
#   endif
#   ifndef BLTN_PTHREAD_CONDATTR_GETPSHARED
#   define BLTN_PTHREAD_CONDATTR_GETPSHARED pthread_condattr_getpshared
#   endif
#   ifndef BLTN_PTHREAD_CONDATTR_INIT
#   define BLTN_PTHREAD_CONDATTR_INIT pthread_condattr_init
#   endif
#   ifndef BLTN_PTHREAD_CONDATTR_SETCLOCK
#   define BLTN_PTHREAD_CONDATTR_SETCLOCK pthread_condattr_setclock
#   endif
#   ifndef BLTN_PTHREAD_CONDATTR_SETPSHARED
#   define BLTN_PTHREAD_CONDATTR_SETPSHARED pthread_condattr_setpshared
#   endif
#   ifndef BLTN_PTHREAD_MUTEX_CONSISTENT
#   define BLTN_PTHREAD_MUTEX_CONSISTENT pthread_mutex_consistent
#   endif
#   ifndef BLTN_PTHREAD_MUTEX_DESTROY
#   define BLTN_PTHREAD_MUTEX_DESTROY pthread_mutex_destroy
#   endif
#   ifndef BLTN_PTHREAD_MUTEX_GETPRIOCEILING
#   define BLTN_PTHREAD_MUTEX_GETPRIOCEILING pthread_mutex_getprioceiling
#   endif
#   ifndef BLTN_PTHREAD_MUTEX_INIT
#   define BLTN_PTHREAD_MUTEX_INIT pthread_mutex_init
#   endif
#   ifndef BLTN_PTHREAD_MUTEX_LOCK
#   define BLTN_PTHREAD_MUTEX_LOCK pthread_mutex_lock
#   endif
#   ifndef BLTN_PTHREAD_MUTEX_SETPRIOCEILING
#   define BLTN_PTHREAD_MUTEX_SETPRIOCEILING pthread_mutex_setprioceiling
#   endif
#   ifndef BLTN_PTHREAD_MUTEX_TIMEDLOCK
#   define BLTN_PTHREAD_MUTEX_TIMEDLOCK pthread_mutex_timedlock
#   endif
#   ifndef BLTN_PTHREAD_MUTEX_TRYLOCK
#   define BLTN_PTHREAD_MUTEX_TRYLOCK pthread_mutex_trylock
#   endif
#   ifndef BLTN_PTHREAD_MUTEX_UNLOCK
#   define BLTN_PTHREAD_MUTEX_UNLOCK pthread_mutex_unlock
#   endif
#   ifndef BLTN_PTHREAD_MUTEX_CONSISTENT
#   define BLTN_PTHREAD_MUTEX_CONSISTENT pthread_mutex_consistent
#   endif
#   ifndef BLTN_PTHREAD_MUTEX_DESTROY
#   define BLTN_PTHREAD_MUTEX_DESTROY pthread_mutex_destroy
#   endif
#   ifndef BLTN_PTHREAD_MUTEX_GETPRIOCEILING
#   define BLTN_PTHREAD_MUTEX_GETPRIOCEILING pthread_mutex_getprioceiling
#   endif
#   ifndef BLTN_PTHREAD_MUTEX_INIT
#   define BLTN_PTHREAD_MUTEX_INIT pthread_mutex_init
#   endif
#   ifndef BLTN_PTHREAD_MUTEX_LOCK
#   define BLTN_PTHREAD_MUTEX_LOCK pthread_mutex_lock
#   endif
#   ifndef BLTN_PTHREAD_MUTEX_SETPRIOCEILING
#   define BLTN_PTHREAD_MUTEX_SETPRIOCEILING pthread_mutex_setprioceiling
#   endif
#   ifndef BLTN_PTHREAD_MUTEX_TIMEDLOCK
#   define BLTN_PTHREAD_MUTEX_TIMEDLOCK pthread_mutex_timedlock
#   endif
#   ifndef BLTN_PTHREAD_MUTEX_TRYLOCK
#   define BLTN_PTHREAD_MUTEX_TRYLOCK pthread_mutex_trylock
#   endif
#   ifndef BLTN_PTHREAD_MUTEX_UNLOCK
#   define BLTN_PTHREAD_MUTEX_UNLOCK pthread_mutex_unlock
#   endif
#   ifndef BLTN_PTHREAD_MUTEXATTR_DESTROY
#   define BLTN_PTHREAD_MUTEXATTR_DESTROY pthread_mutexattr_destroy
#   endif
#   ifndef BLTN_PTHREAD_MUTEXATTR_GETPRIOCEILING
#   define BLTN_PTHREAD_MUTEXATTR_GETPRIOCEILING pthread_mutexattr_getprioceiling
#   endif
#   ifndef BLTN_PTHREAD_MUTEXATTR_GETPROTOCOL
#   define BLTN_PTHREAD_MUTEXATTR_GETPROTOCOL pthread_mutexattr_getprotocol
#   endif
#   ifndef BLTN_PTHREAD_MUTEXATTR_GETPSHARED
#   define BLTN_PTHREAD_MUTEXATTR_GETPSHARED pthread_mutexattr_getpshared
#   endif
#   ifndef BLTN_PTHREAD_MUTEXATTR_GETROBUST
#   define BLTN_PTHREAD_MUTEXATTR_GETROBUST pthread_mutexattr_getrobust
#   endif
#   ifndef BLTN_PTHREAD_MUTEXATTR_GETTYPE
#   define BLTN_PTHREAD_MUTEXATTR_GETTYPE pthread_mutexattr_gettype
#   endif
#   ifndef BLTN_PTHREAD_MUTEXATTR_INIT
#   define BLTN_PTHREAD_MUTEXATTR_INIT pthread_mutexattr_init
#   endif
#   ifndef BLTN_PTHREAD_MUTEXATTR_SETPRIOCEILING
#   define BLTN_PTHREAD_MUTEXATTR_SETPRIOCEILING pthread_mutexattr_setprioceiling
#   endif
#   ifndef BLTN_PTHREAD_MUTEXATTR_SETPROTOCOL
#   define BLTN_PTHREAD_MUTEXATTR_SETPROTOCOL pthread_mutexattr_setprotocol
#   endif
#   ifndef BLTN_PTHREAD_MUTEXATTR_SETPSHARED
#   define BLTN_PTHREAD_MUTEXATTR_SETPSHARED pthread_mutexattr_setpshared
#   endif
#   ifndef BLTN_PTHREAD_MUTEXATTR_SETROBUST
#   define BLTN_PTHREAD_MUTEXATTR_SETROBUST pthread_mutexattr_setrobust
#   endif
#   ifndef BLTN_PTHREAD_MUTEXATTR_SETTYPE
#   define BLTN_PTHREAD_MUTEXATTR_SETTYPE pthread_mutexattr_settype
#   endif
#   ifndef BLTN_PTHREAD_KILL
#   define BLTN_PTHREAD_KILL pthread_kill
#   endif
#   ifndef BLTN_PTHREAD_SIGMASK
#   define BLTN_PTHREAD_SIGMASK pthread_sigmask
#   endif
#   ifndef BLTN_PTHREAD_SIGQUEUE
#   define BLTN_PTHREAD_SIGQUEUE 0
#   endif
#   ifndef BLTN_PTHREAD_SETCONCURRENCY
#   define BLTN_PTHREAD_SETCONCURRENCY 0
#   endif
#   ifndef BLTN_PTHREAD_GETCONCURRENCY
#   define BLTN_PTHREAD_GETCONCURRENCY 0
#   endif
#   ifndef BLTN_PTHREAD_ATFORK
#   define BLTN_PTHREAD_ATFORK pthread_atfork
#   endif
#   ifndef BLTN_PTHREAD_CREATE
#   define BLTN_PTHREAD_CREATE pthread_create
#   endif
#   ifndef BLTN_PTHREAD_ONCE
#   define BLTN_PTHREAD_ONCE pthread_once
#   endif
#   ifndef BLTN_PTHREAD_CANCEL
#   define BLTN_PTHREAD_CANCEL pthread_cancel
#   endif
#   ifndef BLTN_PTHREAD_DETACH
#   define BLTN_PTHREAD_DETACH pthread_detach
#   endif
#   ifndef BLTN_PTHREAD_EQUAL
#   define BLTN_PTHREAD_EQUAL pthread_equal
#   endif
#   ifndef BLTN_PTHREAD_GETCPUCLOCKID
#   define BLTN_PTHREAD_GETCPUCLOCKID pthread_getcpuclockid
#   endif
#   ifndef BLTN_PTHREAD_GETSCHEDPARAM
#   define BLTN_PTHREAD_GETSCHEDPARAM pthread_getschedparam
#   endif
#   ifndef BLTN_PTHREAD_JOIN
#   define BLTN_PTHREAD_JOIN pthread_join
#   endif
#   ifndef BLTN_PTHREAD_SETCANCELSTATE
#   define BLTN_PTHREAD_SETCANCELSTATE pthread_setcancelstate
#   endif
#   ifndef BLTN_PTHREAD_SETCANCELTYPE
#   define BLTN_PTHREAD_SETCANCELTYPE pthread_setcanceltype
#   endif
#   ifndef BLTN_PTHREAD_SETSCHEDPRIO
#   define BLTN_PTHREAD_SETSCHEDPRIO pthread_setschedprio
#   endif
#   ifndef BLTN_PTHREAD_SETSCHEDPARAM
#   define BLTN_PTHREAD_SETSCHEDPARAM pthread_setschedparam
#   endif
#   ifndef BLTN_PTHREAD_SETSPECIFIC
#   define BLTN_PTHREAD_SETSPECIFIC pthread_setspecific
#   endif
#   ifndef BLTN_PTHREAD_SELF
#   define BLTN_PTHREAD_SELF pthread_self
#   endif
#   ifndef BLTN_PTHREAD_GETSPECIFIC
#   define BLTN_PTHREAD_GETSPECIFIC pthread_getspecific
#   endif
#   ifndef BLTN_PTHREAD_TESTCANCEL
#   define BLTN_PTHREAD_TESTCANCEL pthread_testcancel
#   endif
#   ifndef BLTN_PTHREAD_EXIT
#   define BLTN_PTHREAD_EXIT pthread_exit
#   endif
#   ifndef BLTN_PTHREAD_KEY_CREATE
#   define BLTN_PTHREAD_KEY_CREATE pthread_key_create
#   endif
#   ifndef BLTN_PTHREAD_KEY_DELETE
#   define BLTN_PTHREAD_KEY_DELETE pthread_key_delete
#   endif
    self->pthread.attr.getdetachstate=BLTN_PTHREAD_ATTR_GETDETACHSTATE;
    self->pthread.attr.getguardsize=BLTN_PTHREAD_ATTR_GETGUARDSIZE;
    self->pthread.attr.getinheritsched=BLTN_PTHREAD_ATTR_GETINHERITSCHED;
    self->pthread.attr.getschedparam=BLTN_PTHREAD_ATTR_GETSCHEDPARAM;
    self->pthread.attr.getschedpolicy=BLTN_PTHREAD_ATTR_GETSCHEDPOLICY;
    self->pthread.attr.getscope=BLTN_PTHREAD_ATTR_GETSCOPE;
    self->pthread.attr.getstack=BLTN_PTHREAD_ATTR_GETSTACK;
    self->pthread.attr.getstacksize=BLTN_PTHREAD_ATTR_GETSTACKSIZE;
    self->pthread.attr.init=BLTN_PTHREAD_ATTR_INIT;
    self->pthread.attr.destroy=BLTN_PTHREAD_ATTR_DESTROY;
    self->pthread.attr.setdetachstate=BLTN_PTHREAD_ATTR_SETDETACHSTATE;
    self->pthread.attr.setguardsize=BLTN_PTHREAD_ATTR_SETGUARDSIZE;
    self->pthread.attr.setinheritsched=BLTN_PTHREAD_ATTR_SETINHERITSCHED;
    self->pthread.attr.setschedparam=BLTN_PTHREAD_ATTR_SETSCHEDPARAM;
    self->pthread.attr.setschedpolicy=BLTN_PTHREAD_ATTR_SETSCHEDPOLICY;
    self->pthread.attr.setscope=BLTN_PTHREAD_ATTR_SETSCOPE;
    self->pthread.attr.setstack=BLTN_PTHREAD_ATTR_SETSTACK;
    self->pthread.attr.setstacksize=BLTN_PTHREAD_ATTR_SETSTACKSIZE;
    self->pthread.cond.broadcast=BLTN_PTHREAD_COND_BROADCAST;
    self->pthread.cond.destroy=BLTN_PTHREAD_COND_DESTROY;
    self->pthread.cond.init=BLTN_PTHREAD_COND_INIT;
    self->pthread.cond.signal=BLTN_PTHREAD_COND_SIGNAL;
    self->pthread.cond.timedwait=BLTN_PTHREAD_COND_TIMEDWAIT;
    self->pthread.cond.wait=BLTN_PTHREAD_COND_WAIT;
    self->pthread.condattr.destroy=BLTN_PTHREAD_CONDATTR_DESTROY;
    self->pthread.condattr.getclock=BLTN_PTHREAD_CONDATTR_GETCLOCK;
    self->pthread.condattr.getpshared=BLTN_PTHREAD_CONDATTR_GETPSHARED;
    self->pthread.condattr.init=BLTN_PTHREAD_CONDATTR_INIT;
    self->pthread.condattr.setclock=BLTN_PTHREAD_CONDATTR_SETCLOCK;
    self->pthread.condattr.setpshared=BLTN_PTHREAD_CONDATTR_SETPSHARED;
    self->pthread.key.create=BLTN_PTHREAD_KEY_CREATE;
    self->pthread.key.delete=BLTN_PTHREAD_KEY_DELETE;
    self->pthread.mutex.consistent=BLTN_PTHREAD_MUTEX_CONSISTENT;
    self->pthread.mutex.destroy=BLTN_PTHREAD_MUTEX_DESTROY;
    self->pthread.mutex.getprioceiling=BLTN_PTHREAD_MUTEX_GETPRIOCEILING;
    self->pthread.mutex.init=BLTN_PTHREAD_MUTEX_INIT;
    self->pthread.mutex.lock=BLTN_PTHREAD_MUTEX_LOCK;
    self->pthread.mutex.setprioceiling=BLTN_PTHREAD_MUTEX_SETPRIOCEILING;
    self->pthread.mutex.timedlock=BLTN_PTHREAD_MUTEX_TIMEDLOCK;
    self->pthread.mutex.trylock=BLTN_PTHREAD_MUTEX_TRYLOCK;
    self->pthread.mutex.unlock=BLTN_PTHREAD_MUTEX_UNLOCK;
    self->pthread.mutex.consistent=BLTN_PTHREAD_MUTEX_CONSISTENT;
    self->pthread.mutex.destroy=BLTN_PTHREAD_MUTEX_DESTROY;
    self->pthread.mutex.getprioceiling=BLTN_PTHREAD_MUTEX_GETPRIOCEILING;
    self->pthread.mutex.init=BLTN_PTHREAD_MUTEX_INIT;
    self->pthread.mutex.lock=BLTN_PTHREAD_MUTEX_LOCK;
    self->pthread.mutex.setprioceiling=BLTN_PTHREAD_MUTEX_SETPRIOCEILING;
    self->pthread.mutex.timedlock=BLTN_PTHREAD_MUTEX_TIMEDLOCK;
    self->pthread.mutex.trylock=BLTN_PTHREAD_MUTEX_TRYLOCK;
    self->pthread.mutex.unlock=BLTN_PTHREAD_MUTEX_UNLOCK;
    self->pthread.mutexattr.destroy=BLTN_PTHREAD_MUTEXATTR_DESTROY;
    self->pthread.mutexattr.getprioceiling=BLTN_PTHREAD_MUTEXATTR_GETPRIOCEILING;
    self->pthread.mutexattr.getprotocol=BLTN_PTHREAD_MUTEXATTR_GETPROTOCOL;
    self->pthread.mutexattr.getpshared=BLTN_PTHREAD_MUTEXATTR_GETPSHARED;
    self->pthread.mutexattr.getrobust=BLTN_PTHREAD_MUTEXATTR_GETROBUST;
    self->pthread.mutexattr.gettype=BLTN_PTHREAD_MUTEXATTR_GETTYPE;
    self->pthread.mutexattr.init=BLTN_PTHREAD_MUTEXATTR_INIT;
    self->pthread.mutexattr.setprioceiling=BLTN_PTHREAD_MUTEXATTR_SETPRIOCEILING;
    self->pthread.mutexattr.setprotocol=BLTN_PTHREAD_MUTEXATTR_SETPROTOCOL;
    self->pthread.mutexattr.setpshared=BLTN_PTHREAD_MUTEXATTR_SETPSHARED;
    self->pthread.mutexattr.setrobust=BLTN_PTHREAD_MUTEXATTR_SETROBUST;
    self->pthread.mutexattr.settype=BLTN_PTHREAD_MUTEXATTR_SETTYPE;
#   ifdef BLTN_PTHREAD_SIGQUEUE    
    self->pthread.sigqueue      = BLTN_PTHREAD_SIGQUEUE;
#   endif
    self->pthread.kill          = BLTN_PTHREAD_KILL;
    self->pthread.sigmask       = BLTN_PTHREAD_SIGMASK;
    self->pthread.setconcurrency= BLTN_PTHREAD_SETCONCURRENCY;
    self->pthread.getconcurrency= BLTN_PTHREAD_GETCONCURRENCY;
    self->pthread.atfork        = BLTN_PTHREAD_ATFORK;
    self->pthread.create        = BLTN_PTHREAD_CREATE;
    self->pthread.once          = BLTN_PTHREAD_ONCE;
    self->pthread.cancel        = BLTN_PTHREAD_CANCEL;
    self->pthread.testcancel    = BLTN_PTHREAD_TESTCANCEL;
    self->pthread.setcancelstate= BLTN_PTHREAD_SETCANCELSTATE;
    self->pthread.setcanceltype = BLTN_PTHREAD_SETCANCELTYPE;
    self->pthread.detach        = BLTN_PTHREAD_DETACH;
    self->pthread.equal         = BLTN_PTHREAD_EQUAL;
    self->pthread.getcpuclockid = BLTN_PTHREAD_GETCPUCLOCKID;
    self->pthread.getschedparam = BLTN_PTHREAD_GETSCHEDPARAM;
    self->pthread.join          = BLTN_PTHREAD_JOIN;
    self->pthread.setschedprio  = BLTN_PTHREAD_SETSCHEDPRIO;
    self->pthread.setschedparam = BLTN_PTHREAD_SETSCHEDPARAM;
    self->pthread.setspecific   = BLTN_PTHREAD_SETSPECIFIC;
    self->pthread.self          = BLTN_PTHREAD_SELF;
    self->pthread.getspecific   = BLTN_PTHREAD_GETSPECIFIC;
    self->pthread.exit          = BLTN_PTHREAD_EXIT;
    __basedef(pthread_h, "<pthread.h>")
        __dentr(enums, Enum[])
            __predef("PTHREAD")
                EDEF_(PTHREAD,BARRIER_SERIAL_THREAD)
                //EDEF_(PTHREAD,CANCEL)
                //EDEF_(PTHREAD,CANCEL_ASYNCHRONOUS)
                //EDEF_(PTHREAD,CANCEL_ENABLE)
                //EDEF_(PTHREAD,CANCEL_DEFERRED)
                //EDEF_(PTHREAD,CANCEL_DISABLE)
                //EDEF_(PTHREAD,CANCELED)
                EDEF_(PTHREAD,CREATE_DETACHED)
                EDEF_(PTHREAD,CREATE_JOINABLE)
                EDEF_(PTHREAD,EXPLICIT_SCHED)
                EDEF_(PTHREAD,INHERIT_SCHED)
                EDEF_(PTHREAD,MUTEX_DEFAULT)
                EDEF_(PTHREAD,MUTEX_ERRORCHECK)
                EDEF_(PTHREAD,MUTEX_NORMAL)
                EDEF_(PTHREAD,MUTEX_RECURSIVE)
                //EDEF_(PTHREAD,MUTEX_ROBUST)
                //EDEF_(PTHREAD,MUTEX_STALLED)
                EDEF_(PTHREAD,ONCE_INIT)
            __preend("PTHREAD", .fmt="x", .sort=C__VSORT)
        __dexit(enums)
    __baseret(pthread_h)
    return 0;
}

#endif