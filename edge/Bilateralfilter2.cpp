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
	Mat GaussBlur_img;
	Mat UnsharpMasking_img;
	Mat bilateral_img;
	Mat Gauss_img;
	GaussianBlur(src_img, GaussBlur_img,Size(3,3), 500, 500);
	absdiff(src_img,GaussBlur_img,diff_img);
	diffmulti_img = diff_img*10;
	UnsharpMasking_img = diffmulti_img + src_img;
	


	bilateralFilter(UnsharpMasking_img, bilateral_img, 3, 100, 100);
	GaussianBlur(UnsharpMasking_img, Gauss_img,Size(3,3), 100, 100);

	//Mat img =imread("../img/lena.jpg",-1);

	namedWindow("noise", WINDOW_AUTOSIZE);
	namedWindow("bilateral", WINDOW_AUTOSIZE);
	namedWindow("Gaussian", WINDOW_AUTOSIZE);

	imshow("noise", UnsharpMasking_img);
	imshow("bilateral", bilateral_img);
	imshow("Gaussian", Gauss_img);
	waitKey(0);

	return 0;


}
