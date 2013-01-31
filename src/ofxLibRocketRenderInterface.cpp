/*
 * This source file is part of libRocket, the HTML/CSS Interface Middleware
 *
 * For the latest information, see http://www.librocket.com
 *
 * Copyright (c) 2008-2010 CodePoint Ltd, Shift Technology Ltd
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 */

#include "ofxLibRocketRenderInterface.h"
#include <Rocket/Core.h>

#include "ofMain.h"

class MeshWrapper{
public:
	ofMesh* mesh;
	Rocket::Core::TextureHandle texture;
};

#define GL_CLAMP_TO_EDGE 0x812F

ofxLibRocketRenderInterface::ofxLibRocketRenderInterface()
{
}


ofxLibRocketRenderInterface::~ofxLibRocketRenderInterface()
{
}

// Called by Rocket when it wants to render geometry that it does not wish to optimise.
void ofxLibRocketRenderInterface::RenderGeometry(Rocket::Core::Vertex* vertices, int num_vertices, int* indices, int num_indices, const Rocket::Core::TextureHandle texture, const Rocket::Core::Vector2f& translation)
{
	ofPushMatrix();
	ofTranslate(translation.x, translation.y);

	bool normalizedTex = ofGetUsingNormalizedTexCoords();

	if(texture){
		if(!normalizedTex)
			ofEnableNormalizedTexCoords();
		((ofImage*)texture)->bind();
	}

	ofMesh mesh;

	for(int i=0; i<num_vertices; i++) {
		mesh.addVertex(ofVec3f(vertices[i].position.x, vertices[i].position.y, 0));
		mesh.addColor(ofFloatColor(vertices[i].colour.red/255.f, vertices[i].colour.green/255.f, vertices[i].colour.blue/255.f, vertices[i].colour.alpha/255.f));
		mesh.addTexCoord(ofVec2f(vertices[i].tex_coord.x, vertices[i].tex_coord.y));		
	}

	for(int i=0; i<num_indices; i++) {
		mesh.addIndex(indices[i]);
	}

	mesh.draw();
	
	if(!normalizedTex)
		ofDisableNormalizedTexCoords();
	
	ofPopMatrix();
}

// Called by Rocket when it wants to compile geometry it believes will be static for the forseeable future.
Rocket::Core::CompiledGeometryHandle ofxLibRocketRenderInterface::CompileGeometry(Rocket::Core::Vertex* vertices, int num_vertices, int* indices, int num_indices, const Rocket::Core::TextureHandle texture)
{
	MeshWrapper* wrapper = new MeshWrapper();
	
	wrapper->texture = texture;
	
	wrapper->mesh = new ofMesh();
	ofMesh* mesh = wrapper->mesh;

	for(int i=0; i<num_vertices; i++) {
		mesh->addVertex(ofVec3f(vertices[i].position.x, vertices[i].position.y, 0));
		mesh->addColor(ofFloatColor(vertices[i].colour.red/255.f, vertices[i].colour.green/255.f, vertices[i].colour.blue/255.f, vertices[i].colour.alpha/255.f));
		mesh->addTexCoord(ofVec2f(vertices[i].tex_coord.x, vertices[i].tex_coord.y));
	}

	for(int i=0; i<num_indices; i++) {
		mesh->addIndex(indices[i]);
	}

	return (Rocket::Core::CompiledGeometryHandle) wrapper;
}

// Called by Rocket when it wants to render application-compiled geometry.
void ofxLibRocketRenderInterface::RenderCompiledGeometry(Rocket::Core::CompiledGeometryHandle geometry, const Rocket::Core::Vector2f& translation)
{
	ofPushMatrix();
	ofTranslate(translation.x, translation.y);
	
	MeshWrapper* wrapper = (MeshWrapper*)geometry;	
	
	bool normalizedTex = ofGetUsingNormalizedTexCoords();
	
	if(wrapper->texture){
		ofEnableAlphaBlending();
		if(!normalizedTex)
			ofEnableNormalizedTexCoords();
		((ofImage*)wrapper->texture)->bind();
	}
	
	ofMesh* mesh = wrapper->mesh;
	mesh->draw();
	
	if(wrapper->texture){
		((ofImage*)wrapper->texture)->unbind();
		ofDisableAlphaBlending();
	}
	
	if(!normalizedTex)
		ofDisableNormalizedTexCoords();
	
	ofPopMatrix();
}

// Called by Rocket when it wants to release application-compiled geometry.
void ofxLibRocketRenderInterface::ReleaseCompiledGeometry(Rocket::Core::CompiledGeometryHandle geometry)
{
	delete ((MeshWrapper*)geometry)->mesh;
}

// Called by Rocket when it wants to enable or disable scissoring to clip content.
void ofxLibRocketRenderInterface::EnableScissorRegion(bool enable)
{
	if (enable)
		glEnable(GL_SCISSOR_TEST);
	else
		glDisable(GL_SCISSOR_TEST);
}

// Called by Rocket when it wants to change the scissor region.
void ofxLibRocketRenderInterface::SetScissorRegion(int x, int y, int width, int height)
{
	//ofViewport(x, ofGetHeight() - (y + height), width, height);
	glScissor(x, ofGetHeight() - (y + height), width, height);
}

// Called by Rocket when a texture is required by the library.
bool ofxLibRocketRenderInterface::LoadTexture(Rocket::Core::TextureHandle& texture_handle, Rocket::Core::Vector2i& texture_dimensions, const Rocket::Core::String& source)
{
	ofImage* img = new ofImage();
	img->loadImage(source.CString());
	texture_handle = (Rocket::Core::TextureHandle) img;
	return img->isAllocated();
}

// Called by Rocket when a texture is required to be built from an internally-generated sequence of pixels.
bool ofxLibRocketRenderInterface::GenerateTexture(Rocket::Core::TextureHandle& texture_handle, const Rocket::Core::byte* source, const Rocket::Core::Vector2i& source_dimensions)
{
	ofImage* img = new ofImage();
	img->setFromPixels(source, source_dimensions.x, source_dimensions.y, OF_IMAGE_COLOR_ALPHA, false);
	texture_handle = (Rocket::Core::TextureHandle) img;
	return img->isAllocated();
}

// Called by Rocket when a loaded texture is no longer required.
void ofxLibRocketRenderInterface::ReleaseTexture(Rocket::Core::TextureHandle texture_handle)
{
	delete (ofImage*)texture_handle;
}
