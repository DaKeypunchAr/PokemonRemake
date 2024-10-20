#pragma once

struct VB_Handle;

namespace Graphics {

    class VertexBuffer {
    public:
		VertexBuffer() = default;
    	VertexBuffer(const VertexBuffer& rhs) = delete;
		VertexBuffer(VertexBuffer&& rhs) = delete;
		VertexBuffer& operator=(const VertexBuffer& rhs) = delete;
    	VertexBuffer& operator=(VertexBuffer&& rhs) = delete;

    	static VB_Handle Create();
    	static void FillData(VB_Handle vb, void* data, unsigned long size);

    	virtual ~VertexBuffer() = default;
    	virtual void fillData(void* data, unsigned long size) = 0;
    	virtual void getAPI_ID(void* apiId) const = 0;
    };
}
