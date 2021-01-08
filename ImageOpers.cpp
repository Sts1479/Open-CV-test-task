/*
 * ImageOpers.cpp
 *
 *  Created on: 4 янв. 2021 г.
 *      Author: user
 */
#include "ImageOpers.hpp"
#include "Comm.hpp"
using namespace cv;
using namespace std;
extern ImgParamsDto imgParamsDto;

// unused method in this realization
bool ImageOpers::VerifySizes(const cv::Mat& imgIn, int rows, int cols){
	if (imgIn.rows < rows){
        cout << "incorrect rows" << endl;
        return false;
	}
	if (imgIn.cols < cols){
        cout << "incorrect cols" << endl;
        return false;
	}
	return true;
}

void ImageOpers::StoreToMat(const string& imgname, const string& imgpath){
	 Mat img = imread(imgpath, IMREAD_UNCHANGED); // Read in the image file	 auto it = imgMap.find(imgname);
	 if(img.empty()){
		 cout << "Failed to load an image file!" << endl;
		 return;
	 }
	 int rows = img.rows;
	 int cols = img.cols;
	 int channels = img.channels();
     cout << "" << endl;
	 cout << "Image Rows = " << rows << endl;
	 cout << "Image Columns = " << cols << endl;
	 cout << "Image Channels = " << channels << endl;

	 imgMap.addToMap(imgname, img);
	 cout << "Operation successful!" << endl;
}
// unused method in this realization
void ImageOpers::BlurImage(const string& imgname, const string &imgname_new, int x, int y){
	Mat *imgsrc;
	Mat imgdst;
	imgsrc = imgMap.getMatbyName(imgname);
	if (imgsrc == nullptr){
		cout << "The Mat is empty (blur)!" << endl;
		return;
	}
	blur(*imgsrc,imgdst,Size(x,y));
	imgMap.addToMap(imgname_new, imgdst);
	cout << "Operation successful!" << endl;
}

void ImageOpers::BlurImage(const string& imgname, const string &imgname_new, int s){
	Mat *imgsrc;
	Mat imgdst;
	imgsrc = imgMap.getMatbyName(imgname);
	if (imgsrc == nullptr){
		cout << "The Mat is empty, incorrect image name (blur)!" << endl;
		return;
	}
	blur(*imgsrc,imgdst,Size(s,s));
	imgMap.addToMap(imgname_new, imgdst);
	cout << "Operation successful!" << endl;
}

void ImageOpers::ResizeImage(const string& imgname, const string& imgname_new, int x, int y){
	Mat *imgsrc;
	Mat imgdst;
	imgsrc = imgMap.getMatbyName(imgname);
	if (imgsrc == nullptr){
		cout << "The Mat is empty, incorrect image name (resize)!" << endl;
		return;
	}
	resize(*imgsrc,imgdst,Size(x,y));
	imgMap.addToMap(imgname_new, imgdst);
	cout << "Operation successful!" << endl;
}

void ImageOpers::SaveImage(const string& imgname, const string& imgfile){
	Mat *img;
	img = imgMap.getMatbyName(imgname);
	if (img == nullptr){
		cout << "The Mat is empty, incorrect image name (save image)!" << endl;
		return;
	}
	int rows = static_cast<int &>(img->rows);
	int cols = static_cast<int &>(img->cols);
	int channels =img->channels();
    cout << "" << endl;
	cout << "Image Rows = " << rows << endl;
	cout << "Image Columns = " << cols << endl;
	cout << "Image Channels = " << channels << endl;
	imwrite(imgfile,*img);
	cout << "Operation successful!" << endl;
}

void ImageOpers::ImageMain(){
	   if (imgParamsDto.operCode == 1) {
		  imgParamsDto.operCode = 0;
		  StoreToMat(imgParamsDto.nameOfImg, imgParamsDto.pathToFile);
		  imgParamsDto.Clear();
	   }
	   if (imgParamsDto.operCode == 2) {
		  imgParamsDto.operCode = 0;
		  ResizeImage(imgParamsDto.nameOfImg,imgParamsDto.nameOfImgNew,imgParamsDto.newWidth,imgParamsDto.newHeight);
		  imgParamsDto.Clear();
	   }
	   if (imgParamsDto.operCode == 3) {
		  imgParamsDto.operCode = 0;
		  SaveImage(imgParamsDto.nameOfImg,imgParamsDto.pathToFile);
		  imgParamsDto.Clear();
	   }
	   if (imgParamsDto.operCode == 4) {
		  imgParamsDto.operCode = 0;
		  //BlurImage(imgParamsDto.nameOfImg,imgParamsDto.nameOfImgNew,imgParamsDto.newWidth,imgParamsDto.newHeight);
		  BlurImage(imgParamsDto.nameOfImg,imgParamsDto.nameOfImgNew,imgParamsDto.blurCore);
		  imgParamsDto.Clear();
	   }
}
