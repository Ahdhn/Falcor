#pragma once
#include "Falcor.h"
#include "SampleTest.h"
#include "Utils\Picking\Picking.h"

using namespace Falcor;

class ModelViewer : public Sample
{
public:
	void onLoad() override;
	void onFrameRender() override;
	void onShutdown() override;
	void onResizeSwapChain() override;
	bool onKeyEvent(const KeyboardEvent& keyEvent) override;
	bool onMouseEvent(const MouseEvent& mouseEvent) override;
	void onGuiRender() override;

private:
	//Model load and save
	void loadModel();
	void saveModel();
	void deleteCulledMeshes();
	void loadModelFromFile(const std::string& Filename);

	//Camera 
	void resetCamera();
	void renderModelUI();
	void setModelString(bool isAfterCull, float LoadTime);

	Model::SharedPtr mpModel = nullptr;
	ModelViewCameraController mModelViewCameraController;
	FirstPersonCameraController mFirstPersonCameraController;
	SixDoFCameraController m6DoFCameraController;

	//Filtering 
	bool mUseTriLinearFiltering = true;
	Sampler::SharedPtr mpPointerSamples = nullptr;
	Sampler::SharedPtr mpLinearSamples = nullptr;

	GraphicsProgram::SharedPtr mpProgram = nullptr;	
	GraphicsVars::SharedPtr mpProgramVars = nullptr;
	GraphicsState::SharedPtr mpGraphicsState = nullptr;

	enum 
	{
		ModelViewCamera,
		FirstPersonCamera,
		SixDoFCamera
	} mCameraType = ModelViewCamera;

	CameraController& getActiveCameraController();

	Camera::SharedPtr mpCamera;

	bool mDrawWireFrame = false;
	bool mAnimate = false;
	bool mGenerateTangentSpace = true;
	glm::vec3 mAmbientIntensity = glm::vec3(0.1f, 0.1f, 0.1f);

	uint32_t mActiveAnimationID = kBindPoseAnimationID;
	static const uint32_t kBindPoseAnimationID = AnimationController::kBindPoseAnimationId;

	RasterizerState::SharedPtr mpWireframeRS = nullptr;
	RasterizerState::SharedPtr mpCullPastState[3];  // 0 = no culling, 1 = backface culling, 2 = frontface culling

	DepthStencilState::SharedPtr mpNoDepthDS = nullptr;
	DepthStencilState::SharedPtr mpDepthTestDS = nullptr;

	DirectionalLight::SharedPtr mpDirLight;
	PointLight::SharedPtr mpPointLight;

	std::string mModelString;

	float mNearZ;
	float mFarZ;	
};
