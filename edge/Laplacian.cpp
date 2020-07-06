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

	// (3)calculate the Laplacian of an image  
	Mat tmp_img; 	
	Mat laplacian_img;
  	Laplacian(src_img, tmp_img, CV_32F, 3);
  	convertScaleAbs(tmp_img, laplacian_img, 1, 0);
	//Mat img =imread("../img/lena.jpg",-1);

	namedWindow("Original(Grayscale)", WINDOW_AUTOSIZE);
	namedWindow("laplacian", WINDOW_AUTOSIZE);
	imshow("Original(Grayscale)", src_img);
	imshow("laplacian", laplacian_img);
	waitKey(0);

	return 0;


}
