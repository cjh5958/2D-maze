#pragma once

#define ERROR_LIST -1


namespace Engine{

	enum Error {
		OK,	// (0)
		FAILED,	/// Generic fail error
		ERR_OUT_OF_MEMORY,	/// out of memory
		ERR_NO_SUCH_FILE,	/// can't find the file
		ERR_FILE_NO_PERMISSION,	/// do not have permission to open the file requested
		ERR_FILE_READ_FAILED,	/// failure occured when loading the file
		ERR_FILE_EOF,	
		ERR_TIMEOUT,	
		ERR_OUT_OF_RANGE,	
		ERR_CREATE_FAILED,	/// creation of a object is failed deu to some reasons
		ERR_DELETE_FAILED,	/// deletion of a object is failed deu to some reasons
		ERR_UNAVAILABLE,	/// operation is not available now
		ERR_NO_PERMISSION,	/// operation is not allowed
		ERR_UNCONFIGURED,	/// application did not config completely
		ERR_UNKNOWN,		/// unknown error
		ERR_COUNT,	// Not being returned, value represents the number of errors(except OK)
	};	//ERROR

	extern const char *error_strings[];

};	//namespace Engine

