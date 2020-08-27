#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

// 1. 形态学操作
/*int main(){
	Mat src = imread("E:/copy.png");

	if (!src.data){
		cout << "imread error" << endl;
		return -1;
	}

	imshow("src", src);

	Mat kernel = getStructuringElement(MORPH_RECT,Size(25,25));
	Mat dst;
	// 腐蚀
	// erode(src, dst, kernel);
	// 膨胀
	//dilate(src,dst,kernel);

	// MORPH_OPEN 开：先腐蚀后膨胀
	// morphologyEx(src, dst,MORPH_OPEN,kernel);
	
	// MORPH_CLOSE 闭：先膨胀后腐蚀
	// morphologyEx(src,dst,MORPH_CLOSE,kernel);
	
	// MORPH_GRADIENT 梯度：膨胀 - 腐蚀
	//morphologyEx(src, dst, MORPH_GRADIENT, kernel);

	// MORPH_TOPHAT 顶帽：原图像 - 开图像
	// morphologyEx(src,dst,MORPH_TOPHAT,kernel);

	// MORPH_BLACKHAT 黑帽：闭图像 - 原图像
	morphologyEx(src,dst,MORPH_BLACKHAT,kernel);


	imshow("dst",dst);

	waitKey(0);
	return 0;
}*/

// 2. 验证码识别
/*int main(){
	Mat src = imread("E:/copy.png");

	if (!src.data){
		cout << "imread error" << endl;
		return -1;
	}

	imshow("src", src);

	// 2.1 把彩色变成 黑白 二值化
	// 灰白
	Mat gray;
	cvtColor(src,gray,COLOR_BGR2GRAY);
	// imshow("gray",gray);
	// 二值化方法，自动阈值
	// ~ 符号表示 = （255 - 原本的像素值） 等同于 bitwise_not
	Mat binary;
	adaptiveThreshold(~gray,binary,255,ADAPTIVE_THRESH_MEAN_C,THRESH_BINARY,15,0);
	imshow("binary",binary);

	Mat kernel = getStructuringElement(MORPH_RECT,Size(5,5));
	Mat dst;
	// 腐蚀
	erode(src,dst,kernel);
	// 膨胀
	dilate(src, dst, kernel);
	// morphologyEx(src,dst,MORPH_CLOSE,kernel);
	bitwise_not(dst, dst);

	imshow("dst",dst);

	waitKey(0);
	return 0;
}*/

// 3. 提取水平线
/*int main(){
	Mat src = imread("E:/copy.png");

	if (!src.data){
		cout << "imread error" << endl;
		return -1;
	}

	imshow("src", src);
	Mat gray;
	cvtColor(src, gray, COLOR_BGR2GRAY);
	// imshow("gray",gray);
	// 二值化方法，自动阈值
	// ~ 符号表示 = （255 - 原本的像素值） 等同于 bitwise_not
	Mat binary;
	adaptiveThreshold(~gray, binary, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 15, 0);

	// 二值化有些小问题，做一下弥补
	Mat kernel = getStructuringElement(MORPH_RECT, Size(9, 9));
	Mat dst;
	dilate(binary, dst, kernel);
	erode(dst, dst, kernel);

	// 取水平
	Mat lLine = getStructuringElement(MORPH_RECT, Size(src.cols/16,1));
	erode(dst,dst,lLine);
	dilate(dst,dst,lLine);
	imshow("dst",dst);


	waitKey(0);
	return 0;
}*/


// 4. 上采样与降采样
int main(){
	Mat src = imread("E:/copy.png");

	if (!src.data){
		cout << "imread error" << endl;
		return -1;
	}

	imshow("src", src);

	Mat dst;
	// 上采样 拉普拉斯 双线性插值，预计算（推算）值
	// pyrUp(src,dst,Size(src.cols*2,src.rows*2));
	// 降采样：1. 对图像进行高斯模糊，2.再过滤左右临近点。 采用的高斯 所以比较慢
	pyrDown(src,dst,Size(src.cols/2,src.rows/2));

	imshow("dst",dst);

	// imwrite("E:/copy_pyrUp.png", dst);


	waitKey(0);
	return 0;
}