#include "T03_ContainsBadWords.h"
#include <algorithm>
#include <string>

using namespace std;

bool ContainsBadWords(const string& text, int N)
{
    if (text.empty())
        return false;

    string lower = text;
    transform(lower.begin(), lower.end(), lower.begin(),
        [](unsigned char c) { return tolower(c); });

    string bad1 = "idiot";
    string bad2 = "stupid";

    string bad3;
    int r = N % 3;
    if (r == 0) bad3 = "hate";
    else if (r == 1) bad3 = "noob";
    else bad3 = "trash";  

    if (lower.find(bad1) != string::npos) return true;
    if (lower.find(bad2) != string::npos) return true;
    if (lower.find(bad3) != string::npos) return true;

    return false;
}
