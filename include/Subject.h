#pragma once

#include "Observer.h"
#include <vector>
#include <algorithm>

class Subject {
public:
	Subject();

	void AddObserver(Observer* observer);

	void RemoveObserver(Observer* observer);

	void Notify(Event event);

private:

	std::vector<Observer*> observers;
};