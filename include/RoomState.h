/*
 * nheko Copyright (C) 2017  Konstantinos Sideris <siderisk@auth.gr>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef ROOM_STATE_H
#define ROOM_STATE_H

#include <QPixmap>

#include "AliasesEventContent.h"
#include "AvatarEventContent.h"
#include "CanonicalAliasEventContent.h"
#include "CreateEventContent.h"
#include "HistoryVisibilityEventContent.h"
#include "JoinRulesEventContent.h"
#include "NameEventContent.h"
#include "PowerLevelsEventContent.h"
#include "TopicEventContent.h"

#include "Event.h"
#include "RoomEvent.h"
#include "StateEvent.h"

namespace events = matrix::events;

class RoomState
{
public:
	QString resolveName() const;
	inline QString resolveTopic() const;

	QPixmap avatar_img_;

	events::StateEvent<events::AliasesEventContent> aliases;
	events::StateEvent<events::AvatarEventContent> avatar;
	events::StateEvent<events::CanonicalAliasEventContent> canonical_alias;
	events::StateEvent<events::CreateEventContent> create;
	events::StateEvent<events::HistoryVisibilityEventContent> history_visibility;
	events::StateEvent<events::JoinRulesEventContent> join_rules;
	events::StateEvent<events::NameEventContent> name;
	events::StateEvent<events::PowerLevelsEventContent> power_levels;
	events::StateEvent<events::TopicEventContent> topic;
};

inline QString RoomState::resolveTopic() const
{
	return topic.content().topic().simplified();
}

#endif  // ROOM_STATE_H
