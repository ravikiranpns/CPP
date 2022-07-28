// https://en.cppreference.com/w/cpp/thread/timed_mutex/try_lock_for
#include <iostream>
#include <mutex>
#include <chrono>
#include <thread>
#include <vector>
#include <sstream>

using namespace std;
using namespace std::chrono_literals;

mutex cout_mutex;
timed_mutex mutex_lock;

void job(int id)
{
    ostringstream stream;

    for (int i = 0; i < 3; ++i) {
        if (mutex_lock.try_lock_for(100ms)) {
            stream << "success ";
            this_thread::sleep_for(100ms);
            mutex_lock.unlock();
        } else {
            stream << "failed ";
        }
        this_thread::sleep_for(100ms);
    }

    lock_guard<mutex> lock{cout_mutex};
    cout << "[" << id << "] " << stream.str() << "\n";
}

int main() 
{
    vector<thread> threads;
    for (int i = 0; i < 4; ++i) {
        threads.emplace_back(job, i);
    }

    for (auto& i: threads) {
        i.join();
    }
}