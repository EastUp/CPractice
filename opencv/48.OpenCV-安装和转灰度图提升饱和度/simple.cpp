// 头文件 + dll动态库
#include <opencv2/opencv.hpp>
#include <iostream> // 头文件 ， dll

using namespace cv;

void main(){
	// imread 读取一张图片 Mat(图片)
	Mat src = imread("E:/test.jpg");

	// Mat dst;

	// Bitmap 里面是RGB ，mat 默认 BGR 
	// cvtColor(src,dst,COLOR_BGR2GRAY);

	// 高，宽，颜色通道 rows 行(高) cols 列(宽) 3 （1个像素点 3 颜色通道，包含三个信息，BGR）
	printf("行高：%d,列宽：%d,通道：%d",src.rows,src.cols,src.channels());

	// char 是有符号的 unsigned char 是无符号的,char 整数范围为-128到127( 0x80__0x7F)， 而unsigned char 整数范围为0到255( 0__0xFF ) 有时候想把整数数值限在255范围内，也用unsigned char，这个类型在嵌入式用的多
	for (int i = 0; i < src.rows; i++){
		// 读取当前行的首地址
		uchar* start_pixels = src.ptr<uchar>(i);
		
		for (int j = 0; j < src.cols; j++){
			uchar b = start_pixels[0];
			uchar g = start_pixels[1];
			uchar r = start_pixels[2];

			// 彩色转灰度
			// 公式计算 f =  0.11R + 0.59G + 0.30B   gery 最大255 ，其他处理可能会超过 255
			// uchar gery = 0.11f*r + 0.59f*g + 0.30f*b;
			uchar gray = 0.11f*r + 0.59f*g + 0.30f*b;

			// 彩色转黑白
			uchar bw = (b + g + r) / 3 > 125 ? 255 : 0;

			// saturate_cast 大于 255就变成255 ，小于0 就变成0
			/* start_pixels[0] = saturate_cast<uchar>(bw);
			start_pixels[1] = saturate_cast<uchar>(bw);
			start_pixels[2] = saturate_cast<uchar>(bw);*/

			// 饱和度提升会更亮些
			start_pixels[0] = saturate_cast<uchar>(1.2f * b);
			start_pixels[1] = saturate_cast<uchar>(1.2f * g);
			start_pixels[2] = saturate_cast<uchar>(1.2f * r);

			start_pixels += 3;
		}
	}


	// 把 mat 写入文件
	imwrite("E://test3.jpg",src);

	// 显示图片
	imshow("test pic", src);

	waitKey(0);
}