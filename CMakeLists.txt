#  Copyright (C) 2021, Bayerische Motoren Werke Aktiengesellschaft (BMW AG),
#    Author: Alexander Domin (Alexander.Domin@bmw.de)
#  Copyright (C) 2021, ProFUSION Sistemas e Soluções LTDA,
#    Author: Leandro Ferlin (leandroferlin@profusion.mobi)
#    Author: Gabriel Fernandes Silva (g7fernandes@profusion.mobi)
#  SPDX-License-Identifier: MPL-2.0
#
#  This Source Code Form is subject to the terms of the
#  Mozilla Public License, v. 2.0. If a copy of the MPL was
#  not distributed with this file, You can obtain one at
#  http://mozilla.org/MPL/2.0/.
#

project(someip-server-playground)

cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x")

find_package(CommonAPI 3.2 REQUIRED)
find_package(CommonAPI-SomeIP 3.2 REQUIRED)
find_package (vsomeip3 3.1.0 REQUIRED)


include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/commonapi-wrappers/playground/include
    ${COMMONAPI_INCLUDE_DIRS}
    ${VSOMEIP3_INCLUDE_DIRS}
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(PlaygroundClient
    src/PlaygroundClient.cpp
)
target_link_libraries(
    PlaygroundClient
    CommonAPI
    CommonAPI-SomeIP
    vsomeip3
    ${CMAKE_CURRENT_SOURCE_DIR}/commonapi-wrappers/playground/lib/liborg.genivi.vehicle.playground.SomeIPCommon.so
    ${CMAKE_CURRENT_SOURCE_DIR}/commonapi-wrappers/playground/lib/liborg.genivi.vehicle.playground.SomeIPProxy.so
)

add_executable(PlaygroundService
    src/PlaygroundService.cpp
    src/PlaygroundStubImpl.cpp
)
target_link_libraries(
    PlaygroundService
    CommonAPI
    CommonAPI-SomeIP
    vsomeip3
    ${CMAKE_CURRENT_SOURCE_DIR}/commonapi-wrappers/playground/lib/liborg.genivi.vehicle.playground.SomeIPCommon.so
    ${CMAKE_CURRENT_SOURCE_DIR}/commonapi-wrappers/playground/lib/liborg.genivi.vehicle.playground.SomeIPStub.so
)
