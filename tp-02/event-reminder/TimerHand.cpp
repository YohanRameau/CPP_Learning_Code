#include "TimerHand.h"

MinuteHand::MinuteHand()  
    : _minutes {0}
    {}

unsigned int MinuteHand::get_minutes() const{
    return _minutes;
}

void MinuteHand::advance(){
    _minutes++;
}

SecondHand::SecondHand(MinuteHand& minuteHand)
    : _min_hand {minuteHand} , _seconds {0} 
    {}

unsigned int SecondHand::get_seconds() const{
    return _seconds;
}

void SecondHand::advance(){
    if(++_seconds == 60)
    {
        _min_hand.advance();
        _seconds = 0;

    }
}

Clock::Clock(MinuteHand& minuteHand)
    : _min_hand {minuteHand} , _sec_hand {SecondHand(_min_hand)}
    {}

void delete_events(std::vector<Event> events, int current_min, int current_sec)
{
    for (size_t i = 0; i < events.size(); i++)
    {
        auto ev = events[i];
        if(ev.notify_time(current_min , current_sec))
        {
            events.erase(events.begin() + i);
            return delete_events(events, current_min, current_sec);
        }
    }
    return;
}

void Clock::tick()
{
    delete_events(_events ,_min_hand.get_minutes(), _sec_hand.get_seconds());
    _sec_hand.advance();
    
    
}
void Clock::add_events(const Event& event)
{
    _events.emplace_back(event);
}