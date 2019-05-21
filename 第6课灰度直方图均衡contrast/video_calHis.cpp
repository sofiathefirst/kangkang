#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
using namespace cv;
using namespace std;
Mat getHistImg(const MatND &hist) {
	double maxVal = 0;
	double minVal = 0;

	//找到直方图中的最大值和最小值
	minMaxLoc(hist, &minVal, &maxVal, 0, 0);
	int histSize = hist.rows;
	Mat histImg(histSize, histSize, CV_8U, Scalar(255));
	// 设置最大峰值为图像高度的90%
	int hpt = static_cast<int>(0.9 * histSize);

	for (int h = 0; h < histSize; h++) {
		float binVal = hist.at<float>(h);
		int intensity = static_cast<int>(binVal * hpt / maxVal);
		line(histImg, Point(h, histSize), Point(h, histSize - intensity),
				Scalar::all(0));
	}

	return histImg;
}
int main() {

	VideoCapture camCapLeft(0);
	int i = 0;

	camCapLeft.set(cv::CAP_PROP_FRAME_WIDTH, 10000);
	camCapLeft.set(cv::CAP_PROP_FRAME_HEIGHT, 10000);
	// int w = (int)mCapture.get(cv::CAP_PROP_FRAME_WIDTH);
	//  int h = (int)mCapture.get(cv::CAP_PROP_FRAME_HEIGHT);

	int w = camCapLeft.get(CV_CAP_PROP_FRAME_WIDTH);
	int h = camCapLeft.get(CV_CAP_PROP_FRAME_HEIGHT);
	printf("cam Resolution%d,%d\n", w, h);
	while (camCapLeft.isOpened()) {
		cv::Mat frame;
		camCapLeft >> frame;
		imshow("raw", frame);
		char c = cv::waitKey(1);
		char name[10] = "";
		sprintf(name, "a%d.jpg", i);
		i++;

		const int channels[1] = { 0 };
		const int histSize[1] = { 256 };
		float hranges[2] = { 0, 255 };
		const float* ranges[1] = { hranges };
		MatND hist;
		calcHist(&frame, 1, channels, Mat(), hist, 1, histSize, ranges);
		Mat himg = getHistImg(hist);
		imshow("raw", frame);

		imshow("hist image", himg);
		waitKey(30);
		//imwrite(name, img1);
	}

	camCapLeft.release();
	return 0;
}

