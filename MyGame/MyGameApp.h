#pragma once
#include "Smiley.h"
#include "Unit.h"
#include <vector>
class MyGameApp : public Smiley::SmileyApp {
	// User must override the OnUpdate virtual method
	public:
		MyGameApp();
		virtual void OnUpdate() override;
		virtual void OnKeyPressed(Smiley::KeyPressedEvent& event) override;
		enum class Hollow {
			hollow1, hollow2, hollow3, hollow4, hollow5
		};
		void UpdateHollows();
		Unit GetHollow(Hollow hollowType, int PosX, int PosY);
	private:	
		Unit mHero;
		Unit mBackground;
		Unit mTitleScreen;
		Unit mGameOver1;
		Unit mGameOver2;
		Unit mGameOver3;
		bool mStarted;
		bool mGameOver;
		Smiley::Shader mShader;
		bool mUsedPower;
		bool mSlash;
		int mFrameCounter;
		int mPoints;
		std::vector<Unit> mHollows;
};
