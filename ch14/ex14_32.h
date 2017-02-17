#include "ex14_16_18_26_27_28_StrBlob_StrBlobPtr.h"

class StrBlobPP {
public:
	StrBlobPP(StrBlobPtr *sb) : ptr(sb) {}
	StrBlobPtr& operator->() {
		return *ptr;
	}
private:
	StrBlobPtr *ptr;
};