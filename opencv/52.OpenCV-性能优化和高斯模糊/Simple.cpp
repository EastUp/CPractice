#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;

int main(){
	Mat src = imread("E:/copy.png");

	if (src.empty()){
		cout << "src read error" << endl;
	}
	imshow("src", src);

	// 均值模糊
	Mat dst;
	// Size（w,h）只能是基数，这样才能找到中心点
	// Point(-1,-1) 代表中心店
	blur(src,dst,Size(151,151),Point(-1,-1));
	imshow("dst", dst);

	// 高斯模糊
	Mat gaussian;
	// sigmaX sigmaY 代表 作用
	// sigmaY 不传代表和 sigmaX 一样
	// 如果 sigmaX <= 0 ,自己会计算 0.3*((ksize-1)*0.5 - 1) + 0.8
	// sigmaX 越小越没效果
	GaussianBlur(src, gaussian, Size(151, 151), 0);
	imshow("gaussian", gaussian);

	waitKey(0);
	return 0;
}