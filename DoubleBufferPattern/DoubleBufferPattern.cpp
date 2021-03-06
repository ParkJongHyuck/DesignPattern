#include <iostream>

using namespace std;

class DeliveryMan
{
public:
	DeliveryMan() : hasBox(false) {}
	
	void Update() {
		if (HasBox()) {
			cout << "carry out" << endl;
			next->SendBox();
		}
	}

	void SetNextDeliveryMan(DeliveryMan* next_) { next = next_; }
	void Reset() { hasBox = false; }
	void SendBox() { hasBox = true; }
	bool HasBox() { return hasBox; }

private:
	DeliveryMan* next = nullptr;
	bool hasBox;
};

class Stage
{
public:
	void Add(DeliveryMan* man, int index) {
		deliveryMan[index] = man;
	}

	void Update() {
		for (int i = 0; i < NUM_MAN; ++i) {
			deliveryMan[i]->Update();
			deliveryMan[i]->Reset();
		}
	}
private:
	static const int NUM_MAN = 3;
	DeliveryMan* deliveryMan[NUM_MAN];
};
int main()
{
	Stage* stage = new Stage();
	DeliveryMan* tom = new DeliveryMan();
	DeliveryMan* dave = new DeliveryMan();
	DeliveryMan* cat = new DeliveryMan();

	tom->SetNextDeliveryMan(dave);
	dave->SetNextDeliveryMan(cat);
	cat->SetNextDeliveryMan(tom);

	stage->Add(tom, 0);
	stage->Add(dave, 1);
	stage->Add(cat, 2);

	cat->SendBox();

	for (int i = 0; i < 3; ++i)
	{
		cout << "[" << i << "]" << endl;
		stage->Update();
	}
	
	return 0;
}