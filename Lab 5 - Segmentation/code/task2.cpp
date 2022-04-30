#include <stdio.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {

	Mat img = imread(argv[1]);
	namedWindow("Image");
    imshow("Image", img);
	waitKey(0);
	
	Mat data;
	//Convert to float type
	img.convertTo(data,CV_32F);
	// convert to float & reshape to a [1 x W*H] Mat 
	// (so every pixel is on a row of it's own)
	data = data.reshape(1,data.total());

	//Input/output integer array that stores the cluster indices for every sample
	Mat labels;
	//Output matrix of the cluster centers, one row per each cluster center
	Mat centers;
	// do kmeans
	kmeans(data, 3, labels, TermCriteria(TermCriteria::EPS+TermCriteria::COUNT, 10, 0.1), 15, KMEANS_PP_CENTERS, centers);

	// reshape both to a single row of Vec3f pixels:
	centers = centers.reshape(3,centers.rows);
	data = data.reshape(3,data.rows);

	// replace pixel values with their center value:
	Vec3f *p = data.ptr<Vec3f>();
	for (size_t i=0; i<data.rows; i++) {
	   int center_id = labels.at<int>(i);
	   p[i] = centers.at<Vec3f>(center_id);
	}

	// back to 2d, and uchar:
	img = data.reshape(3, img.rows);
	img.convertTo(img, CV_8U);
	namedWindow("Cluster Segmentation");
    imshow("Cluster Segmentation", img);
	waitKey(0);
	return 0;
}
