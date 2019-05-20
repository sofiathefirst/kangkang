#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>
using namespace cv;
using namespace std;

int main() {
	std::vector<Scalar> color;
	color.push_back(Scalar(255, 0, 0));
	color.push_back(Scalar(0, 255, 0));
	color.push_back(Scalar(0, 0, 255));
	color.push_back(Scalar(0, 255, 255));
	color.push_back(Scalar(255, 0, 25));
	color.push_back(Scalar(255, 0, 255));
	int scale = 3;
	Mat v0(15 * scale, 100 * scale, CV_8UC3, color[0]);
	Mat v1(15 * scale, 100 * scale, CV_8UC3, color[1]);
	Mat v2(15 * scale, 100 * scale, CV_8UC3, color[2]);
	Mat v3(15 * scale, 100 * scale, CV_8UC3, color[3]);
	Mat v4(15 * scale, 100 * scale, CV_8UC3, color[4]);
	Mat v5(15 * scale, 100 * scale, CV_8UC3, color[5]);

	Mat v, h;

//hconcat(v0,v1,v1);//水平拼接
//vconcat
	vconcat(v0, v1, h);
	vconcat(h, v2, h);
	vconcat(h, v3, h);
	vconcat(h, v4, h);
	vconcat(h, v5, h);
	imshow("hc", h);
	hconcat(v0, v1, h);

	cv::waitKeyEx(0);
	return 0;
}
