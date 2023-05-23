#include <sys/time.h>
#include <iostream>

class Benchmark {
public:
    Benchmark();
    ~Benchmark();
    void start();
    void stop();
    long long timeStamp();
private:
    Benchmark(const Benchmark &other);
    Benchmark &operator=(const Benchmark &rhs);
    _STRUCT_TIMEVAL _startTime;
    _STRUCT_TIMEVAL _stopTime;
    long long _timeStamp;
};