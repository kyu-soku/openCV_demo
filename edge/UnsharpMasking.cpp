#include "opencv2/opencv.hpp"
#include <iostream>
#include "opencv2/highgui.hpp"
using namespace cv;
using namespace std;

int main(int argc, char **argv) {
	// (1)load a specified file as a grayscale image
	const char *imagename = argc > 1 ? argv[1] : "../img/lena.jpg";
	Mat src_img = imread(imagename, 0);
	if (!src_img.data){
		return -1;
	}

	// (2)calculate the first image derivatives using an Sobel operator
	Mat diffmulti_img;
	Mat diff_img;
	Mat Gauss_img;
	Mat UnsharpMasking_img;
	GaussianBlur(src_img, Gauss_img,Size(3,3), 500, 500);
	absdiff(src_img,Gauss_img,diff_img);
	diffmulti_img = diff_img*2;
	UnsharpMasking_img = diffmulti_img + src_img;
	

	//Mat img =imread("../img/lena.jpg",-1);

	namedWindow("Original(Grayscale)", WINDOW_AUTOSIZE);
	namedWindow("UnsharpMasking", WINDOW_AUTOSIZE);
	imshow("Original(Grayscale)", src_img);
	imshow("UnsharpMasking", UnsharpMasking_img);
	waitKey(0);

	return 0;


}
