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

void save_data(FILE* file, int diff_x, int diff_y, double tmp);

int main(int, char**){

    int i,j,count;
    Vec3f pixel;
    serial_com tty;

    FILE* file = NULL;
    file = fopen("result/xprad40sp4.txt", "w+");

    std::string desc = "/dev/cu.usbmodem1411";
    const char* file_desc = desc.c_str();
    serial_open(&tty, file_desc);
    ssize_t bytes_write;


    VideoCapture cap(0); // open the default camera
    if(!cap.isOpened())  // check if we succeeded
        return -1;

    Mat frame, frame1, mask;
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
        if(cap.read(frame1)){// get a new frame from camera
            if ((((double) std::clock() - start)/1000) > 6000)
                break;
            cv::flip(frame1, frame, 1);
            center->x = frame.cols/2;
            center->y = frame.rows/2;
            mask = frame.clone();
            mask_it = mask.begin<Vec3b>();

            int sum_x = 0, sum_y = 0;
            int nb_pixel = 0;

            for( it = frame.begin<Vec3b>(), end = frame.end<Vec3b>(); it != end; ++it){
                if ((((*it)[2] - (*it)[0]) > TOLERANCE) && (((*it)[2] - (*it)[1]) > TOLERANCE)){
                    (*mask_it)[0] = 255;
                    (*mask_it)[1] = 255;
                    (*mask_it)[2] = 255;

                    sum_x += (it).pos().x;
                    sum_y += (it).pos().y;
                    nb_pixel++;
                }
                else{
                    (*mask_it)[0] = 0;
                    (*mask_it)[1] = 0;
                    (*mask_it)[2] = 0;
                }
                ++mask_it;
            }

            if(nb_pixel != 0){
                Point* baricentre = new Point(sum_x/nb_pixel, sum_y/nb_pixel);
                circle(frame, *baricentre, 2, Scalar(0, 255, 0), 3);
                int pos_x = baricentre->x, pos_y = baricentre->y;
                int diff_x = pos_x - center->x, diff_y = pos_y - center->y;
                save_data(file, diff_x, diff_y, ((double) std::clock() - start)/1000);
                /*printf("%f\n", (double) (std::clock() - start)/1000000);
                printf("x: %d\ty: %d\n", pos_x - center->x, pos_y - center->y);*/
                if (diff_x > RADIUS)
                    bytes_write = serial_simple_write(&tty, 'q');
                else if(diff_x < -RADIUS)
                    bytes_write = serial_simple_write(&tty, 'd');
                if (diff_y > RADIUS)
                    bytes_write = serial_simple_write(&tty, 's');
                else if (diff_y < -RADIUS)
                    bytes_write = serial_simple_write(&tty, 'z');
                else
                    bytes_write = serial_simple_write(&tty, ' ');
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
