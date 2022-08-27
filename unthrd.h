

/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */
/*  SRWLock: Slim Reader/Writer Locks */
/* 
    Slim reader/writer's locks are limited to the threads of 
    a single process. They are intended for resources that
    are read more often than modified.

    At any given time:
    *   one thread may hold an exclusive (writer's) lock 
    *   many threads may hold a shared (reader's) lock

    Attempting to acquire a lock when any of the following is 
    true results in undefined behavior:
    *   lock wasn't initialized by calling SRWLock_init
    *   lock has been destroyed by calling SRWLock_destroy
    *   the calling thread already holds a lock

    The following operations are supported:

    int
    SRWLock_init(SRWLock *lock)
        Initialize lock. 
        Errors:
        *   ENOMEM 
        *   EAGAIN 
        *   EPERM

    void
    SRWLock_destroy(SRWLock *lock)
        Releases the resources allocated for lock.

    int
    SRWLock_acquireex(SRWLock *lock) 
        Request a "writer's" (exclusive) lock.
        Returns 0 on success or nonzero on failure.

    int
    SRWLock_acquiresh(SRWLock *lock) 
        Request a "reader's" (shared) lock.
        Returns 0 for success and nonzero for failure.

    int
    SRWLock_releaseex(SRWLock *lock)
        Release a previously acquired writer's lock.

    int
    SRWLock_releasesh(SRWLock *lock)
        Release a previously acquired reader's lock.

*/



#if defined(_MSC_VER)

#include <synchapi.h>

typedef SRWLOCK SRWLock;

static inline int 
SRWLock_init(SRWLock *lock) {
    return InitializeSRWLock(lock), 0;
}

static inline void
SRWLock_destroy(SRWLock *lock) {
    return 0;
}


static inline int
SRWLock_acquireex(SRWLock *lock) {
    return AcquireSRWLockExclusive(lock), 0;
}

static inline int
SRWLock_acquiresh(SRWLock *lock) {
    return AcquireSRWLockShared(lock), 0;
}

static inline int
SRWLock_releaseex(SRWLock *lock) {
    return ReleaseSRWLockExclusive(lock), 0;
}

static inline int
SRWLock_releasesh(SRWLock *lock) {
    return ReleaseSRWLockShared(lock), 0;
}

#elif defined(_POSIX_THREADS)

#include <pthread.h>

typedef pthread_rwlock_t SRWLock;

static inline int
SRWLock_init(SRWLock *lock) {
    return pthread_rwlock_init(lock, 0);
}

static inline void
SRWLock_destroy(SRWLock *lock) {
    pthread_rwlock_destroy(lock);
}

static inline int
SRWLock_acquireex(SRWLock *lock) {
    return pthread_rwlock_wrlock(lock);
}

static inline int
SRWLock_acquiresh(SRWLock *lock) {
    return pthread_rwlock_rdlock(lock);
}

static inline int
SRWLock_releaseex(SRWLock *lock) {
    return pthread_rwlock_unlock(lock);
}

#define SRWLock_releasesh SRWLock_releaseex

#else

#   error "couldn't locate a compatible threading API"

#endif /* defined (_MSC_VER) */
