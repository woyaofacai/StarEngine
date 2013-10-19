#pragma once

#include "defines.h"
#include "Scenes/BaseScene.h"
#include "Logger.h"
#include "Context.h"
#include "Objects/Object.h"
#include "StarComponents.h"
#include "Input/Gestures/DoubleTapGesture.h"
#include "Objects/FreeCamera.h"

class TestScene : public star::BaseScene
{
public:
	TestScene(const tstring& name);
	virtual ~TestScene();

	status CreateObjects();
	status AfterInitializedObjects(const star::Context& context);
	status Update(const star::Context& context);
	status Draw();

private:
	star::DoubleTapGesture* m_TapGesture;
	int m_TotalFrames;
	int m_Step;
	int m_FPS;
	float m_PassedMiliseconds;

	float mRed, mGreen, mBlue;

	star::Object	*m_pObjectOne, 
					*m_pObjectTwo,
					*m_pObjectThree;

	star::FreeCamera *m_pActiveCamera;

	star::RectangleColliderComponent* m_pRectCompOne, *m_pRectCompTwo;
	star::CircleColliderComponent *m_pCircleCompOne, *m_pCircleCompTwo;

	star::SpriteComponent *m_pSpriteComp1,
						  *m_pSpriteComp2;

	float m_Angle, m_Scale, m_ScaleSign;
	int m_XPos;

	static const vec3 NO_PATH_AVAILBLE;
		
	TestScene(const TestScene& t);
	TestScene(TestScene&& t);
	TestScene& operator=(const TestScene& t);
};
