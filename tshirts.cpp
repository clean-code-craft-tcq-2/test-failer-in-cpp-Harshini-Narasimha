#include <iostream>
#include <assert.h>

char size(int cms) {
    char sizeName = '\0';
    if(cms < 38) {
        sizeName = 'S';
    } else if(cms >= 38 && cms < 42) {
        sizeName = 'M';
    } else if(cms >= 42) {
        sizeName = 'L';
    }
    return sizeName;
}

void testShirtsize(int cms, char expectedSize)
{
    assert(size(cms) == expectedSize);
}

int main() {
    testShirtsize(37,'S');
    testShirtsize(40,'M');
    testShirtsize(43,'L');
    testShirtsize(38,'M');
    testShirtsize(42,'L');
    return 0;
}
