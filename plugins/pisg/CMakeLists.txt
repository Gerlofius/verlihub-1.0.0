SET(STATS_VERSION_MAJOR 1)
SET(STATS_VERSION_MINOR 2)
SET(STATS_VERSION_PATCH 0)
SET(STATS_VERSION "${STATS_VERSION_MAJOR}.${STATS_VERSION_MINOR}.${STATS_VERSION_PATCH}")

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})
ADD_DEFINITIONS(-DSTATS_VERSION="${STATS_VERSION}")

SET(STATS_HDRS
	cpipisg.h
)

SET(STATS_SRCS
	cpipisg.cpp
)

ADD_LIBRARY(libpisg_pi MODULE ${STATS_SRCS})
SET_TARGET_PROPERTIES(libpisg_pi PROPERTIES OUTPUT_NAME "pisg_pi")

INSTALL(TARGETS libpisg_pi LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
