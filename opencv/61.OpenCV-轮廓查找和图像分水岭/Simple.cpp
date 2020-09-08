#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;


// 彩色图直方均衡化
/*int main(){
	Mat src = imread("E:/2_05.jpg");
	if (!src.data){
		cout << "read error" << endl;
		return -1;
	}

	imshow("src",src);
	
	vector<Mat> channels;
	split(src,channels);

	Mat blue, green, red;
	blue = channels.at(0);
	green = channels.at(1);
	red = channels.at(2);

	// 直方均衡
	equalizeHist(blue, blue);
	equalizeHist(green, green);
	equalizeHist(red, red);

	Mat dst;
	merge(channels,dst);

	imshow("dst",dst);

	waitKey(0);
	return 0;
}*/


// 1.银行卡轮廓查找与绘制
/*int main(){
	Mat src = imread("E:/card.jpg");
	if (!src.data){
		cout << "read error" << endl;
		return -1;
	}

	imshow("src", src);

	// 梯度和二值化
	Mat binary;
	Canny(src,binary,50,150);
	imshow("binary", binary);

	//findContours(InputArray image, OutputArrayOfArrays contours,
	//	int mode, int method, Point offset = Point())

	vector<vector<Point>> contours;
	findContours(binary,contours,RETR_EXTERNAL,CHAIN_APPROX_SIMPLE);

	Mat contours_mat = Mat::zeros(src.size(),CV_8UC3);
	for (int i = 0; i < contours.size(); i++)
	{
		// 画轮廓 
		// boundingRect 获取可以包围轮廓的外层的矩形
		Rect rect = boundingRect(contours[i]);
		if (rect.width > src.cols / 2 && rect.height > src.rows / 2){
			// 画轮廓
			drawContours(contours_mat,contours,i,Scalar(0,0,255),1);
			rectangle(contours_mat, Point(rect.x, rect.y), Point(rect.x + rect.width, rect.y + rect.height), Scalar(255, 255, 255), 2);
			break;
		}
	}

	imshow("contours_mat", contours_mat);
	
	waitKey(0);
	return 0;
}*/


// 2. 图像矩
/*int main(){
	/// 创建一个图形     
	const int r = 100;
	Mat src = Mat::zeros(Size(4 * r, 4 * r), CV_8UC1);

	/// 绘制一系列点创建一个轮廓:
	vector<Point2f> vert(6);

	vert[0] = Point(1.5*r, 1.34*r);
	vert[1] = Point(1 * r, 2 * r);
	vert[2] = Point(1.5*r, 2.866*r);
	vert[3] = Point(2.5*r, 2.866*r);
	vert[4] = Point(3 * r, 2 * r);
	vert[5] = Point(2.5*r, 1.34*r);

	/// 在src内部绘制
	for (int j = 0; j < 6; j++)
	{
		line(src, vert[j], vert[(j + 1) % 6], Scalar(255), 3, 8);
	}

	imshow("src", src);

	// 查找轮廓
	vector<vector<Point>> contours;
	findContours(src,contours,RETR_EXTERNAL,CHAIN_APPROX_SIMPLE);

	// 计算到轮廓的距离
	Mat raw_dist(src.size(),CV_32FC1);
	for (int row = 0; row < src.rows; row++)
	{
		for (int col = 0; col < src.cols; col++)
		{
			raw_dist.at<float>(row, col) = pointPolygonTest(contours[0], Point2f(col, row), true);
		}
	}

	// 优化
	Mat drawing = Mat::zeros(src.size(),CV_8UC3);
	for (int row = 0; row < src.rows; row++)
	{
		for (int col = 0; col < src.cols; col++)
		{
			// raw_dist.at<float>(row, col) = pointPolygonTest(contours[0], Point2f(col, row), true);
			float value = raw_dist.at<float>(row, col);
			if (value < 0){ // 外面
				drawing.at<Vec3b>(row, col)[0] = saturate_cast<int>((int)abs(value));
			}
			else if (value > 0){ // 里面
				drawing.at<Vec3b>(row, col)[2] = saturate_cast<int>((int)value);
			}
			else{// 矩形上面
				drawing.at<Vec3b>(row, col)[0] = 255;
				drawing.at<Vec3b>(row, col)[1] = 255;
				drawing.at<Vec3b>(row, col)[2] = 255;
			}
		}
	}

	imshow("drawing", drawing);

	waitKey(0);
	return 0;
}*/


// 3.图像分水岭切割
int main(){
	Mat src = imread("E:/card.jpg");
	if (!src.data){
		cout << "read error" << endl;
		return -1;
	}

	imshow("src", src);

	Mat markers;
	watershed(src, markers);

	imshow("markers", markers);

	waitKey(0);
	return 0;
}