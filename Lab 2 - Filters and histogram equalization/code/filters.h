#include <stdio.h>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

cv::Mat maxFilter(cv::Mat img, int sz);
cv::Mat minFilter(cv::Mat img, int sz);