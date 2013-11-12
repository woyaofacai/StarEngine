#pragma once

#ifdef ANDROID

#include "../defines.h"
#include "SerializedData.h"

namespace star_a
{
	void ReadFileAsset(const tstring & path, star::SerializedData & data);
	void WriteFileAsset(const tstring & path, const star::SerializedData & data);
}

#endif
