#include <stdio.h>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <cmath>

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
	int sz = 9;
	
	if(event == cv::EVENT_LBUTTONDOWN) {
		//casting from void* to cv::Mat*
		cv::Mat img = *(cv::Mat*)userdata;
		
		cv::Mat square = img(cv::Rect(x-((sz-1)/2), y-((sz-1)/2), sz, sz));
		int blue=0;
		int green=0;
		int red=0;
		
		for(int i = 0; i < square.rows; i++) {
			for(int j = 0; j < square.cols; j++) {
				blue = blue + square.at<cv::Vec3b>(i,j)[0];
				green = green + square.at<cv::Vec3b>(i,j)[1];
				red = red + square.at<cv::Vec3b>(i,j)[2];
			}
		}
		
		blue = blue/(9*9);
		green = green/(9*9);
		red = red/(9*9);
		
		//threshold from 45 to 60 
		int T = 60;
		cv::Mat mask(img.rows, img.cols, CV_8UC1);
		
		for(int i = 0; i < mask.rows; i++) {
			for(int j = 0; j < mask.cols; j++) {
				cv::Vec3b tmp = img.at<cv::Vec3b>(i,j);
				if(abs(tmp[0]-blue)<T && abs(tmp[1]-green)<T && abs(tmp[2]-red)<T) {
					mask.at<unsigned char>(i,j) = 255;
				} else {
					mask.at<unsigned char>(i,j) = 0;
				}
			}
		}
		cv::namedWindow("Mask", cv::WindowFlags::WINDOW_NORMAL);
		cv::resizeWindow("Mask", mask.rows, mask.cols);
		cv::imshow("Mask", mask);
		cv::waitKey(0);
	}
}