#include <opencv2/opencv.hpp>
using namespace cv;
int main()
{
	//������ͷ��ȡ��Ƶ
	VideoCapture capture("man.mp4");
	//ѭ����ʾÿһ֡
	while(1){
		Mat frame;//����һ��Mat���������ڴ洢ÿһ֡��ͼ��
		capture >> frame;//��ȡ��ǰ֡
		if(frame.empty())//������ϣ��˳�
			break;
		imshow("��ȡ��Ƶ֡",frame);//��ʾ��ǰ֡
		waitKey(30);//��ʱ30ms
	}
	system("pause");
	return 0;
}
