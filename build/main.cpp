#ifdef __CODEGEARC__
#pragma hdrstop
#pragma argsused
#endif

#ifdef _WIN32
#include <tchar.h>
#else
typedef char _TCHAR;
#define _tmain main
#endif

// Suppress Visual Studio warnings about call to standard library with unchecked iterators (e.g., call to std::missmatch using boost path iterators)
#define _SCL_SECURE_NO_WARNINGS 

#include <vector>
#include <iostream>
#include <sstream>
#include <boost/filesystem.hpp>
#include <algorithm>

namespace filesystem = boost::filesystem; // Enable change of applied filesystem by later changing alias (e.g., to C++17 std::filesystem)
using Path = filesystem::path;
using Paths = std::vector<Path>;

namespace local { namespace detail {
	// until filesystem::relative in http://www.boost.org/doc/libs/1_61_0/libs/filesystem/doc/reference.html#op-relative
	using path = filesystem::path;
	path relative(const path& p, const path& base=filesystem::current_path()) {
		path result;
		auto iter_pair = std::mismatch(
			 std::begin(base),std::end(base)
			,std::begin(p));
		std::for_each(iter_pair.second,std::end(p),[&result](const path& p) {result /= p;});
// std::cout << "missmatch of " << p << " and " << base << " returns " << result << "\n";
		return result;
	}
}}

void recursive_dir(Paths& result, const Path& p,const Path& root_path) {
//	std::copy(filesystem::directory_iterator(p),filesystem::directory_iterator(),std::back_inserter(result));
	std::for_each(
		 filesystem::directory_iterator(p)
		,filesystem::directory_iterator()
		,[&result,root_path](const Path& sub_p){
			result.push_back(local::detail::relative(sub_p, root_path));
			if (filesystem::is_directory(sub_p)) {
				recursive_dir(result,sub_p,root_path);
			}
		});
}

using Fml_Iterator = Path::iterator;
using Fml_Functor = std::function<void (Fml_Iterator::value_type)>;
void for_first_middle_last(Fml_Iterator _first, Fml_Iterator _end,Fml_Functor first,Fml_Functor middle,Fml_Functor last) {
	// (1) [_first,_end[ = {}
	//                      iter_pair {_end,_end}
	//						apply none
	// (2) [_first,_end[ = {<1>}
	//                      iter_pair {<1>,end}
	//						apply last(<1>)
	// (3) [_first,_end] = {<1>,<2>}
	//                      iter_pair {<1>,<2>},{<2>,end}
	//						apply first(<1>),last(<2>)
	// (4) [_first,_end] = {<1>,<2>,...<n>}
	//                      iter_pair {<1>,<2>},{<2>,<3>}...{<n>,end}
	//						apply first(<1>),middle(<2>)...middle(<n-1>), last(<n>)

	auto iter_pair = std::make_pair(_first,_first);
	if (iter_pair.first == _end) {
		// (1) [_first,_end[ = {}
		//                      iter_pair {_end,_end}
		//						apply none
	}
	else {
		++iter_pair.second; // pair = first and second in range
		if (iter_pair.second == _end) {
			// (2) [_first,_end[ = {<1>}
			//                      iter_pair {<1>,end}
			//						apply last(<1>)
			last(*iter_pair.first);
		}
		else {
			Fml_Iterator second_next = iter_pair.second; ++second_next;
			if (second_next == _end) {
				// (3) [_first,_end[ = {<1>,<2>}
				//                      iter_pair {<1>,<2>},{<2>,end}
				//						apply first(<1>),last(<2>)
				first(*iter_pair.first);
				last(*iter_pair.second);
			}
			else {
				// (4) [_first,_end] = {<1>,<2>,...<n>}
				//                      iter_pair {<1>,<2>},{<2>,<3>}...{<n>,end}
				//						apply first(<1>),middle(<2>)...middle(<n-1>), last(<n>)
				first(*iter_pair.first);
				++iter_pair.first; ++iter_pair.second;
				while (iter_pair.second != _end) {
					middle(*iter_pair.first); // apply middle
					++iter_pair.first; ++iter_pair.second;
				}
				last(*iter_pair.first); // apply last
			}
		}
	}
}

auto print_tree_entry = [](Path p) {
// TEST
//std::cout << p << "\n";
	for_first_middle_last(std::begin(p),std::end(p)
	,[](Path::iterator::value_type s){std::cout << '|' << "   ";}
	,[](Path::iterator::value_type s){std::cout << '|' << "   ";}
	,[](Path::iterator::value_type s){std::cout << '|' << "---" << s;});
	std::cout << "\n";
};

 int _tmain(int argc, _TCHAR* argv[])
{

// TEST
// Path root_path = R"(C:\Users\kjell-olovhogdahl\Documents\cpp\MyNakedCMakeConsoleApp)";
// Path root_path = R"(C:\Users\kjell-olovhogdahl\Documents\Embarcadero\Studio\Projects\tree)"; // This project on my windows 10 development machine

	Path root_path = filesystem::current_path();
	Paths v;
	recursive_dir(v,root_path,root_path);
	std::cout << root_path << "\n";
	std::for_each(std::begin(v),std::end(v),print_tree_entry);
	return 0;
}
