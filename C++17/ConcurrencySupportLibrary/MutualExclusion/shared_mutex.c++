/*
https://en.cppreference.com/w/cpp/thread/shared_mutex


*/
#include <iostream>
#include <mutex>
#include <shared_mutex>
#include <thread>

using namespace std;

class ThreadSafeCounter {
    public:
        ThreadSafeCounter() = default;

        unsigned int get() const {
            shared_lock lock(mutex_);
            return value_;
        }

        unsigned int increment() {
            unique_lock lock(mutex_);
            return ++value_;
        }

        void reset() {
            unique_lock lock(mutex_);
            value_ = 0;
        }
    
    private:
        mutable shared_mutex mutex_;
        unsigned int value_ = 0;

};


int main() {
    ThreadSafeCounter counter;

    auto increment_and_print = [&counter]() {
        for (int i = 0; i < 3; i++) {
            cout << this_thread::get_id() << ' ' << counter.increment() << '\n';
        }
    };

    thread thread1(increment_and_print);
    thread thread2(increment_and_print);

    thread1.join();
    thread2.join();
}