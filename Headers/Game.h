//
// Created by wilke on 10/30/2023.
//

#ifndef QUEUE2_GAME_H
#define QUEUE2_GAME_H
#include <iostream>
#include <sstream>
#include <Windows.h>
#include "Queue.h"
#include "list.h"
class GameInstance:Queue<string>{
private:
    boolean wincond;
    string easy[20]{};
    string hard[20]{};
public:
    GameInstance(int diffChoice):wincond(false){
        unique_ptr<Queue<string>> frameQueue(new Queue<string>());
        frameQueue->getHangmanQueue();
        hard->append("")
    }
    /*
     * do {
            cout << "\n\n\n\n\n\n\n\n\n\n";
            cout << frameQueue->get();
            Sleep(1000);
        } while (frameQueue->remove() && !wincond);
     * */
};
#endif //QUEUE2_GAME_H
