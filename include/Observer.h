#pragma once

enum Event {
	TARGET_SHOT,
	BUTTON_CLICKED
};

class Observer {
public:
	virtual ~Observer() {};
	virtual void OnNotify(Event event) = 0;

private:

};