#include "Benchmark.hpp"

Benchmark::Benchmark() { }

Benchmark::~Benchmark() { }

void Benchmark::start() {
    gettimeofday(&_startTime, NULL);
}

void Benchmark::stop() {
    gettimeofday(&_stopTime, NULL);
}

long long Benchmark::timeStamp() {
    long long timeMs = 0;

    timeMs += _stopTime.tv_sec - _startTime.tv_sec;
    timeMs += (_stopTime.tv_usec - _startTime.tv_usec);
    return timeMs;
}

void Benchmark::setTimeVector(int timeMs) {
    this->_timeVector = timeMs;
}

void Benchmark::setTimeDeque(int timeMs) {
    this->_timeDeque = timeMs;
}

void Benchmark::setTimeDataManagement(int timeMs) {
    this->_timeDataManagement = timeMs;
}

int Benchmark::getTimeVector() {
    return _timeVector;
}

int Benchmark::getTimeDeque() {
    return _timeDeque;
}

int Benchmark::getTimeDataManagement() {
    return _timeDataManagement;
}