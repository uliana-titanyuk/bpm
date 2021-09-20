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
	for (int i = 0; i < pic.size; i += 3) {
		unsigned char tpm = pic.pixels[i];
		pic.pixels[i] = pic.pixels[i + 2];
		pic.pixels[i + 2]=tpm;
	}
	bmp newpic;
	newpic.Xx = pic.Yy;
	newpic.Yy = pic.Xx;
	newpic.size = pic.size;
	for (int x = 0; x < newpic.Xx;x++) {
		for (int y = 0; y < newpic.Yy;y ++) {
			newpic.pixels[x * newpic.Xx + y] = pic.pixels[y * newpic.Xx + x];
		}
	}
	FILE* out = fopen("pic2.bpm", "wb");
	fclose(out);
	fwrite(newpic.header, sizeof(unsigned char), 54, out);
		for (int i = 0; i < pic.size; i += 3) {
			unsigned char tpm = pic.pixels[i];
			pic.pixels[i] = pic.pixels[i + 2];
			pic.pixels[i + 2] = tpm;
		}
		return 0;
}
