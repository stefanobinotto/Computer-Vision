#include <stdio.h>
#include <opencv2/highgui.hpp>

void modifyFirstChannel(cv::Mat* image);

//using namespace cv;

int main(int argc, char **argv)
{
	cv::Mat img = cv::imread(argv[1]);
	cv::namedWindow("Example 1");
	cv::imshow("Example 1", img);
	char outputWK = cv::waitKey(0);
	
	modifyFirstChannel(&img);
	
	/*
	 * questo codice serve per incorporare la funzione nel main
	 * if (img.channels() == 3) {
		cv::Mat chans[3];
		cv::split(img, chans);
		chans[0] = Mat::zeros(img.rows, img.cols, CV_8U); // first channel is set to 0
		
		//then merge them back
		cv::merge(chans, 3, img);
	}
	*/
	cv::namedWindow("Example 2");
	cv::imshow("Example 2", img);
	char outputWK2 = cv::waitKey(0);
	
	return 0;
}


//funzione dedicata
void modifyFirstChannel(cv::Mat* image) {
	if ((*image).channels() == 3) {
		cv::Mat chans[3];
		cv::split(*image, chans);
		//first channel = B, second channel = G, third channel = R
		chans[0] = cv::Mat::zeros((*image).rows, (*image).cols, CV_8U); // first channel is set to 0
		
		//then merge them back
		cv::merge(chans, 3, *image);
	}	
}
