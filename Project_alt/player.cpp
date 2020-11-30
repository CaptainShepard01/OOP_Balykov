#include "player.h"
#include <vector>
#include "utils.h"

int BULLET_SPEED = 5;

Player::Player(int aX, int aY)
	: myBox(aX, aY, 32, 32)
{
	myBulletCount = 50;
	myCurrentBullet = 0;
	myBox.rectangle.setFillColor(sf::Color::Green);
}

bool Player::Update(Box aCollision[], int aCollisionCount)
{
	for (int i = 0; i < myBulletCount; i++)
	{
		Box& bullet = myBullets[i];
		if (bullet.valid)
		{
			bullet.Update(nullptr, 0);
		}
	}

	return myBox.Update(aCollision, aCollisionCount);
}

void Player::Draw(sf::RenderWindow& aWindow)
{
	myBox.Draw(aWindow);

	for (int i = 0; i < myBulletCount; i++)
	{
		Box& bullet = myBullets[i];
		bullet.rectangle.setFillColor(sf::Color::White);
		if (bullet.valid)
		{
			bullet.Draw(aWindow);
		}
	}
}

void Player::OnKeyTyped(sf::Keyboard::Key aKey)
{
	myBox.OnKeyTyped(aKey);

	if (aKey == sf::Keyboard::Space)
	{
		myBullets[myCurrentBullet] = Box(myBox.x+12, myBox.y+12, 8, 16);
		myBullets[myCurrentBullet].SetHorizontal(random(-5, 5));
		myBullets[myCurrentBullet].SetVertical(random(-5, 5));

		myCurrentBullet = myCurrentBullet + 1;
		if (myCurrentBullet == myBulletCount)
		{
			myCurrentBullet = 0;
		}
	}
	else if (aKey == sf::Keyboard::Left)
	{
		myBullets[myCurrentBullet] = Box(myBox.x+12, myBox.y+12, 8, 16);
		myBullets[myCurrentBullet].SetHorizontal(-5);
		myBullets[myCurrentBullet].SetVertical(0);

		myCurrentBullet = myCurrentBullet + 1;
		if (myCurrentBullet == myBulletCount)
		{
			myCurrentBullet = 0;
		}
	}
	else if (aKey == sf::Keyboard::Right)
	{
		myBullets[myCurrentBullet] = Box(myBox.x + 12, myBox.y + 12, 8, 16);
		myBullets[myCurrentBullet].SetHorizontal(5);
		myBullets[myCurrentBullet].SetVertical(0);

		myCurrentBullet = myCurrentBullet + 1;
		if (myCurrentBullet == myBulletCount)
		{
			myCurrentBullet = 0;
		}
	}
	else if (aKey == sf::Keyboard::Down)
	{
		myBullets[myCurrentBullet] = Box(myBox.x + 12, myBox.y + 12, 16, 8);
		myBullets[myCurrentBullet].SetHorizontal(0);
		myBullets[myCurrentBullet].SetVertical(5);

		myCurrentBullet = myCurrentBullet + 1;
		if (myCurrentBullet == myBulletCount)
		{
			myCurrentBullet = 0;
		}
	}
	else if (aKey == sf::Keyboard::Up)
	{
		myBullets[myCurrentBullet] = Box(myBox.x + 12, myBox.y + 12, 16, 8);
		myBullets[myCurrentBullet].SetHorizontal(0);
		myBullets[myCurrentBullet].SetVertical(-5);

		myCurrentBullet = myCurrentBullet + 1;
		if (myCurrentBullet == myBulletCount)
		{
			myCurrentBullet = 0;
		}
	}
}

void Player::OnKeyReleased(sf::Keyboard::Key aKey)
{
	myBox.OnKeyReleased(aKey);
}