#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
#include <cmath>
using namespace cv;
using namespace std;
int main( int argc, char** argv ) {
	Mat img = imread(argv[1]);
	namedWindow("Original");
	imshow("Original", img);
	waitKey(0);
	cvtColor(img, img, COLOR_BGR2GRAY);
	GaussianBlur(img, img, Size(7, 7), 5, 5/*, BORDER_DEFAULT*/);
	//blur(img, img, Size(5, 5));
	namedWindow("Denoised img");
	imshow("Denoised img", img);
	waitKey(0);

	Mat dst;
	double thresh = 75;
	double maxValue = 255;

    /*
        Otsu's method for thresholding works really well for the first and third pictures, but 
        doesn't work at all for the second one.
    */
	threshold(img,dst, thresh, maxValue, THRESH_BINARY /*| THRESH_OTSU*/); 

	//cout << "Otsu Threshold : " << thres <<endl;
	
	namedWindow("output");
	imshow("output", dst);
	waitKey(0);
}
