#include <opencv2/opencv.hpp>
#include <quickopencv.h>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
	Mat src = imread("D:/codes/opencv_c++/opencv480_quick_tutorial/img/OIP.jpg");
	if (src.empty()) {
		printf("could not load image.....");
		return -1;
	}
	//cout << src.depth() << endl;
	//namedWindow("ÊäÈë´°¿Ú", WINDOW_FREERATIO);
	imshow("ÊäÈëÍ¼Ïñ", src);

	QuickDemo qd;
	//qd.colorSpace_Demo(src);
	//qd.mat_creation_Demo(src);
	//qd.pixel_visit_Demo(src);
	//qd.operators_Demo(src);
	//qd.tracking_bar_demo(src);
	qd.key_demo(src);

	waitKey(0);
	destroyAllWindows();
	return 0;
}
