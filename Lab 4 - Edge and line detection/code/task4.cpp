#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
using namespace cv;
using namespace std;
int main(int argc, char** argv)
{
    // Loads an image
    Mat src = imread( argv[1]);
	
    Mat gray;
    cvtColor(src, gray, COLOR_BGR2GRAY);
    medianBlur(gray, gray, 5);
	cv::Canny(gray, gray, 50, 200, 3);
    vector<Vec3f> circles;
    HoughCircles(gray, circles, HOUGH_GRADIENT, 2,
                 gray.rows/16,  // change this value to detect circles with different distances to each other
                 100, 30, 6, 8 // change the last two parameters
            // (min_radius & max_radius) to detect larger circles
    );
    for( size_t i = 0; i < circles.size(); i++ ) //let's create the circles
    {
        Vec3i c = circles[i];
        Point center = Point(c[0], c[1]);
        // circle center
        circle( src, center, 1, Scalar(0,0,255), 3, LINE_AA);
        // circle outline
        int radius = c[2];
        circle( src, center, radius, Scalar(0,0,255), FILLED, LINE_AA);
    }
    imshow("Circles", src);
    waitKey();
    return 0;
}