#include <iostream>
#include <string>

using namespace std;

//base class
class Ziptastic
{
    private:
        string apiKey;
    public:
        Ziptastic(string key); // Constructor
        void forwardGeo(string zip);
        void reverseGeo(string latitude, string longitude);
        void makeRequest(string url);
        void getApiKey();
};

//member functions
Ziptastic::Ziptastic(string key)
{
    apiKey = key;
}

void Ziptastic::forwardGeo(string zip)
{
    
}

void Ziptastic::reverseGeo(string latitude, string longitude)
{

}

void Ziptastic::makeRequest(string url)
{

}

void Ziptastic::getApiKey()
{
    cout << "API KEY : " << apiKey;
}

int main()
{
    Ziptastic ziptastic("asdasdasdasdasd");
    ziptastic.getApiKey();
}