#include <stdio.h>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>



int main(int argc, char **argv)
{
	cv::Mat img = cv::imread("Lena_color.jpg");
	cv::namedWindow("Original", cv::WindowFlags::WINDOW_NORMAL);
	//cv::resizeWindow("Original",img.size().width,img.size().height);
	cv::resizeWindow("Original", img.rows, img.cols);
	cv::imshow("Original", img);
	cv::waitKey(0);
	cv::destroyAllWindows();
	
	cv::Mat dst;
	double angle = 45;
	
	//find the center where to apply the rotation
	cv::Point2f center((img.cols-1)*0.5, (img.rows-1)*0.5);
	//find the rotation matrix
	cv::Mat rotationMatrix = cv::getRotationMatrix2D(center, angle, 1.0);
	//apply the rotation to img and save the rotated image to dst
	cv::warpAffine(img, dst, rotationMatrix, img.size());
	
	cv::namedWindow("Rotated", cv::WindowFlags::WINDOW_NORMAL);
	cv::resizeWindow("Rotated", dst.rows, dst.cols);
	cv:imshow("Rotated", dst);
	cv::waitKey(0);
	cv::destroyAllWindows();
	
	
	//initial 3 points in source image
	cv::Point2f srcpt[3];
	srcpt[0] = cv::Point2f(0, 0);
	srcpt[1] = cv::Point2f(img.cols-1, 0);
	srcpt[2] = cv::Point2f(0, img.rows-1);
	//3 points in destination image
	cv::Point2f dstpt[3];
	dstpt[0] = cv::Point2f(0, img.rows*0.33);
	dstpt[1] = cv::Point2f(img.cols*0.85, img.rows*0.25);
	dstpt[2] = cv::Point2f(img.cols*0.15, img.rows*0.7);
	//get transformation points corrispondences
	cv::Mat warp_mat = cv::getAffineTransform(srcpt, dstpt);
	//get destination image
	cv::Mat warp_dst = cv::Mat::zeros(img.rows, img.cols, img.type());
	//apply transformation to source image and save in destination image
	cv::warpAffine(img, warp_dst, warp_mat, warp_dst.size());
	
	cv::namedWindow("3-points Warped", cv::WindowFlags::WINDOW_NORMAL);
	cv::resizeWindow("3-points Warped", warp_dst.rows, warp_dst.cols);
	cv::imshow("3-points Warped", warp_dst);
	cv::waitKey(0);
	cv::destroyAllWindows();
	
	return 0;
}
