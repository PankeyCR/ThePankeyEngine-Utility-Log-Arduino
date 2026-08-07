
#ifndef PS_Ram_MemoryAllocator_hpp
	#define PS_Ram_MemoryAllocator_hpp

	#include "MemoryAllocator.hpp"

	namespace pankey{

		namespace Arduino{

			class PS_Ram_MemoryAllocator : public Base::MemoryAllocator{
				public:
					PS_Ram_MemoryAllocator(){
						if(!m_ps_init){
							psramInit();
							m_ps_init = true;
						}
					}
					PS_Ram_MemoryAllocator(bool a_managed){
						if(!m_ps_init){
							psramInit();
							m_ps_init = true;
						}
						this->m_managed = a_managed;
					}
					virtual ~PS_Ram_MemoryAllocator(){}

					virtual void* create(Base::memory_size a_type_size){return ps_malloc(a_type_size);}
					virtual void* create(){return nullptr;}

					virtual void* createArray(Base::memory_size a_type_size, Base::memory_size a_count){return ps_malloc(a_type_size * a_count);}
					virtual void* createArray(Base::memory_size a_count){return nullptr;}

					virtual void destroy(Base::memory_size a_type_size, void* a_destroy){free(a_destroy);}
					virtual void destroy(void* a_destroy){free(a_destroy);}

					virtual void destroyArray(Base::memory_size a_type_size, Base::memory_size a_count, void* a_destroy){free(a_destroy);}
					virtual void destroyArray(void* a_destroy){free(a_destroy);}

					virtual void isManaged(bool a_managed){
						this->m_managed = a_managed;
					}

					virtual bool isManaged(){
						return this->m_managed;
					}

					virtual PS_Ram_MemoryAllocator* clone()const{
						return new PS_Ram_MemoryAllocator();
					}

				protected:
					bool m_managed = false;

					static bool m_ps_init;
			};

			bool PS_Ram_MemoryAllocator::m_ps_init = false;

		}

	}

#endif