#pragma once

	#include "CharPointer.hpp"
	#include "Mac.hpp"
	#include "CharArrayPrimitive.hpp"

	#if defined(pankey_Log) && (defined(to_CharPointer_String_Log) || defined(pankey_Global_Log) || defined(pankey_Arduino_Log))
		#include "Logger_status.hpp"
		#define to_CharPointer_StringLog(status,method,mns) pankey_Log(status,"to_CharPointer_String",method,mns)
	#else
		#define to_CharPointer_StringLog(status,method,mns)
	#endif

	namespace pankey{

		namespace Type{

			namespace Array{

				namespace Arduino{

					CharPointer toCharPointer(const String& a_array){
						to_CharPointer_StringLog(pankey_Log_StartMethod, "toCharPointer", "");
						if(a_array == ""){
							to_CharPointer_StringLog(pankey_Log_EndMethod, "toCharPointer", "a_array.isEmpty()");
							return CharPointer();
						}
						to_CharPointer_StringLog(pankey_Log_Statement, "toCharPointer", "length:");
						to_CharPointer_StringLog(pankey_Log_Statement, "toCharPointer", a_array.length());
						CharPointer i_array;
						i_array.create(a_array.length());
						for(int x = 0; x < a_array.length(); x++){
							to_CharPointer_StringLog(pankey_Log_Statement, "toCharPointer", "Iteration:");
							to_CharPointer_StringLog(pankey_Log_Statement, "toCharPointer", x);
							char f_chr = a_array.charAt(x);
							i_array.set(x, f_chr);
							to_CharPointer_StringLog(pankey_Log_Statement, "toCharPointer", "Adding");
							to_CharPointer_StringLog(pankey_Log_Statement, "toCharPointer", f_chr);
						}
						to_CharPointer_StringLog(pankey_Log_EndMethod, "toCharPointer", "");
						return i_array;
					}

					String toString(const CharPointer& a_array){
						to_CharPointer_StringLog(pankey_Log_StartMethod, "toCharPointer", "const CharArray&");
						String i_array;
						for(int x = 0; x < a_array.length(); x++){
							i_array += a_array.get(x);
						}
						to_CharPointer_StringLog(pankey_Log_EndMethod, "toCharPointer", "");
						return i_array;
					}
					
				}
				
			}
			
		}
			
	}