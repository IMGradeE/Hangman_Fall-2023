//
// Created by wilke on 9/27/2023.
//
#ifndef PROJECT_TEAM_QUEUE_H
#define PROJECT_TEAM_QUEUE_H

#include <iostream>
#include <sstream>

using namespace std;

class HangManImageFrame {
private:
    string data[7][7] = {
            {"             | \n", /* 4 lines at node 7, 3 at node 6, 2 at node 5, 1 at node 8*/
                   "          _____ \n", /*in every frame top*/
                   "       ____________ \n", /*in every frame bottom*/},
            {"         |   | \n"},
            {"         O   | \n"},
            {"          \\  | \n",
                   "         |\\  | \n",
                   "        /|\\  | \n"},
            {"        / \\  | \n",
                   "          \\  |\n"}
    };
    public:
    HangManImageFrame(int control_param_x/*TODO add args to control lines 1, 2, 3, & 4*/){
        //TODO make frame, pass to appropriate node.
        frame += data[0][1]; // Top of hanging post
        //TODO add content of frame, varies depending on frame number.

        for(int i = 0; i < 4; ++i) {
            if((0 < control_param_x) && (control_param_x < 2)){
                frame += data[control_param_x][0];
                ++i;
            }
            frame += data[0][0];
        }
        frame += data[0][2]; // Floor of hanging post
    };
    string frame;
    string makeframe(int control_param);
};

string HangManImageFrame::makeframe(int control_param/*TODO add args to control lines 1, 2, 3, & 4*/){
    //TODO make frame, pass to appropriate node.
    frame += data[0][1]; // Top of hanging post
    //TODO add content of frame, varies depending on frame number.
    if (control_param == 0)

        frame += data[0][2]; // Floor of hanging post
};

#endif //PROJECT_TEAM_QUEUE_H
