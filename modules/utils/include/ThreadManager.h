#pragma once

#include <iostream>
#include <pthread.h>
#include <stdexcept>
#include <thread>

namespace utils
{

class ThreadManager
{
public:
	template<typename FuncType, typename... ArgTypes>
	static void DetachThread(FuncType func, ArgTypes &&...args)
	{
		auto lambda = [func](auto &...args) {
			try
			{
				func(args...);
			} catch (const std::exception &ex)
			{
				std::cout << ex.what();
			} catch (...)
			{
				std::cout << "Unknown exception in a detached thread...";
			}
		};

		try
		{
			//std::thread{func, std::forward<ArgTypes>(args)...}.detach();
			std::thread{lambda, std::forward<ArgTypes>(std::ref(args))...}.detach();
		} catch (const std::exception &ex)
		{
			std::cout << ex.what();
		} catch (...)
		{
			std::cout << "Unknown exception either on thread creation or on thread detach";
		}
	}
};

}// namespace utils
