#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// 1. mat �����÷�
/*int main(){
	Mat src = imread("E:/test.jpg");

	// �ж���ȡ�Ƿ���ȷ���ļ�������
	if (src.empty()){
		cout << "src read error" << endl;
		return -1;
	}

	// uchar* data; ͷָ��
	if (!src.data){
		cout << "src read error" << endl;
		return -1;
	}

	// imshow("test",src);

	// ��ȡ��Ϣ
	int cols = src.cols;// ��
	int rows = src.rows;// ��
	int chnnales = src.channels();// ��ɫͨ��

	// Mat�Ĺ��캯��
	// CV_8UC1 1����ɫ��ͨ��  (0-255)
	// CV_8UC2 2����ɫ��ͨ��  16λ RGB565
	// CV_8UC3 3����ɫ��ͨ��  24λ
	// CV_8UC4 4����ɫ��ͨ��  32λ ARGB8888
	// ƥ���� Java Bitmap ����ɫͨ�� RGB565 ARGB8888
	// Scalar ָ����ɫ

	// ��һ������ rows �ߣ��ڶ������� cols ��
	Mat mat(500,300,CV_8UC1,Scalar(255));

	// Size ��һ�������� width , �ڶ��������� height
	Mat mat1(Size(300,500),CV_8UC1,Scalar(255));

	//����ɫͨ��
	Mat mat2(Size(300,500),CV_8UC3,Scalar(255,0,255));

	// cout << mat2 << endl;

	// �������캯�������ǲ���ȥ�������ݲ����Ļ���ԭ����ͼ
	// Mat dst(src);
	// Mat dst = src;

	// �´������
	Mat dst;
	// src.copyTo(dst);
	dst = src.clone();

	imshow("test", mat2);

	cout << cols << "," << rows << "," << chnnales << endl;

	waitKey(0);
	return 0;
}*/

// 2. ͼ�����
/*int main(){
	Mat src = imread("E:/test.jpg");

	// �����ȡ(���漰�����µ�����)
	Mat srcROT = src(Rect(20,20,400,400));

	// ���ı�ԭͼ
	Mat dstROI = srcROT.clone();

	int rows = dstROI.rows;
	int cols = dstROI.cols;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			// ��ȡ���� at Vec3b 3���ֽ�
			int b = dstROI.at<Vec3b>(i, j)[0];
			int g = dstROI.at<Vec3b>(i, j)[1];
			int r = dstROI.at<Vec3b>(i, j)[2];

			// ��ƬЧ��
			dstROI.at<Vec3b>(i, j)[0] = 255 - b;
			dstROI.at<Vec3b>(i, j)[1] = 255 - g;
			dstROI.at<Vec3b>(i, j)[2] = 255 - r;
		}
	}

	Mat gray;
	cvtColor(src,gray,COLOR_BGR2GRAY); // ����ת������1��ͨ��
	// ��ȡ��Ϣ
	int cols = gray.cols; // ��
	int rows = gray.rows; // ��
	int chnnales = gray.channels();
	cout << cols << "," << rows << "," << chnnales << endl;

	// Bitmap ����ת���� 4 ͨ����һ��ͨ���Ϳ��Դ���Ҷ�
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (chnnales == 3){
				int b = src.at<Vec3b>(i, j)[0];
				int g = src.at<Vec3b>(i, j)[1];
				int r = src.at<Vec3b>(i, j)[2];

				// ��ƬЧ��
				gray.at<Vec3b>(i, j)[0] = 255 - b;
				gray.at<Vec3b>(i, j)[1] = 255 - g;
				gray.at<Vec3b>(i, j)[2] = 255 - r;
			}else if (chnnales == 1){
				uchar pixels = gray.at<uchar>(i, j);
				gray.at<uchar>(i, j) = 255 - pixels;
			}
		}
	}

	// ��дһ��ͨ���ĻҶ�ͼ
	Mat gray(src.rows, src.cols, CV_8UC1);
	int cols = gray.cols; // ��
	int rows = gray.rows; // ��
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			int b = src.at<Vec3b>(i, j)[0];
			int g = src.at<Vec3b>(i, j)[1];
			int r = src.at<Vec3b>(i, j)[2];

			// ��ƬЧ��
			gray.at<uchar>(i, j) = 0.11f*r + 0.59f*g + 0.3f*b;
		}
	}

	imwrite("E:/test_onegray.jpg",gray);
	imshow("test", gray);

	waitKey(0);
	return 0;
}*/


// 3.ͼƬ��ϣ���ˮӡ��
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
	// add ������ע������ͼƬ�Ĵ�С����һ�£�Ч������Ӳ��ֱ����������ӣ�
	// add(src,logo,dst);

	// ��һ���ǵ��� alpha + beta = 1; dst(x) = saturate_cast(src(x)*alpha + logo(x)*beta + gamma)
	// addWeighted ������ע������ͼƬ�Ĵ�С����һ��
	// addWeighted(src,0.8,logo,0.2,0.0,dst);

	// �ǵü�ͼƬ��һ������ô�죬ͨ����ȡ�ķ�ʽ����ͼƬ�ϲ�
	Mat srcROI = src(Rect(0, 0, logo.cols, logo.rows));
	// �����ʺϼ�ˮӡ��ֻ�ʺ���ͼƬ�Ļ��
	addWeighted(srcROI, 0.8, logo, 1, 0.0, srcROI);

	imshow("test", src);

	waitKey(0);
	return 0;
}*/


// 4. ���Ͷȡ����ȺͶԱȶ�
// ���Ͷȣ�ָ����ʵ��ɫ�ʵĴ��ȣ�����Խ�ߣ�����Խ���������Ƚϵͣ�������������� ��ɫ�����죬�ʺ죬��÷��ϵȵ�   R -> 1.2R B -> 1.2B G -> 1.2G
// ���ȣ������ĳ̶�
// �Աȶ�: ͼ��Աȶ�ָ���� [1]  һ��ͼ�����������������İ׺���ĺ�֮�䲻ͬ���Ȳ㼶�Ĳ�������ָһ��ͼ��Ҷȷ���Ĵ�С
int main(){
	Mat src = imread("E:/test.jpg");
	if (src.empty()){
		cout << "src read error" << endl;
		return -1;
	}

	// �˾� UI���ʦ �ٵ���һ�� ������һ�㣬�Աȶ��ٵ���һ�㣿 alpha ����ɱ���ȥ�� 1:500  10:5000  beta��
	// alpha ���Ͷ� , �Աȶ�
	// beta ����
	// F(R) = alpha*R + beta;
	// F(G) = alpha*G + beta;
	// F(B) = alpha*B + beta;
	// ��ȡ��Ϣ
	int cols = src.cols;// ��
	int rows = src.rows;// ��
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