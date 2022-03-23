#include <stdio.h>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include "filters.h"

int main(int argc, char **argv)
{
	cv::Mat img = cv::imread("image.jpg");
	cv::Mat dstMax = maxFilter(img, 7);
	cv::Mat dstMin = minFilter(img, 7);
	
	cv::namedWindow("Original", cv::WINDOW_NORMAL);
	cv::imshow("Original", img);
	cv::namedWindow("Max Filter", cv::WINDOW_NORMAL);
	cv::imshow("Max Filter", dstMax);
	cv::namedWindow("Min Filter", cv::WINDOW_NORMAL);
	cv::imshow("Min Filter", dstMin);
	char outputWK = cv::waitKey(0);
	
	return 0;
	
}