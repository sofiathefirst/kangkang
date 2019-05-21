#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
using namespace cv;
using namespace std;
double alpha = 1.0; /*< Simple contrast control */
int beta = 0,ialpha=0;
#define WINDOW "out"
//Changing the contrast and brightness of an image!
//https://docs.opencv.org/3.4/d3/dc1/tutorial_basic_linear_transform.html
static void on_trackbar(int, void*)
{
   // Mat L(150,200, CV_8UC3, Scalar(blue ,green,red));
	//imshow(WINDOW, L );
	alpha = ialpha/100.0;
	cout<<"alpha = "<<alpha<<endl;
}
int main() {

	VideoCapture camCapLeft(0);
	int i = 0;

	camCapLeft.set(cv::CAP_PROP_FRAME_WIDTH, 480);
	camCapLeft.set(cv::CAP_PROP_FRAME_HEIGHT, 640);
	// int w = (int)mCapture.get(cv::CAP_PROP_FRAME_WIDTH);
	//  int h = (int)mCapture.get(cv::CAP_PROP_FRAME_HEIGHT);

	int w = camCapLeft.get(CV_CAP_PROP_FRAME_WIDTH);
	int h = camCapLeft.get(CV_CAP_PROP_FRAME_HEIGHT);
	printf("cam Resolution%d,%d\n", w, h);
    namedWindow(WINDOW, WINDOW_NORMAL);
	createTrackbar( "ialpha", WINDOW, &ialpha, 255, on_trackbar );
	createTrackbar( "beta", WINDOW, &beta, 255, on_trackbar );

	while (camCapLeft.isOpened()) {
		cv::Mat raw, heqResult;
		camCapLeft >> raw;
		cv::cvtColor(raw,heqResult,CV_BGR2GRAY);
		heqResult.copyTo(raw);

		  for( int y = 0; y < raw.rows; y++ ) {
		        for( int x = 0; x < raw.cols; x++ ) {
		            //for( int c = 0; c < raw.channels(); c++ )
		            {
		            	heqResult.at<uchar>(y,x) =
		                  saturate_cast<uchar>( alpha*raw.at<uchar>(y,x) + beta );
		            }
		        }
		    }
		imshow("raw", raw);
		imshow(WINDOW, heqResult);
		char c = cv::waitKey(1);
		//imwrite(name, img1);
	}

	camCapLeft.release();
	return 0;
}

