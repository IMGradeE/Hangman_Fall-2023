//
// Created by wilke on 11/16/2023.
//

#ifndef QUEUE2_ASCII_H
#define QUEUE2_ASCII_H
#include <iostream>
#include <sstream>

using namespace std;
struct ASCIIRender {
    int count = 0;
    string thinChars[5] = {"'",",",  ".",".",  "'"};
    string thickChars[5] = {"&","$", "#", "@","?"};
    int height = 4;
    int width = 6;
    
    void clearConsole(){
        stringstream ss;
        int i = 0;
        while(i<1800){ // "clears" console but not really
            ss<<'\n';
            ++i;
        }
        cout << ss.str();
        ss.clear();
    };
    
    int randomIndex(int num = 5){
        int ret = (rand() %num);
        return ret;
    }
    
    string enhance(string asciiString){
        string ret;
        for (int i = 0; i < height; ++i) {
            count = width;
            for (char c: asciiString) {
                for(int k = 0; k< width;++k){
                    if (count <= 0){
                        count = width;
                    }
                    if (c == '-') {
                        if (i < height/2) {
                            ret += thickChars[randomIndex()];
                        } else {
                            ret += thinChars[randomIndex()];
                        }
                    } else if (c == '_') {
                        if (i >= height/2) {
                            ret += thickChars[randomIndex()];
                        } else {
                            ret += thinChars[randomIndex()];
                        }
                    } else if (c == '|') {
                        ret += thickChars[randomIndex()];
                        continue;
                    } else if (c == '\\') {
                        if(k <= i) {
                            ret += thickChars[randomIndex()];
                        }
                        else{
                            ret += thinChars[randomIndex()];
                        }
                    }else if (c == 'l') {
                        if(k <= i) {
                            ret += thinChars[randomIndex()];
                        }
                        else{
                            ret += thickChars[randomIndex()];
                        }

                    }else if (c == '/') {
                        if(count <= i) {
                            ret += thinChars[randomIndex()];
                        }
                        else{
                            ret += thickChars[randomIndex()];
                        }
                        --count;
                    }else if (c == 'r') {
                        if(count <= i) {
                            ret += thickChars[randomIndex()];
                        }
                        else{
                            ret += thinChars[randomIndex()];
                        }
                        --count;
                    }else if (c == 't'){
                        for (int j = 0; j < width/2; ++j) {
                            ret += thinChars[randomIndex()];
                        }
                        k = width;
                    }else if (c == '\n') {
                        for (int j = 0; j < 1920/width*2;++j){
                            ret += thinChars[randomIndex()];
                        }
                        ret += "\n";
                        break;
                    }else if(c == 'O') {
                        if(i == 0 || i == height -1||k == 0 || k == width - 1){
                            ret += thickChars[randomIndex()];
                        }else{
                            ret += ' ';
                        }
                    }else if(c == ':') {
                        if (k < width/2 || k > width - (width/2)){
                            ret += thinChars[randomIndex()];
                        }else{
                                ret += '#';
                        }
                    }else {
                        ret += thinChars[randomIndex()];
                    }
                }
            }
        }
        return ret;
    }
};


#endif //QUEUE2_ASCII_H
