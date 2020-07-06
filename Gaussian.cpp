#include "opencv2/opencv.hpp"
#include <iostream>
#include "opencv2/highgui.hpp"
using namespace cv;
using namespace std;

int main(int argc, char **argv) {
	// (1)load a specified file as a grayscale image
	const char *imagename = argc > 1 ? argv[1] : "../img/pic2.png";
	Mat src_img = imread(imagename, 0);
	if (!src_img.data){
		return -1;
	}

	// (2)calculate the first image derivatives using an Sobel operator
	
	Mat Gauss_img;
	GaussianBlur(src_img, Gauss_img,Size(3,3), 500, 500);


	//Mat img =imread("../img/lena.jpg",-1);

	namedWindow("Original(Grayscale)", WINDOW_AUTOSIZE);
	namedWindow("Gaussian", WINDOW_AUTOSIZE);
	imshow("Original(Grayscale)", src_img);
	imshow("Gaussian", Gauss_img);
	waitKey(0);

	return 0;


}
