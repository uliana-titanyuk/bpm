#pragma once
struct bmp {
	int Xx;
	int Yy;
	unsigned char header[54];
	unsigned char* pixels;
	int size;
};
//typedef unsigned _int16 WORD 
//typedef struct {
	//unsigned int bfType;
	//unsigned long bfSize;
	//unsigned int bfReserved1;
	//unsigned int bfReserved2;
	//int bfOffBits;
//}BITMAPFILEHEADER;
//typedef struct {
	//int biSize;
	//int biWidth;
	//int biHight;
	//unsigned short biplanes;
	//unsigned short biBitCount;
	//unsigned int biCompression;
	//unsigned int biSizeImagee;
	//int biXPerMeter;
	//int biYPerMeter;
	//unsigned int biClrUsed;
	//unsigned int biClrImportant;
//}BITMAPIFOHEADER;
//typedef struct {
	//int rgbBlue;
	//int rgbGreen;
	//int rgbRed;
	//int rgbReserved;
//}RGBQUAD;
//static unsigned short read_u16(FILE* fp);
//static unsigned int read_u32(FILE* fp);
//static int read_s32(FILE* fp);

