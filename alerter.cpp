#include <iostream>
#include <assert.h>

#define NETWORKALERTSUCCESS 200
#define NETWORKALERTFAILURE 500
#define THRESHLOADTEMPERATURE 200.0

int alertFailureCount = 0;

class INetworkAlerterInterface{
    public:
       virtual int networkAlert(float celcius)=0;
};

class networkAlerter: public INetworkAlerterInterface{
     public:
        int networkAlert(float celcius)
        {
            std::cout << "ALERT: Temperature is " << celcius << " celcius.\n";
            bool isNetworkAccessAvailable=false;
            //TODO:Check the network access available and set the variable isNetworkAccessAvailable accordingly
             if(isNetworkAccessAvailable)
             {
                return NETWORKALERTSUCCESS;
              }
              return NETWORKALERTFAILURE;
        }
};

class networkAlerterStub: public INetworkAlerterInterface{
     public:
    int networkAlert(float celcius) {
    std::cout << "ALERT: Temperature is " << celcius << " celcius.\n";
    if(celcius>THRESHLOADTEMPERATURE)
    {
         return NETWORKALERTSUCCESS;
    }
         return NETWORKALERTFAILURE;        
    }
};

int convertFarenheitToCelcius(float farenheit) {
    return (farenheit - 32) * 5 / 9;
}

void alertInCelcius(float farenheit, INetworkAlerterInterface &networkAlerterStatus) {
    int celcius = convertFarenheitToCelcius(farenheit);
    int returnCode = networkAlerterStatus.networkAlert((float)celcius);
    if (returnCode != NETWORKALERTSUCCESS) {
        alertFailureCount += 1;
    }
}

void testconvertFarenheitToCelcius(float farenheit, int expectedCelcius)
{
    assert(convertFarenheitToCelcius(farenheit) == expectedCelcius);
}

void testAlertFailure(float farenheit, int expectedFailureCount)
{
    networkAlerterStub testAlertInCelcius;
    alertInCelcius(farenheit,testAlertInCelcius);
    assert(alertFailureCount == expectedFailureCount);
}

int main() {
    
    testconvertFarenheitToCelcius(400.5,204);
    testAlertFailure(400.5,0);
    testconvertFarenheitToCelcius(303.6,150);
    testAlertFailure(303.6, 1);
    return 0;
}
