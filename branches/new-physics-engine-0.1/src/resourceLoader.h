#ifndef RESOURCE_LOADER_H
#define RESOURCE_LOADER_H

#include <stdio.h>
#include <stdarg.h>
#include <vector>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <allegro.h>
using namespace std;

#include "gameBase.h"
#include "StdString.h"

//! Resource loader class
//! Resolves resource filenames to absolute paths

class ResourceLoader : public GameBase {
	protected:
		vector<CString> paths;
		
	public:
		int Init(GameState*);
		void Shutdown();
		
		//! Set the search path
		void SetSearchPath(const char* path, ...);

		//! Append a new path to the search path
		void AppendToSearchPath(const char* path);

		//! Reset search paths
		void ResetPaths();

		//! This function either returns a full to a file path which 
		//! is guaranteed to exist, or returns "" if one can't be found
		//! in the current search path
		CString ResourceLoader::GetPathOf(const char* filename);

		//! Returns true if the file exists.
		bool FileExists(const char* file);

		//! Opens a bitmap file, or returns NULL on failure
		//! This function looks in the current search path
		//! it also outputs the palette in *pal
		BITMAP* OpenBitmap(const char* file, PALETTE* pal);

		//! Returns the current working directory
		CString GetCurrentWorkingDir();

		ResourceLoader();
		~ResourceLoader();
};

#endif // RESOURCE_LOADER_H