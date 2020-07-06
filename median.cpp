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


	Mat diffmulti_img;
	Mat diff_img;
	Mat Gauss_img;
	Mat UnsharpMasking_img;
	Mat median_img;
	GaussianBlur(src_img, Gauss_img,Size(3,3), 500, 500);
	absdiff(src_img,Gauss_img,diff_img);
	diffmulti_img = diff_img*10;
	UnsharpMasking_img = diffmulti_img + src_img;
	medianBlur(UnsharpMasking_img,median_img,3);

	//Mat img =imread("../img/lena.jpg",-1);

	namedWindow("medianBlur", WINDOW_AUTOSIZE);
	namedWindow("noise", WINDOW_AUTOSIZE);
	imshow("medianBlur", median_img);
	imshow("noise", UnsharpMasking_img);
	waitKey(0);

	return 0;


}
