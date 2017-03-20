#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <math.h>
#include <windows.h>

#include "mat.cpp"

using namespace std;

int thinning() {
	
	BITMAPFILEHEADER fileheader;
	BITMAPINFOHEADER infoheader;
	
	FILE *pic = fopen("./h.bmp", "rb");
	FILE *picout = fopen("./skeleton.bmp", "wb");
	
	fread(&fileheader, sizeof(BITMAPFILEHEADER), 1, pic);
	fread(&infoheader, sizeof(BITMAPINFOHEADER), 1, pic);
	
	int height = infoheader.biHeight;
	int width = infoheader.biWidth;
	int picsize = height * width;
	
	unsigned char img[height*width*4];
	
	for (int i = 0; i < height*width*4; i++) {
		img[i] = 0;
	}
	
	//skeleton
	
	//read input image
	unsigned char input_img[height*width*3];
	fread(&input_img, height*width*3, 1, pic);
	
	//threshold
	int thre = 120;
	
	int *skt_idx;
	
	skt_idx = skt(input_img, height, width, thre);
	
	int tpp;
	
	for (int i = 0; i < height*width*4; i++) {
		
		tpp = *skt_idx;
		img[i] = tpp;
		skt_idx++;
		
	}
	
	
	//save
	
	infoheader.biBitCount = 32;
	
	fwrite(&fileheader, sizeof(BITMAPFILEHEADER), 1, picout);
	fwrite(&infoheader, sizeof(BITMAPINFOHEADER), 1, picout);
	fwrite(img, picsize, 4, picout);
	
	fclose(pic);
	fclose(picout);
	
	return 0;
	
}

int main() {
	thinning();
}