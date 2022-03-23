#include <stdio.h>
#include <opencv2/highgui.hpp>
#include <iostream>

void onMouse(int event, int x, int y, int flags, void* userdata);

int main(int argc, char **argv)
{
	cv::Mat img = cv::imread("robocup.jpg");
	cv::namedWindow("Example 1", cv::WindowFlags::WINDOW_NORMAL);
	cv::resizeWindow("Original", img.rows, img.cols);
	
	cv::setMouseCallback("Example 1", onMouse,&img);
	
	cv::imshow("Example 1", img);
	cv::waitKey(0);
	
	return 0;
}

void onMouse(int event, int x, int y, int flags, void* userdata) {
	if(event == cv::EVENT_LBUTTONDOWN) {
		//casting from void* to cv::Mat*
		cv::Vec3b pixel = (*(cv::Mat*)userdata).at<cv::Vec3b>(y,x);
		//BGR order
		int blu_pixel = (int)pixel[0];
		int green_pixel = (int)pixel[1];
		int red_pixel = (int)pixel[2];
		
		printf("Blue value: %i\nGreen value: %i\nRed value: %i\n",blu_pixel,green_pixel,red_pixel);
	}
}