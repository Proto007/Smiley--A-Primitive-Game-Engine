#include "MyGameApp.h"
#include <random>
MyGameApp::MyGameApp():mTitleScreen("Assets/Textures/title.png", 0, 0, 10), 
					mBackground("Assets/Textures/background.png", 0, 0, 10),
					mHero("Assets/Textures/ichigo.png",0,0, 100),
					mGameOver1("Assets/Textures/gameover1.png",0,0,10),
					mGameOver2("Assets/Textures/gameover2.png",0,0,10),
					mGameOver3("Assets/Textures/gameover3.png",0,0,10) {
	mShader.Load("Assets/Shaders/myVertexShader.glsl","Assets/Shaders/myFragmentShader.glsl");
	mShader.SetVec2IntUniform("screenSize", 800, 800);
	mSlash = false;
	mUsedPower = false;
	mFrameCounter = 0;
	mPoints = 0;
	mStarted = false;
	mGameOver = false;
}

void MyGameApp::OnUpdate() {
	if (mStarted && !mGameOver) {
		mHero.UpdatePosition();
		mBackground.Draw(mShader);
		if (mSlash) {
			mHero.UsePower(mShader);
			auto it = mHollows.begin();
			while (it != mHollows.end()) {
				if (mHero.mPower->CollideWith(*it)) {
					it = mHollows.erase(it);
					mPoints++;
				}
				else {
					it++;
				}
			}
			mSlash = false;
			mUsedPower = false;
		}
		if (mUsedPower) {
			mHero.UsePower(mShader);
			auto it = mHollows.begin();
			while (it != mHollows.end()) {
				if (mHero.mPower->CollideWith(*it)) {
					it = mHollows.erase(it);
					mPoints++;
				}
				else {
					it++;
				}
			}
		}
		//Update the movement of the hollows
		for (auto& hollow : mHollows) {
			hollow.UpdatePosition();
		}
		//Get a random hollow type
		int randHollowNum = rand() % 5 + 1;
		Hollow randomHollow = Hollow::hollow3;
		if (randHollowNum == 1) {
			randomHollow = Hollow::hollow1;
		}
		else if (randHollowNum == 2) {
			randomHollow = Hollow::hollow2;
		}
		else if (randHollowNum == 3) {
			randomHollow = Hollow::hollow3;
		}
		else if (randHollowNum == 4) {
			randomHollow = Hollow::hollow4;
		}
		else if (randHollowNum == 5) {
			randomHollow = Hollow::hollow5;
		}
		//Spawn hollow at random location on the right side of the screen
		int randX = rand() % 300 + 400;
		int randY = rand() % 700;
		if (mFrameCounter % FRAMES_PER_SECOND == 0 && mHollows.size() <= 10) {
			mHollows.push_back(GetHollow(randomHollow, randX, randY));
		}

		//Handle collisions
		auto it = mHollows.begin();
		while (it != mHollows.end()) {
			if (mHero.CollideWith(*it)) {
				mGameOver = true;
				break;
			}
			else {
				it++;
			}
		}
		//If too many hollows escape, end game
		if (mHollows.size() >= 10) {
			mGameOver = true;
		}
		//Draw hero, hollows, projectiles and increment frame counter
		mHero.Draw(mShader);
		UpdateHollows();
		mFrameCounter++;
	}
	// If game ends, give one of the three endings based on how many hollows are killed by user
	else if (mGameOver) {
		if (mPoints > 200) {
			mGameOver3.Draw(mShader);
		}
		else if (mPoints > 100) {
			mGameOver2.Draw(mShader);
		}
		else {
			mGameOver1.Draw(mShader);
		}
	}
	else {
		mTitleScreen.Draw(mShader);
	}
}

void MyGameApp::OnKeyPressed(Smiley::KeyPressedEvent& event) {
	switch (event.GetKeyCode()) {
	case SMILEY_KEY_SPACE: {
		mStarted = true;
		break;
	}
	case SMILEY_KEY_LEFT: {
		mHero.SetPower("Assets/Textures/slash.png", mHero.GetPosX() + 50, mHero.GetPosY() - 10, 100, Unit::Direction::Right);
		mSlash = true;
		break;
	}
	case SMILEY_KEY_RIGHT: {
		mHero.SetPower("Assets/Textures/getsuga.png", mHero.GetPosX(), mHero.GetPosY(), 100, Unit::Direction::Right);
		mUsedPower = true;
		break;
	}
	case SMILEY_KEY_DOWN: {
		if (mHero.IsPositionPossible(mHero.GetPosX(), mHero.GetPosY() - mHero.GetSpeed())) {
			mHero.SetPosY(mHero.GetPosY() - mHero.GetSpeed());
		}
		break;
	}
	case SMILEY_KEY_UP: {
		if (mHero.IsPositionPossible(mHero.GetPosX(), mHero.GetPosY() + mHero.GetSpeed())) {
			mHero.SetPosY(mHero.GetPosY() + mHero.GetSpeed());
		}
		break;
	}
	}
}
//Returns a hollow of hollowType that is set to spawn in PosX and PosY.
//Each hollow type has its own speed and projectile speed
Unit MyGameApp::GetHollow(MyGameApp::Hollow hollowType, int PosX, int PosY) {
	switch (hollowType) {
	case MyGameApp::Hollow::hollow1: {
		Unit HollowType("Assets/Textures/hollow1.png", PosX, PosY, 1);
		HollowType.SetDirection(Unit::Direction::Left);
		HollowType.SetPower("Assets/Textures/power1.png", HollowType.GetPosX(), HollowType.GetPosY(), 6, Unit::Direction::Left);
		return HollowType;
	}
	case MyGameApp::Hollow::hollow2: {
		Unit HollowType("Assets/Textures/hollow2.png", PosX, PosY, 2);
		HollowType.SetDirection(Unit::Direction::Left);
		HollowType.SetPower("Assets/Textures/power2.png", HollowType.GetPosX(), HollowType.GetPosY(), 7, Unit::Direction::Left);
		return HollowType;
	}
	case MyGameApp::Hollow::hollow3: {
		Unit HollowType("Assets/Textures/hollow3.png", PosX, PosY, 3);
		HollowType.SetDirection(Unit::Direction::Left);
		HollowType.SetPower("Assets/Textures/power3.png", HollowType.GetPosX(), HollowType.GetPosY(), 8, Unit::Direction::Left);
		return HollowType;
	}
	case MyGameApp::Hollow::hollow4: {
		Unit HollowType("Assets/Textures/hollow4.png", PosX, PosY, 4);
		HollowType.SetDirection(Unit::Direction::Left);
		HollowType.SetPower("Assets/Textures/power4.png", HollowType.GetPosX(), HollowType.GetPosY(), 9, Unit::Direction::Left);
		return HollowType;
	}
	case MyGameApp::Hollow::hollow5: {
		Unit HollowType("Assets/Textures/hollow5.png", PosX, PosY, 5);
		HollowType.SetDirection(Unit::Direction::Left);
		HollowType.SetPower("Assets/Textures/power5.png", HollowType.GetPosX(), HollowType.GetPosY(), 10, Unit::Direction::Left);
		return HollowType;
	}
	}
}
//Draws hollows, projectiles and ends game on collision with the hero
void MyGameApp::UpdateHollows() {
	for (auto& hollow : mHollows) {
		hollow.Draw(mShader);
		hollow.UsePower(mShader);
		auto it = mHollows.begin();
		while (it != mHollows.end()) {
			if (mHero.CollideWith(*it->mPower)) {
				mGameOver = true;
				break;
			}
			else {
				it++;
			}
		}
	}
}
