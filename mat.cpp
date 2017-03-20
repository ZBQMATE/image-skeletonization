using namespace std;

int* skt(unsigned char ipt[], int height, int width, int thre) {
	
	unsigned char cvs[height*width*4];
	
	for (int i = 0; i < height*width*4; i++) {
		cvs[i] = 0;
	}
	
	//into binary picture
	for (int c = 0; c < height*width; c++) {
		if (ipt[c*3] > thre) {
			cvs[c*4] = 255;
		}
	}
	
	
	//first loop
	
	int np = 0;
	int tp = 0;
	int c_con;
	int d_con;
	
	for (int ca = 1; ca < height-1; ca++) {
		for (int cb = 1; cb < width-1; cb++) {
			
			
			//condition a
			//p2
			if(cvs[((ca+1)*width+cb)*4] == 255) {np++;}
			//p3
			if(cvs[((ca+1)*width+cb+1)*4] == 255) {np++;}
			//p4
			if(cvs[((ca)*width+cb+1)*4] == 255) {np++;}
			//p5
			if(cvs[((ca-1)*width+cb+1)*4] == 255) {np++;}
			//p6
			if(cvs[((ca-1)*width+cb)*4] == 255) {np++;}
			//p7
			if(cvs[((ca-1)*width+cb-1)*4] == 255) {np++;}
			//p8
			if(cvs[((ca)*width+cb-1)*4] == 255) {np++;}
			//p9
			if(cvs[((ca+1)*width+cb-1)*4] == 255) {np++;}
			
			
			//condition b
			//p3 - p2
			if (cvs[((ca+1)*width+cb+1)*4] - cvs[((ca+1)*width+cb)*4] == 255) {tp++;}
			//p4 - p3
			if (cvs[((ca)*width+cb+1)*4] - cvs[((ca+1)*width+cb+1)*4] == 255) {tp++;}
			//p5 - p4
			if (cvs[((ca-1)*width+cb+1)*4] - cvs[((ca)*width+cb+1)*4] == 255) {tp++;}
			//p6 - p5
			if (cvs[((ca-1)*width+cb)*4] - cvs[((ca-1)*width+cb+1)*4] == 255) {tp++;}
			//p7 - p6
			if (cvs[((ca-1)*width+cb-1)*4] - cvs[((ca-1)*width+cb)*4] == 255) {tp++;}
			//p8 - p7
			if (cvs[((ca)*width+cb-1)*4] - cvs[((ca-1)*width+cb-1)*4] == 255) {tp++;}
			//p9 - p8
			if (cvs[((ca+1)*width+cb-1)*4] - cvs[((ca)*width+cb-1)*4] == 255) {tp++;}
			//p2 - p9
			if (cvs[((ca+1)*width+cb)*4] - cvs[((ca+1)*width+cb-1)*4] == 255) {tp++;}
			
			
			//condition c, p2*p4*p6
			c_con = cvs[((ca+1)*width+cb)*4] * cvs[((ca)*width+cb+1)*4] * cvs[((ca-1)*width+cb)*4];
			
			//condition d, p4*p6*p8
			d_con = cvs[((ca)*width+cb+1)*4] * cvs[((ca-1)*width+cb)*4] * cvs[((ca)*width+cb-1)*4];
			
			if (np >= 2 & np <= 6 & tp == 1 & c_con == 0 & d_con == 0) {
				cvs[(ca * width + cb) * 4] = 0;
			}
			
			np = 0;
			tp = 0;
			
		}
	}
	
	//second loop
	for (int ca = 1; ca < height-1; ca++) {
		for (int cb = 1; cb < width-1; cb++) {
			
			//condition a
			//p2
			if(cvs[((ca+1)*width+cb)*4] == 255) {np++;}
			//p3
			if(cvs[((ca+1)*width+cb+1)*4] == 255) {np++;}
			//p4
			if(cvs[((ca)*width+cb+1)*4] == 255) {np++;}
			//p5
			if(cvs[((ca-1)*width+cb+1)*4] == 255) {np++;}
			//p6
			if(cvs[((ca-1)*width+cb)*4] == 255) {np++;}
			//p7
			if(cvs[((ca-1)*width+cb-1)*4] == 255) {np++;}
			//p8
			if(cvs[((ca)*width+cb-1)*4] == 255) {np++;}
			//p9
			if(cvs[((ca+1)*width+cb-1)*4] == 255) {np++;}
			
			
			//condition b
			//p3 - p2
			if (cvs[((ca+1)*width+cb+1)*4] - cvs[((ca+1)*width+cb)*4] == 255) {tp++;}
			//p4 - p3
			if (cvs[((ca)*width+cb+1)*4] - cvs[((ca+1)*width+cb+1)*4] == 255) {tp++;}
			//p5 - p4
			if (cvs[((ca-1)*width+cb+1)*4] - cvs[((ca)*width+cb+1)*4] == 255) {tp++;}
			//p6 - p5
			if (cvs[((ca-1)*width+cb)*4] - cvs[((ca-1)*width+cb+1)*4] == 255) {tp++;}
			//p7 - p6
			if (cvs[((ca-1)*width+cb-1)*4] - cvs[((ca-1)*width+cb)*4] == 255) {tp++;}
			//p8 - p7
			if (cvs[((ca)*width+cb-1)*4] - cvs[((ca-1)*width+cb-1)*4] == 255) {tp++;}
			//p9 - p8
			if (cvs[((ca+1)*width+cb-1)*4] - cvs[((ca)*width+cb-1)*4] == 255) {tp++;}
			//p2 - p9
			if (cvs[((ca+1)*width+cb)*4] - cvs[((ca+1)*width+cb-1)*4] == 255) {tp++;}
			
			
			//condition c, p2*p4*p8
			c_con = cvs[((ca+1)*width+cb)*4] * cvs[((ca)*width+cb+1)*4] * cvs[((ca)*width+cb-1)*4];
			
			//condition d, p2*p6*p8
			d_con = cvs[((ca+1)*width+cb)*4] * cvs[((ca-1)*width+cb)*4] * cvs[((ca)*width+cb-1)*4];
			
			
			if (np >= 2 & np <= 6 & tp == 1 & c_con == 0 & d_con ==0) {
				cvs[(ca * width + cb) * 4] = 0;
			}
			
			np = 0;
			tp = 0;
			
		}
	}
	
	//ugly transform
	int int_cvs[height*width*4];
	for (int i = 0; i < height*width*4; i++) {
		int_cvs[i] = cvs[i];
	}
	
	int *opt;
	opt = int_cvs;
	
	return opt;
	
}