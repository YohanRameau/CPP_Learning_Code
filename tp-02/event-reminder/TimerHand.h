#pragma once

#include "Event.h"
#include <vector>

class MinuteHand
{
private:
    unsigned int _minutes;
public:
    MinuteHand();
    unsigned int get_minutes() const;
    void advance(); 
};

class SecondHand
{
private:
    unsigned int _seconds;
    MinuteHand&  _min_hand;
public:
    SecondHand();
    SecondHand(MinuteHand&);
    unsigned int get_seconds() const;
    void advance();
};

class Clock
{
private:
    std::vector<Event> _events = std::vector<Event>();
    MinuteHand&         _min_hand;
    SecondHand        _sec_hand;
public:
    void tick();
    Clock();
    Clock( MinuteHand&);
    Clock(MinuteHand, SecondHand);
    void add_events(const Event&);
     
};

int main(int argc, char const *argv[])
{
    MinuteHand m;
    SecondHand secondHand{m};

    return 0;
}
