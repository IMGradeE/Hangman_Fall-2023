//
// Created by wilke on 11/16/2023.
//

#ifndef QUEUE2_HANGMANGRAPHICS_H
#define QUEUE2_HANGMANGRAPHICS_H
#include <iostream>
#include <sstream>
#include <random>


using namespace std;
class ASCIIRender;



class ASCIIRender{
public:
    char whiteSpace = ' ';
    string thickChars[5] = {"&","$", "#", "@","?"};
    default_random_engine engine;
    uniform_int_distribution<int> distribution;
    int count = 0;
    int height = 4;
    int width = 6;

    ASCIIRender(uniform_int_distribution<int> dist):distribution(dist){}

    ASCIIRender():distribution(0,4){} // default constructor generates a value between 0 and 4.

    static void clearConsole(){
        stringstream ss;
        int i = 0;
        while(i<2400){ // "clears" console but not really
            ss<<'\n';
            ++i;
        }
        cout << ss.str();
    };

    int randomIndex(int num = 5){
        if (num != 5) {
            return distribution(engine) % num;
        }else{
            return distribution(engine);
        }
    }

    string enhance(string asciiString, int titleCard = 0, int enhanceWidth = 6, int enhanceHeight = 4){ //TODO simplify
        int count2 = 0;
        string ret;
        for (int i = 0; i < enhanceHeight; ++i) {
            count = enhanceWidth;
            for (char c: asciiString) {
                for(int k = 0; k < enhanceWidth;++k){
                    if (count <= 0){
                        count = enhanceWidth;
                    }

                    if (c == '-') {
                        if (i < enhanceHeight / 2) {
                            ret += thickChars[randomIndex()];
                        } else {
                            ret += whiteSpace;
                        }
                    } else if (c == '_') {
                        if (i >= enhanceHeight / 2) {
                            ret += thickChars[randomIndex()];
                        } else {
                            ret += whiteSpace;
                        }
                    } else if (c == '|') {
                        ret += thickChars[randomIndex()];
                    } else if (c == '\\') {
                        if(k <= i) {
                            ret += thickChars[randomIndex()];
                        }
                        else{
                            ret += whiteSpace;
                        }
                    }else if (c == 'l') {
                        if(k <= i) {
                            ret += whiteSpace;
                        }
                        else{
                            ret += thickChars[randomIndex()];
                        }

                    }else if (c == '/') {
                        if(count <= i) {
                            ret += whiteSpace;
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
                            ret += whiteSpace;
                        }
                        --count;
                    }else if (c == 't'){
                        for (int j = 0; j < enhanceWidth/2; ++j) {
                            ret += whiteSpace;
                        }
                        k = enhanceWidth;
                    }else if (c == '\n') {
                        for (int j = 0; j < 1920/(enhanceWidth*4);++j){
                            ret += whiteSpace;
                        }
                        ret += "\n";
                        break;
                    }else if(c == 'O') {
                        if(i == 0 || i == enhanceHeight - 1 || k == 0 || k == enhanceWidth - 1){
                            ret += thickChars[randomIndex()];
                        }else{
                            ret += ' ';
                        }
                    }else if(c == ':') {
                        if (k < enhanceWidth/2 || k > enhanceWidth - (enhanceWidth/2)){
                            ret += whiteSpace;
                        }else{
                                ret += '#';
                        }
                    }else {
                        ret += whiteSpace;
                    }
                }
            }
            ++count2;
            if (titleCard != 0){
                for (int j = 0; j < titleCard +randomIndex(5); ++j) {
                    ret += enhance("\n",0,1,1);
                }
            }
        }
        return ret;
    }
};

class Graphics{
public:
    ASCIIRender ascii = ASCIIRender();
    string Title[2] = {
                "| | r/l\\ |l\\ |t|-- |l\\r/| r/l\\ |l\\ |\n",
                "|-|r/r\\l\\| l\\|t|_/ | l/ |r/r\\l\\| l\\|\n"};
    string Death[4] = {
            "l\\  r/ |--| |  |  |--\\ --- |--- |--\\  \n",
            " l\\r/  |  | |  |  |  |  |  |___ |  |  \n",
            "  t|t   |  | |  |  |  |  |  |    |  |  \n",
            "  t|t   |__| |__|  |__/ ___ |___ |__/  \n"};

    string titleCard(int distance, string arr[], int size){
        stringstream ss;
        for (int i = 0; i < size; ++i) {
            try {
                ss << ascii.enhance(arr[i], distance);
            }catch (exception){
                break;
            }
        }
        return ss.str();
    }

    void pseudo_animation_helper(string arr[],int size) {
        for (int i = 228; i >= 0; --i) {

            if (i >= 100) {
                Sleep(5);
                stringstream ss;
                static int x = (i-100) / 4;
                if (i % 4 == 0) {
                    --x;
                }
                ss << titleCard(x, arr, size);
                ascii.clearConsole();
                cout << ss.str();
                if (x == 0){
                    x = 32;
                }
            } else {
                Sleep(5);
                stringstream ss;
                for (int k = 0; k < size; ++k) {
                    ss << ascii.enhance(arr[k]);
                }
                ascii.clearConsole();
                cout << ss.str();
            }
        }

    }

    void pseudo_animation(int arraySelector){
        if (arraySelector == 1) {
            int size = 4;
            pseudo_animation_helper(Death, size);
        }else{
            int size = 2;
            pseudo_animation_helper(Title, size);
        }
        Sleep(200);

        ascii.clearConsole();
    }
};



#endif //QUEUE2_HANGMANGRAPHICS_H
