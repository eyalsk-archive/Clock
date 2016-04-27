#include "event.h"

std::list<Event::Callback>::size_type Event::_idCounter = 0;

Event::Callback::Callback(std::function<void(Event*)> func)
    : _id(_idCounter++), _func(func)
{
}

void Event::Callback::operator()(Event* e) const
{
    _func(e);
}

std::list<Event::Callback>::size_type Event::Callback::GetID() const
{
    return _id;
}

Event::Callback Event::Attach(std::function<void(Event*)> func)
{
    Callback callback = Callback(func);
    _callbacks.push_back(callback);
    return callback;
}

void Event::Detach(Callback& callback)
{
    _callbacks.remove(callback);
}

void Event::Notify()
{
    for (auto callback : _callbacks) {
        callback(this);
    }
}

std::list<Event::Callback>::size_type Event::Size() const
{
    return _callbacks.size();
}

bool Event::Contains(Callback& callback)
{
    return std::find(_callbacks.begin(), _callbacks.end(), callback) != _callbacks.end();
}

bool operator==(const Event::Callback& lhs, const Event::Callback& rhs)
{
    return lhs.GetID() == rhs.GetID();
}

bool operator!=(const Event::Callback& lhs, const Event::Callback& rhs)
{
    return !operator==(lhs, rhs);
}
