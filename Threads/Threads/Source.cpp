#include <iostream>
#include <thread>
#include <chrono>
//got some help from the tutor for running the program with regular threads instead of boost threads
void workerFunc()
{
    std::cout << "Worker: Running" << std::endl;
    // Pretend to do something useful...
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "Worker: Finished" << std::endl;
}
void machineFunc()
{
    //added a machine function
    std::cout << "Machine: Startup" << std::endl;
    //starts up here with a line of text
    std::this_thread::sleep_for(std::chrono::seconds(2));
    //pauses for 2 seconds
    std::cout << "Machine: Finished" << std::endl;
    //finishes the machine thread
}
void coffeeFunc()
{
    //coffee function
    std::cout << "Coffee: Drinking" << std::endl;
    //how long to take a break for drinking coffee
    std::this_thread::sleep_for(std::chrono::seconds(5));
    //three second pause
    std::cout << "Coffee: Finished" << std::endl;
}
int main(int argc, char* argv[])
{
    std::cout << "Main: Startup" << std::endl;
    std::thread workerThread(workerFunc);
    std::thread machineThread(machineFunc); //added machineFunc into main
    std::thread coffeeThread(coffeeFunc); //added coffeeFunc
    std::cout << "Main: Waiting for Thread" << std::endl;
    workerThread.join();
    machineThread.join(); //made the ending of the thread
    coffeeThread.join();
    std::cout << "Main: Done" << std::endl;
    system("pause");
    return 0;
}