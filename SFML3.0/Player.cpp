#include "Player.h"
#include "WorldMap.h"

double radianConversion(double angle)
{
	return angle * (PI / 180.0);
}


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

Vector2f Player::direction_with_rotation(Vector2f direction)
{
	double rad = radianConversion(angle);

	Vector2f rotDir;

	rotDir.x = direction.x * cos(rad) - direction.y * sin(rad);
	rotDir.y = direction.x * sin(rad) + direction.y * cos(rad);

	return rotDir;
}

void Player::move(CircleShape& playerShape)
{
	//Rotation

	if (angle > 360)
	{
		angle = 0;
	}

	if (angle < 0)
	{
		angle = 360;
	}

	if (Keyboard::isKeyPressed(Keyboard::Key::Right))
	{
		angle -= 5.f;
		double rad = radianConversion(angle);
		Angle a = radians(rad);
		playerShape.rotate(a);
	}

	if (Keyboard::isKeyPressed(Keyboard::Key::Left))
	{
		angle += 5.f;
		double rad = radianConversion(angle);
		Angle a = radians(rad);
		playerShape.rotate(a);
	}


	//Movement
	if (Keyboard::isKeyPressed(Keyboard::Key::W) && !CollisionDetection(direction_with_rotation(directions.up)))
	{
		playerShape.move(direction_with_rotation(directions.up));
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::S) && !CollisionDetection(direction_with_rotation(directions.down)))
	{
		playerShape.move(direction_with_rotation(directions.down));
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::D) && !CollisionDetection(direction_with_rotation(directions.right)))
	{
		playerShape.move(direction_with_rotation(directions.right));
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::A) && !CollisionDetection(direction_with_rotation(directions.left)))
	{
		playerShape.move(direction_with_rotation(directions.left));
	}
}
