/*
 * ImageOpers.hpp
 *
 *  Created on: 4 янв. 2021 г.
 *      Author: user
 */


#ifndef IMAGEOPERS_HPP_
#define IMAGEOPERS_HPP_

#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <map>
#include <utility>

class ImgMap {
private:
	std::map <std::string,cv::Mat> _imgMap;
public:
	ImgMap(){};
	~ImgMap(){};
	void addToMap(const std::string& imgname, const cv::Mat& mat){
		 auto it = _imgMap.find(imgname);
		 if (it != _imgMap.end()){
			 (*it).second = mat; //?
		 } else{
			 _imgMap[imgname] = mat;
		 }
	}
	void clearMap (){
		_imgMap.clear();
	}
	cv::Mat* getMatbyName(const std::string& imgname){
		auto it = _imgMap.find(imgname);
		if (it == _imgMap.end()){
			std::cout << "The image does not exist, enter correct name of an image." << std::endl;
			return nullptr;
		}
		else {
			return &it->second;
		}
	}
};


struct ImgParamsDto {
	std::string pathToFile;
	std::string nameOfImg;
	std::string pathToFileNew;
	std::string nameOfImgNew;
	int newWidth;
	int newHeight;
	int operCode;
	int blurCore;
	void Clear (){
		pathToFile.clear();
		nameOfImg.clear();
		pathToFileNew.clear();
		nameOfImgNew.clear();
		newWidth = 0;
		newHeight = 0;
		operCode = 0;
		blurCore = 0;
	}
};

class ImageOpers {

public:
	ImageOpers(){};
	~ImageOpers(){};
	ImgMap imgMap;
    void ResizeImage(const std::string& imgname,const std::string& imgname_new, int x, int y);
    void SaveImage(const std::string &imgname, const std::string& imgfile);
    void ImageMain();
    void StoreToMat(const std::string& imgname, const std::string& imgpath);
    void BlurImage(const std::string& imgname, const std::string &imgname_new, int x, int y);// unused method in this realization
    void BlurImage(const std::string& imgname, const std::string &imgname_new, int s);
    bool VerifySizes (const cv::Mat& imgIn, int rows, int cols);// unused method in this realization
};


#endif /* IMAGEOPERS_HPP_ */
