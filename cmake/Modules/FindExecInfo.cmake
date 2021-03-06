# Module for finding ExecInfo library on BSD

IF(EXECINFO_LIBRARY)
	SET(EXECINFO_FOUND TRUE)
ELSE(EXECINFO_LIBRARY)
	FIND_PATH(EXECINFO_INCLUDE_DIR execinfo.h
		PATHS
			/usr/include
			/usr/local/include
			/usr/pkg/include
	)

	FIND_LIBRARY(EXECINFO_LIBRARY NAMES execinfo
		PATHS
			/usr/lib
			/usr/local/lib
			/usr/pkg/lib
	)

	IF(EXECINFO_INCLUDE_DIR AND EXECINFO_LIBRARY)
		SET(EXECINFO_FOUND TRUE)
		INCLUDE(FindPackageHandleStandardArgs)
		FIND_PACKAGE_HANDLE_STANDARD_ARGS(EXECINFO DEFAULT_MSG EXECINFO_LIBRARY EXECINFO_INCLUDE_DIR)
		MARK_AS_ADVANCED(EXECINFO_LIBRARY EXECINFO_INCLUDE_DIR)
	ELSE(EXECINFO_INCLUDE_DIR AND EXECINFO_LIBRARY)
		SET(EXECINFO_FOUND FALSE)
	ENDIF(EXECINFO_INCLUDE_DIR AND EXECINFO_LIBRARY)
ENDIF(EXECINFO_LIBRARY)