#pragma once
#include <functional>
#include <list>

class Event final {
public:
	void Attach(std::function<void(Event*)> func);
	void Detach(std::function<void(Event*)> func);
	void Notify();
private:
	std::list<std::function<void(Event*)>> _funcs;
};