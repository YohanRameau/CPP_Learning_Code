#pragma once

#include <string>
#include <utility>
#include <iostream>

// Contains the number of minutes first, and then the number of seconds.
using Time = std::pair<unsigned int, unsigned int>;

class Event
{
public:
    Event(const Time& notif_time, const std::string& message)
        : _notif_time { notif_time }
        , _message { message }
    {}
    bool notify_time(int current_min, int current_sec)
    {
        int min = _notif_time.first;
        int sec = _notif_time.second;
        if(min == current_min && sec == current_sec)
        {
            std::cout << _message << std::endl;
            return true;
        }
        return false;
    }

private:
    const Time        _notif_time;
    const std::string _message;
};
