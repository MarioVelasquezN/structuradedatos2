#include <limits>
#include <stdio.h>
#include <stdint.h> 
#include <cstring>
#include "mybmp.h"

using namespace std;

void MyBMP::ReadHeader() {
	file_bmp.seekg(0, ios_base::beg);
	file_bmp.read((char *)&reg_header, sizeof(reg_header));
}

void MyBMP::OpenBmp(const char * filename) {
	file_name = (char *)filename;
	file_bmp.open(filename, ifstream::in | ifstream::binary);
	ReadHeader();
}

void MyBMP::PrintHeader() {
	char type[3];
	
	type[0] = reg_header.BMP_TYPE[0];
	type[1] = reg_header.BMP_TYPE[1];
	type[2] = '\0';//son null terminated en c++, que si tiene hola en char * realmente lo que se tiene es "hola\0"
	 //memcpy(type, &reg_header.BMP_TYPE, 2);
	
	cout << "********************************************" << endl;
	cout << "Tipo: " << type << endl;
	cout << "Size: " << reg_header.SIZE << endl;
	cout << "Reservado 1: " << reg_header.RESERVED1 << endl;
	cout << "Reservado 2: " << reg_header.RESERVED2 << endl;
	cout << "Offset: " << reg_header.OFFSET << endl;
	cout << "********************************************" << endl;
}


//hacer un 
//char *   el unpack tieen que agarrar todo y empaquetarlos en el char*
//class BMPHeader{
//UnPack
//};

//ami me toca el ELF para la expo el jueves
//por que el bmp utiliza memoria en par, por que desperdicia un byte
//cuando usamos el pragma y cuando no? cuando usa struct