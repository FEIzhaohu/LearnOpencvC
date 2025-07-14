#pragma once

#include <opencv2/opencv.hpp>

using namespace cv;

class QuickDemo {
public:
	void colorSpace_Demo(Mat &image);
	void mat_creation_Demo(Mat &iamge);
	void pixel_visit_Demo(Mat &image);
	void operators_Demo(Mat &image);
	void tracking_bar_demo(Mat &iamge);
	void key_demo(Mat &image);
};
