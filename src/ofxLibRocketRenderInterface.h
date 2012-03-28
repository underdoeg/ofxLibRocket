#ifndef OFXLIBROCKETRENDERINTERFACE_H
#define OFXLIBROCKETRENDERINTERFACE_H

#include "Rocket/Core/RenderInterface.h"
#include "Rocket/Core/Texture.h"
#include "Rocket/Core/Vertex.h"

class ofxLibRocketRenderInterface: public Rocket::Core::RenderInterface {

public:
	ofxLibRocketRenderInterface();
	~ofxLibRocketRenderInterface();
	Rocket::Core::CompiledGeometryHandle CompileGeometry(Rocket::Core::Vertex* vertices, int num_vertices, int* indices, int num_indices, Rocket::Core::TextureHandle texture);
	void EnableScissorRegion(bool enable);
	bool GenerateTexture(Rocket::Core::TextureHandle& texture_handle, const Rocket::Core::byte* source, const Rocket::Core::Vector2i& source_dimensions);
	bool LoadTexture(Rocket::Core::TextureHandle& texture_handle, Rocket::Core::Vector2i& texture_dimensions, const Rocket::Core::String& source);
	void ReleaseCompiledGeometry(Rocket::Core::CompiledGeometryHandle geometry);
	void ReleaseTexture(Rocket::Core::TextureHandle texture);
	void RenderCompiledGeometry(Rocket::Core::CompiledGeometryHandle geometry, const Rocket::Core::Vector2f& translation);
	void RenderGeometry(Rocket::Core::Vertex* vertices, int num_vertices, int* indices, int num_indices, Rocket::Core::TextureHandle texture, const Rocket::Core::Vector2f& translation);
	void SetScissorRegion(int x, int y, int width, int height);


};

#endif // OFXLIBROCKETRENDERINTERFACE_H
