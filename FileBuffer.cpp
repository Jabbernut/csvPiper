#include<cstdio>
#include<cwchar>
#include<cwctype>
#include"settings.h"

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

	size_t advance(size_t advLen) {
		size_t startPos=ftell(this->stream);

		if(BSIZ <= advLen) {
			fseek(this->stream, advLen-BSIZ, SEEK_CUR);
			fgetws(this->array, BSIZ, this->stream);
		} else {
			size_t i=0;
			do{
				this->array[i] = this->array[i + advLen];
			}while(this->array[i++]);
			wchar_t *temp = new wchar_t[advLen+1];
			fgetws(temp, advLen+1, this->stream);
			wcscat(this->array, temp);
			delete temp;
		}
		return ftell(this->stream) - startPos;
	}
}
