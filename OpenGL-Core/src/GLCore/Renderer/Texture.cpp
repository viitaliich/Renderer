#include "glpch.h"
#include "Texture.h"

#include "stb_image.h"


namespace GLCore::Render
{
	Texture::Texture(const std::string& filePath)
		: mRendererID(0), mFilePath(filePath), mLocalBuffer(nullptr),
		mWidth(0), mHeight(0), mBPP(0)
	{
		// TODO: Maybe move this code to Bind() function?
		stbi_set_flip_vertically_on_load(1);
		
		// if 0 instead 4 - will return the number of channels present in the image file.
		mLocalBuffer = stbi_load(filePath.c_str(), &mWidth, &mHeight, &mBPP, 4);

		glGenTextures(1, &mRendererID);
		glBindTexture(GL_TEXTURE_2D, mRendererID);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);	// x and...
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);	// y, but for textures

		// can pass 0 or null instead of local buffer (if data is not ready yet)
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, mWidth, mHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, mLocalBuffer);
		
		// Unbind
		glBindTexture(GL_TEXTURE_2D, 0);
		if (mLocalBuffer)
		{
			stbi_image_free(mLocalBuffer);
			mLocalBuffer = nullptr;
		}

	}
	Texture::~Texture()
	{
		/*if (mLocalBuffer)
		{
			stbi_image_free(mLocalBuffer);
			mLocalBuffer = nullptr;
		}*/
		glDeleteTextures(1, &mRendererID);

	}

	void Texture::Bind(unsigned int slot) const
	{
		glActiveTexture(GL_TEXTURE0 + slot);
		glBindTexture(GL_TEXTURE_2D, mRendererID);

	}
	void Texture::Unbind() const
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}
}