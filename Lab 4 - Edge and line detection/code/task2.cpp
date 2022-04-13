#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
#include <cmath>
using namespace cv;
using namespace std;
int main( int argc, char** argv ) {
	Mat image,src, src_gray, grad, grad1, grad2;
	const String window_name = "Sobel Demo - Simple Edge Detector";
	
	int ddepth = CV_16S;
  
	image = imread(argv[1]); // Load an image
	// Remove noise by blurring with a Gaussian filter ( kernel size = 3 )
	GaussianBlur(image, src, Size(3, 3), 0, 0, BORDER_DEFAULT);//blur(image, src, Size(3, 3));
	// Convert the image to grayscale
	cvtColor(src, src_gray, COLOR_BGR2GRAY);
	Mat grad_x, grad_y;
	Mat abs_grad_x, abs_grad_y;
	Sobel(src_gray, grad_y, ddepth, 0, 1, 1, BORDER_DEFAULT);
    Sobel(src_gray, grad_x, ddepth, 1, 0, 1, BORDER_DEFAULT);
    
    //converting back to CV_8U
	convertScaleAbs(grad_x, grad1);
    convertScaleAbs(grad_y, grad2);
	
    addWeighted(grad1, 0.5, grad2, 0.5, 0, grad);
	threshold(grad, grad, 230, 255, THRESH_BINARY);
    imshow(window_name, grad);
    waitKey(0);
	return 0;
}