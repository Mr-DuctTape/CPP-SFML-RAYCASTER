#include "Enemy.h"

void Enemy::drawEnemy(RenderWindow& renderWindow, Player& player)
{
	Vector2f enemyPosition = enemyShape.getPosition();
	Vector2f origin = player.shape.getPosition();

	Vector2f toEnemy = enemyPosition - origin;
	Vector2f playerLookDirection = player.lookingDirection;

	double dot = toEnemy.x * playerLookDirection.x + toEnemy.y * playerLookDirection.y;
	float magToEnemy = sqrt(toEnemy.x * toEnemy.x + toEnemy.y * toEnemy.y);
	float magLookDir = sqrt(playerLookDirection.x * playerLookDirection.x + playerLookDirection.y * playerLookDirection.y);

	float distance = sqrt(toEnemy.x * toEnemy.x + toEnemy.y * toEnemy.y);

	if (magToEnemy == 0 || magLookDir == 0) return;

	float angleRad = atan2(toEnemy.y, toEnemy.x) - atan2(playerLookDirection.y, playerLookDirection.x);

	if (angleRad > PI) angleRad -= 2 * PI;
	if (angleRad < -PI) angleRad += 2 * PI;

	float angle = (180.0 / PI) * angleRad;

	if (angle > FOV) 
	{
		return; 
	}

	float halfFov = (float)FOV / 2.0f;
	float clampedAngle = std::max((float) - FOV, std::min((float)FOV, angle));
	float screenX = resX * (0.5f + (clampedAngle / (float)FOV));

	float maxSpriteHeight = resY * 2;
	float spriteHeight = maxSpriteHeight / (distance / 2.0);

	CircleShape temp;
	temp.setRadius(spriteHeight);
	temp.setPosition(Vector2f(screenX, resY / 2));
	

	enemyShape.move(Vector2f(0.05f, 0.0));
	renderWindow.draw(temp);

}

