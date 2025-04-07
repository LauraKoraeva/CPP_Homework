#pragma once

#include <chrono>
#include <functional> //
#include <atomic> //
#include <mutex> //
#include <condition_variable> //

class Timer
{
private:
    std::chrono::time_point<std::chrono::steady_clock> startTime;
    int durationSeconds;
    int elapsedSeconds;
    std::atomic<bool> isRunning;
    std::atomic<bool> isPaused;
    std::thread timerThread;
    std::function<void()> callback;
    std::mutex mutex;
    std::condition_variable cv;
};