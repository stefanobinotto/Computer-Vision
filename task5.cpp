#include <stdio.h>
#include <opencv2/highgui.hpp>

std::vector<cv::Mat> returnThreeImages(cv::Mat* image);

int main(int argc, char **argv) {
	cv::Mat img = cv::imread(argv[1]);
	cv::namedWindow("Example 1");
	cv::imshow("Example 1", img);
	char outputWK = cv::waitKey(0);
	
	//vettore di canali
	std::vector<cv::Mat> immagini = returnThreeImages(&img);
	
	cv::namedWindow("Example 2");
	cv::imshow("Example 2", immagini[0]);
	char outputWK2 = cv::waitKey(0);
	
	cv::namedWindow("Example 3");
	cv::imshow("Example 3", immagini[1]);
	char outputWK3 = cv::waitKey(0);
	
	cv::namedWindow("Example 4");
	cv::imshow("Example 4", immagini[2]);
	char outputWK4 = cv::waitKey(0);
	
	return 0;
}

//funzione dedicata
std::vector<cv::Mat> returnThreeImages(cv::Mat* image) {
	if ((*image).channels() == 3) {
		
		//creo un vettore di Mat
		std::vector<cv::Mat> channels;
		
		//ogni canale di image viene salvato in channel
		cv::split(*image, channels);
		
		return channels;
	}	
}
