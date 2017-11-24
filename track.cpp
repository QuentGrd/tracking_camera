#include <opencv2/opencv.hpp>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

extern "C"{
    #include "include/serial.h"
}

using namespace cv;

#define TOLERANCE 100
#define RADIUS 20

int main(int, char**){

    int i,j,count;
    Vec3f pixel;
    serial_com tty;

    std::string file = "/dev/cu.usbmodem1421";
    const char* file_desc = file.c_str();
    serial_open(&tty, file_desc);
    ssize_t bytes_write;


    VideoCapture cap(0); // open the default camera
    if(!cap.isOpened())  // check if we succeeded
        return -1;

    Mat frame, mask;
    namedWindow("BazooCam",1);
    namedWindow("ChatRoulette", 1);
    moveWindow("BazooCam", 0, 0);
    moveWindow("ChatRoulette", 320, 0);


    cap.set(CV_CAP_PROP_FRAME_WIDTH,320);  //taille de la fenetre
    cap.set(CV_CAP_PROP_FRAME_HEIGHT,240); //au dela de 320*240


    MatIterator_<Vec3b> it, end, mask_it;
    int color[3] = {0, 0, 255};
    Point* center = new Point(0, 0);

    while(1){
           if(cap.read(frame)){// get a new frame from camera
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
                printf("x: %d\ty: %d\n", pos_x - center->x, pos_y - center->y);
                if (diff_x > RADIUS)
                    bytes_write = serial_simple_write(&tty, 'd');
                else if(diff_x < -RADIUS)
                    bytes_write = serial_simple_write(&tty, 'q');
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
    return 0;
}
