#include <stdio.h>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include "filters.h"

cv::Mat maxFilter(cv::Mat img, int sz) {
	if (sz % 2 == 0) {
		exit(1);
	} else {
		//create destination image to return
		cv::Mat dst(((img).rows)-sz+1, (((img).cols)-sz+1), CV_8UC1);
		
		for(int i = 0; i<dst.rows -sz+1; i++) {
			for(int j = 0; j<dst.cols -sz+1; j++) {
				//create temporary matrix where to apply the filtering
				//cv::Mat tmp = img(cv::Rect(j,i,sz,sz));
				double min, max;
				//get maximum value on the szxsz partition of the image
				//cv::minMaxLoc(*img(cv::Rect(j,i,sz,sz)), &min, &max);
				cv::minMaxLoc(img(cv::Rect(j,i,sz,sz)), &min, &max);
				//apply max filtering
				dst.at<unsigned char>(i,j) = (unsigned char)max;
			}
		}
		return dst;
	}
}

cv::Mat minFilter(cv::Mat img, int sz) {
	if (sz % 2 == 0) {
		exit(1);
	} else {
		//create destination image to return
		cv::Mat dst(((img).rows)-sz+1, (((img).cols)-sz+1), CV_8UC1);
		
		for(int i = 0; i<dst.rows -sz+1; i++) {
			for(int j = 0; j<dst.cols -sz+1; j++) {
				//create temporary matrix where to apply the filtering
				//cv::Mat tmp = img(cv::Rect(j,i,sz,sz));
				double min, max;
				//get maximum value on the szxsz partition of the image
				//cv::minMaxLoc(*img(cv::Rect(j,i,sz,sz)), &min, &max);
				cv::minMaxLoc(img(cv::Rect(j,i,sz,sz)), &min, &max);
				//apply max filtering
				dst.at<unsigned char>(i,j) = (unsigned char)min;
			}
		}
		return dst;
	}
}