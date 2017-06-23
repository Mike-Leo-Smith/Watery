//
// Created by Mike Smith on 2017/4/17.
//

#ifndef WATERY_MESSAGE_H
#define WATERY_MESSAGE_H

#include <ctime>
#include <string>
#include <set>
#include "../Timer/timer.h"
#include "../../Framework/Clock/clock.h"
#include "../Configuration/default.h"

namespace watery
{
	class Message
	{
	private:
		std::string _type;
		Timer _timer;
		std::set<std::string> _signatures;
		
	public:
		Message(const std::string &type = "undefined", Microsecond time_out = MESSAGE_DEFAULT_TIMEOUT)
				: _type(type), _timer(time_out) { _timer.reset(); }
		virtual ~Message(void) {}
		virtual const std::string &type(void) const { return _type; }
		virtual bool time_out(void) const { return _timer.time_out(); }
		virtual void sign(const std::string &system) { _signatures.emplace(system); }
		virtual bool signed_by(const std::string &system) { return (_signatures.count(system) != 0); }
	};
}

#endif  // WATERY_MESSAGE_H
