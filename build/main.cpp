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

namespace detail {
	template <typename Tag>
	struct is_forward_iterator_tag : public std::false_type {};
	template <>
	struct is_forward_iterator_tag<std::forward_iterator_tag> : public std::true_type {};
}

using Fml_Iterator = Path::iterator;
using Fml_Functor = std::function<void (Fml_Iterator::value_type)>;
void for_first_middle_last(Fml_Iterator _first, Fml_Iterator _end,Fml_Functor first,Fml_Functor middle,Fml_Functor last) {
	// Always apply last to last element if at least one entry in the proved range.
	// Apply first and last if two elemnts in provded range.
	// Otherwise apply first to the first element, middle to intermediate elements and last to last element.
	static_assert(!detail::is_forward_iterator_tag<Fml_Iterator::iterator_category>::value,"for_first_middle_last must be called with Forward Iteratable range");
	switch (std::distance(_first, _end)) {
	case 0: break;
	case 1: {last(*_first); } break;
	case 2: {first(*_first); last(*(++_first)); } break;
	default: {
		auto iter_pair = std::make_pair(_first, ++Fml_Iterator(_first));
		first(*iter_pair.first);
		++iter_pair.first; ++iter_pair.second;
		while (iter_pair.second != _end) {
			middle(*iter_pair.first); // apply middle
			++iter_pair.first; ++iter_pair.second;
		}
		last(*iter_pair.first);
	} break;
	}
}

auto print_tree_entry = [](const Path& p) {
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
	Path root_path = filesystem::current_path();
	Paths v;
	recursive_dir(v,root_path,root_path);
	std::cout << root_path << "\n";
	std::for_each(std::begin(v),std::end(v),print_tree_entry);
	return 0;
}
