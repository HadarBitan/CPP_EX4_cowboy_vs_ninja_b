#pragma once

#include <vector>
#include "Cowboy.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"

namespace ariel
{
	class Team
	{
		private:
			Character *leader;
			std::vector<Character *> teamMembers;

		protected:
			Character *closestMember();
			Character *chooseVictom(Team *enemy);

		public:
			Team(Character *leader);

			Team(const Team &other);

			Team(Team &&other) noexcept;

			Team &operator=(const Team &other);

			Team &operator=(Team &&other) noexcept;

			virtual ~Team();

			Character *getLeader() const {
				return leader;
			}

			void setLeader(Character *newLeader) {
				leader = newLeader;
			}

			const std::vector<Character *> &getTeamMembers() const {
				return teamMembers;
			}

			void add(Character *teamMember);

			int stillAlive();

			virtual void attack(Team *enemy);

			virtual void print() const;
	};
}