#pragma once

#include "ZResource.h"
#include "tinyxml2.h"

#include <vector>

enum TextureType
{
	RGBA32bpp,
	RGBA16bpp,
	Palette4bpp,
	Palette8bpp,
	Grayscale4bpp,
	Grayscale8bpp,
	GrayscaleAlpha4bpp,
	GrayscaleAlpha8bpp,
	GrayscaleAlpha16bpp,
	Error
};

class ZTexture : public ZResource
{
protected:
	TextureType type;
	int width, height;

	uint8_t* bmpRgb;
	uint8_t* bmpRgba;

	void ParseXML(tinyxml2::XMLElement* reader);
	void FixRawData();
	void PrepareBitmap();
	void PrepareBitmapRGBA16();
	void PrepareBitmapRGBA32();
	void PrepareBitmapGrayscale8();
	void PrepareBitmapGrayscaleAlpha8();
	void PrepareBitmapGrayscale4();
	void PrepareBitmapGrayscaleAlpha4();
	void PrepareBitmapGrayscaleAlpha16();
	void PrepareBitmapPalette4();
	void PrepareBitmapPalette8();
	void PrepareRawData(std::string inFolder);
	void PrepareRawDataRGBA16(std::string rgbaPath);
	void PrepareRawDataRGBA32(std::string rgbaPath);
	void PrepareRawDataGrayscale4(std::string grayPath);
	void PrepareRawDataGrayscale8(std::string grayPath);
	void PrepareRawDataGrayscaleAlpha4(std::string grayAlphaPath);
	void PrepareRawDataGrayscaleAlpha8(std::string grayAlphaPath);
	void PrepareRawDataGrayscaleAlpha16(std::string grayAlphaPath);
	void PrepareRawDataPalette4(std::string palPath);
	void PrepareRawDataPalette8(std::string palPath);
	float GetPixelMultiplyer();

public:
	ZTexture();
	ZTexture(tinyxml2::XMLElement* reader, std::vector<uint8_t> nRawData, int rawDataIndex, std::string nRelPath);
	ZTexture(tinyxml2::XMLElement* reader, std::string inFolder);
	ZTexture(TextureType nType, std::vector<uint8_t> rawData, std::string nName, int nWidth, int nHeight);
	ZTexture(TextureType nType, std::vector<uint8_t> nRawData, int rawDataIndex, std::string nName, int nWidth, int nHeight);

	static ZTexture* FromPNG(std::string pngFilePath, TextureType texType);
	static TextureType GetTextureTypeFromString(std::string str);

	std::string GetSourceOutputHeader(std::string prefix);
	std::string GetSourceOutputCode(std::string prefix);

	std::vector<uint8_t> GetRawData();
	int GetRawDataSize();
	//SourceType GetSourceType();
	void Save(std::string outFolder);
};