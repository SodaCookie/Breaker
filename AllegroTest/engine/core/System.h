#ifndef SYSTEM_H
#define SYSTEM_H

#include "Data.h"
#include "Component.h"
#include "Handle.h"
#include <tuple>
#include <memory>
#include <string>
#include <vector>

enum INITSTATUS{
	INITSUCCESS,
	INITFAILURE
};

enum SYSTEMSTATUS{
	SYSTEMERROR,
	SYSTEMNORMAL,
	SYSTEMEXIT
};

class System
{
	private:
		SystemType type;
		std::string error_msg = "";

	public:
		System(SystemType type);
		~System() = default;

		virtual INITSTATUS init() = 0;
		virtual void quit() = 0;
		virtual SYSTEMSTATUS update(std::vector<std::shared_ptr<Component>> components, double dtime) = 0;
		virtual std::shared_ptr<Component> create_component(Handle id, std::shared_ptr<void> data);
		
		virtual std::string error();

		std::shared_ptr<Component> get_component(Handle id);
		SystemType get_type();
		
	protected:
		void set_error_msg(const std::string& msg);

};

#endif