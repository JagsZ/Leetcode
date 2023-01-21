#include "semaphore.h"
class Foo {
    protected:
        sem_t first_job_done;
        sem_t second_job_done; 
public:
    Foo() {
        sem_init(&first_job_done, 0, 0);
        sem_init(&second_job_done, 0, 0);
    }

    void first(function<void()> printFirst) {
        //cout<<1<<endl;
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        sem_post(&first_job_done);
    }

    void second(function<void()> printSecond) {
        sem_wait(&first_job_done);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        sem_post(&second_job_done);
    }

    void third(function<void()> printThird) {
        sem_wait(&second_job_done);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};