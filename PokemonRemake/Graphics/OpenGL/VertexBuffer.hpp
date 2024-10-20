#pragma once
#include "Graphics/VertexBuffer.hpp"

namespace OpenGL {

	class VertexBuffer : public Graphics::VertexBuffer {
	public:
		VertexBuffer();
		~VertexBuffer() override;

		void fillData(void* data, unsigned long size) override;
		void getAPI_ID(void* apiId) const override;

	private:
		unsigned int m_API_ID;
	};

}
