#ifndef OPENBIRTH_CHARDEV_H
#define OPENBIRTH_CHARDEV_H
#include <iostream>

namespace Openbirth {
	namespace Characters {
		class Character {
		public:
			std::string charName; // NAME OF THE CHARACTER
			int basehealth; // BASE HEALTH OF THE CHARACTER
			int basedmg; // BASE DAMAGE POINTS OF THE CHARACTER
			int tearrate; //
		};
		class CharacterBuffer {
		public:
			Character characters[256];
			void AddToBuffer(Character toadd); // Adds a character to the buffer.
		};
		void CharacterBuffer::AddToBuffer(Character toadd) {
			int i = 0;

			Character emptyChar = { "", NULL, NULL, NULL };
			bool searching = true;
			while (searching) {
				if(characters[i].charName != emptyChar.charName && characters[i].basehealth != emptyChar.basehealth && characters[i].basedmg != emptyChar.basedmg && characters[i].tearrate != emptyChar.tearrate)
				i++;
			}

			characters[i] = toadd;
		}
	}
}


#endif