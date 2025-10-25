#include "Player.h"
#include "WorldMap.h"


bool Player::CollisionDetection(Vector2f direction)
{
	Vector2f futurePrediction = direction;
	CircleShape shapeP = Player::shape;
	shapeP.move(futurePrediction);

	for (auto const &object : World::mapObjects)
	{
		if (shapeP.getGlobalBounds().findIntersection(object.getGlobalBounds()))
		{
			return true;
		}
	}
	return false;
}

void Player::move(CircleShape& playerShape) 
{
	//Rotation

	if (Keyboard::isKeyPressed(Keyboard::Key::Right))
	{
		Angle rotation = radians(rotationAmount);
		playerShape.rotate(rotation);
	}

	if (Keyboard::isKeyPressed(Keyboard::Key::Left)) 
	{
		Angle rotation = -radians(rotationAmount);
		playerShape.rotate(rotation);
	}

	//Movement
	if (Keyboard::isKeyPressed(Keyboard::Key::W) && !CollisionDetection(Vector2f(0, -5.f * movementSpeed)))
	{
		playerShape.move(Vector2f(0, -5.f * movementSpeed));
	}

	if (Keyboard::isKeyPressed(Keyboard::Key::S) && !CollisionDetection(Vector2f(0, 5.f * movementSpeed)))
	{
		playerShape.move(Vector2f(0, 5.f * movementSpeed));
	}

	if (Keyboard::isKeyPressed(Keyboard::Key::D) && !CollisionDetection(Vector2f(5.f * movementSpeed , 0)))
	{
		playerShape.move(Vector2f(5.f * movementSpeed, 0.f));
	}

	if (Keyboard::isKeyPressed(Keyboard::Key::A) && !CollisionDetection(Vector2f(-5.f * movementSpeed, 0)))
	{
		playerShape.move(Vector2f(-5.f * movementSpeed, 0));
	}
}