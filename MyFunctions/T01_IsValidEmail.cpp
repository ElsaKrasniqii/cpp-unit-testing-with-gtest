#include "T01_IsValidEmail.h"
#include <string>

using namespace std;

bool IsValidEmail(const string& email)
{
    int atPos = email.find('@');
    if (atPos <= 0) return false;               

    string rest = email.substr(atPos + 1);

    int dotPos = rest.find('.');
    if (dotPos == string::npos) return false;   

    string domain = rest.substr(rest.rfind('.') + 1);
    if (domain.length() < 2) return false;     

    return true;
}
