//
// Created by wilke on 10/30/2023.
//

#ifndef QUEUE2_HANGMANIMAGE_H
#define QUEUE2_HANGMANIMAGE_H
#include <iostream>
#include <sstream>
#include "ASCII.h"
using namespace std;

class HangManImageFrame {
private:
    string data[5][3] = {
            {"                 | \n", /* 4 lines at node 7, 3 at node 6, 2 at node 5, 1 at node 8*/
                   "         --------\\ \n", /*in every frame top*/
                   "     ____________| \n", /*in every frame bottom*/},
            {"        |        | \n"},
            {"        O        | \n"},
            {"         \\      | \n",
                   "        |\\      | \n",
                   "       /|\\      | \n"},
            {"       / \\      | \n",
                   "         \\      |\n"}
    }; // TODO reformat
    string frame;
    string makeframe(int control_param, int innerlines = 4);
    ASCIIRender ascii = ASCIIRender();
public:
    HangManImageFrame(int control_param){
        frame = makeframe(control_param);
    };

    string getFrame(){
        return this->frame;
    }
};

string HangManImageFrame::makeframe(int control_param, int innerlines){
    frame += ascii.enhance(data[0][1]); // Top of hanging post
    switch (control_param) {
        case 7:
            frame += ascii.enhance(data[1][0]);
            frame += ascii.enhance(data[2][0]);
            frame += ascii.enhance(data[3][2]);
            frame += ascii.enhance(data[4][0]);
            innerlines = 0;
            break;
        case 6:
            frame += ascii.enhance(data[1][0]);
            frame += ascii.enhance(data[2][0]);
            frame += ascii.enhance(data[3][2]);
            frame += ascii.enhance(data[4][1]);
            innerlines = 0;
            break;
        case 5:
            frame += ascii.enhance(data[1][0]);
            frame += ascii.enhance(data[2][0]);
            frame += ascii.enhance(data[3][2]);
            innerlines = 1;
            break;
        case 4:
            frame += ascii.enhance(data[1][0]);
            frame += ascii.enhance(data[2][0]);
            frame += ascii.enhance(data[3][1]);
            innerlines = 1;
            break;
        case 3:
            frame += ascii.enhance(data[1][0]);
            frame += ascii.enhance(data[2][0]);
            frame += ascii.enhance(data[3][0]);
            innerlines = 1;
            break;
        case 2:
            frame += ascii.enhance(data[1][0]);
            frame += ascii.enhance(data[2][0]);
            innerlines = 2;
            break;
        case 1:
            frame += ascii.enhance(data[1][0]);
            innerlines = 3;
            break;
    }

    for(int i = 0; i < innerlines; ++i){
        frame +=ascii.enhance( data[0][0]);
    }
    frame += ascii.enhance( data[0][2]);
    return frame;
}
#endif //QUEUE2_HANGMANIMAGE_H
