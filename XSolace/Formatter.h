#pragma once
#include "stdafx.h"

namespace xTools {

	class Formatter {

	public:
		static std::string Format(const char* format, ...);

		static std::wstring ToWide(const std::string& narrowString);
	};
}
