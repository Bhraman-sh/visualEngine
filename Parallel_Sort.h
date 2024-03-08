#pragma once
#include "State.h"
#include <mutex>
#include "CreateRectangle.h"

class Parallel_Sort :
    public State
{
public:
    Parallel_Sort(sf::RenderWindow* , std::stack<std::unique_ptr<State>>*,
        std::vector<int>&, CreateRectangle& );

    // MAIN STUFF  
    virtual void update();
    virtual void render();

    // UNIQUE TO PARALLEL SORT STATES
    void splitData();

    // UNIQUE TO SORT STATES;
    void sortStart();
    void merge();

    void initArray();
    void bubbleSort(int, int);

    // BUTTON RELATED
    virtual void initButtons();
    virtual void updateButtons();
    virtual void renderButtons();

private:
    std::vector<int> array, array1[2];
    CreateRectangle rectBar, rectBar1[2];

    bool finished{ false };
    std::mutex mtx;

    std::map<std::string, Button*> buttonMap;
    //std::lock_guard<std::mutex> lock;
};

