#pragma once
#include <iostream>

inline char* convert_int_to_char_ret_pointer_to_heap(int from)
{
	char* buffer = new char[sizeof(int) * 8 + 1];

	std::cout << static_cast<void*>(buffer) << std::endl;

	_itoa(from, buffer, 10);

	std::cout << static_cast<void*>(buffer) << std::endl;

	return buffer;
}

inline char* convert_int_to_char_ret_pointer_to_stack(int from)
{
	char buffer[sizeof(int) * 8 + 1];

	std::cout << static_cast<void*>(buffer) << std::endl;

	_itoa(from, buffer, 10);

	std::cout << static_cast<void*>(buffer) << std::endl;

	return buffer;
}

inline void convert_int_to_char_ref(int& from, char &to)
{
	//char* buffer = new char[sizeof(int) * 8 + 1];

	std::cout << static_cast<void*>(&to) << std::endl;

	_itoa(from, &to, 10);

	std::cout << static_cast<void*>(&to) << std::endl;
}

inline char* convert_char_to_char(char* from)
{
	char* buffer = new char[sizeof(int) * 8 + 1];

	strcpy(buffer, from);
	
	std::cout << static_cast<void*>(buffer) << std::endl;

	std::cout << static_cast<void*>(buffer) << std::endl;

	return buffer;
}