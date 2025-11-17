#include "T05_IsStrongPassword.h"
#include <string>
#include <cctype>

using namespace std;

bool IsStrongPassword(const string& password, int N)
{
    int minLength = 6 + (N % 5);  

    if ((int)password.size() < minLength)
        return false;

    bool hasUpper = false;
    bool hasDigit = false;
    bool hasSpecial = false;

    string specials = "!@#$%";

    for (char c : password)
    {
        if (isupper((unsigned char)c)) hasUpper = true;
        if (isdigit((unsigned char)c)) hasDigit = true;
        if (specials.find(c) != string::npos) hasSpecial = true;
    }

    if (N % 2 == 1)
        return hasUpper && hasDigit && hasSpecial;

    return hasUpper && hasDigit;
}
