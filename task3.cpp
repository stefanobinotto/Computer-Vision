#include <stdio.h>
#include <opencv2/highgui.hpp>

void makeChessboard(cv::Mat* board, int square);

int main(int argc, char **argv)
{
	cv::Mat img1(256, 256, CV_8U);
	cv::Mat img2(256, 256, CV_8U);
	
	for(int i = 0; i < 256; i++) {
		for(int j = 0; j < 256; j++) {
			img1.at<unsigned char> (i,j) = i;
		}
	}
	
	for(int i = 0; i < 256; i++) 
		for(int j = 0; j < 256; j++) 
			img2.at<unsigned char> (i,j) = j;
	
	cv::namedWindow("Example 1");
	cv::imshow("Example 1", img1);
	cv::waitKey(0);
	cv::namedWindow("Example 2");
	cv::imshow("Example 2", img2);	
	cv::waitKey(0);
	cv::destroyAllWindows();
	
	cv::Mat chessboard(300, 300, CV_8UC1);
	int squareSize[] = {20, 50};
	
	makeChessboard(&chessboard, squareSize[0]);
	cv::namedWindow("Chessboard20", cv::WindowFlags::WINDOW_NORMAL);
	cv::resizeWindow("Chessboard20", chessboard.rows, chessboard.cols);
	cv:imshow("Chessboard20", chessboard);
	cv::waitKey(0);
	//cv::destroyAllWindows();
	
	makeChessboard(&chessboard, squareSize[1]);
	cv::namedWindow("Chessboard50", cv::WindowFlags::WINDOW_NORMAL);
	cv::resizeWindow("Chessboard50", chessboard.rows, chessboard.cols);
	cv::imshow("Chessboard50", chessboard);
	cv::waitKey(0);
	cv::destroyAllWindows();
	
	return 0;
}

void makeChessboard(cv::Mat* board, int square) {
	int color = 0;
	int starting_color = 0;
	
	for (int i = 0; i < (*board).cols; i++) {
		color = starting_color;
		for (int j = 0; j < (*board).rows; j++) {
			(*board).at<unsigned char>(i,j) = color;
			if (j+1 == (*board).cols) {
				break;
			} else if ((j+1) % square == 0 && color == 0) {
				color = 255;
			} else if ((j+1) % square == 0 && color == 255) {
				color = 0;
			}
		}
		if ((i+1) % square == 0 && starting_color == 0) {
			starting_color = 255;
		} else if ((i+1) % square == 0 && starting_color == 255) {
			starting_color = 0;
		}
	}
}