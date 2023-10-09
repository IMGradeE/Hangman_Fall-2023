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
        frame = makeframe(control_param_x);
    };
    string frame;
    string makeframe(int control_param);
};

string HangManImageFrame::makeframe(int control_param_x/*TODO add args to control lines 1, 2, 3, & 4*/){
    {
        //TODO make frame, pass to appropriate node.
        frame += data[0][1]; // Top of hanging post
        //TODO add content of frame, varies depending on frame number.
        for(int i = 0; i < 4; ++i) {
            if(control_param_x != 0){
                frame += data[1][0];
                ++i;
                --control_param_x;
                if((control_param_x != 0) && (i >= 1)){
                    frame += data[2][0];
                    --control_param_x;
                    ++i;
                    if((control_param_x != 0) && (i >= 2)){

                        frame += data[3][control_param_x - 1];
                        --control_param_x;
                        ++i;
                        if((control_param_x != 0) && (i >= 3)){
                            frame += data[3][control_param_x - 1];
                            --control_param_x;
                            ++i;
                        }
                    }
                }
            }else{
                frame += data[0][0];
            }
        }
        frame += data[0][2];
    }
    return frame;
};

#endif //PROJECT_TEAM_QUEUE_H
