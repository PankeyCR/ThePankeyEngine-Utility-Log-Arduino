
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

				bool g_arduino_method_logger_enable = true;
	
				#ifndef pankey_Log_enable
					#define pankey_Log_enable(status,name,method,mns) g_arduino_method_logger_enable
				#endif
				
					
				template<class L>
				void ArduinoLogging(int status, const String& name, const String& method, L mns){
					if(!pankey_Log_enable(status,name,method,mns)){
						return;
					}
					ArduinoLog<L>(status, name, method, mns);
				}
	
				void ArduinoLoggingStartPrint_(){
					g_arduino_method_logger_enable = true;
				}
			
				void ArduinoLoggingStopPrint_(){
					g_arduino_method_logger_enable = false;
				}
			}
		}

		#ifndef pankey_Log_set
			#define pankey_Log_set(S) 
		#endif 
	
		#ifndef pankey_Log_Split
			#define pankey_Log_Split(tittle) Serial.println("------------------Split----------------------");
		#endif
		
		#ifndef pankey_Log_Start
			#define pankey_Log_Start pankey::Arduino::ArduinoLoggingStartPrint_
		#endif
		
		#ifndef pankey_Log_Stop
			#define pankey_Log_Stop pankey::Arduino::ArduinoLoggingStopPrint_
		#endif 
	
		#ifndef pankey_Log
			#define pankey_Log(status,name,method,mns) pankey::Arduino::ArduinoLogging(status,name,method,mns)
		#endif 

		#ifndef pankey_Trigger_Log
			#define pankey_Trigger_Log(trigger,status,name,method,mns) if(trigger){pankey_Log(status,name,method,mns);}
		#endif
	
		#ifndef pankey_Logger
			#define pankey_Logger(status,name,method,mns) pankey::Arduino::ArduinoLogging(status,name,method,mns)
		#endif

		#ifndef pankey_Trigger_Logger
			#define pankey_Trigger_Logger(trigger,status,name,method,mns) if(trigger){pankey_Logger(status,name,method,mns);}
		#endif

	#endif
 
#endif