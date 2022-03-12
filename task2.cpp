#include <stdio.h>
#include <opencv2/highgui.hpp>

using namespace cv;

int main(int argc, char **argv)
{
	Mat img = imread(argv[1]);
	namedWindow("Example 1");
	imshow("Example 1", img);
	char outputWK = waitKey(0);
	
	printf("output of waitKey: %c\n", outputWK);
	printf("# of channels: %d\n", img.channels());
	
	
	
	return 0;
}
