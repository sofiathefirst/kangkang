#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
using namespace cv;
using namespace std;
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
	while (camCapLeft.isOpened()) {
		cv::Mat raw, heqResult;
		camCapLeft >> raw;
		cv::cvtColor(raw,raw,CV_BGR2GRAY);
		//cout<<raw.channels()<<endl;
		equalizeHist(raw, heqResult);
		//vconcat(raw, heqResult, heqResult);
		imshow("raw", raw);
		imshow("heqResult", heqResult);
		char c = cv::waitKey(1);
		//imwrite(name, img1);
	}

	camCapLeft.release();
	return 0;
}

