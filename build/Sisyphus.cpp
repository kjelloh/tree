//
// Created by kjell-olovhogdahl on 7/31/2016.
//

#include "Sisyphus.h"
#include <iterator>
#include <vector>
#include <type_traits>

namespace sisyphus {

    namespace detail {

		namespace detail {
			template <class Derived>
			struct no_scalar_throwing_new {
				void* operator()(std::size_t) noexcept {
					static_assert(false, "throwing new Derived not allowed");
				};
			};
			template <class Derived>
			struct no_scalar_nothrowing_new {
				void* operator()(std::size_t) noexcept {
					static_assert(false, "nothrowing new Derived not allowed");
				};
			};
			template <class Derived>
			struct no_scalar_placement_new {
				void* operator()(std::size_t) noexcept {
					static_assert(false, "placement new Derived not allowed");
				}
			};

			template <class Derived>
			struct no_array_throwing_new {
				void* operator()(std::size_t) noexcept {
					static_assert(false, "throwing new Derived[] not allowed");
				}
			};
			template <class Derived>
			struct no_array_nothrowing_new {
				void* operator()(std::size_t) noexcept {
					static_assert(false, "nothrowing new Derived[] not allowed");
				}
			};
			template <class Derived>
			struct no_array_placement_new {
				void* operator()(std::size_t) noexcept {
					static_assert(false, "placement new Derived[] not allowed");
				}
			};
		}

        // Inspired by https://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/Requiring_or_Prohibiting_Heap-based_Objects
		class NoHeap {
		protected:

			// NOTE: Will not prevent ::new to instatiate new instances of this class.

			// Will cause compiler warning (not accessible) if invoked
			// See http://en.cppreference.com/w/cpp/memory/new/operator_new
			
			// class-specific allocation functions
			static void* operator new  ( std::size_t count ); // (15)
			static void* operator new[]( std::size_t count ); // (16)
#if __cplusplus > 201402L														
			static void* T::operator new  ( std::size_t count, std::align_val_t al ); // (17)  (since C++17)
			static void* T::operator new[]( std::size_t count, std::align_val_t al ); // (18)  (since C++17)
#endif

			// class-specific placement allocation functions
			static void* operator new  ( std::size_t count, ... ); // (19)
			static void* operator new[]( std::size_t count, ... ); // (20)
#if __cplusplus > 201402L
			static void* T::operator new  ( std::size_t count,std::align_val_t al, ... ); // (21)  (since C++17)
			static void* T::operator new[]( std::size_t count,std::align_val_t al, ... ); // (22)  (since C++17)
#endif

			// stat_assert on invokation does not yet work (always instatiated in current form)
			// TODO: Consider SFIANE selection of instatiated new memebers (http://en.cppreference.com/w/cpp/language/sfinae)?
			//void* operator new (std::size_t size) { return detail::no_scalar_throwing_new<NoHeap>()(0); }
			//void* operator new (std::size_t size, ...) noexcept { return detail::no_scalar_placement_new<NoHeap>()(0); }
			//void* operator new[](std::size_t size) {return detail::no_array_throwing_new<NoHeap>()(0); }
			//void* operator new[](std::size_t size, ...) noexcept {return detail::no_array_placement_new<NoHeap>()(0); }
		};
    }

	class MyClass : public detail::NoHeap {};
	
    void make_the_unit_link() {
		unsigned char memory[128];
		MyClass class_on_stack_ok;

		//MyClass* pClassOnHeap1NotOk = new MyClass();
		//MyClass* pClassOnHeap3NotOk = new(memory) MyClass();

		//MyClass* pClassArrayOnHeap1NotOk = new MyClass[5]; // new[]
		//MyClass* pClassArrayOnHeap3NotOk = new(memory) MyClass[5]; // placement new[]
	}
}

