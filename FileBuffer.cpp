#include<cstdio>
#include<cwchar>
#include<cwctype>
#include"settings.h"

#define WNULL (wchar_t) '\0'

size_t wstrlen(wchar_t *s) {
	size_t len=0;
	while(s[len] != WNULL)
		len++;
	return len;
}

bool wstrcmp(wchar_t *a, wchar_t *b) {
	do{
		if(*a != *(b++))
			return false;
	}while(*(a++) != WNULL);
	return true;
}

bool wstrncmp(wchar_t *a. wchar_t *b, size_t n) {
	size_t i=0;
	do{
		if(a[i] != b[i])
			return false;
	}while(a[i] != WNULL && i++ < n);
	return true;
}

wchar_t* wstrcpy(wchar_t* dest, wchar_t* src) {
	size_t len = wstrlen(src) + 1;
	for(size_t i=0; i<len; i++) {
		dest[i] = src[i];
	}

	return dest;
}

size_t* subWstrPos(wchar_t *haystack, wchar_t *needle) {
	size_t pos=0;
}


class StreamBuffer {
	bool initialized = false;
	FILE *stream;
	wchar_t array[BSIZ];

	public:

	bool isInitialized(void) {return this->initialized;}

	void initialize(void) {
		this->stream = stdin;
		fgetws(this->array, BSIZ, this->stream);
		this->initialized = true;
		return;
	}
	void initialize(FILE *fp) {
		this->stream = fp;
		fgetws(this->array, BSIZ, this->stream);
		this->initialized = true;
		return;
        }


}
