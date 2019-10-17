cmake_minimum_required(VERSION 3.13)
project(Geo_R)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall -Wno-unused-but-set-variable")

include_directories(yourcode)

add_executable(main
        yourcode/RTree.h
        yourcode/submit-1AddPolygonBeforeQueryPoint.cpp
        yourcode/submit-1AddPolygonBeforeQueryPoint.h
        yourcode/submit-2AddPointBeforeQueryPolygon.cpp
        yourcode/submit-2AddPointBeforeQueryPolygon.h
        yourcode/submit-3AddBeforeQuery.cpp
        yourcode/submit-3AddBeforeQuery.h
        yourcode/submit-4MixQueryPoint.cpp
        yourcode/submit-4MixQueryPoint.h
        yourcode/submit-5MixQueryPolygon.cpp
        yourcode/submit-5MixQueryPolygon.h
        yourcode/submit-6MixQuery.cpp
        yourcode/submit-6MixQuery.h
        main.cpp yourcode/global.h yourcode/global.cpp)
