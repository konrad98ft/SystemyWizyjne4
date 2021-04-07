#include <iostream>
#include<opencv2\opencv.hpp>

#define LENA_PATH "lena.png"
#define KOMORKI_PATH "komorki.png"

void dispTest(cv::Mat img)
{
	cv::imshow("Test", img);
	cv::waitKey(50);
}

void dispKernel(cv::Mat k_o, cv::Mat k_tlo)
{
	std::vector<cv::Mat> vec{ k_tlo, cv::Mat(k_tlo.size(),CV_8UC1,cv::Scalar()), k_o };
	cv::Mat imgd;
	cv::merge(vec, imgd);
	cv::resize(imgd, imgd, cv::Size(20 * imgd.cols, 20 * imgd.rows), 0, 0, cv::INTER_NEAREST);
	cv::imshow("HitMiss", imgd);
	cv::waitKey(10);
}

void hitmiss(cv::Mat& src, cv::Mat& dst, cv::Mat& kernel)
{
	cv::Mat k_obiekt = (kernel == 1) * 255;
	cv::Mat k_tlo = (kernel == -1) * 255;
	dispKernel(k_obiekt, k_tlo);
	cv::Mat obiekt, tlo;
	cv::erode(src, obiekt, k_obiekt);
	cv::erode(~src, tlo, k_tlo);
	dst = obiekt & tlo;
}

void szkieletyzacja(cv::Mat& img)
{
	cv::Mat b1 = (cv::Mat_<char>(3, 3) <<
		1, 1, 1,
		0, 1, 0,
		-1, -1, -1);
	cv::Mat b2 = (cv::Mat_<char>(3, 3) <<
		0, 1, 1,
		-1, 1, 1,
		-1, -1, 0);
	cv::Mat b3 = (cv::Mat_<char>(3, 3) <<
		-1, 0, 1,
		-1, 1, 1,
		-1, 0, 1);
	cv::Mat b4 = (cv::Mat_<char>(3, 3) <<
		-1, -1, 0,
		-1, 1, 1,
		0, 1, 1);
	cv::Mat b5 = (cv::Mat_<char>(3, 3) <<
		-1, -1, -1,
		0, 1, 0,
		1, 1, 1);
	cv::Mat b6 = (cv::Mat_<char>(3, 3) <<
		0, -1, -1,
		1, 1, -1,
		1, 1, 0);
	cv::Mat b7 = (cv::Mat_<char>(3, 3) <<
		1, 0, -1,
		1, 1, -1,
		1, 0, -1);
	cv::Mat b8 = (cv::Mat_<char>(3, 3) <<
		1, 1, 0,
		1, 1, -1,
		0, -1, -1);
	dispTest(img);
	cv::Mat tmp;
	cv::Scalar sum_post = cv::sum(img);
	cv::Scalar sum_pre;
	do
	{
		sum_pre = sum_post;
		hitmiss(img, tmp, b1);
		img &= ~tmp;
		dispTest(img);
		hitmiss(img, tmp, b2);
		img &= ~tmp;
		dispTest(img);
		hitmiss(img, tmp, b3);
		img &= ~tmp;
		dispTest(img);
		hitmiss(img, tmp, b4);
		img &= ~tmp;
		dispTest(img);
		hitmiss(img, tmp, b5);
		img &= ~tmp;
		dispTest(img);
		hitmiss(img, tmp, b6);
		img &= ~tmp;
		dispTest(img);
		hitmiss(img, tmp, b7);
		img &= ~tmp;
		dispTest(img);
		hitmiss(img, tmp, b8);
		img &= ~tmp;
		dispTest(img);
		sum_post = cv::sum(img);
	} while (sum_pre != sum_post);
	cv::destroyAllWindows();
}

