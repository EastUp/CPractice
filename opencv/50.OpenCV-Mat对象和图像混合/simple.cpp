#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// 1. mat 常见用法
/*int main(){
	Mat src = imread("E:/test.jpg");

	// 判读读取是否正确，文件不存在
	if (src.empty()){
		cout << "src read error" << endl;
		return -1;
	}

	// uchar* data; 头指针
	if (!src.data){
		cout << "src read error" << endl;
		return -1;
	}

	// imshow("test",src);

	// 获取信息
	int cols = src.cols;// 宽
	int rows = src.rows;// 高
	int chnnales = src.channels();// 颜色通道

	// Mat的构造函数
	// CV_8UC1 1个颜色的通道  (0-255)
	// CV_8UC2 2个颜色的通道  16位 RGB565
	// CV_8UC3 3个颜色的通道  24位
	// CV_8UC4 4个颜色的通道  32位 ARGB8888
	// 匹配上 Java Bitmap 的颜色通道 RGB565 ARGB8888
	// Scalar 指定颜色

	// 第一个参数 rows 高，第二个参数 cols 宽
	Mat mat(500,300,CV_8UC1,Scalar(255));

	// Size 第一个参数是 width , 第二个参数是 height
	Mat mat1(Size(300,500),CV_8UC1,Scalar(255));

	//三颜色通道
	Mat mat2(Size(300,500),CV_8UC3,Scalar(255,0,255));

	// cout << mat2 << endl;

	// 拷贝构造函数，但是不会去拷贝内容操作的还是原来的图
	// Mat dst(src);
	// Mat dst = src;

	// 会拷贝内容
	Mat dst;
	// src.copyTo(dst);
	dst = src.clone();

	imshow("test", mat2);

	cout << cols << "," << rows << "," << chnnales << endl;

	waitKey(0);
	return 0;
}*/

// 2. 图像操作
/*int main(){
	Mat src = imread("E:/test.jpg");

	// 区域截取(不涉及创建新的内容)
	Mat srcROT = src(Rect(20,20,400,400));

	// 不改变原图
	Mat dstROI = srcROT.clone();

	int rows = dstROI.rows;
	int cols = dstROI.cols;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			// 获取像素 at Vec3b 3个字节
			int b = dstROI.at<Vec3b>(i, j)[0];
			int g = dstROI.at<Vec3b>(i, j)[1];
			int r = dstROI.at<Vec3b>(i, j)[2];

			// 底片效果
			dstROI.at<Vec3b>(i, j)[0] = 255 - b;
			dstROI.at<Vec3b>(i, j)[1] = 255 - g;
			dstROI.at<Vec3b>(i, j)[2] = 255 - r;
		}
	}

	Mat gray;
	cvtColor(src,gray,COLOR_BGR2GRAY); // 这样转过来是1个通道
	// 获取信息
	int cols = gray.cols; // 宽
	int rows = gray.rows; // 高
	int chnnales = gray.channels();
	cout << cols << "," << rows << "," << chnnales << endl;

	// Bitmap 里面转的是 4 通道，一个通道就可以代表灰度
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (chnnales == 3){
				int b = src.at<Vec3b>(i, j)[0];
				int g = src.at<Vec3b>(i, j)[1];
				int r = src.at<Vec3b>(i, j)[2];

				// 底片效果
				gray.at<Vec3b>(i, j)[0] = 255 - b;
				gray.at<Vec3b>(i, j)[1] = 255 - g;
				gray.at<Vec3b>(i, j)[2] = 255 - r;
			}else if (chnnales == 1){
				uchar pixels = gray.at<uchar>(i, j);
				gray.at<uchar>(i, j) = 255 - pixels;
			}
		}
	}

	// 手写一个通道的灰度图
	Mat gray(src.rows, src.cols, CV_8UC1);
	int cols = gray.cols; // 宽
	int rows = gray.rows; // 高
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			int b = src.at<Vec3b>(i, j)[0];
			int g = src.at<Vec3b>(i, j)[1];
			int r = src.at<Vec3b>(i, j)[2];

			// 底片效果
			gray.at<uchar>(i, j) = 0.11f*r + 0.59f*g + 0.3f*b;
		}
	}

	imwrite("E:/test_onegray.jpg",gray);
	imshow("test", gray);

	waitKey(0);
	return 0;
}*/


// 3.图片混合（加水印）
/*int main(){
	Mat src = imread("E:/test.jpg");
	if (src.empty()){
		cout << "src read error" << endl;
		return -1;
	}

	Mat logo = imread("E:/android.png");
	if (logo.empty()){
		cout << "logo read error" << endl;
		return -1;
	}

	Mat dst;
	// add 方法：注意两张图片的大小必须一致（效果很生硬，直接是像素相加）
	// add(src,logo,dst);

	// 不一定非得是 alpha + beta = 1; dst(x) = saturate_cast(src(x)*alpha + logo(x)*beta + gamma)
	// addWeighted 方法：注意两张图片的大小必须一致
	// addWeighted(src,0.8,logo,0.2,0.0,dst);

	// 非得加图片不一样的怎么办，通过截取的方式进行图片合并
	Mat srcROI = src(Rect(0, 0, logo.cols, logo.rows));
	// 并不适合加水印，只适合做图片的混合
	addWeighted(srcROI, 0.8, logo, 1, 0.0, srcROI);

	imshow("test", src);

	waitKey(0);
	return 0;
}*/


// 4. 饱和度、亮度和对比度
// 饱和度：指的其实是色彩的纯度，纯度越高，表现越鲜明，纯度较低，表现则较黯淡。 红色，淡红，鲜红，红得发紫等等   R -> 1.2R B -> 1.2B G -> 1.2G
// 亮度：亮暗的程度
// 对比度: 图像对比度指的是 [1]  一幅图像中明暗区域最亮的白和最暗的黑之间不同亮度层级的测量，即指一幅图像灰度反差的大小
int main(){
	Mat src = imread("E:/test.jpg");
	if (src.empty()){
		cout << "src read error" << endl;
		return -1;
	}

	// 滤镜 UI设计师 再调亮一点 ，饱和一点，对比度再调高一点？ alpha 增大成比例去增 1:500  10:5000  beta增
	// alpha 饱和度 , 对比度
	// beta 亮度
	// F(R) = alpha*R + beta;
	// F(G) = alpha*G + beta;
	// F(B) = alpha*B + beta;
	// 获取信息
	int cols = src.cols;// 宽
	int rows = src.rows;// 高
	int chnnales = src.channels();// 1 

	int alpha = 3;
	int beta = -50;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			int b = src.at<Vec3b>(i, j)[0];
			int g = src.at<Vec3b>(i, j)[1];
			int r = src.at<Vec3b>(i, j)[2];

			
			src.at<Vec3b>(i, j)[0] = saturate_cast<uchar>(alpha*b + beta);
			src.at<Vec3b>(i, j)[1] = saturate_cast<uchar>(alpha*g + beta);
			src.at<Vec3b>(i, j)[2] = saturate_cast<uchar>(alpha*r + beta);
		}
	}

	imshow("test", src);

	waitKey(0);
	return 0;
}