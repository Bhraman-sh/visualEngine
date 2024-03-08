#pragma once
#include "State.h"
#include <mutex>
#include "CreateRectangle.h"

class Parallel_Sort :
    public State
{
public:
    Parallel_Sort(sf::RenderWindow* , std::stack<std::unique_ptr<State>>*,
        std::vector<int>&, CreateRectangle&, int , char);

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
    void selectionSort(int pos, int ind);
    void mergeSort(int pos, int ind);
    void mergeSortHelper(std::vector<int>& arr, int l, int r, int ind, int pos);
    void mergee(std::vector<int>& arr, int l, int m, int r, int ind, int pos);

    void quickSort(int pos, int ind);
    void quickSortHelper(std::vector<int>& arr, int low, int high, int ind, int pos);
    int partition(std::vector<int>& arr, int low, int high, int ind, int pos);
    // BUTTON RELATED
    virtual void initButtons();
    virtual void updateButtons();
    virtual void renderButtons();

private:
    
    std::string duration;
    sf::Text infoText;
    char whichSort;
    int speed;
    std::vector<int> array, array1[2];
    CreateRectangle rectBar, rectBar1[2];

    bool finished{ false };
    std::mutex mtx;

    std::map<std::string, Button*> buttonMap;
    int start{ 0 };
    int end{ 0 };
    //std::lock_guard<std::mutex> lock;
};

