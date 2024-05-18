#include "pthread.h"
#include "stdint.h"

void __dmb(void);
uint32_t __ldrex(volatile uint32_t *addr);
uint32_t __strex(uint32_t val, volatile uint32_t *addr);
void __clrex(void);

/* DMB is supported on CM0 */
void __dmb(void) { __asm__ volatile("dmb"); }

uint32_t __ldrex(volatile uint32_t *addr) {
  uint32_t res;
  __asm__ volatile("ldrex %0, [%1]" : "=r"(res) : "r"(addr));
  return res;
}

uint32_t __strex(uint32_t val, volatile uint32_t *addr) {
  uint32_t res;
  __asm__ volatile("strex %0, %2, [%1]" : "=&r"(res) : "r"(addr), "r"(val));
  return res;
}

void __clrex(void) { __asm__ volatile("clrex"); }

int pthread_spin_destroy(pthread_spinlock_t *lock) { return 0; }

// EAGAIN The system has insufficient resources to initialize a new spin lock.
// ENOMEM Insufficient memory to initialize the spin lock.
// TODO: implement EAGAIN, ENOMEM when error
int pthread_spin_init(pthread_spinlock_t *lock, int pshared) {
  lock->locked_ = 0;

  return 0;
  // return EAGAIN;
  // return ENOMEM
}

int pthread_spin_lock(pthread_spinlock_t *lock) {
  while (0 != pthread_spin_trylock(lock)) {
    ;
  }
  return 0; // success
}

int pthread_spin_trylock(pthread_spinlock_t *lock) {
  unsigned int status = __ldrex(&(lock->locked_));
  if (status == 0) {
    status = __strex(1, &(lock->locked_)); // lock
    __dmb();
    return 0; // success
  }
  return 1; // fail
}

int pthread_spin_unlock(pthread_spinlock_t *lock) {
  __dmb();

  /* Free the lock. */
  lock->locked_ = 0;

  return 0;
  // return EDEADLOCK
  // return EBUSY
}
