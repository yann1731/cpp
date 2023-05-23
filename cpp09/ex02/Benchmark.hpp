#include <sys/time.h>
#include <iostream>

class Benchmark {
public:
    Benchmark();
    ~Benchmark();
    void start();
    void stop();
    long long timeStamp();
    void setTimeVector(int timeMs);
    void setTimeDeque(int timeMs);
    void setTimeDataManagement(int timeMs);
    int getTimeVector();
    int getTimeDeque();
    int getTimeDataManagement();
private:
    Benchmark(const Benchmark &other);
    Benchmark &operator=(const Benchmark &rhs);
    _STRUCT_TIMEVAL _startTime;
    _STRUCT_TIMEVAL _stopTime;
    long long _timeStamp;
    long long _timeVector;
    long long _timeDeque;
    long long _timeDataManagement;
};