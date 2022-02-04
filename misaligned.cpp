#include <iostream>
#include <assert.h>
#include <map>

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

int getColorPairNumber(int majorColorIndex, int minorColorIndex)
{
    return ((majorColorIndex * 5 + minorColorIndex)+1); //Colour pair number must start with 1
}
std::string getColorPairString(int majorColorIndex, int minorColorIndex)
{
    std::string majorColorName(majorColor[majorColorIndex]);
    std::string minorColorName(minorColor[minorColorIndex]);
    return majorColorName.append(" | ").append(minorColorName);
}
int updateColorCoderMap( int majorColorIndex, int minorColorIndex, std::map<int,std::string> & colorCoderList)
{
   int pairNumber= getColorPairNumber(majorColorIndex,minorColorIndex);
   std::string colorPair= getColorPairString(majorColorIndex,minorColorIndex);
   colorCoderList[pairNumber]=colorPair;
   return pairNumber;
}
void printColorCode(int majorColorIndex, int minorColorIndex, std::map<int,std::string> & colorCoderList)
{
   int pairNumber= updateColorCoderMap(majorColorIndex,minorColorIndex,colorCoderList);
   std::cout << pairNumber << " | " << colorCoderList[pairNumber]<<"\n";
}
int printColorMap(std::map<int,std::string> & colorCoderList) {
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printColorCode(i,j,colorCoderList);
        }
    }
    return i * j;
}
void testPrintColorMap(std::map<int,std::string> &colorCodedList) 
{
    int result = printColorMap(colorCodedList);
    assert(colorCodedList.size() == 25);
    assert(colorCodedList[1] == "White | Blue");
    assert(colorCodedList[25] == "Violet | Slate");
    assert(result == 25);
    assert(getColorPairNumber(0,0) == 1);// Pair number should start with 1
    assert(getColorPairNumber(4,4) == 25);// Pair number should end with 25
    assert(getColorPairString(0,0) == "White | Blue");
    assert(getColorPairString(1,0) == "Red | Blue");
}
void testUpdateColorCoderMap(std::map<int,std::string> &colorCodedList)
{
    int pairNumber = updateColorCoderMap(0,0,colorCodedList);
    assert(pairNumber ==1);
    assert(colorCodedList.size() == 1);
    assert(colorCodedList[1] == "White | Blue");
}
int main() {   
    std::map<int,std::string> colorCoderList;
    testPrintColorMap(colorCoderList);
    std::map<int,std::string> testColorCoderList;
    testUpdateColorCoderMap(testColorCoderList);
    return 0;
}
