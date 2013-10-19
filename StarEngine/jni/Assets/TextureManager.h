#pragma once

#include <map>
// [COMMENT] if you fix the comment on line 38, don't forget
// to delete this include as well then.
#include <vector>
#include "../defines.h"
#include <memory>

#ifdef DESKTOP
#include <glew.h>
#else
#include "GLES/gl.h"
#endif

namespace star
{
	class Texture2D;

	class TextureManager
	{
	public:
		~TextureManager(void);

		static std::shared_ptr<TextureManager> GetInstance();

		bool LoadTexture(const tstring& path, const tstring& name);
		bool DeleteTexture(const tstring& name);
		GLuint GetTextureID(const tstring& name);
		ivec2 GetTextureDimensions(const tstring& name);
		void EraseAllTextures();

	private:
		//Data Members
		static std::shared_ptr<TextureManager> mTextureManager;
		std::map<tstring, std::shared_ptr<Texture2D> > mTextureMap;
		std::map<tstring,tstring> mPathList;

		TextureManager(void);

		TextureManager(const TextureManager& yRef);
		TextureManager(TextureManager&& yRef);
		TextureManager& operator=(const TextureManager& yRef);
	};
}