void nitki(cv::Mat& img)
{
	cv::Mat b1 = (cv::Mat_<char>(3, 3) <<
		-1, -1, -1,
		-1, 1, -1,
		-1, 0, 0);
	cv::Mat b2 = (cv::Mat_<char>(3, 3) <<
		-1, -1, -1,
		0, 1, -1,
		0, -1, -1);
	cv::Mat b3 = (cv::Mat_<char>(3, 3) <<
		0, 0, -1,
		-1, 1, -1,
		-1, -1, -1);
	cv::Mat b4 = (cv::Mat_<char>(3, 3) <<
		-1, -1, 0,
		-1, 1, 0,
		-1, -1, -1);
	cv::Mat b5 = (cv::Mat_<char>(3, 3) <<
		-1, -1, -1,
		-1, 1, -1,
		0, 0, -1);
	cv::Mat b6 = (cv::Mat_<char>(3, 3) <<
		0, -1, -1,
		0, 1, -1,
		-1, -1, -1);
	cv::Mat b7 = (cv::Mat_<char>(3, 3) <<
		-1, 0, 0,
		-1, 1, -1,
		-1, -1, -1);
	cv::Mat b8 = (cv::Mat_<char>(3, 3) <<
		-1, -1, -1,
		-1, 1, 0,
		-1, -1, 0);

	dispTest(img);
	cv::Scalar sum_post = cv::sum(img);
	cv::Scalar sum_pre;
	cv::Mat tmp;
	do
	{
		sum_pre = sum_post;
		hitmiss(img, tmp, b1);
		img &= ~tmp;
		dispTest(img);
		hitmiss(img, tmp, b2);
		img &= ~tmp;
		dispTest(img);
		hitmiss(img, tmp, b3);
		img &= ~tmp;
		dispTest(img);
		hitmiss(img, tmp, b4);
		img &= ~tmp;
		dispTest(img);
		hitmiss(img, tmp, b5);
		img &= ~tmp;
		dispTest(img);
		hitmiss(img, tmp, b6);
		img &= ~tmp;
		dispTest(img);
		hitmiss(img, tmp, b7);
		img &= ~tmp;
		dispTest(img);
		hitmiss(img, tmp, b8);
		img &= ~tmp;
		dispTest(img);
		sum_post = cv::sum(img);
	} while (sum_pre != sum_post);
	cv::destroyAllWindows();
}

void szkieletyzacja2(cv::Mat& img)
{
	cv::Mat b1 = (cv::Mat_<char>(3, 3) <<
		1, 1, 1,
		0, 1, 0,
		-1, -1, -1);
	cv::Mat b2 = (cv::Mat_<char>(3, 3) <<
		0, 1, 1,
		-1, 1, 1,
		-1, -1, 0);
	cv::Mat b3 = (cv::Mat_<char>(3, 3) <<
		-1, 0, 1,
		-1, 1, 1,
		-1, 0, 1);
	cv::Mat b4 = (cv::Mat_<char>(3, 3) <<
		-1, -1, 0,
		-1, 1, 1,
		0, 1, 1);
	cv::Mat b5 = (cv::Mat_<char>(3, 3) <<
		-1, -1, -1,
		0, 1, 0,
		1, 1, 1);
	cv::Mat b6 = (cv::Mat_<char>(3, 3) <<
		0, -1, -1,
		1, 1, -1,
		1, 1, 0);
	cv::Mat b7 = (cv::Mat_<char>(3, 3) <<
		1, 0, -1,
		1, 1, -1,
		1, 0, -1);
	cv::Mat b8 = (cv::Mat_<char>(3, 3) <<
		1, 1, 0,
		1, 1, -1,
		0, -1, -1);
	dispTest(img);
	cv::Scalar sum_post = cv::sum(img);
	cv::Scalar sum_pre;
	cv::Mat tmp;
	do
	{
		sum_pre = sum_post;
		cv::morphologyEx(img, tmp, cv::MORPH_HITMISS, b1);
		img &= ~tmp;
		cv::morphologyEx(img, tmp, cv::MORPH_HITMISS, b2);
		img &= ~tmp;
		cv::morphologyEx(img, tmp, cv::MORPH_HITMISS, b3);
		img &= ~tmp;
		cv::morphologyEx(img, tmp, cv::MORPH_HITMISS, b4);
		img &= ~tmp;
		cv::morphologyEx(img, tmp, cv::MORPH_HITMISS, b5);
		img &= ~tmp;
		cv::morphologyEx(img, tmp, cv::MORPH_HITMISS, b6);
		img &= ~tmp;
		cv::morphologyEx(img, tmp, cv::MORPH_HITMISS, b7);
		img &= ~tmp;
		cv::morphologyEx(img, tmp, cv::MORPH_HITMISS, b8);
		img &= ~tmp;
		sum_post = cv::sum(img);
	} while (sum_pre != sum_post);
	cv::destroyAllWindows();
}

