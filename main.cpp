#include <iostream>
#include <thread>
#include <zconf.h>
#include "Watery/Engine/Timer/timer.h"

void func(void)
{
	watery::Timer timer(500000);
	timer.reset();
	
	for (int i = 0;;)
	{
		std::this_thread::sleep_for(std::chrono::microseconds(5000));
		if (timer.time_out())
		{
			i++;
			std::cout << ("Hello " + std::to_string(i)) << std::endl;
			timer.set_time_out(1000000 - timer.elapsed_time());
			timer.reset();
		}
	}
}

void func2(void)
{
	watery::Timer timer(500000);
	timer.reset();
	
	for (int i = 0;;)
	{
		if (timer.time_out())
		{
			i++;
			std::cout << ("Bye " + std::to_string(i)) << std::endl;
			timer.set_time_out(1000000 - timer.elapsed_time());
			timer.reset();
		}
	}
}

int main(void)
{
	std::thread t1(func);
	std::thread t2(func);
	std::thread t3(func);
	std::thread t4(func);
	std::thread t5(func);
	std::thread t6(func);
	std::thread t7(func);
	std::thread t8(func);
	std::thread t9(func);
	std::thread t10(func);
	std::thread t11(func);
	std::thread t12(func);
	std::thread t13(func);
	std::thread t14(func);
	std::thread t15(func);
	std::thread t16(func);
	std::thread t17(func);
	std::thread t18(func);
	std::thread t19(func);
	std::thread t20(func);
	
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();
	t7.join();
	t8.join();
	t9.join();
	t10.join();
	t11.join();
	t12.join();
	t13.join();
	t14.join();
	t15.join();
	t16.join();
	t17.join();
	t18.join();
	t19.join();
	t20.join();
	
	return 0;
}