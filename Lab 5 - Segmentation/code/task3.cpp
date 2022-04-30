#include <stdio.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {

	Mat img = imread(argv[1]);
	namedWindow("Image");
    imshow("Image", img);
	waitKey(0);
	Mat dst;
	Scalar lower_bound(0, 72, 118);  //lower bound for shirt's color
	Scalar upper_bound(50, 225, 225);//upper bound for shirt's color
	//thresholding
	inRange(img, lower_bound, upper_bound, dst);
	namedWindow("Output");
    imshow("Output", dst);
	waitKey(0);
	
	
}
