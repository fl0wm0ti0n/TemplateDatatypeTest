#pragma once
// TemplateDatatypeTest.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <chrono>
#include <iostream>
#include <string>

#include "logger.h"
#include "TestDatatypeConvert.h"
#include "TestVariableBehavior.h"
using namespace std::chrono;

int main()
{
	auto start = std::chrono::steady_clock::now();
	char chaar[] = "Logging";
	logger* logger = logger::GetInstance(debug, serial, chaar);
		while (true)
		{
			static const char* const buffer = "Zwischenzeit: ";
			logger->LnWriteLog(buffer, debug);
			
			auto end = std::chrono::steady_clock::now();
			unsigned int ms = duration_cast<milliseconds>(end - start).count();

			logger->WriteLog(ms, debug);

			//delete buffer;
		}

	//std::cout << "--ret-pointer-heap--" << std::endl;
	//int varint = 111;
	////char char1[sizeof(int) * 8 + 1];
	////strcpy(char1, convert_int_to_char_ret_pointer_to_heap(varint));
	//char* pointer = convert_int_to_char_ret_pointer_to_heap(varint);
	//std::cout << "Inhalt:  " << pointer << std::endl;
	//std::cout << "Adresse: " << static_cast<void*>(pointer) << std::endl;
	//std::cout << "Adresse: " << static_cast<void*>(&pointer) << std::endl;
	//std::cout << "-----------------------------" << std::endl;

	//std::cout << "--ret-pointer-stack--" << std::endl;
	//int varint1 = 222;
	////char char1[sizeof(int) * 8 + 1];
	////strcpy(char1, convert_int_to_char_ret_pointer_to_heap(varint));
	//char* pointer1 = convert_int_to_char_ret_pointer_to_stack(varint1);
	//// Lokale variable wurde gelöscht
	//std::cout << "Inhalt:  " << pointer1 << std::endl; // direkt darauf wird der inhalt der lokalen variable gelöscht... der pointer ist leer
	//std::cout << "Adresse: " << static_cast<void*>(pointer1) << std::endl;
	//std::cout << "Adresse: " << static_cast<void*>(&pointer1) << std::endl;
	//std::cout << "-----------------------------" << std::endl;

	//std::cout << "--ret-pointer-heap-strcpy--" << std::endl;
	//int varint2 = 333;
	//char char2[sizeof(int) * 8 + 1];
	//strcpy(char2, convert_int_to_char_ret_pointer_to_heap(varint2));
	//std::cout << "Inhalt:  " << char2 << std::endl;
	//std::cout << "Adresse: " << static_cast<void*>(char2) << std::endl;
	//std::cout << "Adresse: " << static_cast<void*>(&char2) << std::endl;
	//std::cout << "-----------------------------" << std::endl;

	//std::cout << "--ret-pointer-stack-strcpy--" << std::endl;
	//int varint3 = 444;
	//char char1[sizeof(int) * 8 + 1];
	//strcpy(char1, convert_int_to_char_ret_pointer_to_stack(varint3));
	//// Lokale variable wurde gelöscht
	//std::cout << "Inhalt:  " << char1 << std::endl;
	//std::cout << "Adresse: " << static_cast<void*>(char1) << std::endl;
	//std::cout << "Adresse: " << static_cast<void*>(&char1) << std::endl;
	//std::cout << "----------------------------" << std::endl;

	//std::cout << "--send-ref-convert-there--" << std::endl;
	//int varint4 = 555;
	//char char3[sizeof(int) * 8 + 1];
	//convert_int_to_char_ref(varint4, *char3);
	//std::cout << "Inhalt:  " << char3 << std::endl;
	//std::cout << "Adresse: " << static_cast<void*>(char3) << std::endl;
	//std::cout << "Adresse: " << static_cast<void*>(&char3) << std::endl;
	//std::cout << "----------------------------" << std::endl;

	//std::cout << "-var-before-delete---" << std::endl;
	//std::cout << "Inhalt:  " << pointer << std::endl;
	//std::cout << "Adresse: " << static_cast<void*>(pointer) << std::endl;
	//std::cout << "Inhalt:  " << pointer1 << std::endl;
	//std::cout << "Adresse: " << static_cast<void*>(pointer1) << std::endl;
	//std::cout << "Inhalt:  " << char2 << std::endl;
	//std::cout << "Adresse: " << static_cast<void*>(char2) << std::endl;
	//std::cout << "Inhalt:  " << char1 << std::endl;
	//std::cout << "Adresse: " << static_cast<void*>(char1) << std::endl;
	//std::cout << "Inhalt:  " << char3 << std::endl;
	//std::cout << "Adresse: " << static_cast<void*>(char3) << std::endl;
	//std::cout << "-----------------------------" << std::endl;
	//
	//std::cout << "--Delete Variables-----" << std::endl;
	//delete [] pointer;
	////delete pointer1;
	////delete char2;
	////delete char1;
	////delete char3;
	//std::cout << "-----------------------------" << std::endl;

	
	//std::cout << "-var-after-delete---" << std::endl;
	//std::cout << "Inhalt:  " << pointer << std::endl;
	//std::cout << "Adresse: " << static_cast<void*>(pointer) << std::endl;
	//std::cout << "Inhalt:  " << pointer1 << std::endl;
	//std::cout << "Adresse: " << static_cast<void*>(pointer1) << std::endl;
	//std::cout << "Inhalt:  " << char2 << std::endl;
	//std::cout << "Adresse: " << static_cast<void*>(char2) << std::endl;
	//std::cout << "Inhalt:  " << char1 << std::endl;
	//std::cout << "Adresse: " << static_cast<void*>(char1) << std::endl;
	//std::cout << "Inhalt:  " << char3 << std::endl;
	//std::cout << "Adresse: " << static_cast<void*>(char3) << std::endl;


	const int varint4 = -99;
	const char varchar5[] = "Test1";
	WriteLog(varint4);
	WriteLog(varchar5);
	
	std::cout << "----" << std::endl;
	char varchar1[] = "Test";
	char* pointer = convert_char_to_char(varchar1);
	std::cout << "Inhalt:  " << pointer << std::endl;
	std::cout << "Adresse: " << static_cast<void*>(pointer) << std::endl;
	std::cout << "Adresse: " << static_cast<void*>(&pointer) << std::endl;
	std::cout << "-----------------------------" << std::endl;
	delete[] pointer;

	const int varint2 = -99;
	char *buffer22 = convert_to(varint2);
	std::cout << "Inhalt:  " << buffer22 << std::endl;
	std::cout << "Adresse: " << static_cast<void*>(buffer22) << std::endl;
	std::cout << "Adresse: " << static_cast<void*>(&buffer22) << std::endl;
	std::cout << "-----------------------------" << std::endl;
	delete[] buffer22;

	std::cout << "----" << std::endl;
	char varchar[] = "Test1";
	char* buffer = convert_to(varchar);
	std::cout << "Inhalt:  " << buffer << std::endl;
	std::cout << "Adresse: " << static_cast<void*>(buffer) << std::endl;
	std::cout << "Adresse: " << static_cast<void*>(&buffer) << std::endl;
	std::cout << "-----------------------------" << std::endl;
	delete[] buffer;
	
	std::string varstring = "Test2";
	auto varch2 = convert_to(varstring);
	std::cout << varch2 << std::endl;
	std::cout << &varch2 << std::endl;
	
	const int varint = -99;
	//auto * varch5 = convert_to(varint);
	char char3[sizeof(int) * 8 + 1];
	strcpy(char3, convert_to(varint));
	std::cout << char3 << std::endl;
	std::cout << static_cast<void*>(char3) << std::endl;
	
	const unsigned int varuint = 99;
	//auto* varch6 = convert_to(varuint);
	char char4[sizeof(unsigned int) * 8 + 1];
	strcpy(char4, convert_to(varuint));
	std::cout << char4 << std::endl;
	std::cout << static_cast<void*>(char4) << std::endl;
	
	const long varlong = -99999999;
	//auto* varch7 = convert_to(varlong);
	char char5[sizeof(long) * 8 + 1];
	strcpy(char5, convert_to(varlong));
	std::cout << char5 << std::endl;
	std::cout << static_cast<void*>(char5) << std::endl;
	
	const unsigned long varulong = 99999999;
	//auto* varch8 = convert_to(varulong);
	char char6[sizeof(unsigned long) * 8 + 1];
	strcpy(char6, convert_to(varulong));
	std::cout << char6 << std::endl;
	std::cout << static_cast<void*>(char6) << std::endl;
	
	const short varshort = -888;
	//auto* varch9 = convert_to(varshort);
	char char7[sizeof(short) * 8 + 1];
	strcpy(char7, convert_to(varshort));
	std::cout << char7 << std::endl;
	std::cout << static_cast<void*>(char7) << std::endl;

	const unsigned short varushort = 8888;
	//auto* varch10 = convert_to(varushort);
	char char8[sizeof(unsigned long) * 8 + 1];
	strcpy(char8, convert_to(varushort));
	std::cout << char8 << std::endl;
	std::cout << static_cast<void*>(char8) << std::endl;

	const float varfloat = 99.9f;
	//auto* varch11 = convert_to(varfloat);
	char char9[sizeof(float) * 8 + 1];
	strcpy(char9, convert_to(varfloat));
	std::cout << char9 << std::endl;
	std::cout << static_cast<void*>(char9) << std::endl;

	const double vardouble = 999.99;
	//auto* varch12 = convert_to(vardouble);
	char char10[sizeof(double) * 8 + 1];
	strcpy(char10, convert_to(vardouble));
	std::cout << char10 << std::endl;
	std::cout << static_cast<void*>(char10) << std::endl;

	bool varbool = true;
	//auto* varch3 = convert_to(varbool);
	char char1[sizeof(bool) * 8 + 1];
	strcpy(char1, convert_to(varbool));
	std::cout << char1 << std::endl;
	std::cout << static_cast<void*>(char1) << std::endl;

	varbool = false;
	//auto* varbool = convert_to(varbool);
	char char2[sizeof(bool) * 8 + 1];
	strcpy(char2, convert_to(varbool));
	std::cout << char2 << std::endl;
	std::cout << static_cast<void*>(char2) << std::endl;
}