#ifndef DEBUG_H
#define DEBUG_H

#include <iostream>

#include <string.h>
//The following code uses the __FILE__ macro to get the file name.
//It gets rid of the file path to reduce clutter in the log file.
//I got this code from a certain site that has to do with stacks.
#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)

namespace GAME {
	/// This enum is a simple 8-bit unsigned char
	enum class EMessageType : unsigned char {
		INFO = 0,
		WARNING,
		ERROR,
		FATAL_ERROR
	};

	class Debug {
	public:
		/// New in C11: this deletes the automatic constructor from being formed if no other constructor is decleared 
		Debug() = delete;

		/// Since I'm going C11 nutts - let's kill any default constructor or operator that the compiler might create
		Debug(const Debug&) = delete;
		Debug(Debug&&) = delete;
		Debug& operator=(const Debug&) = delete;
		Debug& operator=(Debug&&) = delete;

		// Init is called once for every time the program runs.
		// It's used to format the log file for each player session.
		static void Init();
		static void Log(const EMessageType MsgType, const std::string& message, const std::string& filename, const int line);
	};
}

#endif