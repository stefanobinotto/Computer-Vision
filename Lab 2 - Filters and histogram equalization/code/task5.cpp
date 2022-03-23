#include <stdio.h>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "opencv2/imgcodecs.hpp"

int main(int argc, char **argv)
{
	cv::Mat img = cv::imread("image.jpg");
	cv::namedWindow("Original", cv::WINDOW_NORMAL);
	cv::imshow("Original", img);
	char outputWK = cv::waitKey(0);
	
	cv::cvtColor(img, img, cv::COLOR_BGR2GRAY);
	cv::namedWindow("Grayscale image", cv::WINDOW_NORMAL);
	cv::imshow("Grayscale image", img);
	outputWK = cv::waitKey(0);
	
	cv::equalizeHist(img,img);
	
	//histSize
	int bins = 256;
	//histRange
	float range[] = { 0, 256 }; //the upper boundary is exclusive
    const float* histRange[] = { range };
	
	bool uniform = true, accumulate = false;
	
	cv::Mat hist;
	
	cv::calcHist( &img, 1, 0, cv::Mat(), hist, 1, &bins, histRange, uniform, accumulate );
	
	int hist_w = 512, hist_h = 400;
    int bin_w = cvRound( (double) hist_w/bins );
	
	cv::Mat histImage( hist_h, hist_w, CV_8UC1);
	cv::normalize(hist, hist, 0, histImage.rows, cv::NORM_MINMAX, -1, cv::Mat() );
	
	for( int i = 1; i < bins; i++ ) {
        cv::line(histImage, cv::Point(bin_w*(i-1), hist_h - cvRound(hist.at<float>(i-1))), cv::Point(bin_w*(i), hist_h - cvRound(hist.at<float>(i))), cv::Scalar(255, 0, 0), 2, 8, 0);
    }

	
	cv::namedWindow("calcHist Demo");
    cv::imshow("calcHist Demo", histImage );
    cv::waitKey();	
	
	return 0;
}