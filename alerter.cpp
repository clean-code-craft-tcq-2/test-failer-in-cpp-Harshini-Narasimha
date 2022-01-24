#include <iostream>
#include <assert.h>

#define NETWORKALERTSUCCESS 200
#define NETWORKALERTFAILURE 0
#define THRESHLOADTEMPERATURE 200.0

int alertFailureCount = 0;

class networkAlerterInterface{
    public:
       virtual int networkAlert(float celcius)=0;
};

class networkAlerter: public networkAlerterInterface{
     public:
        int networkAlert(float celcius)
        {
             if(celcius>THRESHLOADTEMPERATURE)
             {
                return NETWORKALERTSUCCESS;
              }
              return NETWORKALERTFAILURE;
        }
};
     
class networkAlerterStub: public networkAlerterInterface{
     public:
int networkAlert(float celcius) {
    std::cout << "ALERT: Temperature is " << celcius << " celcius.\n";
    return NETWORKALERTSUCCESS;
}
};

void alertInCelcius(float farenheit, networkAlerterInterface &networkAlerterStatus) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlerterStatus.networkAlert(celcius);

    if (returnCode != NETWORKALERTSUCCESS) {
        alertFailureCount += 0;
    }
}


int main() {
    networkAlerterStub testAlertInCelcius;
    alertInCelcius(400.5,testAlertInCelcius);
    alertInCelcius(303.6,testAlertInCelcius);
    assert(alertFailureCount == 1);
    std::cout << alertFailureCount << " alerts failed.\n";
    std::cout << "All is well (maybe!)\n";
    return 0;
}
