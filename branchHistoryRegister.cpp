#include "branchHistoryRegister.h"
#include <iostream>
#include <iomanip>
#include <istream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

//Sean Blucker

using namespace std;

namespace csci5814
{
    BranchHistoryRegister::BranchHistoryRegister()
    {
        value = 0;
        size = 4;
        mask = size;
    }

    int BranchHistoryRegister::getValue()
    {
        return value;
    }

    int BranchHistoryRegister::getSize()
    {
        return size;
    }

    void BranchHistoryRegister::setValue(int setValue)
    {
        value = setValue & mask;
    }

    void BranchHistoryRegister::updateTaken()
    {
        value <<= 1;
        value += 1;
        value = value & mask;
    }

    void BranchHistoryRegister::updateNotTaken()
    {
        value <<= 1;
        value = value & mask;
    }

    void BranchHistoryRegister::updateBranchHistoryRegister(std::string takenBranch)
    {
        if(takenBranch == "T")
            updateTaken();
        else
            updateNotTaken();
    }
}
