#include <stdio.h>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

int main(int argc, char **argv)
{
	cv::Mat img = cv::imread("image.jpg");
	cv::namedWindow("Example 1", cv::WINDOW_NORMAL);
	cv::imshow("Example 1", img);
	char outputWK = cv::waitKey(0);
	
	//convert img to grayscale
	cv::Mat dst;
	cv::cvtColor(img, dst, cv::COLOR_RGB2GRAY, 1);
	cv::namedWindow("Example 2", cv::WINDOW_NORMAL);
	cv::imshow("Example 2", dst);
	outputWK = cv::waitKey(0);
	
	cv::imwrite("image_grayscale.jpg",dst);
	
	return 0;
}