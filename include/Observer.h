#pragma once
#include "vec3.h"

enum EventType {
	TARGET_SHOT,
	TARGETS_MISSED,
};

struct Event {
	EventType type;
	vec3 targetPosition;
};

class Observer {
public:
	virtual ~Observer() {};
	virtual void OnNotify(const Event& event) = 0;

private:

};