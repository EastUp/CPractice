#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int element_size = 1;
int max_size = 21;
Mat src;


/*int main(){
	Mat src = imread(wo);

	if (!src.data){
		cout << "src read error" << endl;
		return -1;
	}
	imshow("src", src);

	Mat dst;
	 blur(src, dst, Size(15, 15));

	 中值滤波 对所有考虑点进行排序，取中间的那个值   1,2,“3”,4,5  去掉噪音
	 medianBlur(src, dst,5);

	 双边滤波 可以用作美容 ，基于高斯，高斯保留的轮廓并不强，双边保留的轮廓信息会增强，基于高斯再增加像素差
	bilateralFilter(src,dst,15,100,5);

	imshow("dst", dst);

	 掩膜操作
	Mat final;
	Mat kernal = (Mat_<int>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
	filter2D(dst,final,dst.depth(),kernal);
	imshow("final",final);

	waitKey(0);
	return 0;
}*/

// 膨胀与腐蚀，处理黑白图片
void trackbarCallback(int pos, void *userdata){
	int size = element_size * 2 + 1;
	// 创建一个 kernel
	Mat kernel = getStructuringElement(MORPH_RECT, Size(size, size));
	Mat dst;

	//膨胀 ， 最大值(去黑点)
	dilate(src, dst, kernel);
	// 腐蚀 ，最小值 （去白点）
	// erode(src,dst,kernel);
	imshow("output image", dst);
}


int main(){
	src = imread("E:/copy.png");

	if (!src.data){
		cout << "src read error" << endl;
		return -1;
	}
	imshow("src", src);
	
	// 创建一个 window
	namedWindow("output image");

	// 动态控制
	createTrackbar("Trackbar","output image",&element_size,max_size,trackbarCallback);


	waitKey(0);
	return 0;
}