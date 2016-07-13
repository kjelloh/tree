# tree
A cross platform tree recursive directory listing program inspired by the Debian distribution tree command. Written in modern C++11 and Boost.

## output
```
C:\Users\kjell-olovhogdahl\Documents\GitHub\tree>tree
"C:\Users\kjell-olovhogdahl\Documents\GitHub\tree"
|---".git"
|   |---"COMMIT_EDITMSG"
|   |---"config"
|   |---"description"
|   |---"FETCH_HEAD"
|   |---"HEAD"
|   |---"hooks"
|   |   |---"applypatch-msg.sample"
|   |   |---"commit-msg.sample"
|   |   |---"post-update.sample"
|   |   |---"pre-applypatch.sample"
|   |   |---"pre-commit.sample"
|   |   |---"pre-push.sample"
|   |   |---"pre-rebase.sample"
|   |   |---"prepare-commit-msg.sample"
|   |   |---"update.sample"
|   |---"index"
|   |---"info"
|   |   |---"exclude"
|   |---"logs"
|   |   |---"HEAD"
|   |   |---"refs"
|   |   |   |---"heads"
|   |   |   |   |---"master"
|   |   |   |---"remotes"
|   |   |   |   |---"origin"
|   |   |   |   |   |---"HEAD"
|   |   |   |   |   |---"master"
|   |---"objects"
|   |   |---"0a"
|   |   |   |---"3d063dbeed8b615fb067aa1f996c5c537337da"
|   |   |---"0c"
|   |   |   |---"c7e4b527553e3b57cd57050a58d7a560675c69"
|   |   |---"2a"
|   |   |   |---"3f9e65708797c0b5a5d9665dee79fd9c3d1d49"
|   |   |---"34"
|   |   |   |---"761832a50b9f5813b2441d398f515bd2d73ce5"
|   |   |---"36"
|   |   |   |---"6a58a172f9dbdfc2ae3c93ea73abbdeb3cc2cc"
|   |   |---"51"
|   |   |   |---"1a4e2484903d0b75157717590981201cbdfff8"
|   |   |---"53"
|   |   |   |---"aee4a83e169349cb4e5620a52803fed1aa5e01"
|   |   |---"59"
|   |   |   |---"10fef4b4bc30193a7b6c9f44d30950bff71843"
|   |   |---"5a"
|   |   |   |---"572c7f17a4189d496e6e47f00487941dd27f4d"
|   |   |---"70"
|   |   |   |---"dcd1a58ad639df6d73497a2111ac4a4ed08f35"
|   |   |---"92"
|   |   |   |---"cc35afffa392022d65e730234bf6dcce46110c"
|   |   |---"98"
|   |   |   |---"d8eee1fd0e8f170082e3428cee979ea8da1edb"
|   |   |---"9c"
|   |   |   |---"ecc1d4669ee8af2ca727a5d8cde10cd8b2d7cc"
|   |   |---"ba"
|   |   |   |---"ec807bc4ef5c0d9aae1049d5ef3639e239e00b"
|   |   |---"cf"
|   |   |   |---"a1119d860567071a00d5e56ece011d312accea"
|   |   |---"f8"
|   |   |   |---"6ac204ec0ceea1510efb7d9b61266df6e6d87b"
|   |   |---"fd"
|   |   |   |---"150d8e4b7508638d51ced73ab1eb50a20845ac"
|   |   |---"info"
|   |   |---"pack"
|   |---"ORIG_HEAD"
|   |---"packed-refs"
|   |---"refs"
|   |   |---"heads"
|   |   |   |---"master"
|   |   |---"remotes"
|   |   |   |---"origin"
|   |   |   |   |---"HEAD"
|   |   |   |   |---"master"
|   |   |---"tags"
|---".gitignore"
|---"build"
|   |---".vs"
|   |   |---"tree"
|   |   |   |---"v14"
|   |   |   |   |---".suo"
|   |---"ALL_BUILD.vcxproj"
|   |---"ALL_BUILD.vcxproj.filters"
|   |---"CMakeCache.txt"
|   |---"CMakeFiles"
|   |   |---"3.5.1"
|   |   |   |---"CMakeCCompiler.cmake"
|   |   |   |---"CMakeCXXCompiler.cmake"
|   |   |   |---"CMakeDetermineCompilerABI_C.bin"
|   |   |   |---"CMakeDetermineCompilerABI_CXX.bin"
|   |   |   |---"CMakeRCCompiler.cmake"
|   |   |   |---"CMakeSystem.cmake"
|   |   |   |---"CompilerIdC"
|   |   |   |   |---"CMakeCCompilerId.c"
|   |   |   |   |---"CompilerIdC.exe"
|   |   |   |   |---"CompilerIdC.vcxproj"
|   |   |   |   |---"Debug"
|   |   |   |   |   |---"CMakeCCompilerId.obj"
|   |   |   |   |   |---"CompilerIdC.tlog"
|   |   |   |   |   |   |---"CL.command.1.tlog"
|   |   |   |   |   |   |---"CL.read.1.tlog"
|   |   |   |   |   |   |---"CL.write.1.tlog"
|   |   |   |   |   |   |---"CompilerIdC.lastbuildstate"
|   |   |   |   |   |   |---"link.command.1.tlog"
|   |   |   |   |   |   |---"link.read.1.tlog"
|   |   |   |   |   |   |---"link.write.1.tlog"
|   |   |   |---"CompilerIdCXX"
|   |   |   |   |---"CMakeCXXCompilerId.cpp"
|   |   |   |   |---"CompilerIdCXX.exe"
|   |   |   |   |---"CompilerIdCXX.vcxproj"
|   |   |   |   |---"Debug"
|   |   |   |   |   |---"CMakeCXXCompilerId.obj"
|   |   |   |   |   |---"CompilerIdCXX.tlog"
|   |   |   |   |   |   |---"CL.command.1.tlog"
|   |   |   |   |   |   |---"CL.read.1.tlog"
|   |   |   |   |   |   |---"CL.write.1.tlog"
|   |   |   |   |   |   |---"CompilerIdCXX.lastbuildstate"
|   |   |   |   |   |   |---"link.command.1.tlog"
|   |   |   |   |   |   |---"link.read.1.tlog"
|   |   |   |   |   |   |---"link.write.1.tlog"
|   |   |---"965b4db26a828816345ed1ea53bfe68c"
|   |   |   |---"generate.stamp.rule"
|   |   |---"cmake.check_cache"
|   |   |---"CMakeOutput.log"
|   |   |---"CMakeTmp"
|   |   |---"feature_tests.bin"
|   |   |---"feature_tests.cxx"
|   |   |---"generate.stamp.depend"
|   |   |---"generate.stamp.list"
|   |   |---"TargetDirectories.txt"
|   |---"CMakeLists.txt"
|   |---"cmake_install.cmake"
|   |---"Debug"
|   |---"main.cpp"
|   |---"tree.cbproj"
|   |---"tree.dir"
|   |   |---"Debug"
|   |   |   |---"tree.Build.CppClean.log"
|   |   |   |---"tree.log"
|   |   |   |---"tree.tlog"
|   |---"tree.sln"
|   |---"tree.VC.db"
|   |---"tree.vcxproj"
|   |---"tree.vcxproj.filters"
|   |---"treePCH1.h"
|   |---"Win32"
|   |   |---"Debug"
|   |   |   |---"ALL_BUILD"
|   |   |   |   |---"ALL_BUILD.tlog"
|   |   |   |   |---"ALL_BUILD.vcxprojResolveAssemblyReference.cache"
|   |   |   |---"ZERO_CHECK"
|   |   |   |   |---"ZERO_CHECK.Build.CppClean.log"
|   |   |   |   |---"ZERO_CHECK.log"
|   |   |   |   |---"ZERO_CHECK.tlog"
|   |---"ZERO_CHECK.vcxproj"
|   |---"ZERO_CHECK.vcxproj.filters"
|---"LICENSE"
|---"README.md"
|---"tree.exe"

C:\Users\kjell-olovhogdahl\Documents\GitHub\tree>
```
##build
###Use cmake in sub-folder build to generate the default tool-chain build files for your environment
```
C:\Users\kjell-olovhogdahl\Documents\GitHub\tree\build>cmake .
-- Building for: Visual Studio 14 2015
-- The C compiler identification is MSVC 19.0.24210.0
-- The CXX compiler identification is MSVC 19.0.24210.0
-- Check for working C compiler using: Visual Studio 14 2015
-- Check for working C compiler using: Visual Studio 14 2015 -- works
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working CXX compiler using: Visual Studio 14 2015
-- Check for working CXX compiler using: Visual Studio 14 2015 -- works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Boost version: 1.60.0
-- Found the following Boost libraries:
--   filesystem
--   system
-- Configuring done
-- Generating done
-- Build files have been written to: C:/Users/kjell-olovhogdahl/Documents/GitHub/tree/build

C:\Users\kjell-olovhogdahl\Documents\GitHub\tree\build>
```
###In this example - click the generated tree.sln to build in Visual Studio 2015

#Version 0.1 Notes
This is the initial version. 

    * No parameters supported.
    * Only tested on Windows 10.
    * Built and run ok using Visual Studio 2015
    * Built and run ok using Embarcadero RAD STudio Seattle (See provided project file)

##License
Feel free to join or fork this project under the general GNU open source license (See project license file)

