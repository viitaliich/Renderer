#pragma once

#include <GLCore.h>
#include <GLCoreUtils.h>


namespace GLCore::Render
{
	class Texture
	{
	private:
		unsigned int mRendererID;
		unsigned char* mLocalBuffer;
		std::string mFilePath;
		int mWidth;
		int mHeight;
		int mBPP;	// bits per pixel or number of channels in input image

	public:
		Texture(const std::string& filePath);
		~Texture();

		void Bind(unsigned int slot) const;
		void Unbind() const;

		inline int GetWidth() const { return mWidth; };
		inline int GetHeight() const { return mHeight; };
	};
}