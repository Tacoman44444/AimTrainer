#include "ButtonEvent.h"

ButtonEvent::ButtonEvent() {

}

void ButtonEvent::AddObserver(ButtonObserver* observer) {
	m_observers.push_back(observer);
}

void ButtonEvent::RemoveObserver(ButtonObserver* observer) {

}

void ButtonEvent::Notify(std::string buttonID) {
	for (ButtonObserver* observer : m_observers) {
		observer->OnNotify(buttonID);
	}
}