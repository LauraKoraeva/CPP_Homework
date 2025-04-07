#include <iostream>
#include "Timer.h"

Timer::Timer() : isRunning(false), isPaused(false), durationSeconds(0), elapsedSeconds(0) { }

void Timer::start(int inDurationSeconds, std::function<void()> inCallback)
{
    if (isRunning)
    {
        std::cerr << "Timer is already running.\n";
        return;
    }

    startTime = std::chrono::steady_clock::now();
    durationSeconds = inDurationSeconds;
    elapsedSeconds = 0; // 
    isRunning = true;
    isPaused = false; //
    callback = inCallback;

    timerThread = std::thread([this]() 
    {
        std::unique_lock<std::mutex> lock(mutex);
        auto start = std::chrono::steady_clock::now();

        while (isRunning && elapsedSeconds < durationSeconds)
        {
            while (isPaused)
            {
                cv.wait(lock);
            }

            auto now = std::chrono::steady_clock::now();
            int elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - start).count();

            if (elapsed > 0)
            {
                elapsedSeconds += elapsed;
                start = now;
            }

            if (elapsedSeconds < durationSeconds)
            {
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
        }

        isRunning = false;
        if(callback)
        {
            callback();
        }
    });
    timerThread.detach(); //
    
}


void Timer::pause()
{
    if (isRunning && !isPaused)
    {
        std::unique_lock<std::mutex> lock(mutex);
        isPaused = true;
        std::cout << "Timer paused.\n";
    }
}


void Timer::resume()
{
    if (isRunning && isPaused)
    {
        std::unique_lock<std::mutex> lock(mutex);
        isPaused = false;
        cv.notify_one();
        std::cout << "Timer resumed.\n";
    }
}


void Timer::stop()
{
    if (isRunning)
    {
        std::unique_lock<std::mutex> lock(mutex);
        isRunning = false;
        isPaused = false;
        cv.notify_one();

        if (timerThread.joinable())
        {
            timerThread.join();
        }
        std::cout << "Timer stopped.\n";
    }
    else
    {
        std::cout << "Timer not running.\n";
    }
}