#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H

#include "stdafx.h"

#include "singleton.h"
#include "globals.h"

/* The primary things the Asset manager does are this:
 * 
 * 1) Resolve paths
 *    It resolves relative paths to absolute paths, and handles
 *    platform specific path weirdness (as we have on MacOSx)
 *
 * 2) Handle duplicate assets (bitmaps/sounds/etc) efficiently
 * 		Example: if something asks for "ring.bmp", we load it the first time,
 * 		         we store it in sprites["ring.bmp"]. The second time something 
 * 		         asks for "ring.bmp", we find the copy we already loaded, and
 * 		         use that.
 *
 * All deletion/creation of assets are handled HERE and only HERE.
 */

class Sprite;

typedef map<CString, Sprite*> SpriteList;
typedef map<CString, Sprite*>::iterator SpriteListIter;

typedef map<CString, SAMPLE*> SampleList;
typedef map<CString, SAMPLE*>::iterator SampleListIter;

class OGGFILE;

//! Manages game assets and memory
class AssetManager {

	DECLARE_SINGLETON_CLASS(AssetManager)

	protected:
		vector<CString> paths;
		SpriteList sprites;
		SampleList samples;
		OGGFILE* music;
		
	public:
		int Init();
		void Shutdown();

		void FreeSprites();
		void FreeSamples();
		void FreeMusic();
		void Free();

		//! Set the search path
		void SetSearchPath(const char* path, ...);

		//! Append a new path to the search path
		void AppendToSearchPath(const char* path);

		//! Reset search paths
		void ResetPaths();

		//! This function either returns a full to a file path which 
		//! is guaranteed to exist, or returns "" if one can't be found
		//! in the current search path
		CString GetPathOf(const char* filename) const;

		//! Returns true if the file exists.
		bool FileExists(const char* file) const;

		//! Opens a bitmap file, or returns NULL on failure
		//! This function looks in the current search path
		//! it also outputs the palette in *pal
		//! if use_alpha is true, this bitmap is loaded as a 32bit RGBA image
		Sprite* LoadSprite(	const char* filename, 
												bool use_alpha = false, 
												PALETTE* pal = NULL	); 

		//! Opens a sound file (e.g. WAV), or returns NULL on failure
		//! This function looks in the current search path
		SAMPLE* LoadSound(const char* filename);

		//! Opens an ogg file, or returns NULL on failure
		//! This function looks in the current search path
		OGGFILE* LoadMusic(const char* filename);

		inline OGGFILE* GetMusic() { return music; };

		//! Returns the current working directory
		CString GetMacOSXCurrentWorkingDir() const;

		virtual ~AssetManager();
};

#define ASSETMANAGER AssetManager::GetInstance()

#endif // ASSET_MANAGER_H
