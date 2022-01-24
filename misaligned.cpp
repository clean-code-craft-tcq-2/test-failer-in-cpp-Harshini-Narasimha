#include <iostream>
#include <assert.h>

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};

const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

int getColorPairNumber(int majorColorIndex, int minorColorIndex)
{
    return majorColorIndex * 5 + minorColorIndex;
}

std::string getColorPairString(int majorColorIndex, int minorColorIndex)
{
    std::cout<<"majorColorIndex:"<<majorColorIndex<<",minorColorIndex:"<<minorColorIndex<<"\n";
    std::string majorColorName(majorColor[majorColorIndex]);
    std::string minorColorName(minorColor[majorColorIndex]);
    return majorColorName.append(" | ").append(minorColorName);
}

void printColorCode(int majorColorIndex, int minorColorIndex)
{
   std::cout << getColorPairNumber(majorColorIndex,minorColorIndex) << " | " <<  getColorPairString(majorColorIndex,majorColorIndex) << "\n";
}

int printColorMap() {
    int i = 0, j = 0;

    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printColorCode(i,j);
        }
    }
    return i * j;
}

int main() {

    int result = printColorMap();

    assert(result == 25);
    assert(getColorPairNumber(0,4) == 4);
    assert(getColorPairString(0,0) == "White | Blue");
    assert(getColorPairString(1,0) == "Red | Blue");

    std::cout << "All is well (maybe!)\n";

    return 0;
}
