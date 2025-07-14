#include <quickopencv.h>

void QuickDemo::colorSpace_Demo(Mat &image) {
	Mat gray, hsv;
	cvtColor(image, hsv, COLOR_BGR2HSV);
	cvtColor(image, gray, COLOR_BGR2GRAY);
	imshow("HSV", hsv);
	imshow("灰度", gray);
	imwrite("D:/codes/opencv_c++/hsv.png", hsv);
	imwrite("D:/codes/opencv_c++/gray.png", gray);
}

void QuickDemo::mat_creation_Demo(Mat &image) {
	/*Mat m1, m2;
	m1 = image.clone();
	image.copyTo(m2);*/

	//创建空白图像
	Mat m3 = Mat::zeros(Size(8, 8), CV_8UC3);
	m3 = Scalar(0, 0, 255);
	//std::cout << m3 << std::endl;
std::cout << "width:" << m3.cols << "height:" << m3.rows << "channels:" << m3.channels() << std::endl;
	Mat m4;
	m4.copyTo(m3);
	m4 = Scalar(255, 0, 0);
	imshow("图像3", m3);
	imshow("图像4", m4);

	Mat kernel = (Mat_<char>(3, 3) << 0, -1, 0,
		-1, 5, -1,
		0, -1, 0);
}

void QuickDemo::pixel_visit_Demo(Mat &image) {
	int w = image.cols;
	int h = image.rows;
	int dims = image.channels();
	for (int row = 0; row < h; row++){
		for (int col = 0; col < w; col++) {
			if (dims == 1) {
				int pv = image.at<uchar>(row, col);
				image.at<uchar>(row, col) = 255 - pv;
			}
			if (dims == 3) {
				Vec3b bgr = image.at<Vec3b>(row, col);
				image.at<Vec3b>(row, col)[0] = 255 - bgr[0];
				image.at<Vec3b>(row, col)[1] = 255 - bgr[1];
				image.at<Vec3b>(row, col)[2] = 255 - bgr[2];
			}
		}
	}
	imshow("像素读写表示", image);
}

void QuickDemo::operators_Demo(Mat &image) {
	Mat dst = Mat::zeros(image.size(), image.type());
	Mat m = Mat::zeros(image.size(), image.type());
	m = Scalar(50, 50, 50);
	/*dst = image - Scalar(50, 50, 50);
	imshow("加法操作", dst);*/

	add(image, m, dst);
	imshow("加法操作", dst);
}

struct TrackbarData {
	Mat src;
	Mat dst;
};
static void on_track(int pos, void* userdata) {
	TrackbarData* data = (TrackbarData*)userdata;
	Scalar m(pos, pos, pos);
	add(data->src, m, data->dst);
	imshow("亮度调整", data->dst);
}
void QuickDemo::tracking_bar_demo(Mat &image) {
	namedWindow("亮度调整", WINDOW_FREERATIO);
	int max_value = 100;
	TrackbarData* data = new TrackbarData();
	data->src = image;
	data->dst = Mat::zeros(image.size(), image.type());
	//int lightness = 50;

	createTrackbar("Value Bar:", "亮度调整", nullptr, max_value, on_track, (void*)data);
	setTrackbarPos("Value Bar:", "亮度调整", 50);
	on_track(50, data);
}
void QuickDemo::key_demo(Mat &image) {
	Mat dst;
	while (true) {
		char c = waitKey(10);
		std::cout << c << std::endl;
	}	
}

	