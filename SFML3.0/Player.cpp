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
	double rad = radianConversion(rotationAngle);

	Vector2f rotDir;

	//Rotation calculation
	rotDir.x = direction.x * cos(rad) - direction.y * sin(rad);
	rotDir.y = direction.x * sin(rad) + direction.y * cos(rad);

	return rotDir;
}

void Player::move(CircleShape& playerShape, double deltaTime)
{
	//Rotation

	if (rotationAngle > 360)
	{
		rotationAngle = 0;
	}

	if (rotationAngle < 0)
	{
		rotationAngle = 360;
	}

	if (Keyboard::isKeyPressed(Keyboard::Key::Right))
	{
		rotationAngle += 1.f * deltaTime;
		//std::cout << lookingDirection.x << " " << lookingDirection.y << "\n";
	}

	if (Keyboard::isKeyPressed(Keyboard::Key::Left))
	{
		rotationAngle -= 1.f * deltaTime;
		//std::cout << lookingDirection.x << " " << lookingDirection.y << "\n";
	}

	lookingDirection = direction_with_rotation({Vector2f(0.f, -1.f)});

	Vector2f origin = playerShape.getPosition();
	Vector2f target = origin + lookingDirection;

	double dx = target.x - origin.x;
	double dy = target.y - origin.y;

	double rad = atan2(dy, dx);

	Angle a = radians(rad - PI / 2.0);

	// Rotate line of sight
	lineOfSight.setPosition(origin);
	lineOfSight.setRotation(a);


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
