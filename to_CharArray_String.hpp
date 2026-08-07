#pragma once

	#include "CharArray.hpp"

	#if defined(pankey_Log) && (defined(to_CharArray_ByteArray_Log) || defined(pankey_Global_Log) || defined(pankey_Arduino_Log))
		#include "Logger_status.hpp"
		#define to_CharArray_ByteArrayLog(status,method,mns) pankey_Log(status,"to_CharArray_ByteArray",method,mns)
	#else
		#define to_CharArray_ByteArrayLog(status,method,mns)
	#endif

	namespace pankey{

		namespace Type{

			namespace Array{

				namespace Arduino{

					CharArray toCharArray(const String& a_str){
						to_CharArray_ByteArrayLog(pankey_Log_StartMethod, "toCharArray", "");
						to_CharArray_ByteArrayLog(pankey_Log_Statement, "toCharArray", "length:");
						to_CharArray_ByteArrayLog(pankey_Log_Statement, "toCharArray", a_str.length());
						CharArray i_array;
						for(int x = 0; x < a_str.length(); x++){
							to_CharArray_ByteArrayLog(pankey_Log_Statement, "toCharArray", "Iteration:");
							to_CharArray_ByteArrayLog(pankey_Log_Statement, "toCharArray", x);
							char f_chr = a_str.charAt(x);
							i_array.add(f_chr);
							to_CharArray_ByteArrayLog(pankey_Log_Statement, "toCharArray", "Adding");
							to_CharArray_ByteArrayLog(pankey_Log_Statement, "toCharArray", f_chr);
						}
						to_CharArray_ByteArrayLog(pankey_Log_EndMethod, "toCharArray", "");
						return i_array;
					}

					String toByteArray(const CharArray& a_array){
						String i_array;
						for(int x = 0; x < a_array.length(); x++){
							i_array += a_array.get(x);
						}
						return i_array;
					}
					
				}
				
			}
			
		}
			
	}