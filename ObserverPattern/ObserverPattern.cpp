#include <iostream>

using namespace std;

class Entity {

};

enum class Event {
	EVENT_ENTITY_FELL
};

class Observer {
public :
	virtual ~Observer() {}
	virtual void OnNotify(const Entity& entity, Event event) = 0;
};

class Subject {
public:
	void AddObserver(Observer* observer) {}
	void RemoveObserver(Observer* observer) {}
protected:
	void notify(const Entity& entity, Event event) {
		for (int i = 0; i < numObservers; ++i) {
			observers[i]->OnNotify(entity, event);
		}
	}
private:
	static const int MAX_OBSERVERS = 10;
	Observer* observers[MAX_OBSERVERS];
	int numObservers;
};
class Achievements : public Observer {
public:
	virtual void OnNotify(const Entity& entity, Event event) {
		switch (event)
		{
		case Event::EVENT_ENTITY_FELL:
			break;
		default:
			break;
		}
	}
};
class Physics : public Subject {
public:
	void updateEntity(Entity& entity) {}
};
int main()
{

	return 0;
}