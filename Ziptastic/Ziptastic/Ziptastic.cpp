#include <iostream>
#include <string>
#include <http_client.h>
#include <filestream.h>
#include <iostream>
#include <sstream>

using namespace std;
using namespace web::http;
using namespace web::http::client;

//base class
class Ziptastic
{
	private:
		string apiKey;
		string ziptasticUrl;
	public:
		Ziptastic(string key); // Constructor
		void forwardGeo(string countryCode, string postalCode);
		void reverseGeo(string latitude, string longitude);
		void makeRequest(string url);
		void getApiKey();
};

//member functions
Ziptastic::Ziptastic(string key)
{
	apiKey = key;
	ziptasticUrl = "https://zip.getziptastic.com/v3/";
}

void Ziptastic::forwardGeo(string countryCode, string postalCode)
{
	string url = ziptasticUrl + "/" + countryCode + "/" + postalCode;
	cout << "\nForward Geocoding URL : " + url;

}

void Ziptastic::reverseGeo(string latitude, string longitude)
{
	string url = ziptasticUrl + "/reverse/" + latitude + "/" + longitude + "/1000";
	cout << "\nReverse Geocoding URL : " + url;
}

void Ziptastic::makeRequest(string url)
{
	http_client client(L url);

	// Manually build up an HTTP request with header and request URI.
	http_request request(methods::GET);
	request.headers().add(L"x-key", L"MyApiKey");
	return client.request(request).then([](http_response response)
	{
		// Print the status code.
		std::wostringstream ss;
		ss << L"Server returned returned status code " << response.status_code() << L"." << std::endl;
		std::wcout << ss.str();
	});

	/* Sample output:
	Server returned returned status code 200.
	*/
}

void Ziptastic::getApiKey()
{
	cout << "\nAPI KEY : " << apiKey;
}

int main()
{
	Ziptastic ziptastic("asdasdasdasdasd");
	ziptastic.getApiKey();
	ziptastic.forwardGeo("US", "42701");

}