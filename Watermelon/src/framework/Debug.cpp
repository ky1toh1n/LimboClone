#include "Debug.h"
#include <string>
#include <fstream>
using namespace GAME;


void Debug::Init() {
	std::ofstream out;
	out.open("log.txt", std::ios::app | std::ios::out);
	out << std::endl;
	out.close();
}

void Debug::Log(const EMessageType MsgType, const std::string& message, const std::string& filename, const int line) {
	std::ofstream out;
	out.open("log.txt",std::ios::app|std::ios::out);

	switch (MsgType) {
		case EMessageType::INFO:
			out << "INFO: "  << message << " (" << filename << ":" << line << ")"<< std::endl;
			break;
		case EMessageType::WARNING:
			out << "WARNING: "  << message << " (" << filename << ":" << line << ")" << std::endl;
			break;
		case EMessageType::ERROR:
			out << "ERROR: "  << " (" << message << filename << ":" << line << ")"<< std::endl;
			break;
		case EMessageType::FATAL_ERROR:
			out << "FATAL_ERROR: "  << " (" <<  message << filename << ":" << line << ")"<< std::endl;
			break;
	}	
	out.close();


}