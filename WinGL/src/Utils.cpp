#include "Utils.h"

bool ErrorMsg(LPCWSTR message)
{
	MessageBox(NULL, message, NULL, NULL);
	return false;
}
