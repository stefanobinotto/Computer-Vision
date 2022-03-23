#include <stdio.h>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include "filters.h"

int main(int argc, char **argv)
{
	cv::Mat img = cv::imread("image_grayscale.jpg");
	cv::Mat dstMax = maxFilter(img, 3);
	cv::Mat dstMin = minFilter(img, 3);
	cv::Mat dstMedian, dstGaussian;
	cv::medianBlur(img, dstMedian, 3);
	cv::GaussianBlur(img, dstGaussian, cv::Size(3, 3), 3, 3);
	
	
	cv::namedWindow("Original", cv::WINDOW_NORMAL);
	cv::imshow("Original", img);
	char outputWK = cv::waitKey(0);
	cv::destroyAllWindows();
	
	cv::namedWindow("Max Filter", cv::WINDOW_NORMAL);
	cv::imshow("Max Filter", dstMax);
	outputWK = cv::waitKey(0);
	cv::destroyAllWindows();
	
	cv::namedWindow("Min Filter", cv::WINDOW_NORMAL);
	cv::imshow("Min Filter", dstMin);
	outputWK = cv::waitKey(0);
	cv::destroyAllWindows();
	
	cv::namedWindow("Median Filter", cv::WINDOW_NORMAL);
	cv::imshow("Median Filter", dstMedian);
	outputWK = cv::waitKey(0);
	cv::destroyAllWindows();
	
	cv::namedWindow("Gaussian Filter", cv::WINDOW_NORMAL);
	cv::imshow("Gaussian Filter", dstGaussian);
	outputWK = cv::waitKey(0);
	cv::destroyAllWindows();
	
	return 0;
}