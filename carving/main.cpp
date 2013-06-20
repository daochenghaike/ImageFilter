#include <opencv/cv.h>
#include <opencv/highgui.h>
using namespace cv;

int main()
{
	Mat src = imread("F:/image/src/wgk.jpg");
	Mat img0(src.size(),CV_8UC3);
	Mat img1(src.size(),CV_8UC3);
	for (int y=0; y<src.rows-1; y++)
	{
		uchar *p0 = src.ptr<uchar>(y);
		uchar *p1 = src.ptr<uchar>(y+1);

		uchar *q0 = img0.ptr<uchar>(y);
		uchar *q1 = img1.ptr<uchar>(y);
		for (int x=0; x<src.cols-1; x++)
		{
			for (int i=0; i<3; i++)
			{
				int tmp0 = p1[3*(x+1)+i]-p0[3*x+i]+128;//¸¡µñ
				if (tmp0<0)
					q0[3*x+i]=0;
				else if(tmp0>255)
					q0[3*x+i]=255;
				else
					q0[3*x+i]=tmp0;

				int tmp1 = p0[3*x+i]-p1[3*(x+1)+i]+128;//µñ¿Ì
				if (tmp1<0)
					q1[3*x+i]=0;
				else if(tmp1>255)
					q1[3*x+i]=255;
				else
					q1[3*x+i]=tmp1;
			}
		}
	}
	imshow("src",src);
	imshow("¸¡µñ",img0);
	imshow("µñ¿Ì",img1);
	waitKey();
}
