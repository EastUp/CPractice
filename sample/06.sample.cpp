#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <cstdlib>

// mac
/*
char* file_name = "/Users/east/Desktop/Sample.txt"; // 源文件
char* file_copy_name = "/Volumes/MacDataStore/sample_copy.txt"; //拷贝的文件
char* file_image_name = "/Users/east/Desktop/image.jpg"; // 源文件
char* file_encrpy_image_name = "/Volumes/MacDataStore/image_encrpy.jpg"; // 加密后的文件
char* file_decrpy_image_name = "/Volumes/MacDataStore/image_decrpy.jpg"; // 解密后的文件
char* file_decrpy_image_name = "/Volumes/MacDataStore/image_decrpy.jpg"; // 解密后的文件
char* file_split = "/Users/east/Desktop/image_%d.jpg"; // 分割后的文件
*/

// windows
const char* file_name = "F:\\Sample.txt"; // 源文件
const char* file_copy_name = "F:\\sample_copy.txt"; //拷贝的文件
const char* file_image_name = "F:\\image.jpg"; // 源文件
const char* file_encrpy_image_name = "F:\\image_encrpy.jpg"; // 加密后的文件
const char* file_decrpy_image_name = "F:\\image_decrpy.jpg"; // 解密后的文件
const char* file_split = "F:\\image_%d.jpg"; // 分割后的文件
//文件读
/*int main(){
    // 打开文件（文件名，模式） mode r(读) w(写) rb(作为二进制读) wb(作为二进制写) a（追加）
    // FILE* fopen(const char* filename,const char* mode);
    // char *fgets(char *string, int n, FILE *stream);
    FILE* file = fopen(file_name,"r");

    if(!file){
        printf("文件打开失败");
        exit(0);// 退出程序
    }

    char buffer[10];

    // 缓冲区buffer, 长度10，文件指针
    while (fgets(buffer,10,file)){
        printf("%s",buffer);
    }

    //关闭文件
    fclose(file);

}*/

// 文件写
/*int main(){
    FILE* file = fopen(file_name,"w");
    if(!file){
        printf("文件打开失败");
        exit(0);// 退出程序
    }

    fputs("I am eastrise",file);

    // 关闭文件
    fclose(file);

}*/

// 文件复制，当做二进制文件来操作
/*int main(){
    FILE* file = fopen(file_name,"rb"); // 流指针
    FILE* file_copy = fopen(file_copy_name,"wb");

    if(!file || !file_copy){
        printf("文件打开失败");
        exit(0);
    }

    // siz_t fread(void *buffer,size_t size,size_t count, FILE* stream);
    int buffer[512]; // 2048 = 4*512
    int len;
    printf("%d",sizeof(buffer));
    while ((len = fread(buffer,sizeof(int),512,file))!=0){
        fwrite(buffer,sizeof(int),len,file_copy);
    }
    fclose(file);
    fclose(file_copy);
}*/

// 获取文件的大小
/*int main(){
    FILE* file = fopen(file_name,"rb");// 流指针
    if (!file){
        printf("文件打开失败");
        exit(0);// 退出程序
    }
    // 没有一个函数是可以直接拿文件大小
    // 思路：将文件的指针移动到最后，然后再去计算偏移量
    // 三个参数 SEEK_SET（开头），SEEK_CUR（当前），SEEK_END（移动到最后）
    fseek(file,0,SEEK_END);

    // 计算偏移的位置，ftell 从 0 开始统计到当前（SEEK_END）
    long file_size = ftell(file);

    printf("文件大小：%ld个字节",file_size);

    fclose(file);
}*/

// 文件加密（该方法文件适合图片，如果文件中有中文就不适合）
// 图片服务器（使用第三方的），为了防止图片泄密，图片进行加密
/*int main(){
    FILE* file = fopen(file_image_name,"rb"); // 流指针
    FILE* file_encrpy = fopen(file_encrpy_image_name,"wb"); // 新建一个文件 0KB

    if (!file || !file_encrpy){
        printf("文件打开失败");
        exit(0);// 退出程序
    }

    // 破坏文件，还原
    // 思路：把每一个字节都拿出来，对每一个字节都处理，把某部分字节拿出来，进行处理
    // 10^5 异或 加密过程
    // 1010
    // ^0101
    // 1111 加密

    // 解密 同样的去异或 5
    // 1111
    // ^0101
    // 1010   解密后 10
    int c;// EOF end of file
    while ((c = fgetc(file))!=EOF){
        fputc(c ^ 5,file_encrpy);
    }
}*/

