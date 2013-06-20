#include <math.h>
#include <opencv2/contrib/contrib.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

int main()
{
	Mat src = imread("F:/image/src/youth.jpg",1);
	int width = src.cols;
	int heigh = src.rows;
	Mat gray;
	Mat imgColor[12];
	Mat display(heigh*3,width*4,CV_8UC3);

	cvtColor(src,gray,CV_BGR2GRAY);

	for(int i=0; i<12; i++)
	{
		applyColorMap(gray,imgColor[i],i);
		int x=i%4;
		int y=i/4;
		Mat displayROI = display(Rect(x*width,y*heigh,width,heigh));
		resize(imgColor[i],displayROI,displayROI.size());
	}
	imshow("colorImg",display);
	waitKey();
	imwrite("F:/image/dst/beauty.jpg",display);
}
