#include <opencv2/opencv.hpp>
#include <quickopencv.h>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
	Mat src = imread("D:/codes/opencv_c++/OIP.jpg");
	if (src.empty()) {
		printf("could not load image.....");
		return -1;
	}
	cout << src.depth() << endl;
	namedWindow("ÊäÈë´°¿Ú", WINDOW_FREERATIO);
	imshow("ÊäÈëÍ¼Ïñ", src);

	QuickDemo qd;
	//qd.colorSpace_Demo(src);
	//qd.mat_creation_Demo(src);
	//qd.pixel_visit_Demo(src);
	qd.operators_Demo(src);
	waitKey(0);
	return 0;
}
