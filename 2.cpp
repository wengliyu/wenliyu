#include <opencv2/opencv.hpp>
using namespace cv;
int main()
{
	//从摄像头读取视频
	VideoCapture capture("man.mp4");
	//循环显示每一帧
	while(1){
		Mat frame;//定义一个Mat变量，用于存储每一帧的图像
		capture >> frame;//读取当前帧
		if(frame.empty())//播放完毕，退出
			break;
		imshow("读取视频帧",frame);//显示当前帧
		waitKey(30);//延时30ms
	}
	system("pause");
	return 0;
}
