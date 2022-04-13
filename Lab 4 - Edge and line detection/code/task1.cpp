//#include <stdio.h>
#include <iostream>
#include <opencv2/highgui.hpp>
#include "opencv2/imgproc.hpp"

cv::Mat grayImg, edges;

int lowThreshold = 0;
int highThreshold = 0;//255;
//const int ratio = 3; //if you put 4 then the max value of lowThreshold is lowThreshold*4
const int kernel_size = 3;
const char* window_name = "Edge Map";
const int max_lowThreshold = 500;
const int max_highThreshold = 500;


static void minCannyThreshold(int, void*) {
	cv:blur(grayImg, edges, cv::Size(3,3));
    cv::Canny(edges, edges, lowThreshold, highThreshold, kernel_size);
    //dst = cv::Scalar::all(0);
	//img.copyTo(dst, edges);
	
	cv::imshow(window_name, edges);
	
	//cv::waitKey(0);
}

static void maxCannyThreshold(int, void*) {
    cv:blur(grayImg, edges, cv::Size(3,3));
    cv::Canny(edges, edges, lowThreshold, highThreshold, kernel_size);
    //dst = cv::Scalar::all(0);
	//img.copyTo(dst, edges);
	
	cv::imshow(window_name, edges);
	
	//cv::waitKey(0);
}

int main(int argc, char **argv) {
	cv::Mat img = cv::imread(argv[1]);
	//cv::namedWindow("Example 1");
	//cv::imshow("Example 1", img);
	//cv::waitKey(0);
	//cv::destroyAllWindows();

	//grayImg.create(img.size(), img.type());
	cv::cvtColor(img, grayImg, cv::COLOR_BGR2GRAY);
	
	cv::namedWindow("grayscale img");
	cv::imshow("grayscale img", grayImg);
	//cv::waitKey(0);
	//cv::destroyAllWindows();
	
	cv::namedWindow(window_name);
	cv::createTrackbar("Min Threshold: ", window_name, &lowThreshold, max_lowThreshold, minCannyThreshold);
	cv::createTrackbar("Max Threshold: ", window_name, &highThreshold, max_highThreshold, maxCannyThreshold);
	cv::waitKey(0);

	
	return 0;
}
