#include <opencv2/opencv.hpp>
#include <iostream>
#include <cstdio>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string>

extern "C"{
	#include "../include/serial.h"
}

using namespace cv;

#define TOLERANCE 100
#define RADIUS 40
#define DEBUG 1
#define DEBUGLINE 0
#define CHRONO 0

void save_data(FILE* file, int diff_x, int diff_y, double tmp);

int main(int, char**){

	int i,j,count;
	Vec3f pixel;
	serial_com tty;

	FILE* file = NULL;
	file = fopen("result/xprad40sp4 (o).txt", "w+");

	std::string desc = "/dev/cu.usbmodem1411";
	const char* file_desc = desc.c_str();
	serial_open(&tty, file_desc);
	ssize_t bytes_write;


	VideoCapture cap(0); // open the default camera
	if(!cap.isOpened())  // check if we succeeded
		return -1;

	Mat frame, frame1, mask, mask1;
	namedWindow("BazooCam",1);
	namedWindow("ChatRoulette", 1);
	moveWindow("BazooCam", 0, 0);
	moveWindow("ChatRoulette", 640, 0);


	cap.set(CV_CAP_PROP_FRAME_WIDTH, 640);  //taille de la fenetre
	cap.set(CV_CAP_PROP_FRAME_HEIGHT,480); //au dela de 320*240


	MatIterator_<Vec3b> it, end, mask_it;
	int color[3] = {0, 0, 255};
	Point* center = new Point(0, 0);

	bytes_write = serial_simple_write(&tty, 'm');

	//Timer
	std::clock_t start = std::clock();

	while(1){
		if(cap.read(frame)){// get a new frame from camera
			if (((((double) std::clock() - start)/1000) > 6000) && CHRONO)
				break;
			cv::flip(frame, frame1, 1);
			cv::GaussianBlur(frame1, frame, Size(7, 7), 0, 0);

			center->x = frame.cols/2;
			center->y = frame.rows/2;
			mask = frame.clone();
			mask_it = mask.begin<Vec3b>();

			int sum_x = 0, sum_y = 0;
			int nb_pixel = 0;

			for( it = frame.begin<Vec3b>(), end = frame.end<Vec3b>(); it != end; ++it){
				float sum = (*mask_it)[0] + (*mask_it)[1] + (*mask_it)[2];
				float norm = (*mask_it)[2]/sum;
				if (norm > 0.55){
					(*mask_it)[0] = 255;
					(*mask_it)[1] = 255;
					(*mask_it)[2] = 255;

					/*sum_x += (it).pos().x;
					sum_y += (it).pos().y;
					nb_pixel++;*/
				}
				else{
					(*mask_it)[0] = 0;
					(*mask_it)[1] = 0;
					(*mask_it)[2] = 0;
				}
				++mask_it;
			}

			int erosion_size = 5;
			Mat element = getStructuringElement(MORPH_ELLIPSE, Size( 2*erosion_size + 1, 2*erosion_size+1 ), Point( erosion_size, erosion_size ));
			erode(mask, mask, element);
			erosion_size = 3;
			element = getStructuringElement(MORPH_ELLIPSE, Size( 2*erosion_size + 1, 2*erosion_size+1 ), Point( erosion_size, erosion_size ));
			dilate(mask, mask, element);

			for(it = mask.begin<Vec3b>(), end = mask.end<Vec3b>(); it != end; ++it){
				if ((*it)[0] == 255 && (*it)[1] == 255 && (*it)[2] == 255){
					sum_x += (it).pos().x;
					sum_y += (it).pos().y;
					nb_pixel++;
				}
			}

			if (DEBUGLINE){
				//y-line
				//line(frame, Point(0, 240), Point(640, 240), Scalar(0, 255, 0));
				line(frame, Point(0, 230), Point(640, 230), Scalar(0, 255, 0));
				line(frame, Point(0, 250), Point(640, 250), Scalar(0, 255, 0));
				line(frame, Point(0, 215), Point(640, 215), Scalar(0, 255, 0));
				line(frame, Point(0, 265), Point(640, 265), Scalar(0, 255, 0));
				line(frame, Point(0, 185), Point(640, 185), Scalar(0, 255, 0));
				line(frame, Point(0, 295), Point(640, 295), Scalar(0, 255, 0));
				line(frame, Point(0, 125), Point(640, 125), Scalar(0, 255, 0));
				line(frame, Point(0, 355), Point(640, 355), Scalar(0, 255, 0));

				//x-line
				//line(frame, Point(320, 0), Point(320, 480), Scalar(0, 255, 0));
				line(frame, Point(310, 0), Point(310, 480), Scalar(0, 255, 0));
				line(frame, Point(330, 0), Point(330, 480), Scalar(0, 255, 0));
				line(frame, Point(290, 0), Point(290, 480), Scalar(0, 255, 0));
				line(frame, Point(350, 0), Point(350, 480), Scalar(0, 255, 0));
				line(frame, Point(248, 0), Point(248, 480), Scalar(0, 255, 0));
				line(frame, Point(392, 0), Point(392, 480), Scalar(0, 255, 0));
				line(frame, Point(165, 0), Point(165, 480), Scalar(0, 255, 0));
				line(frame, Point(475, 0), Point(475, 480), Scalar(0, 255, 0));
			}

			if(nb_pixel != 0){
				Point* baricentre = new Point(sum_x/nb_pixel, sum_y/nb_pixel);
				circle(frame, *baricentre, 2, Scalar(0, 255, 0), 3);
				int pos_x = baricentre->x, pos_y = baricentre->y;
				int diff_x = pos_x - center->x, diff_y = pos_y - center->y;
				int char_x, char_y;
				char inst;
				save_data(file, diff_x, diff_y, ((double) std::clock() - start)/1000);
				/*printf("%f\n", (double) (std::clock() - start)/1000000);
				printf("x: %d\ty: %d\n", pos_x - center->x, pos_y - center->y);*/
				/*if (diff_x > RADIUS)
					bytes_write = serial_simple_write(&tty, 'q');
				else if(diff_x < -RADIUS)
					bytes_write = serial_simple_write(&tty, 'd');
				if (diff_y > RADIUS)
					bytes_write = serial_simple_write(&tty, 's');
				else if (diff_y < -RADIUS)
					bytes_write = serial_simple_write(&tty, 'z');
				else
					bytes_write = serial_simple_write(&tty, ' ');*/

				if (pos_x <= 165)
					char_x = 10;
				else if (pos_x <= 248)
					char_x = 20;
				else if (pos_x <= 290)
					char_x = 30;
				else if (pos_x <= 310)
					char_x = 40;
				else if (pos_x > 310 && pos_x < 330)
					char_x = 50;
				else if (pos_x >= 475)
					char_x = 90;
				else if (pos_x >= 392)
					char_x = 80;
				else if (pos_x >= 350)
					char_x = 70;
				else if (pos_x >= 330)
					char_x = 60;

				if (pos_y <= 125)
					char_y = 1;
				else if (pos_y <= 185)
					char_y = 2;
				else if (pos_y <= 215)
					char_y = 3;
				else if (pos_y <= 230)
					char_y = 4;
				else if (pos_y > 230 && pos_y < 250)
					char_y = 5;
				else if (pos_y >= 355)
					char_y = 9;
				else if (pos_y >= 295)
					char_y = 8;
				else if (pos_y >= 265)
					char_y = 7;
				else if (pos_y >= 250)
					char_y = 6;

				inst = (char) char_x+char_y;
				printf("char_x: %d\tchar_y: %d\tchar: %d\t char: %c\n", char_x, char_y, char_x+char_y, inst);

				if (char_x+char_y != 55)
					bytes_write = serial_simple_write(&tty, inst);


			}
			else
				bytes_write = serial_simple_write(&tty, ' ');

			imshow("ChatRoulette", mask);
			imshow("BazooCam", frame);

		}
		if(waitKey(30) >= 0) break;
	}
	// the camera will be deinitialized automatically in VideoCapture destructor
	fclose(file);
	return 0;
}

void save_data(FILE* file, int diff_x, int diff_y, double tmp){

  if(file != NULL){
	double dist = sqrt(pow(diff_x, 2) + pow(diff_y, 2));
	fprintf(file, "%f,%f\n", dist, tmp);
  }
  else{
	printf("ERROR ! Impossible to open data file\n");
  }
}
