#include <iostream>

using namespace std;

double GetCurrentTime() {
	return 0;
}

void ProcessInput() {

}

void Render() {

}

void Update(double elapsed) {

}

int main()
{
	// [1] 가변 시간 간격
	// 이전 프레임과의 시간 차이만큼 Update를 시킴으로써
	// fps 상관없이 동일한 계산(물리, AI)이 가능하다.
	// 그러나 고사양의 PC에서는 fps 가 높을 것이고,
	// Update 빈도가 높아지면 부동소수점 반올림 오류가 누적될 가능성이 있다.
	double previous = GetCurrentTime();
	while (true) {
		double current = GetCurrentTime();
		double elapsed = current - previous;
		previous = current;
		ProcessInput();
		Update(elapsed);
		Render();
	}
	return 0;
}