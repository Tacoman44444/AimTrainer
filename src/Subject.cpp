#include "Subject.h"

Subject::Subject() {

}

void Subject::AddObserver(Observer* observer) {
	observers.push_back(observer);
}

void Subject::RemoveObserver(Observer* observer) {
	observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void Subject::Notify(Event event) {
	for (Observer* observer : observers) {
		observer->OnNotify(event);
	}
}