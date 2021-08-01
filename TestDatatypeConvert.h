#pragma once
#include <iostream>

// in the normal case, just the identity
template<typename T>
struct item_return { typedef T type; };
template<typename T>
typename item_return<T>::type convert_to(T from) { std::cout << &from << std::endl; return T(from); }

template<>
struct item_return<bool> { typedef char* type; };
template<>
inline char* convert_to<bool>(bool from)
{
	char vOut[7] = "";
	if (from)
	{
		strcpy(vOut,"wahr");
	}
	else
	{
		strcpy(vOut, "falsch");
		
	}
	std::cout << static_cast<void*>(vOut) << std::endl;
	return vOut;
}

template<>
struct item_return<int> { typedef char* type; };
template<>
inline char* convert_to<int>(const int from) { char * buffer = new char[sizeof(int) * 8 + 1]; _itoa(from, buffer, 10); std::cout << static_cast<void*>(buffer) << std::endl; return buffer; }

template<>
struct item_return<unsigned int> { typedef char* type; };
template<>
inline char* convert_to<unsigned int>(const unsigned int from) { char* buffer = new char[sizeof(unsigned int) * 8 + 1]; _ultoa(from, buffer, 10); std::cout << static_cast<void*>(buffer) << std::endl;  return buffer; }

template<>
struct item_return<short> { typedef char* type; };
template<>
inline char* convert_to<short>(const short from) { char* buffer = new char[sizeof(short) * 8 + 1];  _itoa(from, buffer, 10); std::cout << static_cast<void*>(buffer) << std::endl;  return buffer; }

template<>
struct item_return<unsigned short> { typedef char* type; };
template<>
inline char* convert_to<unsigned short>(const unsigned short from) { char* buffer = new char[sizeof(unsigned short) * 8 + 1];  _ultoa(from, buffer, 10); std::cout << static_cast<void*>(buffer) << std::endl;  return buffer; }

template<>
struct item_return<long> { typedef char* type; };
template<>
inline char* convert_to<long>(const long from) { char* buffer = new char[sizeof(long) * 8 + 1];  _ltoa(from, buffer, 10); std::cout << static_cast<void*>(buffer) << std::endl; return buffer; }

template<>
struct item_return<unsigned long> { typedef char* type; };
template<>
inline char* convert_to<unsigned long>(const unsigned long from) { char* buffer = new char[sizeof(unsigned long) * 8 + 1];  _ultoa(from, buffer, 10); std::cout << static_cast<void*>(buffer) << std::endl;  return buffer; }

template<>
struct item_return<float> { typedef char* type; };
template<>
inline char* convert_to<float>(const float from) { char* buffer = new char[sizeof(float) * 8 + 1]; snprintf(buffer, sizeof buffer, "%f", from); std::cout << static_cast<void*>(buffer) << std::endl;  return buffer; }

template<>
struct item_return<double> { typedef char* type; };
template<>
inline char* convert_to<double>(double from) { char* buffer = new char[sizeof(double) * 8 + 1]; snprintf(buffer, sizeof buffer, "%f", from); std::cout << static_cast<void*>(buffer) << std::endl;  return buffer; }

template<>
struct item_return<char[]> { typedef char* type; };
template<>
inline char* convert_to<char*>(char* from) { char* buffer = new char[sizeof(from) + 2]; strcpy(buffer, from); std::cout << static_cast<void*>(buffer) << std::endl; return buffer; }

inline void write(const char* value)
{
	std::cout << "Inhalt:  " << value << std::endl;
	std::cout << "Adresse: " << &value << std::endl;
	std::cout << "Adresse: " << static_cast<void*>(&value) << std::endl;
	std::cout << "-----------------------------" << std::endl;
}

template <typename T>
void WriteLog(T value)
{
	const char* creturn = convert_to(value);
	write(creturn);
	delete[] creturn;
}

//template<>
//struct item_return<const char[]> { typedef char* type; };
//
//template<>
//inline char* convert_to<const char[]>(const char* from) { return from; }
//
//template<>
//struct item_return<char> { typedef char* type; };
//
//template<>
//inline char* convert_to<char>(char from) { return from; }
//
//template<>
//struct item_return<const char> { typedef char* type; };
//
//template<>
//inline char* convert_to<const char>(const char from) { return from; }
//
//template<>
//struct item_return<std::string> { typedef char* type; };
//
//template<>
//inline char* convert_to<std::string>(std::string from) { return from;}
//
//template<>
//struct item_return<const std::string> { typedef char* type; };
//
//template<>
//inline char* convert_to<const std::string>(const std::string from) { return from; }



