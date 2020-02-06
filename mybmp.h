#include <iostream>
#include <fstream>
#include <inttypes.h>

using namespace std;

#pragma pack(push, 1)
struct BMP_HEADER {
	char BMP_TYPE[2];
	uint32_t SIZE;
	uint16_t RESERVED1;
	uint16_t RESERVED2;
	uint32_t OFFSET;
};
#pragma pack(pop)

class MyBMP {
private:
	char *file_name;
	ifstream file_bmp;
	BMP_HEADER reg_header;

	void ReadHeader();

public:
	void OpenBmp(const char * filename);
	void PrintHeader();
};