
//1712800.07.07.22
// https://en.cppreference.com/w/cpp/thread/thread/joinable

#include <iostream>
#include <thread>
#include <chrono>

using namespace std;
void foo()
{
    this_thread::sleep_for(chrono::seconds(1));
}

int main() 
{
    thread t;

    cout << "before starting, joinable : " << boolalpha << t.joinable() << '\n';
    
    t = thread(foo);
    cout << "after starting, joinable: " << t.joinable() << '\n';

    t.join();
    cout << "after joining, joinable: " << t.joinable() << '\n';
}