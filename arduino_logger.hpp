
#ifndef arduino_logger_hpp
	#define arduino_logger_hpp

	#ifndef pankey_Log
	
    	#include <Arduino.h>

		namespace pankey{

			namespace Arduino{

				template<class T>
				void ArduinoLog(int a_status, const String& a_name, const String& a_method, T a_log){
					Serial.print("Status: ");
					Serial.print(a_status);
					Serial.print(" Class: ");
					Serial.print(a_name);
					Serial.print(" Method: ");
					Serial.print(a_method);
					Serial.print(" Log: ");
					Serial.println(a_log);
				}
			}
		}

		#define pankey_Log(status,name,method,log) pankey::Arduino::ArduinoLog(status,name,method,log)

		#include "Logger.hpp"

	#endif
 
#endif