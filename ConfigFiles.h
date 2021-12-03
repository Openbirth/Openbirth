#ifndef OPENBIRTH_CONFIGFILES_H
#define OPENBIRTH_CONFIGFILES_H
#include <iostream>
// No code is actually written here. Everything is in "ConfigFiles.cpp"

namespace Openbirth {
	namespace Config {
		class Configuration {
		public:
			std::string gamename;
			std::string gamever;
			int width;
			int height;

		};
		Configuration ParseConfig(std::string folder);
	}
}

#endif
