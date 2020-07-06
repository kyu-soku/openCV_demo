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

	// (4)implement the Canny algorithm for edge detection
	Mat tmp_img; 	
	Mat canny_img;
	Canny(src_img, canny_img, 50, 90);
	//Mat img =imread("../img/lena.jpg",-1);

	namedWindow("Original(Grayscale)", WINDOW_AUTOSIZE);
	namedWindow("Canny", WINDOW_AUTOSIZE);
	imshow("Original(Grayscale)", src_img);
	imshow("Canny", canny_img);
	waitKey(0);

	return 0;


}
