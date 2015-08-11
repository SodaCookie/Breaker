#ifndef SYSTEM_H
#define SYSTEM_H

#include "Data.h"
#include "Component.h"
#include "Handle.h"
#include <tuple>
#include <memory>
#include <string>
#include <vector>

typedef bool INITSTATUS; // figure out if best option
#define INITSUCCESS true
#define INITFAILURE false

typedef int SYSTEMSTATUS;
#define SYSTEMERROR -1
#define SYSTEMNORMAL 0
#define SYSTEMEXIT 1

class System
{
	private:
		SystemType type;
		std::string error_msg = "";

	public:
		System(SystemType type);
		~System() = default;

		virtual bool init() = 0;
		virtual void quit() = 0;
		virtual int update(std::vector<std::shared_ptr<Component>> components, double dtime) = 0;
		virtual std::shared_ptr<Component> create_component(Handle id, std::shared_ptr<void> data);
		
		virtual std::string error();

		std::shared_ptr<Component> get_component(Handle id);
		SystemType get_type();
		
	protected:
		void set_error_msg(std::string msg);

};

#endif