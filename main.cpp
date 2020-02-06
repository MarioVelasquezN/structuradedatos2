#include <iostream>
#include <fstream>
#include <limits>
#include <stdio.h>
#include <stdint.h> 
#include <inttypes.h>
#include <cstring>

using namespace std;

int main(){
	//header
	char tipo[3];
	char str_size[4];
    char filename [20];
	char reserved[4];
	char DataOffset[4];
	//info header
	char size_ih[4];
	char width_ih[4];
	char heght_ih[4];
	char planes_ih[2];
	char bit_count_ih[2];
	char compression_ih[4];
	char imageSize_ih[4];
	char XpixelsPerM_ih[4];
	char YpixelsPerM_ih[4];
	char ColorUsed_ih[4];
	char ColorImportant_ih[4];

	//header
	int dataoff;
	int size;
	int rsd;
	char bmp_header[14];
	//info header
	char bmp_infoheader[40];
	int sizehi;
	int widthih;
	int heghthi;
	uint16_t planeshi;
	uint16_t bit_countih;
	int compressionih;
	int imageSizeih;
	int XpixelsPerMih;
	int YpixelsPerMih;
	int ColorUsedih;
	int ColorImportantih;
	ifstream file_bmp;



    //cout << "Bmp file:" << flush; // force output
    //cin >> filename;
	
	file_bmp.open("m.bmp", ifstream::in|ifstream::binary);

	file_bmp.read(bmp_header, sizeof(bmp_header));
	file_bmp.read(bmp_infoheader, sizeof(bmp_infoheader));
	
	tipo[2] = '\0';
	tipo[0] = bmp_header[0];
	tipo[1] = bmp_header[1];
	printf("Tipo: %s\n", tipo);

	str_size[0] = bmp_header[2];
	str_size[1] = bmp_header[3];
	str_size[2] = bmp_header[4];
	str_size[3] = bmp_header[5];
	memcpy(&size, str_size, 4);
	printf("\nFile Size: %d\n", size);

	reserved[0] = bmp_header[6];
	reserved[1] = bmp_header[7];
	reserved[2] = bmp_header[8];
	reserved[3] = bmp_header[9];
	memcpy(&rsd, reserved, 4);
	printf("Reserve: %d\n", reserved);

	DataOffset[0] = bmp_header[10];
	DataOffset[1] = bmp_header[11];
	DataOffset[2] = bmp_header[12];
	DataOffset[3] = bmp_header[13];
	memcpy(&dataoff, DataOffset, 4);
	printf("Data Offset: %d\n", dataoff);


	//
	printf("*************Info Header****************\n");

	size_ih[0] = bmp_infoheader[0];
	size_ih[1] = bmp_infoheader[1];
	size_ih[2] = bmp_infoheader[2];
	size_ih[3] = bmp_infoheader[3];
	memcpy(&sizehi,size_ih, 4);
	printf("Size Info Header: %d\n", sizehi);

	width_ih[0] = bmp_infoheader[4];
	width_ih[1] = bmp_infoheader[5];
	width_ih[2] = bmp_infoheader[6];
	width_ih[3] = bmp_infoheader[7];
	memcpy(&widthih, width_ih, 4);
	printf("Width info header: %d\n", widthih);

	heght_ih[0] = bmp_infoheader[8];
	heght_ih[1] = bmp_infoheader[9];
	heght_ih[2] = bmp_infoheader[10];
	heght_ih[3] = bmp_infoheader[11];
	memcpy(&heghthi, heght_ih, 4);
	printf("Heght info header: %d\n", heghthi);

	planes_ih[0] = bmp_infoheader[12];
	planes_ih[1] = bmp_infoheader[13];
	memcpy(&planeshi, planes_ih, 2);
	printf("Planes ingo heaer: %d\n", planeshi);

	bit_count_ih[0] = bmp_infoheader[14];
	bit_count_ih[1] = bmp_infoheader[15];
	memcpy(&bit_countih, bit_count_ih, 2);
	printf("Bit_count info header: %d\n", bit_countih);

	compression_ih[0]=bmp_infoheader[16];
	compression_ih[1] = bmp_infoheader[17];
	compression_ih[2] = bmp_infoheader[18];
	compression_ih[3] = bmp_infoheader[19];
	memcpy(&compressionih, compression_ih, 4);
	printf("Compression info header: %d\n", compressionih);

	imageSize_ih[0]=bmp_infoheader[20];
	imageSize_ih[1] = bmp_infoheader[21];
	imageSize_ih[2] = bmp_infoheader[22];
	imageSize_ih[3] = bmp_infoheader[23];
	memcpy(&imageSizeih, imageSize_ih, 4);
	printf("ImageSize info header: %d\n", imageSizeih);

	XpixelsPerM_ih[0]=bmp_infoheader[24];
	XpixelsPerM_ih[1] = bmp_infoheader[25];
	XpixelsPerM_ih[2] = bmp_infoheader[26];
	XpixelsPerM_ih[3] = bmp_infoheader[27];
	memcpy(&XpixelsPerMih, XpixelsPerM_ih, 4);
	printf("XpixelsPerM info header: %d\n", XpixelsPerMih);

	YpixelsPerM_ih[0]=bmp_infoheader[28];
	YpixelsPerM_ih[1] = bmp_infoheader[29];
	YpixelsPerM_ih[2] = bmp_infoheader[30];
	YpixelsPerM_ih[3] = bmp_infoheader[31];
	memcpy(&YpixelsPerMih, YpixelsPerM_ih, 4);
	printf("YpixelsPerMinfo header: %d\n", YpixelsPerMih);

	ColorUsed_ih[0]=bmp_infoheader[32];
	ColorUsed_ih[1] = bmp_infoheader[33];
	ColorUsed_ih[2] = bmp_infoheader[34];
	ColorUsed_ih[3] = bmp_infoheader[35];
	memcpy(&ColorUsedih, ColorUsed_ih, 4);
	printf("ColorUsed info header: %d\n", ColorUsedih);

	ColorImportant_ih[0]=bmp_infoheader[36];
	ColorImportant_ih[1] = bmp_infoheader[37];
	ColorImportant_ih[2] = bmp_infoheader[38];
	ColorImportant_ih[3] = bmp_infoheader[39];
	memcpy(&ColorImportantih, ColorImportant_ih, 4);
	printf("ColorImportantinfo header: %d\n", ColorImportantih);



	//cout <<"\n\n\n"<<bmp_header[0] << bmp_header[1] << endl;

	file_bmp.close();

	
	system("pause");
}
//buscar la r=diferencian entre economia planeada y de libre mercado

