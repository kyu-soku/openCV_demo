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
		cout << "failed" << endl;
		return -1;
	}

	// (2)calculate the first image derivatives using an Sobel operator
	Mat tmp_img;
	Mat sobel_img;
	Sobel(src_img, tmp_img, CV_32F, 1, 0);
	convertScaleAbs(tmp_img, sobel_img, 1, 0);

	//Mat img =imread("../img/lena.jpg",-1);

	namedWindow("Original(Grayscale)", WINDOW_AUTOSIZE);
	namedWindow("Sobel", WINDOW_AUTOSIZE);
	imshow("Original(Grayscale)", src_img);
	imshow("Sobel", sobel_img);
	waitKey(0);

	return 0;


}
