#include <jni.h>
#include <string>
#include <android/log.h>  //系统自带的用<>
#include <android/bitmap.h>
#include "cv_helper.h"
#include "bitmap_util.h"

#define TAG "JNI_TAG"
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG,__VA_ARGS__)
//使用命名空间
using namespace cv;
using namespace std;

// 静态注册，动态注册（6.0 以上 frameworker NDK 源码） Linux

// 旋转
extern "C"
JNIEXPORT jobject JNICALL
Java_com_east_opencv63_OpenCvUtils_rotation(JNIEnv *env, jclass clazz, jobject bitmap) {
    Mat src;
    cv_helper::bitmap2mat(env, bitmap, src);

    int res_w = src.rows; // 图片的宽
    int res_h = src.cols; // 图片的高

    Mat res(res_h, res_w, src.type());

    // 处理输出图像的下半部分
    for (int row = 0; row < res_h; ++row) {
        for (int col = 0; col < res_w; ++col) {
            if (src.type() == CV_8UC4)
                res.at<Vec4b>(row, col) = src.at<Vec4b>(src.rows - col, row);
            else if (src.type() == CV_8UC2)
                res.at<Vec3b>(row, col) = src.at<Vec3b>(src.rows - col, row);
            else if (src.type() == CV_8UC1)
                res.at<uchar>(row, col) = src.at<uchar>(src.rows - col, row);
        }
    }

    // 创建一个新的bitmap 宽是原来的高，高是原来的宽
    jobject newBitmap = bitmap_util::create_bitmap(env, res_w, res_h, res.type());
    cv_helper::mat2bitmap(env, res, newBitmap);
    return newBitmap;
}

// 图片仿射变换
extern "C"
JNIEXPORT jobject JNICALL
Java_com_east_opencv63_OpenCvUtils_warpAffine(JNIEnv *env, jclass clazz, jobject bitmap) {
    Mat src;
    cv_helper::bitmap2mat(env, bitmap, src);

    Mat res(src.size(), src.type());
    /*Mat M(2,3,CV_32FC1);
    // 这几个值应该怎么确定？
    // [a0,a1,a2]     两个矩阵    [a0,a1]    [a2]       =     [ x ]     *     [a0,a1]    +   [a2]    =   a0*x+b0*x + a2
    // [b0,b1,b2]                 [b0,b1]    [b2]             [ y ]           [b0,b1]        [b2]    =   b1*y+b1*y + b2
    M.at<float>(0,0) = 1;// a0
    M.at<float>(0,1) = 0;// a1
    M.at<float>(0,2) = 0;// a2
    M.at<float>(1,0) = 0; // b1
    M.at<float>(1,1) = 1; // b2
    M.at<float>(1,2) = 0;*/ //b3

    Point2f center(src.cols / 2, src.rows / 2);
    Mat M = getRotationMatrix2D(center, 45, 1);

    warpAffine(src, res, M, src.size());

    cv_helper::mat2bitmap(env, res, bitmap);
    return bitmap;
}

// 图片缩放
extern "C"
JNIEXPORT jobject JNICALL
Java_com_east_opencv63_OpenCvUtils_resize(JNIEnv *env, jclass clazz, jobject bitmap, jint width,
                                          jint height) {
    Mat src;
    cv_helper::bitmap2mat(env, bitmap, src);
    Mat res(height, width, src.type());

    float src_w = src.cols;
    float src_h = src.rows;

    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {

            int src_row = row * (src_h / height);
            int src_col = col * (src_w / width);

            if (src.type() == CV_8UC4)
                res.at<Vec4b>(row, col) = src.at<Vec4b>(src_row, src_col);
            else if (src.type() == CV_8UC2)
                res.at<Vec3b>(row, col) = src.at<Vec3b>(src_row, src_col);
            else if (src.type() == CV_8UC1)
                res.at<uchar>(row, col) = src.at<uchar>(src_row, src_col);
        }
    }


    jobject newBitmap = bitmap_util::create_bitmap(env, width, height, res.type());
    cv_helper::mat2bitmap(env, res, newBitmap);
    return newBitmap;
}


void remap(Mat &src,Mat &res,Mat &matX,Mat &matY){
    res.create(src.size(),src.type());
    int res_w = res.cols;
    int res_h = res.rows;
    for (int row = 0; row < res_h; ++row) {
        for (int col = 0; col < res_w; ++col) {
            int x = matX.at<float>(row,col);
            int y = matY.at<float>(row,col);
            res.at<Vec4b>(row,col) = src.at<Vec4b>(y,x);
        }
    }
}

// 手写 Remap 重映射
extern "C"
JNIEXPORT jobject JNICALL
Java_com_east_opencv63_OpenCvUtils_reMap(JNIEnv *env, jclass clazz, jobject bitmap) {
    Mat src;
    cv_helper::bitmap2mat(env, bitmap, src);
    Mat res;

    Mat matX(src.size(), CV_32F);
    Mat matY(src.size(), CV_32F);

    for (int row = 0; row < src.rows; ++row) {
        for (int col = 0; col < src.cols; ++col) {
            matX.at<float>(row, col) = src.cols - col;
            matY.at<float>(row, col) = src.rows - row;
        }
    }

    remap(src, res, matX, matY);
    cv_helper::mat2bitmap(env,res,bitmap);
    return bitmap;
}



