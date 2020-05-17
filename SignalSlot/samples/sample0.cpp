#include <iostream>
#include <string>
#include "../signalslot.h"
#include <thread>
#include <functional>
#include <signal.h>

void counting_demon(MEDCPP::Signal<std::string>& rSignal){

    bool bKeepCounting = true;

    static MEDCPP::Signal<int> exitSignal{};
    exitSignal.connect( [&bKeepCounting](int signalInt) {
        std::cout << "The number was: " << signalInt << ". The Ctrl-C operator was called. See you a next time\n";
        if (signalInt == 2) {
          bKeepCounting = false;
        }
    });

    signal(SIGINT, [] (int signalInt) {
        exitSignal.emit(signalInt);
    });

    int count = 0;
    while (bKeepCounting){
        std::this_thread::sleep_for(std::chrono::seconds{1});
        auto msg = std::to_string(count++);
        rSignal.emit(msg);
    }
}

void displaySomethingOnConsole(std::string msg){

    std::cout << msg << std::endl;
}

int main () {

    MEDCPP::Signal<std::string> timer{};
    timer.connect(std::function<void(std::string)>(displaySomethingOnConsole));
    std::thread thrd = std::thread(counting_demon, std::ref(timer));
    thrd.join();

    std::cout << "Program terminated without forcing it :) ";
    return 0;
}
