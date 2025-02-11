#pragma once

enum Event {
	TARGET_SHOT
};

class Observer {
public:
	virtual ~Observer() {};
	virtual void OnNotify(Event event) = 0;

private:

};