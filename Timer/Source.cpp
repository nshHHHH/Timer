#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;
class Timer {
public:
	Timer() {
		m_StartTimepoint = high_resolution_clock::now(); // m_StartTimepoint - chrono
	} // High_resolution_clock – таймер с минимально возможным периодом отсчетов, доступным системе.
	~Timer() {
		Stop();
	}
	void Stop() {
		auto endTimepoint = high_resolution_clock::now();
		auto start = time_point_cast<microseconds>(m_StartTimepoint).time_since_epoch().count();
		auto end = time_point_cast<microseconds>(endTimepoint).time_since_epoch().count();
		auto duration = end - start;
		double ms = duration * 0.001;
		double s = duration * 0.000001;
		double m = duration * 0.00000001;
		cout << "Time in microseconds: " << duration << endl;
		cout << "Time in mili second: " << ms << endl;
		cout << "Time in seconds: " << s << endl;
		cout << "Time in minutes: " << m << endl;
	}
private:
	time_point<high_resolution_clock> m_StartTimepoint;
};
int main(int argc, char* argv[])
{
	Timer timer;
	for (int i{ 0 }; i < 1000000000; ++i)
		int x = 10000 * 10000;
}
//private список свойств и методов для использования внутри класса 
//  public: список методов доступных другим функциям и объектам программы 
// protected список средств, доступных при наследовании
//Чтобы получить интервал времени, прошедший с момента начала отсчета, можно вызвать time_since_epoch
//duration является типом интервала времени. 
//time point - Возвращает наименьший период времени, который можно показать в целевом объекте duration , который больше или равен заданной точке времени.