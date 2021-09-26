#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include"main.h"

int main()
{
	FILE* f = fopen("pic.bpm", "rb");
	if (!f) return -1;
	bmp pic;
	fread(pic.header, sizeof(unsigned char), 54, f);
	pic.Xx = *(int*)&pic.header[18];
	pic.Yy = *(int*)&pic.header[22];
	pic.size = 3 * pic.Xx * pic.Yy;
	pic.pixels = new unsigned char[pic.size];
	fread(pic.pixels, sizeof(unsigned char), pic.size, f);
	fclose(f);
	bmp newpic;
	newpic.header[18]= pic.Yy;
	newpic.header[22] = pic.Xx;
	newpic.Xx = pic.Yy;
	newpic.Yy = pic.Xx;
	newpic.size = pic.size;
	newpic.pixels = new unsigned char[pic.size];
	FILE* out = fopen("pic2.bpm", "wb");
	for (int x = 0; x < newpic.Xx; x++) {
		for (int y = 0; y < newpic.Yy; y++) {
			size_t new_index = newpic.Xx * x + y;
			size_t old_index = pic.Xx * y + x;
			newpic.pixels[new_index] = pic.pixels[old_index];
			newpic.pixels[new_index+1] = pic.pixels[old_index+1];
			newpic.pixels[new_index+2] = pic.pixels[old_index+2];
		}
	}
	fwrite(newpic.header, sizeof(unsigned char), 54, out);
	for (int i = 0; i < newpic.size; i +=3) {
	fwrite(&(newpic.pixels[i]), sizeof(unsigned char),3 ,out);
}
	delete[] pic.pixels;
	delete[] newpic.pixels;
	fclose(out);
	return 0;
}