void onMouse(int event, int x, int y, int flags, void* userdata)
{
	
	
	if (event == cv::EVENT_LBUTTONDOWN)
	{
		cv::Mat* pimg = (cv::Mat*)userdata;
		std::cout << "x:" << x << " y:" << y << " e:" << event << " f:" << flags << std::endl;
		
		//ramka inicjujaca
		cv::Mat wImg = pimg->clone();
		cv:: Mat tmp1 = cv::Mat(wImg.size(), wImg.type());
		tmp1 = 0;
		cv::circle(tmp1, cv::Point(x, y), 10, cv::Scalar(255, 255, 255), 2); //białe kółko
		
		//iteracja 
		cv::Scalar cnt_post = cv::sum(tmp1);
		cv::Scalar cnt_pre;
		do
		{
			cnt_pre = cnt_post;
			cv::dilate(tmp1, tmp1, cv::noArray());
			tmp1 &= wImg;
			cnt_post = cv::sum(tmp1);
		} while (cnt_post != cnt_pre);
		
		wImg &= ~tmp1;
		cv::imshow("Test", tmp1);
		
	}
}

int main()
{
	cv::Mat komorki = cv::imread(KOMORKI_PATH, cv::IMREAD_GRAYSCALE);
	cv::Mat lena = cv::imread(LENA_PATH);
	cv::Mat workImg = komorki.clone();
	cv::Mat tmp1;
	cv::Mat tmp2;
	cv::Mat kernel = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(5, 5));
	//MORPH_RECT, cv::MORPH_CROSS, cv::MORPH_ELLIPSE

	cv::namedWindow("Test");
	while (1)
	{
		cv::imshow("Test", workImg);
		switch (cv::waitKey())
		{
		case 'l':
			workImg = lena.clone();
			break;
		case 'k':
			workImg = komorki.clone();
			break;
		case 'e':
			cv::erode(workImg, workImg, kernel);
			break;
		case 'd':
			cv::dilate(workImg, workImg, kernel);
			break;
		case 'o':
			cv::erode(workImg, workImg, kernel);
			cv::dilate(workImg, workImg, kernel);
			break;
		case 'c':
			cv::dilate(workImg, workImg, kernel);
			cv::erode(workImg, workImg, kernel);
			break;
		case 's':
		{
			//ramka inicjuj�ca
			tmp1 = cv::Mat(workImg.size(), workImg.type());
			tmp1 = 0;
			cv::line(tmp1, cv::Point(0, 0), cv::Point(tmp1.cols - 1, 0), cv::Scalar::all(255));
			cv::line(tmp1, cv::Point(0, tmp1.rows - 1), cv::Point(tmp1.cols - 1, tmp1.rows - 1), cv::Scalar::all(255));
			cv::line(tmp1, cv::Point(0, 0), cv::Point(0, tmp1.rows - 1), cv::Scalar::all(255));
			cv::line(tmp1, cv::Point(tmp1.cols - 1, 0), cv::Point(tmp1.cols - 1, tmp1.rows - 1), cv::Scalar::all(255));
			//iteracja 
			cv::Scalar cnt_post = cv::sum(tmp1);
			cv::Scalar cnt_pre;
			do
			{
				cnt_pre = cnt_post;
				cv::dilate(tmp1, tmp1, cv::noArray());
				tmp1 &= workImg;
				//wy�witlanie operacji po�rednich dla cel�w edukacyjnych
				cv::waitKey(20);
				cv::imshow("Test", tmp1);
				//
				cnt_post = cv::sum(tmp1);
			} while (cnt_post != cnt_pre);
			//odj�cie od obrazu wej�ciowego element�w na brzegach
			workImg &= ~tmp1;
		}
		break;
		case 'y':
			szkieletyzacja(workImg);
			break;
		case 'n':
			nitki(workImg);
			break;
		case 'z':
			szkieletyzacja2(workImg);
			break;
		case 'j':
			cv::erode(workImg, tmp1, kernel);
			cv::dilate(workImg, tmp2, kernel);
			workImg = tmp2 - tmp1;
			break;
		case 't':
			cv::morphologyEx(workImg, workImg, cv::MORPH_TOPHAT, cv::noArray());
			break;
		case 'b':
			cv::morphologyEx(workImg, workImg, cv::MORPH_BLACKHAT, cv::noArray());
			break;
		case 'x':
			cv::setMouseCallback("Test", onMouse, &workImg);
			break;
		case 'q':return 0;
		}
	}
}