// 文件的解密（该方法文件适合图片，如果文件中有中文就不适合）
/*int main(){
    FILE* file = fopen(file_encrpy_image_name,"rb"); // 流指针
    FILE* file_decrpy = fopen(file_decrpy_image_name,"wb");// 新建一个文件 0kb

    if(!file || !file_decrpy){
        printf("文件打开失败");
        exit(0);
    }

    // 思路：把每一个字节都拿出来，对每一个字节都处理，把某部分字节拿出来，进行处理
    // 10^5 异或 加密过程
    //  1010
    // ^0101
    //  1111    加密

    // 解密 同样的去异或 5
    //  1111
    // ^0101
    //  1010  // 解密后 10
    int c; // EOF end of file;
    while((c = fgetc(file))!=EOF){
        fputc(c ^ 5,file_decrpy);
    }

    fclose(file);
    fclose(file_decrpy);

}*/

// 加密就改一个字节，过不去
/*int main(){
    // rwb
    FILE* file = fopen(file_image_name,"wb"); // 流指针，创建文件？有没有其它办法 支付宝人脸识别 Mat 矩阵
    // file 流的头指针

    fputc(5,file);

    fclose(file);
}*/

// 字符串密码进行加密
/*int main(){
    const char* pass_word = "12345"; // 轮流进行^操作

    FILE* file = fopen(file_image_name,"rb"); // 流操作
    FILE* file_encrpy = fopen(file_encrpy_image_name,"wb"); // 新建一个文件 0KB

    if (!file || !file_encrpy){
        printf("文件打开失败");
        exit(0);// 退出程序
    }

    int c; // EOF end of file
    int index = 0;
    int pass_len = strlen(pass_word);
    while((c = fgetc(file))!=EOF){
        fputc(c ^ pass_word[index % pass_len],file_encrpy);
        index++;
    }

    fclose(file);
    fclose(file_encrpy);
}*/

/*int main(){

    const char* pass_word = "12345";// 轮流进行^操作

    FILE* file = fopen(file_encrpy_image_name,"rb"); // 流操作
    FILE* file_decrpy = fopen(file_decrpy_image_name,"wb"); // 新建一个文件 0KB

    if (!file || !file_decrpy){
        printf("文件打开失败");
        exit(0);// 退出程序
    }

    int c; // EOF end of file
    int index = 0;
    int pass_len = strlen(pass_word);
    while ((c = fgetc(file)) != EOF){
        fputc(c ^ pass_word[index%pass_len],file_decrpy);
        index++;
    }

    fclose(file);
    fclose(file_decrpy);
}*/

// java 的操作为什么会复杂？装饰者模式（光环）okio -> JavaIo -> native方法
int getFileSize(const char* fileName){
    FILE* file = fopen(fileName,"rb");

    if(!file)
        return 0;

    fseek(file,0,SEEK_END);
    int file_size = ftell(file);

    fclose(file);
    return file_size;
}

// 文件的切割，思路类似于断点下载
/*int main(){
    // 百度云 不大于4G的文件？ 8G 文件， 扔进去
    // 大文件（断点续传）

    // 文件切割，把文件合作为一个思考

    // 计算每个文件需要写入多少？

    FILE* file = fopen(file_image_name,"rb");

    int file_size = getFileSize(file_image_name);

    // 定义 切多少，计算大小，指定文件名
    int file_number = 3;
    // 二位数组，char[] char*
    // image_0.png
    // image_1.png
    // image_2.png
    // char* file_name;
    // char*
    char** file_names = (char**)malloc(sizeof(char*)*file_number);
    int preFileSize = file_size / file_number;
    // 计算复制
    int i = 0;
    for(; i< file_number; i++){
        file_names[i] = (char*)malloc(sizeof(char)*100);// '\0'
        sprintf(file_names[i],file_split,i);

        printf("%s\n",file_names[i]);
    }

    i = 0;
    for(; i < file_number; i++){
        // 从源文件中往切割文件写入数据
        FILE* cur_file = fopen(file_names[i],"wb");  // w 会新建文件

        // 写多少？
        int start = i*preFileSize;
        int end = (i + 1)*preFileSize;
        if(i == file_number - 1){
            end = file_size;
        }

        // 第一个循环 file 读，第二个循环还是从 file 里面
        for(int j = start; j< end; j++){
            // 从 file 里面读，写入到 cur_file
            fputc(fgetc(file),cur_file);
        }
        fclose(cur_file);
        free(file_names[i]);
    }

    fclose(file);
    free(file_names);
}*/

// 文件的合并
/*int main(){
    FILE* file0 = fopen("F:\\image_0.jpg","rb");
    FILE* file1 = fopen("F:\\image_1.jpg","rb");
    FILE* file2 = fopen("F:\\image_2.jpg","rb");

    FILE* file_merge = fopen("F:\\image_merge.jpg","wb");

    int c=0;
    while((c = fgetc(file0))!=EOF){
        fputc(c,file_merge);
    }

    while((c = fgetc(file1))!=EOF){
        fputc(c,file_merge);
    }

    while((c = fgetc(file2))!=EOF){
        fputc(c,file_merge);
    }

    fclose(file0);
    fclose(file1);
    fclose(file2);
    fclose(file_merge);
}*/












