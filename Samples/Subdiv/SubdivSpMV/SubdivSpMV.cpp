#include "SubdivSpMV.h"

void SubdivSpMV::onLoad() {
	mpCamera = Camera::create();
	mpProgram = GraphicsProgram::createFromFile("", appendShaderExtension("SubdivSpMV.ps"));


	//create rasterizer state
	RasterizerState::Desc wireframeDesc;
}

void SubdivSpMV::onFrameRender() {

}
void SubdivSpMV::onShutdown() {

}
void SubdivSpMV::onResizeSwapChain() {

}
bool SubdivSpMV::onKeyEvent(const KeyboardEvent& keyEvent) {

}
bool SubdivSpMV::onMouseEvent(const MouseEvent& mouseEvent) {

}
void SubdivSpMV::onGuiRender() {

}




int main(int argc, char** argv)
{
	SubdivSpMV SubD;
	SampleConfig config;
	config.windowDesc.title = "My Model Viewer";
	config.windowDesc.resizableWindow = true;

	SubD.run(config);

	return;
}
