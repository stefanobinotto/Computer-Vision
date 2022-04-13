#include <stdio.h>
#include <opencv2/highgui.hpp>
#include "opencv2/imgproc.hpp"

using namespace std;

int main(int argc, char **argv) {
	//save image
	cv::Mat img = cv::imread(argv[1]);
	cv::namedWindow("Original image");
	cv::imshow("Original image", img);
	cv::waitKey(0);
	cv::destroyAllWindows();
	
	cv::Mat grayImg, smooth, canny, hough;
	
	cv::cvtColor(img, grayImg, cv::COLOR_BGR2GRAY);
	
	cv::blur(grayImg, smooth, cv::Size(3, 3)); //to filter out any noise before Canny
	cv::Canny(smooth, canny, 50, 200, 3);
	
	hough = img.clone();
	
	//Standard Hough Line Transform
	vector<cv::Vec2f> lines; //will hold the results of the detection
	cv::HoughLines(canny, lines, 1, CV_PI/180, 150, 0, 0); //runs the actual detection
	
	//draw the lines
	for(size_t i=0; i<lines.size(); ++i) {
        float rho = lines[i][0], theta = lines[i][1];
        cv::Point pt1, pt2;
        double a=cos(theta), b=sin(theta), x0=a*rho, y0=b*rho;

        //check for the two road lines
        //the first condition look for an angle of about 45
        //the second for an angle of about 135
        if(theta>CV_PI/180*40 && theta<CV_PI/180*60) {
            pt1.x = cvRound(x0 + 300*(-b));
            pt1.y = cvRound(y0 + 300*a);
            pt2.x = cvRound(x0 - 300*(-b));
            pt2.y = cvRound(y0 - 300*a);
            
            line(hough, pt1, pt2, cv::Scalar(0, 0, 255), 3, cv::LINE_AA);
        }
        else if(theta>CV_PI/180*130 && theta<CV_PI/180*150) {
            pt1.x = cvRound(x0 + 400*(-b) + 705);
            pt1.y = cvRound(y0 + 400*a + 655);
            pt2.x = cvRound(x0 - 1000*(-b));
            pt2.y = cvRound(y0 - 1000*a);
            
            line(hough, pt2, pt1, cv::Scalar(0, 0, 255), 3, cv::LINE_AA);
        }
    }	
	//color below the red lines
    for(int i=0; i<hough.cols; ++i) {
        bool flag = false;
        for(int j=0; j<hough.rows; ++j) {
            //if the pixel found before was red color the next
            if(flag) {
                hough.at<cv::Vec3b>(j, i) = cv::Vec3b(0, 0, 255);
            }
            else if(hough.at<cv::Vec3b>(j, i) == cv::Vec3b(0, 0, 255)) {
                flag = true;
            }
        }
    }
	//check number of lines detected
	//printf("Lines: %ld\n", lines.size());
	//cv::waitKey(0);
	
	//display image
    cv::namedWindow("Canny");
	cv::imshow("Canny", canny);
	cv::waitKey(0);
	
    cv::namedWindow("Hough");
    cv::imshow("Hough", hough);
	cv::waitKey(0);
	
	return 0;
}
