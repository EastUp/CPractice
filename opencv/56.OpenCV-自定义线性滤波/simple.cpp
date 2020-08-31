#include<iostream>
#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;

// 1.处理边缘类型
/*int main(){
	Mat src = imread("E:/copy.png");

	if (!src.data){
		cout << "imread error" << endl;
		return -1;
	}

	imshow("src", src);

	Mat dst;
	//copyMakeBorder(src,dst,src.rows/8,src.rows/8,src.cols/8,src.cols/8,BORDER_DEFAULT);
	//copyMakeBorder(src, dst, src.rows / 8, src.rows / 8, src.cols / 8, src.cols / 8, BORDER_WRAP);
	//copyMakeBorder(src, dst, src.rows / 8, src.rows / 8, src.cols / 8, src.cols / 8, BORDER_REPLICATE);
	copyMakeBorder(src, dst, src.rows / 8, src.rows / 8, src.cols / 8, src.cols / 8, BORDER_CONSTANT,Scalar(255,0,0));
	imshow("dst", dst);

	waitKey(0);
	return 0;
}*/


// 2. 自定义线性滤波波
/*int main(){
	Mat src = imread("E:/copy.png");

	if (!src.data){
		cout << "imread error" << endl;
		return -1;
	}

	imshow("src", src);

	// 打印 depth 0
	cout << src.depth() << endl;

	Mat gray;
	cvtColor(src, gray, COLOR_BGR2GRAY);

	// depth 概念：
	
	//Mat kernelRobert = (Mat_<int>(2, 2) << 1, 0, 0, -1);

	// 1.Robert算子
	//Mat dstRobert;
	//filter2D(gray, dstRobert, gray.depth(), kernelRobert);
	//imshow("dst", dstRobert);


	// 2.Sobel 算子
	//Mat dstSoble_x;
	//Mat kernelSobelX = (Mat_<int>(3, 3) << -1, 0, 1, -2,0,2,-1,0,1);
	//filter2D(gray, dstSoble_x, gray.depth(), kernelSobelX);
	//imshow("dst", dstSoble_x);

	//Mat dstSoble_y;
	//Mat kernelSobelY = (Mat_<int>(3, 3) << -1, -2, -1, 0, 0, 0, 1, 2, 1);
	//filter2D(gray, dstSoble_y, gray.depth(), kernelSobelY);
	//imshow("dst", dstSoble_y);


	// 3.拉普拉斯算子
	Mat dstlpls;
	Mat kernelLpls= (Mat_<int>(3, 3) << 0, -1, 0, -1, 4, -1, 0, -1, 0);
	filter2D(gray, dstlpls, gray.depth(), kernelLpls);
	imshow("dst", dstlpls);

	waitKey(0);
	return 0;
}*/

// 3. 图像模糊（均值模糊，高斯模糊，中值模糊，双边滤波）
/*int main(){
	Mat src = imread("E:/copy.png");

	if (!src.data){
		cout << "imread error" << endl;
		return -1;
	}

	imshow("src", src);

	Mat blur_m;
	blur(src,blur_m,Size(15,15));

	imshow("blur",blur_m);

	// 自定义模糊
	int size = 15;
	Mat kernel = Mat::ones(size,size,CV_32F)/(size*size);

	Mat dst;
	filter2D(src,dst,src.depth(),kernel);
	imshow("dst",dst);

	waitKey(0);
	return 0;
}*/


// 4.图像的二值化
int main(){
	Mat src = imread("E:/copy.png");

	if (!src.data){
		cout << "imread error" << endl;
		return -1;
	}

	imshow("src", src);
	
	Mat gray;
	cvtColor(src,gray,COLOR_BGR2GRAY);

	imshow("gray", gray);

	Mat dst;
	//threshold(gray,dst,100,255,THRESH_BINARY);
	//threshold(gray, dst, 100, 255, THRESH_BINARY_INV);
	//threshold(gray, dst, 100, 255, THRESH_TRUNC);
	//threshold(gray, dst, 100, 255, THRESH_TOZERO);
	//threshold(gray, dst, 100, 255, THRESH_TOZERO_INV);
	//threshold(gray, dst, 100, 255, THRESH_OTSU|THRESH_BINARY);
	threshold(gray, dst, 100, 255, THRESH_TRIANGLE);

	imshow("dst",dst);

	waitKey(0);
	return 0;
}
