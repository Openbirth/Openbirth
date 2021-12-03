#ifndef OPENBIRTH_PROJECTILES_H
#define OPENBIRTH_PROJECTILES_H

#include <raylib.h>
#include "Coordination.h"

namespace Openbirth {
	namespace Yeetables {
		typedef enum {
			TEAR, /* Normal tear */
			BLOODTEAR, /* Blood tear*/
			BOMB, /* Bomb */
			BOOB, /* Very mature projectile */
			VOIDTEAR
		} ProjectileType;
		class Projectile {
		public:
			Vector2 projectilePosition;
			ProjectileType type;
			int speed;
		};
		Vector2 CalculateTrajectory(Openbirth::Coordination::Direction dir, Projectile proj) {
			Vector2 final = proj.projectilePosition;
			
			switch (dir) {
			case Openbirth::Coordination::Direction::LEFT:
				final.x -= proj.speed;
				break;
			case Openbirth::Coordination::Direction::RIGHT:
				final.x += proj.speed;
				break;
			case Openbirth::Coordination::Direction::UP:
				final.y -= proj.speed;
				break;
			case Openbirth::Coordination::Direction::DOWN:
				final.y += proj.speed;
				break;
			}

			return final;
		}
	}
}


#endif