//	//if (is_same<byte, decltype(value)>::value) { char buffer[sizeof(byte) * 8 + 1]; _itoa(value, buffer, 10); return buffer; }
//	//if (is_same<unsigned int, decltype(newT2)>::value) { char buffer[sizeof(unsigned int) * 8 + 1];  _utoa(newT2, buffer, 10); return buffer; }
//	//if (is_same<short, decltype(newT3)>::value) { char buffer[sizeof(short) * 8 + 1];  _itoa(newT3, buffer, 10); return buffer; }
//	//if (is_same<unsigned short, decltype(newT4)>::value) { char buffer[sizeof(unsigned short) * 8 + 1];  _utoa(newT4, buffer, 10); return buffer; }
//	//if (is_same<long, decltype(newT5)>::value) { char buffer[sizeof(long) * 8 + 1];  _ltoa(newT5, buffer, 10); return buffer; }
//	//if (is_same<unsigned long, decltype(newT6)>::value) { char buffer[sizeof(unsigned long) * 8 + 1];  _ultoa(newT6, buffer, 10); return buffer; }
//	//if (is_same<float, decltype(newT7)>::value) { char buffer[sizeof(float) * 8 + 1]; snprintf(buffer, sizeof buffer, "%f", newT7); return buffer; }
//	//if (is_same<double, decltype(newT8)>::value) { char buffer[sizeof(double) * 8 + 1]; snprintf(buffer, sizeof buffer, "%f", newT8); return buffer; }
//	//if (is_same<bool, decltype(value)>::value) { char* vOut = value ? "true" : "false"; return vOut; }
//	//if (is_same<char[], decltype(newT9)>::value) { char buffer[] = value; return buffer; }
//	//if (is_same<const char[], decltype(newT10)>::value) { return newT10; }
//	//if (is_same<char, decltype(newT11)>::value) { return newT11; }
//	//if (is_same<const char, decltype(newT12)>::value) { return newT12; }
//	//if (is_same<std::string, decltype(newT13)>::value) { return newT13; }
//	//if (is_same<const std::string, decltype(newT14)>::value) { return newT14; }



// might want to stick to the following
// so you only need to update the return-type in one place
// namely, the `item_return` specialization
//template<>
//item_return<float>::type foo<float>(){ ... }
// note: No `typename` needed, because `float` is not a dependent type


//template<typename T, typename U>   //Typen ungleich, gibt 0 zurück
//struct is_same
//{
//	enum { value = 0 };
//};
//
//template<typename T>   //Typen gleich, gibt 1 zurück
//struct is_same < T, T >
//{
//	enum { value = 1 };
//};
//
//template <typename T, typename U>
//U TestDatatypeConvert::GetTypeofAndCovertToChar(T value)
//{
//	//T newT1 = (T)(int)value;
//	//T newT2 = (T)(unsigned int)value;
//	//T newT3 = (T)(short)value;
//	//T newT4 = (T)(unsigned short)value;
//	//T newT5 = (T)(long)value;
//	//T newT6 = (T)(unsigned long)value;
//	//T newT7 = (T)(float)value;
//	//T newT8 = (T)(double)value;
//	//T newT9 = (T)(char[])value;
//	//T newT10 = (T)(const char[])value;
//	//T newT11 = (T)(char)value;
//	//T newT12 = (T)(const char)value;
//	//T newT13 = (T)(std::string)value;
//	//T newT14 = (T)(const std::string)value;
//	//T newT15 = (T)(bool)value;
//	
//	//char newTT1 = (char)(int)value;
//	//T newT111 = (T)(object)value;
//	//string newT2 = (string)(object)t;
//	
//	//if (is_same<byte, decltype(value)>::value) { char buffer[sizeof(byte) * 8 + 1]; _itoa(value, buffer, 10); return buffer; }
//	//if (is_same<int, decltype(newT1)>::value) { char buffer[sizeof(int) * 8 + 1];  _itoa(newT1, buffer, 10); return buffer; }
//	//if (is_same<unsigned int, decltype(newT2)>::value) { char buffer[sizeof(unsigned int) * 8 + 1];  _utoa(newT2, buffer, 10); return buffer; }
//	//if (is_same<short, decltype(newT3)>::value) { char buffer[sizeof(short) * 8 + 1];  _itoa(newT3, buffer, 10); return buffer; }
//	//if (is_same<unsigned short, decltype(newT4)>::value) { char buffer[sizeof(unsigned short) * 8 + 1];  _utoa(newT4, buffer, 10); return buffer; }
//	//if (is_same<long, decltype(newT5)>::value) { char buffer[sizeof(long) * 8 + 1];  _ltoa(newT5, buffer, 10); return buffer; }
//	//if (is_same<unsigned long, decltype(newT6)>::value) { char buffer[sizeof(unsigned long) * 8 + 1];  _ultoa(newT6, buffer, 10); return buffer; }
//	//if (is_same<float, decltype(newT7)>::value) { char buffer[sizeof(float) * 8 + 1]; snprintf(buffer, sizeof buffer, "%f", newT7); return buffer; }
//	//if (is_same<double, decltype(newT8)>::value) { char buffer[sizeof(double) * 8 + 1]; snprintf(buffer, sizeof buffer, "%f", newT8); return buffer; }
//	//if (is_same<bool, decltype(value)>::value) { char* vOut = value ? "true" : "false"; return vOut; }
//	//if (is_same<char[], decltype(newT9)>::value) { char buffer[] = value; return buffer; }
//	//if (is_same<const char[], decltype(newT10)>::value) { return newT10; }
//	//if (is_same<char, decltype(newT11)>::value) { return newT11; }
//	//if (is_same<const char, decltype(newT12)>::value) { return newT12; }
//	//if (is_same<std::string, decltype(newT13)>::value) { return newT13; }
//	//if (is_same<const std::string, decltype(newT14)>::value) { return newT14; }
//
//	//if (is_same<char[], decltype(value)>::value) { return value; }
//
//	return "fehler";
//}
//
//template<typename T, typename U>
//T convert_to(U from) { return from; }
//
//template<>
//inline char* convert_to(int from) { char buffer[sizeof(int) * 8 + 1]; _itoa_s(from, buffer, 10); return buffer; }
//template<>
//inline const char* convert_to(bool from) { const char* vOut = from ? "true" : "false"; return vOut; }

