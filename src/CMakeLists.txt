set(PROJECT_NAME CmdTool)

set(cmd_tool_VERSION_MAJOR 1)
set(cmd_tool_VERSION_MINOR 0)
set(cmd_tool_VERSION_PATCH 0)
set(EXE_VERSION ${cmd_tool_VERSION_MAJOR}.${cmd_tool_VERSION_MINOR}.${cmd_tool_VERSION_PATCH})

configure_file( ${CMAKE_CURRENT_SOURCE_DIR}/version.h.in
	            ${CMAKE_CURRENT_SOURCE_DIR}/version.h
)



include_directories(
	.
)

set(HEADERS version.h)

set(SOURCES
	main.cpp
)

if(MSVC)
	set(SOURCES ${SOURCES}
	)
else()
	set(SOURCES ${SOURCES}
	)
endif()

if(Linux_ARM)
	link_directories(
		${CMAKE_SYSROOT}/lib
		${CMAKE_SYSROOT}/usr/lib
		${CMAKE_SYSROOT}/usr/local/lib
		${CMAKE_SYSROOT}/usr/lib/arm-linux-gnueabihf
	)
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(${PROJECT_NAME}
	${HEADERS}
	${SOURCES}
)

if(UNIX)
	target_link_libraries(${PROJECT_NAME} PRIVATE
		    pthread
	)
endif()


